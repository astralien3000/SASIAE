#ifndef ROBOT_COORDINATOR_HPP
#define ROBOT_COORDINATOR_HPP

#include <QHash>
#include <QString>
#include <QProcess>

//! \brief Manage robots process
/*!

  Contains the list of active robots with their names.
  Listen to process, and forward messages.
  Write messages in process.

 */
class RobotCoordinator {
  Q_OBJECT;

signals:
  //! \brief Ask to forward a device message
  void sendDeviceMessage(QString);

  //! \brief Signal a robot's destruction
  void destroyRobot(QString);

public slots:
  //! \brief Send a message to the right named robot
  void forwardModuleMessage(QString,QString);

  //! \brief Send to all robots a Sync message "T x y"
  void sendSyncMessage(void);

  //! \brief Load a robot from a binary
  bool loadRobot(QString);

  //! \brief Delete a robot
  bool unloadRobot(QString);

public:
  //! \brief Default Constructor
  RobotCoordinator(void);

  //! \brief Destructor
  ~RobotCoordinator(void);

private:
  //! \brief robots list
  QHash<QString, QProcess*> _robots;
};

#endif//ROBOT_COORDINATOR_HPP
