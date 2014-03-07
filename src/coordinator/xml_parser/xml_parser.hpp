#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include <QString>
#include <QtXml>
class XMLParser {
	union positionVector {
		struct{
			float x;
			float y;
			float z;
			float alpha;
			float beta;
			float gamma;
		};
		float val[6];
	};

	struct parameter {
		QString type;
		QString name;
		QVariant* value;
	};

	struct moduleConfig {
		QString name;
		positionVector* position;
		QList<const parameter*>* parameters;
	};

	struct microCConfig {
		QString name;
		QList<const moduleConfig*>* modules;
	};

	struct robotConfig {
		QString mesh_path;
		QList<const microCConfig*>* microcontrollers;
	};

	struct toyConfig {
		positionVector* position;	
		QString mesh_path;
		QString name;
		QVariant* weight;
	};

	struct tableConfig {
		QString mesh_path;
		QList<const toyConfig*>* toys;
	};

	public:
		XMLParser();
		~XMLParser();
		const struct XMLParser::robotConfig* parseRobot(const QString& path);
		const struct XMLParser::robotConfig* parseTable(const QString& path);
};


#endif //XML_PARSER_HPP
