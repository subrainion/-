#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "book.h"
#include "user.h"
#include "library.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Library *lib, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ViewBooks_clicked();
    void on_ViewUsers_clicked();
    void on_AddBook_clicked();
    void on_DeleteBook_clicked();
    void on_GiveBook_clicked();
    void on_ReturnBook_clicked();
    void on_AddUser_clicked();
    void on_DeleteUser_clicked();
    void on_Accouting_clicked();

private:
    Ui::MainWindow *ui;
    Library *library;
};

#endif // MAINWINDOW_H
