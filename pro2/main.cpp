#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsql.h>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlField>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QString>
#include <QApplication>
#include <QTextCodec>
#include <QLibrary>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QApplication::addLibraryPath("/plugins");

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    //打印出可用驱动，必须有QOCI才算Oracle的驱动安装正确
    qDebug()<<QSqlDatabase::drivers();

//    QDateTime dateTime1;
//    QString dateStr1;
//    dateStr1 = dateTime1.fromTime_t(1476374400).toString("yyyy-MM-dd");
//    qDebug()<<dateStr1;
//    QDateTime dateTime1,dateTime2;
//    QString dateStr1;
//    uint dateInt1;
//    dateStr1 = QDateTime::currentDateTime().toString("yyyy-MM-dd");
//    dateTime1 = QDateTime::fromString(dateStr1,"yyyy-MM-dd");
//    dateTime1.setTimeSpec(Qt::LocalTime);
//    dateInt1 = dateTime1.toTime_t()-86400;
//    qDebug()<<dateInt1;
//    qDebug()<<dateTime2.fromTime_t(1476374400).toString("yyyy-MM-dd");;

    MainWindow w;
    w.show();


    return a.exec();
}


