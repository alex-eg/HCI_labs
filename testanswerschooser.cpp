#include <QDebug>
#include <QHBoxLayout>

#include "testanswerschooser.h"
#include "ui_testanswerschooser.h"

#include "digitsdemonstrator.h"

TestAnswersChooser::TestAnswersChooser(const TestGenerator* _testGenerator, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::TestAnswersChooser),
    m_testGenerator(_testGenerator),
    m_demonstrator(NULL),
    m_state(NoState)
{
    ui->setupUi(this);

    //setState(ChooseNums);

    nextState();

    connect(ui->next, SIGNAL(clicked()), SLOT(nextState()));
}

TestAnswersChooser::~TestAnswersChooser()
{
    delete ui;
}

void TestAnswersChooser::nextState()
{
    int tmp = static_cast<unsigned int>(m_state);
    ++tmp;
    m_state = static_cast<ChooserState>(tmp);

    setState(m_state);
}

void TestAnswersChooser::setState(ChooserState _state)
{
    if(_state == ChooseNums)
    {
        ui->numsChooser->setEnabled(true);

        ui->title->show();
        ui->subtitle->hide();

        delete m_demonstrator;
        m_demonstrator = NULL;
    }
    else if(_state == ShowCorrect)
    {
        ui->numsChooser->setEnabled(false);

        ui->title->hide();
        ui->subtitle->show();

        QHBoxLayout* l;
        if(l = static_cast<QHBoxLayout*>(layout()))
        {
            m_demonstrator = new DigitsDemonstrator(m_testGenerator, -1);
            l->insertWidget(l->count()-1, m_demonstrator);
        }
        else
            qDebug() << "Wrong layout type in " << Q_FUNC_INFO;
    }
    else if(_state == Finish)
        emit finished();
    else
        qDebug() << "smth goes wrong in" << Q_FUNC_INFO;
}
