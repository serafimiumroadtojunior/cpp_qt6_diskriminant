#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>  // Включаем основной класс главного окна QT

QT_BEGIN_NAMESPACE
namespace Ui { class Diskriminant; }  // Объявляем пространство имен Ui с классом Diskriminant
QT_END_NAMESPACE

class MainWindow : public QMainWindow {  // Определяем класс MainWindow, который наследуется от QMainWindow
    Q_OBJECT  // Макрос Q_OBJECT для поддержки метаобъектной системы Qt

public:
    MainWindow(QWidget *parent = nullptr);  // Конструктор класса MainWindow, принимающий указатель на родительский виджет
    ~MainWindow();  // Деструктор класса MainWindow

private slots:
    void on_calculateButton_clicked();  // Приватный слот для обработки нажатия кнопки "calculateButton"

private:
    Ui::Diskriminant *ui;  // Указатель на объект класса Ui::Diskriminant для работы с интерфейсом
};

#endif // MAINWINDOW_H  // Завершаем условную компиляцию директивой #endif

