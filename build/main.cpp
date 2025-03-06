#include "mainwindow.h"
#include "dataq.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Загружаем стиль из файла .qss
    QFile styleFile("C:/Users/yaros/Desktop/build/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QTextStream ts(&styleFile);
        QString style = ts.readAll();
        a.setStyleSheet(style);
    }

    Library library;
    if (!library.connectToDatabase("localhost", "library", "postgres", "2024")) {
        return -1; // Выход при ошибке подключения к базе данных
    }

    MainWindow w(&library);
    w.show();

    return a.exec();
}
