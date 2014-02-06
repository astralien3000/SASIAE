#include "../physical_calculator.hpp"
#include "../../../src/modules/modules.hpp"
#include "../../../src/modules/servo.hpp"
#include <QtCore/QThread>
#include <QtCore/QProcess>
#include <QtCore/QHash>
#include <QtCore/QMap>
#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtCore/QDebug>

//#include <cstring>
//#include <iostream>

#define COORD_BUFFER_SIZE 1024


class Coordinator: public QObject{
  Q_OBJECT
  
  signals:
    void calcNextStep(double, int); 
    void log(QString); 
    //! \brief time for UI sync in ms
    void timer(double);

  public:
    enum Slot{MAIN_ROBOT1,SECOND_ROBOT1,MAIN_ROBOT2,SECOND_ROBOT2};
    ~Coordinator();

  public slots:

    //! \brief coordinator is unique, so we need to get is instance (and create one if it doesn't existe)
    static Coordinator& getInstance();

    //! \brief start the simulation
    void play();
    //! \brief pause the simulation
    void pause();

    //! \brief Trigger by Calculator, when a step is finished
    void stepDone();
    void openTable(const QString& XMLPath);
    void openRobot(const QString& XMLPath, Slot slot);
    //void openRobot(QProcess * proc, const QString& XMLPath, Slot slot);

  private slots:
    //! \brief read the message received from the Client Thread
    void CTReceived();
    //! \brief read the message received from the Modules
    void MReceived(QString);

  private:
    /*
      if a QHash -> need to provide a qHash function, and the operator==().
      if QMap, only default and copy constructor, and an assignator.
        enum Slot = int ? qHash funtion & cie should exist
    */
    QHash<enum Slot/*robot_name*/, QString /*robot_code_name*/> _robotInfo;
    QHash<QString/*module_name*/, Modules* /*modules*/> _moduleInfo;
    QHash<QString/*robot_code_name*/, QProcess* /*robot_process*/> _codeInfo;
    QHash<QObject* /* modules*/, 
          QPair<QString/*robot_code*/, QString /*module_name*/> > _modulesInfo;

    void gotoNextStep(); 
    void sendDeviceMessage(QString name, QString msg, QProcess* p);
    void sendDeviceMessage(QString name, QString msg, QString code);
    void sendMessages(QString msg, QProcess* p);
    //! \brief send sync message to all Robot Code Process
    void sendSyncMessages();
    void closeRobot(Slot robot);
    void closeRobot(QProcess *robot);
    //! \brief read one line of proc output
    QString readMessage(QProcess * proc)const;
    bool addToRobotCode(QString name, QProcess * proc);
    bool addToRobotModule(QString name, Modules * mod);  
   

    Coordinator();

    static Coordinator* _instance;
    PhysicalCalculator _physic;

    bool _running;
    int _sync; 
    int _codeFactor;
    double _timeStep;
    int _maxSubStep;

};

