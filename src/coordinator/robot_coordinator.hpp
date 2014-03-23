#ifndef ROBOT_COORDINATOR_HPP
#define ROBOT_COORDINATOR_HPP

#include "base_coordinator.hpp"

#include <QHash>
#include <QString>
#include <QProcess>

//! \brief Manage robots process
/*!

  Contains the list of active robots with their names.
  Listen to process, and forward messages.
  Write messages in process.

 */
class RobotCoordinator : public BaseCoordinator {
  Q_OBJECT;

signals:
  //! \brief Ask to forward a device message
  void recvDeviceMessage(QString,QString);

  //! \brief Ask to forward a GUI message
  void recvGuiMessage(QString);

  //! \brief Signal a robot's destruction
  void destroyRobot(QString);

  //! \brief Emited when all robots are synchronised
  void synchronised(void);

private slots:
  //! \brief Handle message recieved from robots process
  void handleRecv(void);

public slots:
  //! \brief Send a message to the right named robot
  void sendModuleMessage(QString, QString);

  //! \brief Send to all robots a Sync message "T x y"
  void sendSyncMessage(int);

  //! \brief Load a robot from a binary
  //! \param name : the name of the robot, with which modules will be bound
  //! \param path : the path to the binary to execute
  bool loadRobot(const QString& name, const QString& path);

  //! \brief Delete a robot
  bool unloadRobot(QString name);

  //! \brief Sync
  void update(void);

  //! \brief Timestamp recv
  void setTimestamp(int);

public:
  //! \brief Default Constructor
  RobotCoordinator(void);

  //! \brief Destructor
  ~RobotCoordinator(void);

private:
  //! \brief robots list
  QHash<QString, QProcess*> _robots;

  //! \brief number of synchronised robots
  int _sync;

  //! \brief last timestamp
  int _time;
};

#endif//ROBOT_COORDINATOR_HPP
