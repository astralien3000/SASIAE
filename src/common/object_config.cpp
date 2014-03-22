#include "object_config.hpp"

ObjectConfig::moduleConfig::~moduleConfig() {
	for(int i=0; i<parameters.length(); i++)
		delete parameters.at(i);
}
ObjectConfig::microConfig::~microConfig() {
	for(int i=0; i<modules.length(); i++)
		delete modules.at(i);
}
ObjectConfig::robotConfig::~robotConfig() {
	for(int i=0; i<microcontrollers.length(); i++)
		delete microcontrollers.at(i);
}
ObjectConfig::tableConfig::~tableConfig() {
	for(int i=0; i<toys.length(); i++)
		delete toys.at(i);
}
