#include <QKeyEvent>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitsdemonstrator.h"
#include "testgenerator.h"
#include "testanswerschooser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_testGenerator(new TestGenerator),
    m_demonstrator(NULL),
    m_testChooser(NULL)
{
    ui->setupUi(this);

    ui->userNameEdit->hide();
    ui->userNameLabel->installEventFilter(this);
    ui->userNameEdit->installEventFilter(this);

    connect(ui->beginTest, SIGNAL(clicked()), this, SLOT(startTest()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_testGenerator;
}

void MainWindow::startTest()
{
    hide();

    Q_ASSERT(m_testGenerator);
    m_testGenerator->generateOtherTest();

    m_demonstrator = new DigitsDemonstrator(m_testGenerator);
    m_demonstrator->show();

    connect(m_demonstrator, SIGNAL(finished()), SLOT(chooseAnswers()));
}

void MainWindow::chooseAnswers()
{
    m_demonstrator->hide();

    delete m_testChooser;
    m_testChooser = new TestAnswersChooser;
    m_testChooser->show();
}

bool MainWindow::eventFilter(QObject* _obj, QEvent* _ev)
{
    if(_obj == ui->userNameLabel && _ev->type() == QEvent::MouseButtonPress)
    {
        userNameClicked();
        return true;
    }

    if(_obj == ui->userNameEdit && _ev->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(_ev);

        if(!keyEvent)
            return false;

        if(keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
        {
            userNameEditingFinished();
            return true;
        }
        else if(keyEvent->key() == Qt::Key_Escape)
        {
            resetPreviousUserName();
            userNameEditingFinished();
            return true;
        }

    }

    return false;
}

void MainWindow::userNameClicked()
{
    ui->userNameEdit->clear();

    ui->userNameEdit->show();
    ui->userNameLabel->hide();

    ui->beginTest->setEnabled(false);
    ui->statistics->setEnabled(false);
}

void MainWindow::userNameEditingFinished()
{
    if(currentUserName().isEmpty())
        resetPreviousUserName();
    else
        ui->userNameLabel->setText(currentUserName());

    ui->userNameEdit->hide();
    ui->userNameLabel->show();

    ui->beginTest->setEnabled(true);
    ui->statistics->setEnabled(true);
}

void MainWindow::resetPreviousUserName()
{
    ui->userNameEdit->setText(ui->userNameLabel->text());
}

QString MainWindow::currentUserName() const
{
    return ui->userNameEdit->text();
}

//void MainWindow::on_pushButton_released()
//{
//    int j, t;
//    QString s;
//    deque<int> numbers;
//    for (int k=1; k<10; k++)
//        numbers.push_back(k);
//    random_shuffle(numbers.begin(), numbers.end());
//    foreach (QLabel* q, Labels)
//    {
//        j=qrand()%2;

//        if (j==0)
//        {
//            j=qrand()%7;
//            q->setStyleSheet(TextColors[j]);
//            t=qrand()%2;
//            j=numbers.front();
//            numbers.pop_front();
//            if (t==0)
//            {
//                s=QString::number(j);
//            }
//            else
//            {
//                s=RomeNumbers[j];
//            }
//            q->setText(s);
//        }
//        else
//        {
//            q->setText("");
//        }
//    }
//}
