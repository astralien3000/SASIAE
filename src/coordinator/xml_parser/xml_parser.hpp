#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include <QString>
#include <QDomDocument>

namespace XMLParser{
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
		QString *type;
		QString *name;
		QVariant *value;
	};

	struct moduleConfig {
		QString *name;
		positionVector *position;
		QList<const parameter*> *parameters;
	};

	struct microCConfig {
		QString *name;
		QList<const moduleConfig*> *modules;
	};

	struct robotConfig {
		QString *mesh_path;
		QList<const microcontrollerConfig*> *microcontrollers;
	};
}

class XMLParser {
	public:
		static struct robotConfig* parse(QString&);
};


#endif //XML_PARSER_HPP
