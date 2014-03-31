/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrer_sous;
    QAction *actionEnregistrer;
    QAction *actionObjet;
    QAction *actionErreur;
    QAction *actionChoisir;
    QAction *actionSupprimer;
    QAction *actionRobot_new_1;
    QAction *actionRobot_new_2;
    QAction *actionRobot_new_3;
    QAction *actionRobot_new_4;
    QAction *actionRobot_n_5;
    QAction *actionRobot_n_6;
    QAction *actionRobot_n_7;
    QAction *actionRobot_n_8;
    QAction *actionRobot_suppr_1;
    QAction *actionRobot_suppr_2;
    QAction *actionRobot_suppr_3;
    QAction *actionRobot_suppr_4;
    QAction *actionGuide_d_utilisation;
    QAction *actionGuide_d_ajout_de_cr_ation_de_module;
    QAction *actionGuide_du_d_veloppeur;
    QAction *actionQui_sommes_nous;
    QAction *actionQuitter;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuSimulateur;
    QMenu *menuEditer;
    QMenu *menuInsertion;
    QMenu *menuTable;
    QMenu *menuRobot;
    QMenu *menuChoisir;
    QMenu *menuSupprimer_2;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_table;
    QPushButton *button_robot1;
    QPushButton *button_robot2;
    QPushButton *button_robot3;
    QPushButton *button_robot4;
    QDockWidget *dockWidget_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_rec;
    QPushButton *button_play;
    QPushButton *button_pause;
    QPushButton *button_stop;
    QDockWidget *dockWidget_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QTimeEdit *time;
    QDockWidget *dockWidget_5;
    QTreeView *treeView;
    QDockWidget *dockWidget_4;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 513);
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QStringLiteral("actionNouveau"));
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QStringLiteral("actionEnregistrer_sous"));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionObjet = new QAction(MainWindow);
        actionObjet->setObjectName(QStringLiteral("actionObjet"));
        actionErreur = new QAction(MainWindow);
        actionErreur->setObjectName(QStringLiteral("actionErreur"));
        actionChoisir = new QAction(MainWindow);
        actionChoisir->setObjectName(QStringLiteral("actionChoisir"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        actionRobot_new_1 = new QAction(MainWindow);
        actionRobot_new_1->setObjectName(QStringLiteral("actionRobot_new_1"));
        actionRobot_new_2 = new QAction(MainWindow);
        actionRobot_new_2->setObjectName(QStringLiteral("actionRobot_new_2"));
        actionRobot_new_3 = new QAction(MainWindow);
        actionRobot_new_3->setObjectName(QStringLiteral("actionRobot_new_3"));
        actionRobot_new_4 = new QAction(MainWindow);
        actionRobot_new_4->setObjectName(QStringLiteral("actionRobot_new_4"));
        actionRobot_n_5 = new QAction(MainWindow);
        actionRobot_n_5->setObjectName(QStringLiteral("actionRobot_n_5"));
        actionRobot_n_6 = new QAction(MainWindow);
        actionRobot_n_6->setObjectName(QStringLiteral("actionRobot_n_6"));
        actionRobot_n_7 = new QAction(MainWindow);
        actionRobot_n_7->setObjectName(QStringLiteral("actionRobot_n_7"));
        actionRobot_n_8 = new QAction(MainWindow);
        actionRobot_n_8->setObjectName(QStringLiteral("actionRobot_n_8"));
        actionRobot_suppr_1 = new QAction(MainWindow);
        actionRobot_suppr_1->setObjectName(QStringLiteral("actionRobot_suppr_1"));
        actionRobot_suppr_2 = new QAction(MainWindow);
        actionRobot_suppr_2->setObjectName(QStringLiteral("actionRobot_suppr_2"));
        actionRobot_suppr_3 = new QAction(MainWindow);
        actionRobot_suppr_3->setObjectName(QStringLiteral("actionRobot_suppr_3"));
        actionRobot_suppr_4 = new QAction(MainWindow);
        actionRobot_suppr_4->setObjectName(QStringLiteral("actionRobot_suppr_4"));
        actionGuide_d_utilisation = new QAction(MainWindow);
        actionGuide_d_utilisation->setObjectName(QStringLiteral("actionGuide_d_utilisation"));
        actionGuide_d_ajout_de_cr_ation_de_module = new QAction(MainWindow);
        actionGuide_d_ajout_de_cr_ation_de_module->setObjectName(QStringLiteral("actionGuide_d_ajout_de_cr_ation_de_module"));
        actionGuide_du_d_veloppeur = new QAction(MainWindow);
        actionGuide_du_d_veloppeur->setObjectName(QStringLiteral("actionGuide_du_d_veloppeur"));
        actionQui_sommes_nous = new QAction(MainWindow);
        actionQui_sommes_nous->setObjectName(QStringLiteral("actionQui_sommes_nous"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        graphicsView = new QGraphicsView(MainWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        MainWindow->setCentralWidget(graphicsView);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 20));
        menuSimulateur = new QMenu(menubar);
        menuSimulateur->setObjectName(QStringLiteral("menuSimulateur"));
        menuEditer = new QMenu(menubar);
        menuEditer->setObjectName(QStringLiteral("menuEditer"));
        menuInsertion = new QMenu(menuEditer);
        menuInsertion->setObjectName(QStringLiteral("menuInsertion"));
        menuTable = new QMenu(menuEditer);
        menuTable->setObjectName(QStringLiteral("menuTable"));
        menuRobot = new QMenu(menuEditer);
        menuRobot->setObjectName(QStringLiteral("menuRobot"));
        menuChoisir = new QMenu(menuRobot);
        menuChoisir->setObjectName(QStringLiteral("menuChoisir"));
        menuSupprimer_2 = new QMenu(menuRobot);
        menuSupprimer_2->setObjectName(QStringLiteral("menuSupprimer_2"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setFeatures(QDockWidget::DockWidgetFeatureMask);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        button_table = new QPushButton(widget);
        button_table->setObjectName(QStringLiteral("button_table"));

        horizontalLayout_2->addWidget(button_table);

        button_robot1 = new QPushButton(widget);
        button_robot1->setObjectName(QStringLiteral("button_robot1"));

        horizontalLayout_2->addWidget(button_robot1);

        button_robot2 = new QPushButton(widget);
        button_robot2->setObjectName(QStringLiteral("button_robot2"));

        horizontalLayout_2->addWidget(button_robot2);

        button_robot3 = new QPushButton(widget);
        button_robot3->setObjectName(QStringLiteral("button_robot3"));

        horizontalLayout_2->addWidget(button_robot3);

        button_robot4 = new QPushButton(widget);
        button_robot4->setObjectName(QStringLiteral("button_robot4"));

        horizontalLayout_2->addWidget(button_robot4);

        dockWidget->setWidget(widget);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setFeatures(QDockWidget::DockWidgetFeatureMask);
        widget_2 = new QWidget();
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_rec = new QPushButton(widget_2);
        button_rec->setObjectName(QStringLiteral("button_rec"));

        horizontalLayout->addWidget(button_rec);

        button_play = new QPushButton(widget_2);
        button_play->setObjectName(QStringLiteral("button_play"));

        horizontalLayout->addWidget(button_play);

        button_pause = new QPushButton(widget_2);
        button_pause->setObjectName(QStringLiteral("button_pause"));

        horizontalLayout->addWidget(button_pause);

        button_stop = new QPushButton(widget_2);
        button_stop->setObjectName(QStringLiteral("button_stop"));

        horizontalLayout->addWidget(button_stop);

        dockWidget_2->setWidget(widget_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_2);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QStringLiteral("dockWidget_3"));
        dockWidget_3->setFeatures(QDockWidget::DockWidgetFeatureMask);
        widget_3 = new QWidget();
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        time = new QTimeEdit(widget_3);
        time->setObjectName(QStringLiteral("time"));
        time->setFont(font);
        time->setReadOnly(true);
        time->setMaximumTime(QTime(0, 1, 30));
        time->setCurrentSection(QDateTimeEdit::MinuteSection);

        horizontalLayout_3->addWidget(time);

        dockWidget_3->setWidget(widget_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_3);
        dockWidget_5 = new QDockWidget(MainWindow);
        dockWidget_5->setObjectName(QStringLiteral("dockWidget_5"));
        treeView = new QTreeView();
        treeView->setObjectName(QStringLiteral("treeView"));
        dockWidget_5->setWidget(treeView);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_5);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        plainTextEdit = new QPlainTextEdit();
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);
        dockWidget_4->setWidget(plainTextEdit);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_4);

        menubar->addAction(menuSimulateur->menuAction());
        menubar->addAction(menuEditer->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuSimulateur->addAction(actionNouveau);
        menuSimulateur->addAction(actionOuvrir);
        menuSimulateur->addAction(actionEnregistrer_sous);
        menuSimulateur->addAction(actionEnregistrer);
        menuSimulateur->addSeparator();
        menuSimulateur->addAction(actionQuitter);
        menuEditer->addAction(menuInsertion->menuAction());
        menuEditer->addSeparator();
        menuEditer->addAction(menuTable->menuAction());
        menuEditer->addAction(menuRobot->menuAction());
        menuInsertion->addAction(actionObjet);
        menuInsertion->addAction(actionErreur);
        menuTable->addAction(actionChoisir);
        menuTable->addAction(actionSupprimer);
        menuRobot->addAction(menuChoisir->menuAction());
        menuRobot->addAction(menuSupprimer_2->menuAction());
        menuChoisir->addAction(actionRobot_new_1);
        menuChoisir->addAction(actionRobot_new_2);
        menuChoisir->addAction(actionRobot_new_3);
        menuChoisir->addAction(actionRobot_new_4);
        menuSupprimer_2->addAction(actionRobot_suppr_1);
        menuSupprimer_2->addAction(actionRobot_suppr_2);
        menuSupprimer_2->addAction(actionRobot_suppr_3);
        menuSupprimer_2->addAction(actionRobot_suppr_4);
        menuHelp->addAction(actionGuide_d_utilisation);
        menuHelp->addAction(actionGuide_d_ajout_de_cr_ation_de_module);
        menuHelp->addSeparator();
        menuHelp->addAction(actionGuide_du_d_veloppeur);
        menuHelp->addSeparator();
        menuHelp->addAction(actionQui_sommes_nous);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(wantClose()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulateur", 0));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", 0));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", 0));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "Enregistrer sous", 0));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0));
        actionObjet->setText(QApplication::translate("MainWindow", "Objet", 0));
        actionErreur->setText(QApplication::translate("MainWindow", "Erreur", 0));
        actionChoisir->setText(QApplication::translate("MainWindow", "Choisir", 0));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        actionRobot_new_1->setText(QApplication::translate("MainWindow", "Robot 1", 0));
        actionRobot_new_2->setText(QApplication::translate("MainWindow", "Robot 2", 0));
        actionRobot_new_3->setText(QApplication::translate("MainWindow", "Robot 3", 0));
        actionRobot_new_4->setText(QApplication::translate("MainWindow", "Robot 4", 0));
        actionRobot_n_5->setText(QApplication::translate("MainWindow", "Robot 5", 0));
        actionRobot_n_6->setText(QApplication::translate("MainWindow", "Robot 6", 0));
        actionRobot_n_7->setText(QApplication::translate("MainWindow", "Robot 7", 0));
        actionRobot_n_8->setText(QApplication::translate("MainWindow", "Robot 8", 0));
        actionRobot_suppr_1->setText(QApplication::translate("MainWindow", "Robot 1", 0));
        actionRobot_suppr_2->setText(QApplication::translate("MainWindow", "Robot 2", 0));
        actionRobot_suppr_3->setText(QApplication::translate("MainWindow", "Robot 3", 0));
        actionRobot_suppr_4->setText(QApplication::translate("MainWindow", "Robot 4", 0));
        actionGuide_d_utilisation->setText(QApplication::translate("MainWindow", "Guide d'utilisation", 0));
#ifndef QT_NO_TOOLTIP
        actionGuide_d_utilisation->setToolTip(QApplication::translate("MainWindow", "Aide \303\240 l'utilisation de l'interface graphique", 0));
#endif // QT_NO_TOOLTIP
        actionGuide_d_ajout_de_cr_ation_de_module->setText(QApplication::translate("MainWindow", "Guide de cr\303\251ation de module", 0));
#ifndef QT_NO_TOOLTIP
        actionGuide_d_ajout_de_cr_ation_de_module->setToolTip(QApplication::translate("MainWindow", "Aide \303\240 la cr\303\251ation de module", 0));
#endif // QT_NO_TOOLTIP
        actionGuide_du_d_veloppeur->setText(QApplication::translate("MainWindow", "Guide du d\303\251veloppeur", 0));
#ifndef QT_NO_TOOLTIP
        actionGuide_du_d_veloppeur->setToolTip(QApplication::translate("MainWindow", "Documentation de l'impl\303\251mentation", 0));
#endif // QT_NO_TOOLTIP
        actionQui_sommes_nous->setText(QApplication::translate("MainWindow", "Qui sommes-nous ?", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        menuSimulateur->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuEditer->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        menuInsertion->setTitle(QApplication::translate("MainWindow", "Insertion", 0));
        menuTable->setTitle(QApplication::translate("MainWindow", "Table", 0));
        menuRobot->setTitle(QApplication::translate("MainWindow", "Robot", 0));
        menuChoisir->setTitle(QApplication::translate("MainWindow", "Choisir", 0));
        menuSupprimer_2->setTitle(QApplication::translate("MainWindow", "Supprimer", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help !", 0));
        button_table->setText(QApplication::translate("MainWindow", "Table : 2014", 0));
        button_robot1->setText(QApplication::translate("MainWindow", "Robot 1", 0));
        button_robot2->setText(QApplication::translate("MainWindow", "Robot 2", 0));
        button_robot3->setText(QApplication::translate("MainWindow", "Robot 3", 0));
        button_robot4->setText(QApplication::translate("MainWindow", "Robot 4", 0));
        button_rec->setText(QApplication::translate("MainWindow", "Rec", 0));
        button_play->setText(QApplication::translate("MainWindow", "Play", 0));
        button_pause->setText(QApplication::translate("MainWindow", "Pause", 0));
        button_stop->setText(QApplication::translate("MainWindow", "Stop", 0));
        label->setText(QApplication::translate("MainWindow", "Timer :", 0));
        time->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", 0));
        plainTextEdit->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
