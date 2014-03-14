#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include <QString>
#include <QtXml>

class XMLParser {

	public:
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

			inline float& operator[](int index) {
				return val[index];
			}

			inline const float& operator[](int index) const {
				return val[index];
			}
			
		};

		struct parameter {
			QString type;
			QString name;
			QString value;
		};

		struct moduleConfig {
			QString name;
			positionVector position;
			QList<const parameter*> parameters;
		};

		struct microCConfig {
			QString name;
			QList<const moduleConfig*> modules;
		};

		struct robotConfig {
			QString mesh_path;
			QList<const microCConfig*> microcontrollers;
		};

		struct toyConfig {
			positionVector* position;	
			QString mesh_path;
			QString name;
			QVariant* weight;
		};

		struct tableConfig {
			QString mesh_path;
			QList<const toyConfig*> toys;
		};

		XMLParser();
		~XMLParser();
		static const struct XMLParser::robotConfig* parseRobot(const QString& path);
		static const struct XMLParser::robotConfig* parseTable(const QString& path);
};


#endif //XML_PARSER_HPP
