#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include <QString>
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
		QString type;
		QString name;
		QVariant value;
	};

	struct moduleConfig {
		QString name;
		positionVector position;
		QList<parameter> parameters;
	};

	struct microCConfig {
		QString name;
		QList<moduleConfig> modules;
	};

	struct robotConfig {
		QString mesh_path;
		QList<microcontrollerConfig> microcontrollers;
	};
}

class XMLParser {
	public:
		static struct robotConfig& parse(QString&);
}


#endif //XML_PARSER_HPP
