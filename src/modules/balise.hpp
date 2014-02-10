#include "modules.hpp"
#include "../physical_calculator/robot.hpp"
#include "../physical_calculator/physical_calculator.hpp"

#include <QObject>
#include <QString>
#include <QStandardItem>
#include <btBulletDynamicsCommon.h>


class Balise : public Modules {
	Q_OBJECT

public:
	Balise(Robot* robot, QObject* parent, PhysicalCalculator* calculator);
	btVector3 get_position();


	public slots:
	virtual QStandardItem* getData();
	virtual void received(QString message);
	virtual void simulStep();


	signals:
	virtual void send(QString message);


private:
	btVector3 position;
	btRigidBody* boxBody;
	QStandardItem* _dataRoot;
};


