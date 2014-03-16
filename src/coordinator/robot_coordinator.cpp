#include "robot_coordinator.hpp"

#include <QtCore/QDebug>

RobotCoordinator::RobotCoordinator(void) {
  _sync = 0;
  _time = 0;
}

RobotCoordinator::~RobotCoordinator(void) {

}

// utility inline function
inline void sendMessage(QProcess* p, const QString& msg) {
  p->write(msg.toUtf8());
}

void RobotCoordinator::handleRecv(void) {
  QProcess* client = (QProcess*)sender();
      
  if(!client) {
    qDebug() << "ERROR : handleRecv called without sender\n";
    return;
  }

  QString client_name = _robots.key(client);

  while(client->canReadLine()) {
    QString message = client->readLine();
    qDebug() << "message CT -> Coord : " << message;
    // Parse first letter
    switch((message.toStdString())[0]) {
      
    case('S'): // Stop message
      unloadRobot(client_name);
      break;
      
    case('D'): // Device message
      qDebug() << "Message received from " << client_name << " : " << message << "\n";
      emit recvDeviceMessage(client_name, message);
      break;

    case('T'): // Synchronisation message
      qDebug() << "Synchronisation signal received";
      if(_robots.size() <= ++_sync) {
	emit nextStep();
	emit synchronised();
	_sync = 0;
      }
      break;

    case('M'): // Log messages (GUI)
      qDebug() << "[] Log : " << message << "\n";
      emit recvGuiMessage(message);
      break;
      
    default: // Unknown
      qDebug() << "Unrecognized message header\n";
      break;
    }
  }
}

void RobotCoordinator::sendModuleMessage(QString rname, QString msg) {
  //qDebug() << "sending to " << rname << " : " << msg << "\n";
  sendMessage(_robots.value(rname), msg);
}

void RobotCoordinator::sendSyncMessage(int timestamp) {
  foreach(QProcess* bot, _robots) {
    sendMessage(bot, QString("T %1 %2\n").arg(timestamp).arg(10));
    //qDebug() << QString("T %1 %2\n").arg(timestamp).arg(10) << "\n";
  }
}

bool RobotCoordinator::loadRobot(QString name, QString path) {
  qDebug() << "loading robot " << name << "\n";

  QProcess* bot = new QProcess(this);
  _robots.insert(name, bot);
  
  connect(
	  bot, 
	  SIGNAL(readyRead()), 
	  this,
	  SLOT(handleRecv())
	  );

  connect(
	  this, 
	  SIGNAL(synchronised()), 
	  this,
	  SIGNAL(nextStep())
	  );

  bot->start(path, QStringList());

  if(!bot->waitForStarted()) {
    qDebug() << "ERROR : unable to start robot's process\n";
    return false;
  }
  return true;
}

bool RobotCoordinator::unloadRobot(QString name) {
  QProcess* client = _robots.value(name);
  sendMessage(client, "S");
  client->closeWriteChannel();
  if(!client->waitForFinished()) {
    qDebug() << "ERROR : in waitForFinished closeRobot" << '\n';
    return false;
  }
  return true;
}

void RobotCoordinator::setTimestamp(int t) {
  _time = t;
}

void RobotCoordinator::update(void) {
  //qDebug() << "Robots\n";
  if(_robots.size()) {
    sendSyncMessage(_time * 1000); // ms to us
  }
  else {
    emit nextStep();
  }
}
