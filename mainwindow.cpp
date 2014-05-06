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

    m_demonstrator = new DigitsDemonstrator(m_testGenerator, 3);
    m_demonstrator->show();

    connect(m_demonstrator, SIGNAL(finished()), SLOT(chooseAnswers()));
}

void MainWindow::chooseAnswers()
{
    m_demonstrator->hide();

    delete m_testChooser;
    m_testChooser = new TestAnswersChooser(m_testGenerator, m_demonstrator);
    m_testChooser->show();

    connect(m_testChooser, SIGNAL(finished()), SLOT(testFinished()));
}

void MainWindow::testFinished()
{
    saveStatistics();

    m_demonstrator->deleteLater();
    m_demonstrator = NULL;

    m_testChooser->hide();
    m_testChooser->deleteLater();
    m_testChooser = NULL;

    show();
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

void MainWindow::saveStatistics()
{

}
