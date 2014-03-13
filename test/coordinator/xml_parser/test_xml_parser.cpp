#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "../../../src/coordinator/xml_parser/xml_parser.hpp"
#include <QString>

int main() {
	/* Ouverture du fichier test */
	std::cout<<"Ouverture du fichier de configuration"<<std::endl;
	const XMLParser::robotConfig* robot = XMLParser::parseRobot(QString("./robot.xml"));
	assert(robot!=NULL);

	/* Vérification des données */
	std::cout<<"Fichier de configuration ouvert\nAnalyse des données"<<std::endl;

//	assert(robot->mesh_path!=NULL);
//	assert(robot->mesh_path=="~/mesh/robots/robot1A1314.stl");
	assert(!robot->microcontrollers->empty());
	assert((*robot->microcontrollers->begin())->name=="UNIOC");

	assert((*(*robot->microcontrollers->begin())->modules->begin())->name=="GP2");
	assert((*(*robot->microcontrollers->begin())->modules->begin())->position->x==10);
	assert((*(*robot->microcontrollers->begin())->modules->begin())->position->y==-2);
	assert((*(*robot->microcontrollers->begin())->modules->begin())->position->z==10);
	assert((*(*robot->microcontrollers->begin())->modules->begin())->position->alpha==0);
	assert((*(*(*robot->microcontrollers->begin())->modules->begin())->position)[4]==0);
	assert((*(*robot->microcontrollers->begin())->modules->begin())->position->val[5]==0);
	assert((*(*(*robot->microcontrollers->begin())->modules->begin())->parameters->begin())->type=="int");
	assert((*(*(*robot->microcontrollers->begin())->modules->begin())->parameters->begin())->name=="bell");
	assert((*(*(*robot->microcontrollers->begin())->modules->begin())->parameters->begin())->value=="20");

	std::cout<<"Fin de l'analyse"<<std::endl;
	return EXIT_SUCCESS;
}
