#include "modules.hpp"
#include "../PhysicalCalculator/robot.hpp"
#include "../PhysicalCalculator/physical_calculator.hpp"

#include <QObject>
#include <QString>
#include <QStandardItem>
#include <btBulletDynamicsCommon.h>


class Balise : public Modules {
Q_OBJECT

public:
  Balise(Robot* robot, QObject* parent);

public slots:



signals:

private:
  btVector3 position;
};


