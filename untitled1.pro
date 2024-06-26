QT += core gui // подключаю модули Qt Core и Qt GUI
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  //добавляем модуль Qt Widgets так как версия нашей QT больше 4 версии


CONFIG += c++11 //добавляем cpp 11


SOURCES += main.cpp \
           mainwindow.cpp // добавляем наши коды с логикой в проект

HEADERS += mainwindow.h //Подключаем наш заголовочный файл

FORMS += mainwindow.ui //Подключаем дизайн
