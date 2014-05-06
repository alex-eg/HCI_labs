#include <QDebug>
#include <QHBoxLayout>

#include "testanswerschooser.h"
#include "ui_testanswerschooser.h"

#include "digitsdemonstrator.h"

TestAnswersChooser::TestAnswersChooser(const TestGenerator* _testGenerator, DigitsDemonstrator* _demonstrator, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::TestAnswersChooser),
    m_testGenerator(_testGenerator),
    m_demonstrator(_demonstrator),
    m_state(NoState)
{
    ui->setupUi(this);

    nextState();

    connect(ui->next, SIGNAL(clicked()), SLOT(nextState()));
}

TestAnswersChooser::~TestAnswersChooser()
{
    delete ui;
}

QList<int> TestAnswersChooser::checkedNums() const
{
    QList<int> ans;
    int count = ui->numsChooser->count();
    for(int i = 0; i < count; i++)
    {
        bool isChecked = ui->numsChooser->item(i)->checkState() == Qt::Checked;
        if(isChecked)
            ans << i;
    }

    return ans;
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

        m_demonstrator->hide();
    }
    else if(_state == ShowCorrect)
    {
        ui->numsChooser->setEnabled(false);

        ui->title->hide();
        ui->subtitle->show();

        QHBoxLayout* l = static_cast<QHBoxLayout*>(layout());
        if(l)
        {
            m_demonstrator->setCountdown(-1);
            l->insertWidget(l->count()-1, m_demonstrator);
            m_demonstrator->show();
        }
        else
            qDebug() << "Wrong layout type in " << Q_FUNC_INFO;
    }
    else if(_state == Finish)
        emit finished();
    else
        qDebug() << "smth goes wrong in" << Q_FUNC_INFO;
}
