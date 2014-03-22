#ifndef OBJECT_CONFIG_HPP
#define OBJECT_CONFIG_HPP

#include "position_data.hpp"
#include <QList>
#include <QString>

namespace ObjectConfig {

    struct parameter {
			QString type;
			QString name;
			QString value;
		};

		struct moduleConfig {
			QString name;
			QString type;
			PositionData position;
			QList<const parameter*> parameters;
			~moduleConfig();
		};

		struct microConfig {
			QString name;
			QList<const moduleConfig*> modules;
			~microConfig();
		};

		struct robotConfig {
            float weight;
			QString mesh_path;
			QList<const microConfig*> microcontrollers;
			~robotConfig();
		};

		struct toyConfig {
			PositionData position;	
			QString mesh_path;
			QString name;
			int weight;
		};

		struct tableConfig {
			QString mesh_path;
			QString img_path;
			QList<const toyConfig*> toys;
			~tableConfig();
		};
};

#endif
