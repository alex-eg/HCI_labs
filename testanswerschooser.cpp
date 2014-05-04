#include <QDebug>
#include <QHBoxLayout>

#include "testanswerschooser.h"
#include "ui_testanswerschooser.h"

#include "digitsdemonstrator.h"

TestAnswersChooser::TestAnswersChooser(const TestGenerator* _testGenerator, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::TestAnswersChooser),
    m_testGenerator(_testGenerator),
    m_demonstrator(NULL)
{
    ui->setupUi(this);

    setState(ChooseNums);

    connect(ui->next, SIGNAL(clicked()), SLOT(userChoosedVariants()));
}

TestAnswersChooser::~TestAnswersChooser()
{
    delete ui;
}

void TestAnswersChooser::userChoosedVariants()
{
    setState(ShowCorrect);
}

void TestAnswersChooser::setState(ChooserState _state)
{
    if(_state == ChooseNums)
    {
        ui->title->show();
        ui->subtitle->hide();

        delete m_demonstrator;
        m_demonstrator = NULL;
    }
    else if(_state == ShowCorrect)
    {
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
}
