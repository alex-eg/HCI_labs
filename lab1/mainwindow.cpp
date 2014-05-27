#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonStart, SIGNAL(clicked()),
            this, SLOT(startExperiment()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startExperiment()
{
    int seconds = ui->spinBoxSeconds->value();
    ui->labelTimer->setText(QString("%0").arg(seconds));
    int numofdigits = ui->spinBoxDigitNumber->value();

    QSet<int> nums;
    QMap<int, int> nnums;

    while (nums.size() != numofdigits) {
        nums.insert(qrand() % 10);
    }

    for (int i = 0; i < numofdigits; i++) {
        nnums[i] = nums.toList()[i];
    }

    for (int i = numofdigits; i < 10; i++) {
        nnums[i] = -1;
    }

    QLabel* label_list[10] = { ui->label_3,
                            ui->label_4,
                            ui->label_5,
                            ui->label_6,
                            ui->label_7,
                            ui->label_8,
                            ui->label_9,
                            ui->label_10,
                            ui->label_11,
                            ui->label_12
    };

    for (int j = 0; j < 10; j++) {
        QString s = "";
        if (nnums[j] != -1) {
            if (ui->radioButtonPictures->isChecked())
                for (int i = 0; i < nnums[j]; i++) {
                    s.append(QString("♥").toAscii());
                }
            else {
                switch (nnums[j]) {
                case 0:
                    s = "O";
                    break;
                case 1:
                    s = "I";
                    break;
                case 2:
                    s = "II";
                    break;
                case 3:
                    s = "III";
                    break;
                case 4:
                    s = "IV";
                    break;
                case 5:
                    s = "V";
                    break;
                case 6:
                    s = "VI";
                    break;
                case 7:
                    s = "VII";
                    break;
                case 8:
                    s = "VIII";
                    break;
                case 9:
                    s = "IX";
                    break;
            }
            }
            QFont font = label_list[j]->font();
            font.setPointSize(14+nnums[j]);
            label_list[j]->setFont(font);
            label_list[j]->setText(s);
        } else {
            label_list[j]->setText("");
        }
    }
    ui->stackedWidget->setCurrentIndex(1);

    QTimer * t = new QTimer(this);

    t->setInterval(seconds * 1000);
    t->start();
    connect(t, SIGNAL(timeout()), this,
            SLOT(continueExperiment()));
}

void MainWindow::continueExperiment()
{
    ui->stackedWidget->setCurrentIndex(2);
}
