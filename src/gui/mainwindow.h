#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtCore/QDebug>
#include <QtGui>
#include <QFileDialog>
#include <QStandardItemModel>
#include "../common/position_data.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    const QGraphicsScene* getScene(void)const;
    QGraphicsScene* getScene(void);
    void addRobot(QStandardItem* item);

signals:
    void tableFileXml(const QString&);
    void robotFileXml(const QString& name,const QString& path, PositionData p);
    void uiPlay();
    void uiPause();
    void uiStop();
    void close();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* _model;

public slots:
    void setTimestamp(int);
    void openDirForTable();
    void openDirForRobot(int robotNumber);
    void do_sth();
    void CReceived(QString message);
    void slotPlay();
    void slotPause();
    void slotStop();
    void wantClose();
    void robotButtonClicked();
    void newLog(QString msg);
};

#endif // MAINWINDOW_H
