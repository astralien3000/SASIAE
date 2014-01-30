#include "../physical_calculator/physical_calculator.hpp"
#include "../modules/modules.hpp"
#include <QObject>
#include <QHash>
#include <QString>
#include <QProcess>

class Coordinator: public QObject{
  Q_OBJECT

  signals:
    void calcNextStep(); 
    void log(QString); 
    //! \brief time for UI sync in ms
    void timer(int);

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
    void openTable(QString XMLPath);
    void openRobot(QString XMLPath, Slot slot);

  private slots:
    //! \brief read the message received from the Client Thread
    void CTReceived(QString);
    //! \brief read the message received from the Modules
    void MReceived(QString);


  private:
    QHash<enum Slot/*robot_name*/,
          QHash<QString /*robot_code*/, 
                QHash<QString/*module_name*/, 
                      Modules* /*modules*/>> _roboInfo;
    QHash<QString/*robot_code*/,
          QProcess* /*robot_process*/> _codesInfo;
    QHash<QObject* /* modules*/, 
          QPair<QString/*robot_code*/, QString /*module_name*/> _modulesInfo;

    PysicalCalculator _physic;
    void gotoNextStep(); 
    void sendDeviceMessage(QString name, QString msg, QProcess* p);
    void sendDeviceMessage(QString name, QString msg, QString code);
    void sendMessage(QString msg, QProcess* p);
    void sendSyncMessage();
    Coordinator();

    static Coordinator* _instance;

    bool _running;
    unsigned int _sync; 

};

