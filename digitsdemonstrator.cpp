#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QStyleOption>

#include "labapi.h"
#include "digitsdemonstrator.h"
#include "ui_digitsdemonstrator.h"

#include "abstractstylednumberrenderer.h"
#include "testgenerator.h"

DigitsDemonstrator::DigitsDemonstrator(const TestGenerator* _testGenerator, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DigitsDemonstrator),
    m_testGenerator(_testGenerator)
{
    ui->setupUi(this);
    renderNumsPics();
}

DigitsDemonstrator::~DigitsDemonstrator()
{
    emit finished();
    delete ui;
}

void DigitsDemonstrator::renderNumsPics()
{
    QStyleOption option;
    option.palette.setColor(QPalette::Text, Qt::black);
    option.rect = QRect(0, 0, 50, 50);

    foreach(AbstractStyledNumberRenderer* renderer, m_testGenerator->generatedTest())
    {
        if(!renderer)
        {
            qDebug() << "smth goes wrong in " << Q_FUNC_INFO;
            continue;
        }
        renderer->render(option);

        QLabel* label = new QLabel;
        label->setPixmap(QPixmap::fromImage(*renderer->image()));
        layout()->addWidget(label);
    }
}

