#include "../physical_calculator/physical_calculator.hpp"
#include <QObject>
#include <QMap>
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

    //! \brief
    void play();
    void pause();
    void stepDone();
    void openTable(QString XMLPath);
    void openRobot(QString XMLPath, Slot slot);

  private slots:
    //! \brief read the message received from the Client Thread
    void CTReceived(QString);
    //! \brief read the message received from the Modules
    void MReceived(QString);


  private:
    QMap<QString/*robot_name*/, 
          QMap<QString/*module_name*/, 
                Modules* /*modules*/>> _modules;
    QMap<QString/*robot_code*/,
          QProcess* /*robot_process*/> _codes;

    PysicalCalculator _physic;
    
    void sendDeviceMessage(QString name, QString msg, QProcess* p);
    void sendMessage(QString msg, QProcess* p);
    void sendSyncMessage();
    Coordinator();
    
    static Coordinator* _instance;
    bool running;
};

