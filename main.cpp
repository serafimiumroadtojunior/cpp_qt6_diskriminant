#include <QApplication>   // Подключаем файл QApplication который обеспечивает функционал
#include "mainwindow.h"  // Подключаем файл нашего главного окна MainWindow

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Создаем объект приложения QApplication
    MainWindow window;  // Создаем объект класса окно MainWindow
    window.show();  // отображаем окно MainWindow 
    return app.exec();  // Запускаем цикл обработки событий приложения и возвращаем код после завершения
}
