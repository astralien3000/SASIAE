#include "modules.hpp"
#include <QObject>
#include <QString>
#include <QStandardItem>


class Servo : public Modules {
	Q_OBJECT

public:
	Servo(int position, QObject* parent);

	public slots:
	virtual void received(QString message);
	virtual void simulStep();
	virtual QStandardItem* getData();

	signals:
	virtual void send(QString message);

private:
	int position;
	QStandardItem* _dataRoot;
};
