#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "../../../src/coordinator/xml_parser/xml_parser.hpp"
#include <QString>
#include <QCoreApplication>

int main(int argc, char **argv) {
	QCoreApplication app(argc, argv);	
	/* Ouverture du fichier test */
	std::cout<<"Ouverture du fichier de configuration d'un robot"<<std::endl;
	const XMLParser::robotConfig* robot = XMLParser::parseRobot(QString("./robot.xml"));
	assert(robot!=NULL);

	/* Vérification des données */
	std::cout<<"Fichier de configuration ouvert\nAnalyse des données"<<std::endl;

	assert(robot->mesh_path=="~/mesh/robots/robot1A1314.stl");
	assert(!robot->microcontrollers.empty());
	assert((*robot->microcontrollers.begin())->name=="UNIOC");

	assert(!(*robot->microcontrollers.begin())->modules.isEmpty());
	assert((*(*robot->microcontrollers.begin())->modules.begin())->name=="GP2");

	assert((*(*robot->microcontrollers.begin())->modules.begin())->position.x==10);
	assert((*(*robot->microcontrollers.begin())->modules.begin())->position.y==-2);
	assert((*(*robot->microcontrollers.begin())->modules.begin())->position.z==10);
	assert((*(*robot->microcontrollers.begin())->modules.begin())->position.alpha==0);
	assert((*(*robot->microcontrollers.begin())->modules.begin())->position[4]==0);
	assert((*(*robot->microcontrollers.begin())->modules.begin())->position.val[5]==0);

	assert(!(*(*robot->microcontrollers.begin())->modules.begin())->parameters.isEmpty());
	assert((*(*(*robot->microcontrollers.begin())->modules.begin())->parameters.begin())->type=="int");
	assert((*(*(*robot->microcontrollers.begin())->modules.begin())->parameters.begin())->name=="bell");
	assert((*(*(*robot->microcontrollers.begin())->modules.begin())->parameters.begin())->value=="20");

	std::cout<<"Fin de l'analyse"<<std::endl;
	
	std::cout<<"Ouverture du fichier de configuration d'une table"<<std::endl;
	const XMLParser::tableConfig* table = XMLParser::parseTable(QString("./table.xml"));
	assert(table!=NULL);
	std::cout<<"Fichier de configuration ouvert\nAnalyse des données"<<std::endl;
	assert(table->mesh_path=="~/mesh/table/t1314.stl");
	assert(!table->toys.isEmpty());
	assert((*table->toys.begin())->name=="triangle1");
	assert((*table->toys.begin())->weight==170);
	assert((*table->toys.begin())->mesh_path=="~/mesh/jouets/triangle1314.stl");
	assert((*table->toys.begin())->position.x==10);
	assert((*table->toys.begin())->position.y==10);
	assert((*table->toys.begin())->position.z==10);
	assert((*table->toys.begin())->position.alpha==0);
	assert((*table->toys.begin())->position.beta==0);
	assert((*table->toys.begin())->position.gamma==0);
	std::cout<<"Fin de l'analyse"<<std::endl;
	return EXIT_SUCCESS;
}
