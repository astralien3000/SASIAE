/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QStatusBar>
#include <QTimeEdit>
#include <QTreeWidget>
#include <QWidget>
#include "table.h"

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
    QAction *actionRobot_n_1;
    QAction *actionRobot_n_2;
    QAction *actionRobot_n_3;
    QAction *actionRobot_n_4;
    QAction *actionRobot_n_5;
    QAction *actionRobot_n_6;
    QAction *actionRobot_n_7;
    QAction *actionRobot_n_8;
    QAction *actionRobot_n_9;
    QAction *actionRobot_n_10;
    QAction *actionRobot_n_11;
    QAction *actionRobot_n_12;
    QAction *actionGuide_d_utilisation;
    QAction *actionGuide_d_ajout_de_cr_ation_de_module;
    QAction *actionGuide_du_d_veloppeur;
    QAction *actionQui_sommes_nous;
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *button_table;
    QPushButton *button_robot1;
    QPushButton *button_robot2;
    QPushButton *button_robot3;
    QPushButton *pushButton_5;
    QWidget *widget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *widget_3;
    QTimeEdit *timeEdit;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QTreeWidget *treeWidget;
    Table *graphicsView;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(860, 513);
        MainWindow->setMinimumSize(QSize(860, 513));
        MainWindow->setMaximumSize(QSize(860, 513));
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
        actionRobot_n_1 = new QAction(MainWindow);
        actionRobot_n_1->setObjectName(QStringLiteral("actionRobot_n_1"));
        actionRobot_n_2 = new QAction(MainWindow);
        actionRobot_n_2->setObjectName(QStringLiteral("actionRobot_n_2"));
        actionRobot_n_3 = new QAction(MainWindow);
        actionRobot_n_3->setObjectName(QStringLiteral("actionRobot_n_3"));
        actionRobot_n_4 = new QAction(MainWindow);
        actionRobot_n_4->setObjectName(QStringLiteral("actionRobot_n_4"));
        actionRobot_n_5 = new QAction(MainWindow);
        actionRobot_n_5->setObjectName(QStringLiteral("actionRobot_n_5"));
        actionRobot_n_6 = new QAction(MainWindow);
        actionRobot_n_6->setObjectName(QStringLiteral("actionRobot_n_6"));
        actionRobot_n_7 = new QAction(MainWindow);
        actionRobot_n_7->setObjectName(QStringLiteral("actionRobot_n_7"));
        actionRobot_n_8 = new QAction(MainWindow);
        actionRobot_n_8->setObjectName(QStringLiteral("actionRobot_n_8"));
        actionRobot_n_9 = new QAction(MainWindow);
        actionRobot_n_9->setObjectName(QStringLiteral("actionRobot_n_9"));
        actionRobot_n_10 = new QAction(MainWindow);
        actionRobot_n_10->setObjectName(QStringLiteral("actionRobot_n_10"));
        actionRobot_n_11 = new QAction(MainWindow);
        actionRobot_n_11->setObjectName(QStringLiteral("actionRobot_n_11"));
        actionRobot_n_12 = new QAction(MainWindow);
        actionRobot_n_12->setObjectName(QStringLiteral("actionRobot_n_12"));
        actionGuide_d_utilisation = new QAction(MainWindow);
        actionGuide_d_utilisation->setObjectName(QStringLiteral("actionGuide_d_utilisation"));
        actionGuide_d_ajout_de_cr_ation_de_module = new QAction(MainWindow);
        actionGuide_d_ajout_de_cr_ation_de_module->setObjectName(QStringLiteral("actionGuide_d_ajout_de_cr_ation_de_module"));
        actionGuide_du_d_veloppeur = new QAction(MainWindow);
        actionGuide_du_d_veloppeur->setObjectName(QStringLiteral("actionGuide_du_d_veloppeur"));
        actionQui_sommes_nous = new QAction(MainWindow);
        actionQui_sommes_nous->setObjectName(QStringLiteral("actionQui_sommes_nous"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 430, 381, 41));
        button_table = new QPushButton(widget);
        button_table->setObjectName(QStringLiteral("button_table"));
        button_table->setGeometry(QRect(10, 10, 81, 23));
        button_robot1 = new QPushButton(widget);
        button_robot1->setObjectName(QStringLiteral("button_robot1"));
        button_robot1->setGeometry(QRect(100, 10, 61, 23));
        button_robot2 = new QPushButton(widget);
        button_robot2->setObjectName(QStringLiteral("button_robot2"));
        button_robot2->setGeometry(QRect(170, 10, 61, 23));
        button_robot3 = new QPushButton(widget);
        button_robot3->setObjectName(QStringLiteral("button_robot3"));
        button_robot3->setGeometry(QRect(240, 10, 61, 23));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(310, 10, 61, 23));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(400, 430, 291, 41));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 61, 23));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 10, 61, 23));
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 10, 61, 23));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 10, 61, 23));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(700, 430, 151, 41));
        timeEdit = new QTimeEdit(widget_3);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(60, 10, 81, 22));
        QFont font;
        font.setPointSize(10);
        timeEdit->setFont(font);
        timeEdit->setReadOnly(true);
        timeEdit->setMaximumTime(QTime(0, 1, 30));
        timeEdit->setCurrentSection(QDateTimeEdit::MinuteSection);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 41, 21));
        label->setFont(font);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(600, 220, 251, 201));
        plainTextEdit->setReadOnly(true);
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(600, 10, 251, 201));
        treeWidget->setItemsExpandable(true);
        treeWidget->setColumnCount(2);
        treeWidget->header()->setDefaultSectionSize(125);
        treeWidget->header()->setHighlightSections(false);
        treeWidget->header()->setMinimumSectionSize(70);
        graphicsView = new Table(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 581, 411));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 860, 20));
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

        menubar->addAction(menuSimulateur->menuAction());
        menubar->addAction(menuEditer->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuSimulateur->addAction(actionNouveau);
        menuSimulateur->addAction(actionOuvrir);
        menuSimulateur->addAction(actionEnregistrer_sous);
        menuSimulateur->addAction(actionEnregistrer);
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
        menuChoisir->addAction(actionRobot_n_1);
        menuChoisir->addAction(actionRobot_n_2);
        menuChoisir->addAction(actionRobot_n_3);
        menuChoisir->addAction(actionRobot_n_4);
        menuSupprimer_2->addAction(actionRobot_n_9);
        menuSupprimer_2->addAction(actionRobot_n_10);
        menuSupprimer_2->addAction(actionRobot_n_11);
        menuSupprimer_2->addAction(actionRobot_n_12);
        menuHelp->addAction(actionGuide_d_utilisation);
        menuHelp->addAction(actionGuide_d_ajout_de_cr_ation_de_module);
        menuHelp->addSeparator();
        menuHelp->addAction(actionGuide_du_d_veloppeur);
        menuHelp->addSeparator();
        menuHelp->addAction(actionQui_sommes_nous);

        retranslateUi(MainWindow);

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
        actionRobot_n_1->setText(QApplication::translate("MainWindow", "Robot n\302\2601", 0));
        actionRobot_n_2->setText(QApplication::translate("MainWindow", "Robot n\302\2602", 0));
        actionRobot_n_3->setText(QApplication::translate("MainWindow", "Robot n\302\2603", 0));
        actionRobot_n_4->setText(QApplication::translate("MainWindow", "Robot n\302\2604", 0));
        actionRobot_n_5->setText(QApplication::translate("MainWindow", "Robot n\302\2601", 0));
        actionRobot_n_6->setText(QApplication::translate("MainWindow", "Robot n\302\2602", 0));
        actionRobot_n_7->setText(QApplication::translate("MainWindow", "Robot n\302\2603", 0));
        actionRobot_n_8->setText(QApplication::translate("MainWindow", "Robot n\302\2604", 0));
        actionRobot_n_9->setText(QApplication::translate("MainWindow", "Robot n\302\2601", 0));
        actionRobot_n_10->setText(QApplication::translate("MainWindow", "Robot n\302\2602", 0));
        actionRobot_n_11->setText(QApplication::translate("MainWindow", "Robot n\302\2603", 0));
        actionRobot_n_12->setText(QApplication::translate("MainWindow", "Robot n\302\2604", 0));
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
        button_table->setText(QApplication::translate("MainWindow", "Table : 2014", 0));
        button_robot1->setText(QApplication::translate("MainWindow", "Robot 1", 0));
        button_robot2->setText(QApplication::translate("MainWindow", "Robot 2", 0));
        button_robot3->setText(QApplication::translate("MainWindow", "Robot 3", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Robot 4", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Rec", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Play", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Pause", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Stop", 0));
        timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", 0));
        label->setText(QApplication::translate("MainWindow", "Timer :", 0));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "[LOG] D\303\251marrage du robot n\302\2601\n"
"[LOG] D\303\251marrage du robot n\302\2602\n"
"[WARNING] Capteur 1 non initialis\303\251", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Valeurs", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Robots", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Robot 1", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Capteurs", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(1, QApplication::translate("MainWindow", "12", 0));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Capteur 1", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(1, QApplication::translate("MainWindow", "true", 0));
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Capteur 2", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Actionneurs", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(1, QApplication::translate("MainWindow", "1235", 0));
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Actionneur 1", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(1, QApplication::translate("MainWindow", "1852", 0));
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Actionneur 2", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Robot 2", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Capteurs", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(1, QApplication::translate("MainWindow", "42", 0));
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Capteur 1", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(1, QApplication::translate("MainWindow", "36", 0));
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Capteur 2", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Actionneurs", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem12->child(0);
        ___qtreewidgetitem13->setText(1, QApplication::translate("MainWindow", "2135", 0));
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Actionneur 1", 0));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem12->child(1);
        ___qtreewidgetitem14->setText(1, QApplication::translate("MainWindow", "2012", 0));
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "Actionneur 2", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

        menuSimulateur->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuEditer->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        menuInsertion->setTitle(QApplication::translate("MainWindow", "Insertion", 0));
        menuTable->setTitle(QApplication::translate("MainWindow", "Table", 0));
        menuRobot->setTitle(QApplication::translate("MainWindow", "Robot", 0));
        menuChoisir->setTitle(QApplication::translate("MainWindow", "Choisir", 0));
        menuSupprimer_2->setTitle(QApplication::translate("MainWindow", "Supprimer", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help !", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
