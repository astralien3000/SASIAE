#include "modules.hpp"
#include <QObject>
#include <QString>
#include <QStandardItem>
#include <btVector3.h>

class Balise : public Modules {
Q_OBJECT

public:
  Balise(Robot robot, QObject* parent);

public slots:


signals:

private:
  btVector3 position;
};


