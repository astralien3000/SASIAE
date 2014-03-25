#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include "../common/object_config.hpp"
#include <QtXml>

class XMLParser {

	static const QDomDocument* open(const QString& xml_path, const QString& xsd_path);
	public:
		XMLParser();
		~XMLParser();
		static const struct ObjectConfig::robotConfig* parseRobot(const QString& path);
		static const struct ObjectConfig::tableConfig* parseTable(const QString& path);
};


#endif //XML_PARSER_HPP
