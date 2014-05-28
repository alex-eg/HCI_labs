#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    t = new QTimer(this);
    time = -1;
    ui->setupUi(this);
    connect(ui->pushButtonStart, SIGNAL(clicked()),
            this, SLOT(startExperiment()));
    connect(ui->okPushButton, SIGNAL(clicked()),
            this, SLOT(proceedToRusults()));
    connect(ui->ok2PushButton, SIGNAL(clicked()),
            this, SLOT(startOver()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::returnString(bool ispictograms, int num)
{
    QString s = "";
    if (ispictograms) {
        for (int i = 0; i < num; i++) {
            s.append(QString::fromUtf8("♥"));
        }
        if (num == 0)
            s = "o";
    }
    else {
        switch (num) {
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
    return s;
}

void MainWindow::updateTimer()
{
    time -= 1;
    if(time > -1)
        ui->labelTimer->setText((QString("%0").arg(time)));
    else {
        t->stop();
        continueExperiment();
    }
}

void MainWindow::startExperiment()
{
    qsrand(QDateTime::currentDateTime().toTime_t());
    int seconds = ui->spinBoxSeconds->value();
    ui->labelTimer->setText(QString("%0").arg(seconds));
    int numofdigits = ui->spinBoxDigitNumber->value();

    QSet<int> nums;

    while (nums.size() != numofdigits) {
        nums.insert(qrand() % 10);
    }

    for (int i = 0; i < numofdigits; i++) {
        nnums[i] = nums.toList()[i];
    }

    for (int i = numofdigits; i < 10; i++) {
        nnums[i] = -1;
    }

    for (int i = 0; i < 50; i++) {
        int a = qrand() % 10;
        int b = qrand() % 10;
        int q = nnums[a];
        nnums[a] = nnums[b];
        nnums[b] = q;
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
            s = returnString(ui->radioButtonPictures->isChecked(), nnums[j]);
            QFont font = label_list[j]->font();
            font.setPointSize(14+nnums[j]);
            label_list[j]->setFont(font);
            label_list[j]->setText(s);
        } else {
            label_list[j]->setText("");
        }
    }
    ui->stackedWidget->setCurrentIndex(1);

    time = seconds;
    t->setInterval(1000);
    t->start();
    connect(t, SIGNAL(timeout()), this,
            SLOT(updateTimer()));
}

void MainWindow::continueExperiment()
{
    QCheckBox * checkboxes[10] = {ui->checkBox,
                                  ui->checkBox_2,
                                  ui->checkBox_3,
                                  ui->checkBox_4,
                                  ui->checkBox_5,
                                  ui->checkBox_6,
                                  ui->checkBox_7,
                                  ui->checkBox_8,
                                  ui->checkBox_9,
                                  ui->checkBox_10};

    for (int i = 0 ; i < 10; i++) {
        checkboxes[i]->setText(returnString(ui->radioButtonPictures->isChecked(), i));
    }


    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::proceedToRusults()
{
    QCheckBox * checkboxes[10] = {ui->checkBox,
                                  ui->checkBox_2,
                                  ui->checkBox_3,
                                  ui->checkBox_4,
                                  ui->checkBox_5,
                                  ui->checkBox_6,
                                  ui->checkBox_7,
                                  ui->checkBox_8,
                                  ui->checkBox_9,
                                  ui->checkBox_10};
    ui->textEditSelected->appendPlainText(QString::fromUtf8("Вы выбрали:"));
    for (int i = 0 ; i < 10; i++)
        if(checkboxes[i]->isChecked()) {
            ui->textEditSelected->appendPlainText(returnString(ui->radioButtonPictures->isChecked(), i));
    }

    ui->textEditWas->appendPlainText(QString::fromUtf8("Отображались:"));

    QList <int> ll;
    for (int i = 0; i < 10; i++)
        if(nnums[i] != -1) {
            ll.append(nnums[i]);
        }

    qSort(ll);

    for (int i = 0; i < ll.size(); i++)
        ui->textEditWas->appendPlainText(returnString(ui->radioButtonPictures->isChecked(), ll[i]));

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::startOver()
{
    ui->stackedWidget->setCurrentIndex(0);
}
