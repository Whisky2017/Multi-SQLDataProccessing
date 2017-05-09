#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_TableResult = ui->tableWidget;
    dateEdit = ui->dateEdit;
    dateEdit->setDate(QDate::currentDate());
//    qDebug()<<dateEdit->date().toString("yyyy-MM-dd");
    addrEdit = ui->addrEdit;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton1_clicked()
{
    //添加Oracle的驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //Oracle数据库参数配置
    db.setPort(3306);
    db.setHostName("120.26.78.157");
    db.setUserName("wskyt");
    db.setPassword("1234");
    db.setDatabaseName("nengzhongpower");
//    db.setDatabaseName("TMSDB");

    if(!db.open())
    {
        QMessageBox::information(NULL, tr("提示"), tr("连接失败！"));
//        qDebug()<<"test";
    }
    else
    {
        QMessageBox::information(NULL, tr("提示"), tr("连接成功！"));
    }
    db.close();
}

void MainWindow::on_testButton2_clicked()
{
    //添加Oracle的驱动
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QMYSQL","db2");

    //Oracle数据库参数配置
    db2.setPort(3306);
    db2.setHostName("120.26.78.157");
    db2.setUserName("wskyt");
    db2.setPassword("1234");
    db2.setDatabaseName("test2");
//    db2.setDatabaseName("o2000");

    if(!db2.open())
    {
        QMessageBox::information(this, tr("提示"), tr("连接失败！"));
    }
    else
    {
        QMessageBox::information(this, tr("提示"), tr("连接成功！"));
    }

    db2.close();
}

void MainWindow::on_searchButton1_clicked()
{
    QString dateStr,addrStr;
    dateStr = dateEdit->date().toString("yyyy-MM-dd 00:00:00");
    addrStr = addrEdit->text();
//    qDebug()<<dateStr;
//    qDebug()<<addrStr;

    //日期转换问题
    QString dateStr1;
    uint dateInt1;
    QDateTime dateTime1;

    //遍历计算结果
    int row1,row2;
    QModelIndex index1,index2;
    double num1,num2,num3;
//    int num1,num2;

    QSqlQueryModel *model,*model2;
    QSqlDatabase db,db2;


    //添加Oracle的驱动
    db = QSqlDatabase::addDatabase("QMYSQL");
    //Oracle数据库参数配置
    db.setPort(3306);
    db.setHostName("120.26.78.157");
    db.setUserName("wskyt");
    db.setPassword("1234");
    db.setDatabaseName("nengzhongpower");

    if(db.open()){
        model = new QSqlQueryModel(ui->tableView);
    //    model->setQuery("select name,datetime,totalvalue from breaker,mp_day_e where mp_id=id and power_type=10");
//        model->setQuery("select tagdescriptor,planTime,planValue from fuheplan,queryedtagnames where tagid=planId order by tagdescriptor",db);

        if(addrStr.isEmpty()){
            QString sql = "select tagdescriptor,planTime,planValue from fuheplan,queryedtagnames where tagid=planId and planTime='"+dateStr+"' order by tagdescriptor";
//            qDebug()<<sql;
            model->setQuery(sql,db);
//            qDebug()<<"Addr is Empty:"+addrStr;
//            qDebug()<<"dateStr:"+dateStr;
        }else{
            QString sql = "select tagdescriptor,planTime,planValue from fuheplan,queryedtagnames where tagid=planId and planTime='"+dateStr+"' and tagdescriptor like '%"+addrStr+"%' order by tagdescriptor";
//            qDebug()<<sql;
            model->setQuery(sql,db);
//            qDebug()<<"Addr is not Empty:"+addrStr;
//            qDebug()<<"dateStr:"+dateStr;
        }

        model->setHeaderData(0,Qt::Horizontal,tr("地点"));
        model->setHeaderData(1,Qt::Horizontal,tr("时间"));
        model->setHeaderData(2,Qt::Horizontal,tr("表A电量"));

        //获取全部结果
        while(model->canFetchMore())
         {
             model->fetchMore();
         }

        row1 = model->rowCount();

        ui->tableView->setModel(model);
//        ui->tableView->resizeColumnToContents(0);
        ui->tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        ui->tableView->resizeColumnToContents(1);
        ui->tableView->resizeColumnToContents(2);
//        ui->tableView->show();
    }
//    db.close();

    //添加Oracle的驱动
    db2 = QSqlDatabase::addDatabase("QMYSQL","db2");
    //Oracle数据库参数配置
    db2.setPort(3306);
    db2.setHostName("120.26.78.157");
    db2.setUserName("wskyt");
    db2.setPassword("1234");
    db2.setDatabaseName("test2");

    if(db2.open()){
        dateStr1 = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        dateTime1 = QDateTime::fromString(dateStr1,"yyyy-MM-dd");
        dateTime1.setTimeSpec(Qt::LocalTime);
        dateInt1 = dateTime1.toTime_t()-86400;

        model2 = new QSqlQueryModel(ui->tableView_2);
//        model->setQuery("select name,to_char(scn_to_timestamp(datetime),'yyyy-MM-dd'),totalvalue from breaker,mp_day_e where mp_id=id and power_type=10 and datetime="+dateInt1+" order by name");
//        model2->setQuery("select tagdescriptor,planTime,planValue from fuheplan2,queryedtagnames2 where tagid=planId order by tagdescriptor",db2);

        if(addrStr.isEmpty()){
            QString sql = "select tagdescriptor,planTime,planValue from fuheplan2,queryedtagnames2 where tagid=planId and planTime='"+dateStr+"' order by tagdescriptor";
//            qDebug()<<sql;
            model2->setQuery(sql,db2);
//            qDebug()<<"Addr is Empty:"+addrStr;
//            qDebug()<<"dateStr:"+dateStr;
        }else{
            QString sql = "select tagdescriptor,planTime,planValue from fuheplan2,queryedtagnames2 where tagid=planId and planTime='"+dateStr+"' and tagdescriptor like '%"+addrStr+"%' order by tagdescriptor";
//            qDebug()<<sql;
            model2->setQuery(sql,db2);
//            qDebug()<<"Addr is not Empty:"+addrStr;
//            qDebug()<<"dateStr:"+dateStr;
        }

        model2->setHeaderData(0,Qt::Horizontal,tr("地点"));
        model2->setHeaderData(1,Qt::Horizontal,tr("时间"));
        model2->setHeaderData(2,Qt::Horizontal,tr("表B电量"));


        //获取全部结果
        while(model2->canFetchMore())
         {
             model2->fetchMore();
         }

        row2 = model2->rowCount();

        ui->tableView_2->setModel(model2);
//        ui->tableView->resizeColumnToContents(0);
        ui->tableView_2->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        ui->tableView_2->resizeColumnToContents(1);
        ui->tableView_2->resizeColumnToContents(2);
//        ui->tableView_2->show();
    }
//    db2.close();

    p_TableResult->setColumnCount(3);//设置结果显示表列数
    //清空列表数据
    for(int i = p_TableResult->rowCount() - 1; i >= 0; --i)
    {
        p_TableResult->removeRow(i);
    }

    //设置标题
    QStringList header;
    header<<tr("地点")<<tr("正负误差率")<<tr("是否合格");
    p_TableResult->setHorizontalHeaderLabels(header);

    //插入数据（简单匹配版）
    for(int i = 0;i < row1;i++){
        index1 = model->index(i,2);
        num1 = model->data(index1).toDouble();
        index2 = model2->index(i,2);
        num2 = model2->data(index2).toDouble();
        p_TableResult->setRowCount(p_TableResult->rowCount()+1);
        p_TableResult->setItem(i,0,new QTableWidgetItem(model->data(model->index(i,0)).toString()));
//        p_TableResult->setItem(i,1,new QTableWidgetItem(model->data(model->index(1,i)).toString()));
//        p_TableResult->setItem(i,2,new QTableWidgetItem(query.value(0).toString()));
        num3 = (num1/num2-1)*100;
//        qDebug()<<num1;
//        qDebug()<<num2;
//        qDebug()<<num3;
//        qDebug()<<"..";
        p_TableResult->setItem(i,1,new QTableWidgetItem(QString("%1").arg(num3)));
        if((num3<=10)&&(num3>=-10)){
            p_TableResult->setItem(i,2,new QTableWidgetItem("true"));
        }else{
            p_TableResult->setItem(i,2,new QTableWidgetItem("false"));
        }
    }

    p_TableResult->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
    p_TableResult->resizeColumnToContents(1);
    p_TableResult->resizeColumnToContents(2);

    ui->tableView->show();
    ui->tableView_2->show();
    ui->tableWidget->show();
    db.close();
    db2.close();

}

void MainWindow::on_searchButton2_clicked()
{

    //日期转换问题
    QString dateStr1,dateStr2;
    uint dateInt1,dateInt2;
    QDateTime dateTime1,dateTime2;

    //遍历计算结果
    int row1,row2;
    QString addr1,addr2;
    QModelIndex index1,index2;
    double num1,num2,num3;
//    int num1,num2;

    QSqlQueryModel *model,*model2;
    QSqlDatabase db,db2;


    //添加Oracle的驱动
    db = QSqlDatabase::addDatabase("QMYSQL");
    //Oracle数据库参数配置
    db.setPort(3306);
    db.setHostName("120.26.78.157");
    db.setUserName("wskyt");
    db.setPassword("1234");
    db.setDatabaseName("nengzhongpower");

    if(db.open()){
        model = new QSqlQueryModel(ui->tableView);
    //    model->setQuery("select name,datetime,totalvalue from breaker,mp_day_e where mp_id=id and power_type=10");
        model->setQuery("select tagdescriptor,planTime,planValue from fuheplan,queryedtagnames where tagid=planId order by tagdescriptor",db);

        model->setHeaderData(0,Qt::Horizontal,tr("地点"));
        model->setHeaderData(1,Qt::Horizontal,tr("时间"));
        model->setHeaderData(2,Qt::Horizontal,tr("表A电量"));

        //获取全部结果
        while(model->canFetchMore())
         {
             model->fetchMore();
         }

        row1 = model->rowCount();

        ui->tableView->setModel(model);
//        ui->tableView->resizeColumnToContents(0);
        ui->tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        ui->tableView->resizeColumnToContents(1);
        ui->tableView->resizeColumnToContents(2);
//        ui->tableView->show();
    }
//    db.close();

    //添加Oracle的驱动
    db2 = QSqlDatabase::addDatabase("QMYSQL","db2");
    //Oracle数据库参数配置
    db2.setPort(3306);
    db2.setHostName("120.26.78.157");
    db2.setUserName("wskyt");
    db2.setPassword("1234");
    db2.setDatabaseName("test2");

    if(db2.open()){
        dateStr1 = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        dateTime1 = QDateTime::fromString(dateStr1,"yyyy-MM-dd");
        dateTime1.setTimeSpec(Qt::LocalTime);
        dateInt1 = dateTime1.toTime_t()-86400;

        model2 = new QSqlQueryModel(ui->tableView_2);
//        model->setQuery("select name,to_char(scn_to_timestamp(datetime),'yyyy-MM-dd'),totalvalue from breaker,mp_day_e where mp_id=id and power_type=10 and datetime="+dateInt1+" order by name");
        model2->setQuery("select tagdescriptor,planTime,planValue from fuheplan2,queryedtagnames2 where tagid=planId order by tagdescriptor",db2);

        model2->setHeaderData(0,Qt::Horizontal,tr("地点"));
        model2->setHeaderData(1,Qt::Horizontal,tr("时间"));
        model2->setHeaderData(2,Qt::Horizontal,tr("表B电量"));


        //获取全部结果
        while(model2->canFetchMore())
         {
             model2->fetchMore();
         }

        row2 = model2->rowCount();

        ui->tableView_2->setModel(model2);
//        ui->tableView->resizeColumnToContents(0);
        ui->tableView_2->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        ui->tableView_2->resizeColumnToContents(1);
        ui->tableView_2->resizeColumnToContents(2);
//        ui->tableView_2->show();
    }
//    db.close();
//    db2.close();

    p_TableResult->setColumnCount(3);//设置结果显示表列数
    //清空列表数据
    for(int i = p_TableResult->rowCount() - 1; i >= 0; --i)
    {
        p_TableResult->removeRow(i);
    }

    //设置标题
    QStringList header;
    header<<tr("地点")<<tr("正负误差率")<<tr("是否合格");
    p_TableResult->setHorizontalHeaderLabels(header);

    //插入数据（简单匹配版）
    for(int i = 0;i < row1;i++){
        index1 = model->index(i,2);
        num1 = model->data(index1).toDouble();
        index2 = model2->index(i,2);
        num2 = model2->data(index2).toDouble();
        p_TableResult->setRowCount(p_TableResult->rowCount()+1);
        p_TableResult->setItem(i,0,new QTableWidgetItem(model->data(model->index(i,0)).toString()));
//        p_TableResult->setItem(i,1,new QTableWidgetItem(model->data(model->index(1,i)).toString()));
//        p_TableResult->setItem(i,2,new QTableWidgetItem(query.value(0).toString()));
        num3 = (num1/num2-1)*100;
//        qDebug()<<num1;
//        qDebug()<<num2;
//        qDebug()<<num3;
//        qDebug()<<"..";
        p_TableResult->setItem(i,1,new QTableWidgetItem(QString("%1").arg(num3)));
        if((num3<=10)&&(num3>=-10)){
            p_TableResult->setItem(i,2,new QTableWidgetItem("true"));
        }else{
            p_TableResult->setItem(i,2,new QTableWidgetItem("false"));
        }
    }

    p_TableResult->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
    p_TableResult->resizeColumnToContents(1);
    p_TableResult->resizeColumnToContents(2);

    ui->tableView->show();
    ui->tableView_2->show();
    ui->tableWidget->show();
    db.close();
    db2.close();

}
