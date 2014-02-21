#include "xml_parser.hpp"

XMLParser::XMLParser(){}
XMLParser::~XMLParser(){}

const struct robotConfig& XMLParser::parse(const QString& path){
	/*TODO: Validation du fichier */
	QDomDocument doc(path);

	return NULL;
}
