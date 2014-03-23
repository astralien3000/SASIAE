#include "stlmesh.hpp"
#include <QList>
#include <QVector>
#include <QDebug>
#include "../stl/STLReader.hpp"
#include "HACD/hacdCircularList.h"
#include <HACD/hacdVector.h>
#include <HACD/hacdICHull.h>
#include <HACD/hacdGraph.h>
#include <HACD/hacdHACD.h>


QMap<QString, QPair<btCollisionShape*, unsigned int>> STLMesh::s_stlshapes;

STLMesh::STLMesh(const QString stlpath, double mass, PositionData start_pos) : _path(stlpath) {
    qDebug()<<"STLMesh Constructor stlpath="<<stlpath;
  init(stlpath, mass, start_pos);
}

STLMesh::STLMesh(const STLMesh & source) : Mesh(source) {
  // copie la shape d'un smart pointer
  this->_path = source._path;
  STLMesh::s_stlshapes[this->_path].second++;
}

STLMesh::~STLMesh() {
  STLMesh::s_stlshapes[this->_path].second--;
}

void STLMesh::init(const QString stlpath, double mass, PositionData pos) {
  if(mass == 0) {
   qDebug()<<"STLMesh init mass= 0 stlpath="<<stlpath;
    QList<QVector<float>> retour = STLReader::readSTLTextFile(stlpath);
    if(retour.size() == 0)
      return;
    qDebug()<< "return list of size=" << retour.size();

    btTriangleMesh* trimesh = new btTriangleMesh();
    for(int i=0; i<retour.size(); i++ ) 
		{
      QVector<float> s = retour.at(i);
      trimesh->addTriangle(btVector3(s[0],s[1],s[2]),
                            btVector3(s[3],s[4],s[5]), 
                            btVector3(s[6],s[7],s[8]));
		}
        qDebug()<< "STLMesh init mass= 0 END OF LOOP trimesh "<<trimesh;
    buildRigidBody(new btBvhTriangleMeshShape(trimesh, true), mass, pos);
     
  }
  else if(s_stlshapes.contains(stlpath)) {
    s_stlshapes[stlpath].second++;
    buildRigidBody(s_stlshapes[stlpath].first, mass, pos);
  }
  else {
    QList<QVector<float>> retour = STLReader::readSTLTextFile(stlpath);
    if(retour.size() == 0)
      return;
    //séparation points et faces
    std::vector< HACD::Vec3<HACD::Real> > points;
		std::vector< HACD::Vec3<long> > triangles;
    for(int i=0; i<retour.size(); i++ ) 
		{
      int index = points.size();
      int ii[3] = {-1,-1,-1};
      for(int j=0; j<retour.at(i).size(); j+=3)
      {
			  HACD::Vec3<HACD::Real> vertex(retour.at(i).at(j), retour.at(i).at(j+1),retour.at(i).at(j+2));
        //recherche du point dans la list des points deja crée
        for(int h=0; h < points.size();h++) {
          if(points[h].X() == vertex.X()
            && points[h].Y() == vertex.Y() 
            && points[h].Z() == vertex.Z())
            ii[j/3] = h; 
        }
        if(ii[j/3] == -1) {
          ii[j/3] = points.size();
			    points.push_back(vertex);
        }
      }
			HACD::Vec3<long> triangle(ii[0], ii[1], ii[2]);
			triangles.push_back(triangle);
		}
    qDebug() << "Importation de " << points.size()<<" points pour " << triangles.size() <<  "faces.";

    HACD::HACD myHACD;
		myHACD.SetPoints(&points[0]);
		myHACD.SetNPoints(points.size());
		myHACD.SetTriangles(&triangles[0]);
		myHACD.SetNTriangles(triangles.size());
		myHACD.SetCompacityWeight(0.1);
		myHACD.SetVolumeWeight(0.0);

		// HACD parameters
		// Recommended parameters: 2 100 0 0 0 0
		size_t nClusters = 1;
		double concavity = 100;
		bool invert = false;
		bool addExtraDistPoints = false;
		bool addNeighboursDistPoints = false;
		bool addFacesPoints = false;       

		myHACD.SetNClusters(nClusters);                     // minimum number of clusters
		myHACD.SetNVerticesPerCH(200);                      // max of 100 vertices per convex-hull
		myHACD.SetConcavity(concavity);                     // maximum concavity
		myHACD.SetAddExtraDistPoints(addExtraDistPoints);   
		myHACD.SetAddNeighboursDistPoints(addNeighboursDistPoints);   
		myHACD.SetAddFacesPoints(addFacesPoints); 

		myHACD.Compute();
		nClusters = myHACD.GetNClusters();	
    qDebug() << "nbcluster trouve " << nClusters;
		//myHACD.Save("output.wrl", false);

    /*******Création de la forme composé *******/
    btCompoundShape* compound = new btCompoundShape();
			btTransform trans;
			trans.setIdentity();

			for (unsigned int c=0;c<nClusters;c++)
			{
				//generate convex result
				size_t nPoints = myHACD.GetNPointsCH(c);
				size_t nTriangles = myHACD.GetNTrianglesCH(c);

				float* vertices = new float[nPoints*3];
				float* vertices2 = new float[nTriangles*9];
				
        HACD::Vec3<HACD::Real> * pointsCH = new HACD::Vec3<HACD::Real>[nPoints];
				HACD::Vec3<long> * trianglesCH = new HACD::Vec3<long>[nTriangles];
				myHACD.GetCH(c, pointsCH, trianglesCH);

				// points
				for(size_t v = 0; v < nPoints; v++)
				{
					vertices[3*v] = pointsCH[v].X();
					vertices[3*v+1] = pointsCH[v].Y();
					vertices[3*v+2] = pointsCH[v].Z();
				}
				// triangles
				for(size_t f = 0; f < nTriangles; f++)
				{
          memcpy(&vertices2[9*f], &vertices[3*trianglesCH[f].X()], sizeof(float)*3);
          memcpy(&vertices2[9*f+3], &vertices[3*trianglesCH[f].Y()], sizeof(float)*3);
          memcpy(&vertices2[9*f+6], &vertices[3*trianglesCH[f].Z()], sizeof(float)*3);
				}

				delete [] pointsCH;
				delete [] trianglesCH;
      btConvexHullShape* convexShape = new btConvexHullShape();
      for(int k=0; k < nTriangles*9 ; k+=3) {
          convexShape->addPoint(btVector3(vertices2[k],vertices2[k+1],vertices2[k+2]),true);
          //std::cout << vertices2[k] << " " << vertices2[k+1]<< " " << vertices2[k+2] << std::endl;
        }
				//trans.setIdentity();
				compound->addChildShape(trans,convexShape);
			}
      buildRigidBody(compound, mass, pos);
      s_stlshapes.insert(stlpath, QPair<btCollisionShape*,unsigned int>(compound,1)); 
  }
}
