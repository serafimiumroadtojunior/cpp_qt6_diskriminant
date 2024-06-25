#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Diskriminant)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_calculateButton_clicked() {
    bool ok;
    double a = ui->lineEditA->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Пожалуйста, введите корректное число для a");
        return;
    }

    double b = ui->lineEditB->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Пожалуйста, введите корректное число для b");
        return;
    }

    double c = ui->lineEditC->text().toDouble(&ok);
    if (!ok) {
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

    double discriminant = b * b - 4 * a * c;
    ui->labelResult1->setText(QString("D = %1^2 - 4(%2 * %3) = %4")
                                  .arg(b).arg(a).arg(c).arg(discriminant));

    if (discriminant > 0) {
        double sqrt_discriminant = std::sqrt(discriminant);
        ui->labelResult2->setText(QString("√D = %1").arg(sqrt_discriminant));
        ui->labelResult3->setText(QString("x1 = (%1 - %2) / (2 * %3) = %4")
                                      .arg(-b).arg(sqrt_discriminant).arg(a).arg((-b - sqrt_discriminant) / (2 * a)));
        ui->labelResult4->setText(QString("x2 = (%1 + %2) / (2 * %3) = %4")
                                      .arg(-b).arg(sqrt_discriminant).arg(a).arg((-b + sqrt_discriminant) / (2 * a)));
    } else if (discriminant == 0) {
        ui->labelResult2->setText("D = 0, один корень:");
        ui->labelResult3->setText(QString("x = %1 / (2 * %2) = %3")
                                      .arg(-b).arg(a).arg(-b / (2 * a)));
        ui->labelResult4->clear();
    } else {
        ui->labelResult2->setText("D < 0, корней нет");
        ui->labelResult3->clear();
        ui->labelResult4->clear();
    }
}



