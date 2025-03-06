QT += core gui sql
QT += core gui
QT += core gui widgets sql

# Настраиваем компилятор и стандарт C++
CONFIG += c++17
CONFIG -= app_bundle
CONFIG += console

# Путь к исходным файлам проекта
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dataq.cpp

HEADERS += \
    mainwindow.h \
    dataq.h

FORMS += \
    mainwindow.ui
RESOURCES += resources.qrc
