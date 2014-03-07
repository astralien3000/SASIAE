#include "xml_parser.hpp"

XMLParser::XMLParser(){}
XMLParser::~XMLParser(){}
using XMLParser;

const struct robotConfig* parseRobot(const QString& path){
	/*TODO: Validation du fichier */
	QDomDocument doc(path);
    QDomNodeList mcs = doc.elementsByTagName("microcontroller");

	if(mcs.isEmpty())
		return NULL;
		/* Ouverture de la première structure */
    robotConfig *data = new robotConfig();

		/* Noeud Courants de chaque niveau */
    QDomNode tmp1, tmp2, tmp3;

		/* Listes des noeuds utilisés */
    QDomNodeList mods();
    QDomNodeList params();

		/* Pointeurs de sauvegardes des instances courantes */
    microcontrollerConfig *currMC;
    moduleConfig *currMod;
		parameter* currParam;

		/* Parcours des µC */
    for(int i=0; i<mcs.length(); i++) {
			/* Ajout d'une structure µC */
			currMC = new microcontrollerConfig();

			/*Sauvegarde du noeud courrant*/
    	tmp1 = mcs->item(i);

    	currMC->name = tmp1.attributes().namedItem("name").nodeValue();
    	mods = tmp1.toDocument().elementsByTagName("modules");

			/* Parcours des modules */
    	for(int j=0 ; j<mods.length ; j++){
				/* Ajout d'une structure module */
				currMod = new moduleConfig();
    		tmp2=mods->item(j);

    		/* TODO: Récupération des valeurs des attributs */
    		currMC->name=tmp2.attributes().namedItem("name").nodeValue();

    		for(k=0;k<-params.length();k++){
					/* Ajout d'une structure parameter */
					currParam = new parameter();
					
					/* Sauvegarde du noeud */
					tmp3 = params->item(k);

					/* Récupération des valeurs des paramêtres */
					currParam->name = tmp3.attribute().namedItem("name").nodeValue();
					currParam->type = tmp3.attribute().namedItem("type").nodeValue();
					currParam->value = tmp3.attribute().namedItem("value").nodeValue();
					currMod->parameters->push_front(currParam);
				}
    		currMC->modules->push_front(currMod);
    	}
    	data->microcontrollers->push_front(currMC);
    }
	return data;
}
