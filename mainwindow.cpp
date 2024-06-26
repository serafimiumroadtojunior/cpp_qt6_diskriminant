#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> //импортим меседжбокс для системных уведомлений при ошибках
#include <cmath>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Diskriminant) //создаю обыект ui используя сгенерированый класс Ui::Diskriminant(mainwindow.h)
{
    ui->setupUi(this); // Инициализируем UI главного окна, передавая указатель на текущее окно
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);// устанавливаю связь которая по нажатию на кнопку запустит дальнейшую логику(функцию) и слотом on_calculateButton_clicked 
}

MainWindow::~MainWindow() {
    delete ui; // Освобождаем память, выделенную для объекта ui
}

void MainWindow::on_calculateButton_clicked() {
    bool ok;
    double a = ui->lineEditA->text().toDouble(&ok); // Получаем значение строки из lineEditA и конвертируем в double
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Пожалуйста, введите корректное число для a");
        return; // Если конвертация не удалась, выводим сообщение об ошибке и выходим из функции
    }

    double b = ui->lineEditB->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Пожалуйста, введите корректное число для b");
        return;
    }

    double c = ui->lineEditC->text().toDouble(&ok);
    if (!ok) { //проверка если наша переменная является False
        QMessageBox::warning(this, "Input Error", "Пожалуйста, введите корректное число для c");
        return;
    }

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                ui->labelResult1->setText("Бесконечное количество решений (0 = 0)");
                ui->labelResult2->clear();
                ui->labelResult3->clear();
                ui->labelResult4->clear();
            } else {
                ui->labelResult1->setText("Нет решений (несовместное уравнение)");
                ui->labelResult2->clear();
                ui->labelResult3->clear();
                ui->labelResult4->clear();
            }
        } else {
            double x = -c / b;
            ui->labelResult1->setText("Линейное уравнение (a = 0):");
            ui->labelResult2->setText(QString("x = -c / b = %1").arg(x));
            ui->labelResult3->clear();
            ui->labelResult4->clear();
        }
        return;
    }


    double discriminant = b * b - 4 * a * c; //Тут мы назначаем переменную которая в дальнейшем будет использована для получения корня нашего дискриминанта
    ui->labelResult1->setText(QString("D = %1^2 - 4(%2 * %3) = %4") //В начале мы указуем путь к нашему виджету(ui->labelResult1) а дальше благодаря setText мы назначаем текст нашему виджету и назначаем ему тип 'QString'
                                  .arg(b).arg(a).arg(c).arg(discriminant)); //В этой строке мы указуем аргументы для первой части результата подсчета благодаря методу .arg(*args)

    if (discriminant > 0) { // дальше мы делаем проверку на то не является ли наш дискриминант отрицательным числом
        double sqrt_discriminant = std::sqrt(discriminant); //если нет, то мы создаем новую переменную где благодаря функции библиотеки cmath мы преобразовываем наш дискриминант в корень дискриминанта
        ui->labelResult2->setText(QString("√D = %1").arg(sqrt_discriminant));
        ui->labelResult3->setText(QString("x1 = (%1 - %2) / (2 * %3) = %4")
                                      .arg(-b).arg(sqrt_discriminant).arg(a).arg((-b - sqrt_discriminant) / (2 * a)));
        ui->labelResult4->setText(QString("x2 = (%1 + %2) / (2 * %3) = %4")
                                      .arg(-b).arg(sqrt_discriminant).arg(a).arg((-b + sqrt_discriminant) / (2 * a)));
    } else if (discriminant == 0) { //проверяем, является наш дискриминант нулевым
        ui->labelResult2->setText("D = 0, один корень:");
        ui->labelResult3->setText(QString("x = %1 / (2 * %2) = %3")
                                      .arg(-b).arg(a).arg(-b / (2 * a)));
        ui->labelResult4->clear(); //эта функция довольно значимая, она помогает нам очищать наш виджет от текста, если б не эта вещь, результат с прошлого примера оставался бы на том самом виджете
    } else { //делаем проверку, если у нас отрицательный дискриминант
        ui->labelResult2->setText("D < 0, корней нет");
        ui->labelResult3->clear();
        ui->labelResult4->clear();
    }
}
