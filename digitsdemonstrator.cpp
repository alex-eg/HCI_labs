#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QStyleOption>

#include "labapi.h"
#include "digitsdemonstrator.h"
#include "ui_digitsdemonstrator.h"

#include "abstractstylednumberrenderer.h"
#include "arabnumsrenderer.h"

DigitsDemonstrator::DigitsDemonstrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitsDemonstrator)
{
    ui->setupUi(this);
    generateTest();
}

DigitsDemonstrator::~DigitsDemonstrator()
{
    emit finished();
    delete ui;
}

void DigitsDemonstrator::generateTest()
{
    foreach(AbstractStyledNumberRenderer* renderer, m_generatedTest)
        delete renderer;

    int testsNum = qrand() % 9 + 1;

    for(int i = 0; i < testsNum; i++)
    {
        int style = qrand() % StylesCount;
        int randomNum = qrand() % 10;

        switch(ArabNums)
        {
            case ArabNums:
            {
                new ArabNumsRenderer(randomNum);
                m_generatedTest << new ArabNumsRenderer(randomNum);
                break;
            }
        }

    }

    QStyleOption option;
    option.palette.setColor(QPalette::Text, Qt::black);
    option.rect = QRect(0, 0, 50, 50);


    foreach(AbstractStyledNumberRenderer* renderer, m_generatedTest)
    {
        renderer->render(option);

        QLabel* label = new QLabel;
        label->setPixmap(QPixmap::fromImage(*renderer->image()));
        layout()->addWidget(label);
    }
}
