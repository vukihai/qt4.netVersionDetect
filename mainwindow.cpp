#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSettings>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    qDebug() << "test";
    qDebug() << this->net4laterDetect("v4.0");


}
bool MainWindow::net4detect(QString _version) {
    QSettings m("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\NET Framework Setup\\NDP",
                QSettings::NativeFormat);
    QStringList listKey =  m.childGroups();
    qDebug() << listKey;
    for(int i=0; i<listKey.size(); i++) {
        if(_version == listKey[i]) return true;
    }
    return false;
}
QString MainWindow::net4laterDetect(QString _version) {
    QSettings m("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v4\\Full",
                QSettings::NativeFormat);
    if(m.childKeys().contains("Release")) {
        int releaseKey = m.value("Release").toString().toInt();
        if (releaseKey >= 461808)
            return "4.7.2 or later";
         if (releaseKey >= 461308)
            return "4.7.1";
         if (releaseKey >= 460798)
            return "4.7";
         if (releaseKey >= 394802)
            return "4.6.2";
         if (releaseKey >= 394254)
            return "4.6.1";
         if (releaseKey >= 393295)
            return "4.6";
         if (releaseKey >= 379893)
            return "4.5.2";
         if (releaseKey >= 378675)
            return "4.5.1";
         if (releaseKey >= 378389)
            return "4.5";
         // This code should never execute. A non-null release key should mean
         // that 4.5 or later is installed.
         return "No 4.5 or later version detected";
    } else {
        return "No 4.5 or later version detected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
