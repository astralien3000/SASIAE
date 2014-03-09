#include "xml_parser.hpp"

XMLParser::XMLParser(){}
XMLParser::~XMLParser(){}

const struct XMLParser::robotConfig* XMLParser::parseRobot(const QString& path){
	/*TODO: Validation du fichier */
	QDomDocument doc(path);
	QDomNodeList mcs = doc.elementsByTagName("microcontroller");

	if(mcs.isEmpty())
		return NULL;
	/* Ouverture de la première structure */
	XMLParser::robotConfig *data = new XMLParser::robotConfig();

	/* Noeud Courants de chaque niveau */
	QDomNode tmp1, tmp2, tmp3;

	/* Listes des noeuds utilisés */
	QDomNodeList mods;
	QDomNodeList params;

	/* Pointeurs de sauvegardes des instances courantes */
	XMLParser::microCConfig *currMC;
	XMLParser::moduleConfig *currMod;
	XMLParser::parameter* currParam;

	/* Parcours des µC */
	for(int i=0; i<mcs.length(); i++) {
		/* Ajout d'une structure µC */
		currMC = new XMLParser::microCConfig();

		/*Sauvegarde du noeud courrant*/
		tmp1 = mcs.item(i);

		currMC->name = tmp1.attributes().namedItem("name").nodeValue();
		mods = tmp1.toDocument().elementsByTagName("modules");

		/* Parcours des modules */
		for(int j=0 ; j<mods.length() ; j++){
			/* Ajout d'une structure module */
			currMod = new XMLParser::moduleConfig();
			tmp2=mods.item(j);

			tmp3=tmp2.toDocument().elementsByTagName("location").item(0);
			currMod->position = new XMLParser::positionVector();

			/* Extraction des Attributs */
			currMod->position->x = tmp3.toElement().attribute("X").toInt();
			currMod->position->y = tmp3.toElement().attribute("Y").toInt();
			currMod->position->z = tmp3.toElement().attribute("Z").toInt();
			currMod->position->alpha = tmp3.toElement().attribute("alpha").toInt();
			currMod->position->beta = tmp3.toElement().attribute("beta").toInt();
			currMod->position->gamma = tmp3.toElement().attribute("gamma").toInt();
			currMC->name=tmp2.toElement().attribute("name");

			for(int k=0;k<-params.length();k++){
				/* Ajout d'une structure parameter */
				currParam = new XMLParser::parameter();

				/* Sauvegarde du noeud */
				tmp3 = params.item(k);

				/* Récupération des valeurs des paramêtres */
				currParam->name = tmp3.toElement().attribute("name");
				currParam->type = tmp3.toElement().attribute("type");
				currParam->value = tmp3.toElement().attribute("value");
				currMod->parameters->push_front(currParam);
			}
			currMC->modules->push_front(currMod);
		}
		data->microcontrollers->push_front(currMC);
	}
	return data;
}
