#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QDateEdit>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_testButton1_clicked();

    void on_testButton2_clicked();

    void on_searchButton1_clicked();

    void on_searchButton2_clicked();

private:
    Ui::MainWindow *ui;
    QTableWidget *p_TableResult;
    QDateEdit *dateEdit;
    QLineEdit *addrEdit;
};

#endif // MAINWINDOW_H
