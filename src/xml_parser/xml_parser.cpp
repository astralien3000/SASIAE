#include "xml_parser.hpp"
#include <assert.h>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QtXmlPatterns>
#include <QHash>

XMLParser::XMLParser(){}
XMLParser::~XMLParser(){}

const QDomDocument* XMLParser::open(const QString& xml_path, const QString& xsd_path){
	/* Vérification XSD */
	/* Ouverture */
	QXmlSchema schema;
	QFile g(xsd_path);
	if (!g.open(QIODevice::ReadOnly))
		return NULL;
	schema.load(&g);
	g.close();
	if(!schema.isValid()){
		qDebug()<<"Invalid Schema";
		return NULL;
	}

	/* Ouverture du fichier en un Dom Document*/
	QDomDocument* doc = new QDomDocument("doc");
	QFile f(xml_path);
	if (!f.open(QIODevice::ReadOnly))
		return NULL;

	/* Validation du schema */
	QXmlSchemaValidator validator(schema);
	if(!validator.validate(&f)){
		qDebug()<<"Bad XML File";
		return NULL;
	}

	f.seek(0);
	if (!doc->setContent(&f)) {
		f.close();
		return NULL;
	}
	f.close();
	return doc;
}

void parseMesh(const QDomElement& mesh, ObjectConfig::meshConfig& cfg) {
  cfg.path = mesh.attribute("src");
  if(mesh.hasAttribute("scale")) {
    cfg.scale = mesh.attribute("scale").toFloat();
  }
  else {
    cfg.scale = 1;
  }
  
  if(mesh.hasAttribute("xOffset")) {
    cfg.offset.x = mesh.attribute("xOffset").toFloat();
  }
  else {
    cfg.offset.x = 0.f;
  }
	
  if(mesh.hasAttribute("yOffset")) {
    cfg.offset.y = mesh.attribute("yOffset").toFloat();
  }
  else {
    cfg.offset.y = 0.f;
  }
  
  if(mesh.hasAttribute("zOffset")) {
    cfg.offset.z = mesh.attribute("zOffset").toFloat();
  }
  else {
    cfg.offset.z = 0.f;
  }
}

const struct ObjectConfig::robotConfig* XMLParser::parseRobot(const QString& path){
	/* Ouverture d'un fichier xml */
    const QDomDocument* doc = open(path,QString(":/xsd/robot.xsd"));
  if(doc == NULL) {
    qDebug()<< "Impossible de charger le document";
    return NULL;
  }
	QDomNode r = doc->elementsByTagName("robot").item(0);

	/* Ouverture de la première structure */
	ObjectConfig::robotConfig *data = new ObjectConfig::robotConfig();

	/* Noeud Courants de chaque niveau */
	QDomNode tmp1, tmp2, tmp3;

	/* Listes des noeuds utilisés */
	QDomNodeList mcs;
	QDomNodeList mods;
	QDomNodeList params;

	/* Pointeurs de sauvegardes des instances courantes */
	ObjectConfig::microConfig *currMC;
	ObjectConfig::moduleConfig *currMod;
	//ObjectConfig::parameter* currParam;

	/* Ajout du lien vers le mesh du robot */
	QDomElement mesh = r.firstChildElement("mesh");
	parseMesh(mesh, data->mesh);
	
	mcs=r.toElement().elementsByTagName("microcontroller");
    data->weight=r.toElement().attribute("weight").toFloat();
    data->img_path = r.firstChildElement("img").attribute("src");

	/* Parcours des µC */
	for(int i=0; i<mcs.length(); i++) {
		/* Ajout d'une structure µC */
		currMC = new ObjectConfig::microConfig();

		/*Sauvegarde du noeud courrant*/
		tmp1 = mcs.item(i);

		currMC->name = tmp1.toElement().attribute("name");
		currMC->bin = tmp1.toElement().attribute("bin");
		mods = tmp1.toElement().elementsByTagName("module");

		/* Parcours des modules */
		for(int j=0 ; j<mods.length() ; j++){
			/* Ajout d'une structure module */
			currMod = new ObjectConfig::moduleConfig();
			tmp2=mods.item(j);

			tmp3=tmp2.toElement().elementsByTagName("location").item(0);

			/* Extraction des Attributs */
			currMod->position.x = tmp3.toElement().attribute("X").toFloat();
			currMod->position.y = tmp3.toElement().attribute("Y").toFloat();
			currMod->position.z = tmp3.toElement().attribute("Z").toFloat();
			currMod->position.alpha = tmp3.toElement().attribute("alpha").toFloat();
			currMod->position.beta = tmp3.toElement().attribute("beta").toFloat();
			currMod->position.gamma = tmp3.toElement().attribute("gamma").toFloat();
            currMod->name=tmp2.toElement().attribute("name");
            currMod->type = tmp2.toElement().attribute("type");

			params=tmp2.toElement().elementsByTagName("parameter");

			for(int k=0;k<params.length();k++){
				/* Ajout d'une structure parameter */
				//currParam = new ObjectConfig::parameter();

				/* Sauvegarde du noeud */
				tmp3 = params.item(k);

				/* Récupération des valeurs des paramêtres */
				//currParam->name = tmp3.toElement().attribute("name");
				//currParam->type = tmp3.toElement().attribute("type");
				//currParam->value = tmp3.toElement().attribute("value");
				//currMod->parameters.push_front(currParam);
        currMod->parameters.insert(tmp3.toElement().attribute("name"),tmp3.toElement().attribute("value"));
			}
			currMC->modules.push_front(currMod);
		}
		data->microcontrollers.push_front(currMC);
	}
	return data;
}

const struct ObjectConfig::tableConfig* XMLParser::parseTable(const QString& path) {
    qDebug() << "parseTable : " << path;
  const QDomDocument* doc = open(path, QString(":/xsd/table.xsd"));
  if(doc == NULL) {
    qDebug()<< "Impossible de charger le document";
    return NULL;
  }

  QDomElement t = doc->elementsByTagName("table").item(0).toElement();
  ObjectConfig::tableConfig* data = new ObjectConfig::tableConfig();

  QDomElement mesh = t.firstChildElement("mesh");
  parseMesh(mesh, data->mesh);
  
  data->img_path = t.firstChildElement("img").attribute("src");

  QDomNodeList toys = t.elementsByTagName("toy");
  for(int i = 0; i < toys.length(); i++) {
    if(!toys.item(i).isElement()) {
      continue;
    }
    QDomElement toyElem = toys.item(i).toElement();

    ObjectConfig::toyConfig* toy = new ObjectConfig::toyConfig();
    toy->name = toyElem.attribute("name");
    toy->img_path = toyElem.firstChildElement("img").attribute("src");
    toy->weight = toyElem.attribute("weight").toFloat();

    QDomElement mesh = toyElem.firstChildElement("mesh");
    parseMesh(mesh, toy->mesh);

    QDomElement loc = toyElem.firstChildElement("location");
    toy->position.x = loc.attribute("X").toFloat();
    toy->position.y = loc.attribute("Y").toFloat();
    toy->position.z = loc.attribute("Z").toFloat();
    toy->position.alpha = loc.attribute("alpha").toFloat();
    toy->position.beta = loc.attribute("beta").toFloat();
    toy->position.gamma = loc.attribute("gamma").toFloat();

    data->toys.push_front(toy);
  }

  delete doc;
  return data;
}

