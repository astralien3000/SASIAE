#include "xml_parser.hpp"
#include <assert.h>
#include <QDebug>
#include <QFile>
#include <QXmlSchema>
#include <QXmlSchemaValidator>


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

const struct XMLParser::robotConfig* XMLParser::parseRobot(const QString& path){
	/* Ouverture d'un fichier xml */
	const QDomDocument* doc = open(path,QString("./robot.xsd"));
	QDomNode r = doc->elementsByTagName("robot").item(0);

	/* Ouverture de la première structure */
	XMLParser::robotConfig *data = new XMLParser::robotConfig();

	/* Noeud Courants de chaque niveau */
	QDomNode tmp1, tmp2, tmp3;

	/* Listes des noeuds utilisés */
	QDomNodeList mcs;
	QDomNodeList mods;
	QDomNodeList params;

	/* Pointeurs de sauvegardes des instances courantes */
	XMLParser::microCConfig *currMC;
	XMLParser::moduleConfig *currMod;
	XMLParser::parameter* currParam;

	/* Ajout du lien vers le mesh du robot */
	data->mesh_path=r.firstChildElement("mesh").attribute("src");
	mcs=r.toElement().elementsByTagName("microcontroller");

	/* Parcours des µC */
	for(int i=0; i<mcs.length(); i++) {
		/* Ajout d'une structure µC */
		currMC = new XMLParser::microCConfig();

		/*Sauvegarde du noeud courrant*/
		tmp1 = mcs.item(i);

		currMC->name = tmp1.toElement().attribute("name");
		mods = tmp1.toElement().elementsByTagName("module");

		/* Parcours des modules */
		for(int j=0 ; j<mods.length() ; j++){
			/* Ajout d'une structure module */
			currMod = new XMLParser::moduleConfig();
			tmp2=mods.item(j);

			tmp3=tmp2.toElement().elementsByTagName("location").item(0);

			/* Extraction des Attributs */
			currMod->position.x = tmp3.toElement().attribute("X").toInt();
			currMod->position.y = tmp3.toElement().attribute("Y").toInt();
			currMod->position.z = tmp3.toElement().attribute("Z").toInt();
			currMod->position.alpha = tmp3.toElement().attribute("alpha").toInt();
			currMod->position.beta = tmp3.toElement().attribute("beta").toInt();
			currMod->position.gamma = tmp3.toElement().attribute("gamma").toInt();
			currMod->name=tmp2.toElement().attribute("name");

			params=tmp2.toElement().elementsByTagName("parameter");

			for(int k=0;k<params.length();k++){
				/* Ajout d'une structure parameter */
				currParam = new XMLParser::parameter();

				/* Sauvegarde du noeud */
				tmp3 = params.item(k);

				/* Récupération des valeurs des paramêtres */
				currParam->name = tmp3.toElement().attribute("name");
				currParam->type = tmp3.toElement().attribute("type");
				currParam->value = tmp3.toElement().attribute("value");
				currMod->parameters.push_front(currParam);
			}
			currMC->modules.push_front(currMod);
		}
		data->microcontrollers.push_front(currMC);
	}
	return data;
}
