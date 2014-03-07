#include "xml_parser.hpp"

XMLParser::XMLParser(){}
XMLParser::~XMLParser(){}
using XMLParser;

const struct robotConfig* XMLParser::parseRobot(const QString& path){
	/*TODO: Validation du fichier */
	QDomDocument doc(path);
    QDomNodeList mcs = doc.elementsByTagName("microcontroller");

	if(mcs.isEmpty())
		return NULL;

    robotConfig *data = new robotConfig();
    QDomNode tmp1, tmp2, tmp3;
    QDomNodeList mods();
    QDomNodeList params();
    microcontrollerConfig *currMC;
    moduleConfig *currMod;

    for(int i=0; i<mcs.length(); i++) {
    	data->microcontrollers->push_front(new microcontrollerConfig);
    	tmp1=mcs->item(i);
    	currMC=data->microcontrollers->begin();
    	currMC->name=tmp1.attributes().namedItem("name").nodeValue();
    	mods=tmp1.toDocument().elementsByTagName("modules");
    	for(int j=0 ; j<mods.length ; j++){
    		currMC->modules->push_front(new moduleConfig());
    		tmp2=mods->item(j);
    		currMod=currMC->modules->begin();
    		/* TODO: Récupération des valeurs des attributs */
    		currMC->name=tmp2.attributes().namedItem("name").nodeValue();

    		/* TODO: Gestion des paramètres */
    		for(k=0;k<-params.length();k++){}
    	}
    }
	return data;
}
