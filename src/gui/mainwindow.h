#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QtCore/QDebug>
#include <QtGui>
#include <QFileDialog>
#include <QStandardItemModel>

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
    void robotFileXml(const QString& name,const QString& path);
    void uiPlay();
    void uiPause();
    void close();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* _model;

public slots:
    //void setTableBackground(QPixmap pixmap);
    void openDirForTable();
    void openDirForRobot(int robotNumber);
    void do_sth();
    void CReceived(QString message);
    void slotPlay();
    void slotPause();
    void wantClose();
    void robotButtonClicked();
    /*
     * Ancient version
    void animateRobot(qreal x,qreal y);
    */
//    QTimeLine *getTimer()const;
};

#endif // MAINWINDOW_H
