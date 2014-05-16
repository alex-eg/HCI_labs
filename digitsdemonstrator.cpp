#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QStyleOption>

#include "digitsdemonstrator.h"
#include "ui_digitsdemonstrator.h"

#include "stylednums/stylednumberrenderer.h"
#include "testgenerator.h"

DigitsDemonstrator::DigitsDemonstrator(const TestGenerator* _testGenerator, int _timeToShow, QWidget* _parent)
    : QWidget(_parent),
      ui(new Ui::DigitsDemonstrator),
      m_testGenerator(_testGenerator),
      m_timer(new QTimer(this)),
      m_timeLeft(_timeToShow)
{
    ui->setupUi(this);
    renderNumsPics();

    setCountdown(_timeToShow);
}

DigitsDemonstrator::~DigitsDemonstrator()
{
    delete ui;
}

void DigitsDemonstrator::setCountdown(int _seconds)
{
    m_timeLeft = _seconds;
    if(_seconds > 0)
    {
        connect(m_timer, SIGNAL(timeout()), SLOT(timerTicked()), Qt::UniqueConnection);
        m_timer->start(1000);
    }
    else
        m_timer->stop();
}

void DigitsDemonstrator::timerTicked()
{
    m_timeLeft--;
    qDebug() << m_timeLeft;
    //update();

    if(m_timeLeft == 0)
    {
        hide();
        m_timer->stop();

        emit finished();
    }
}

void DigitsDemonstrator::renderNumsPics()
{
    foreach(StyledNumberRenderer* renderer, m_testGenerator->generatedTest())
    {
        if(!renderer)
        {
            qDebug() << "smth goes wrong in " << Q_FUNC_INFO;
            continue;
        }
        renderer->render(generateOption(), generateFont());

        QLabel* label = new QLabel;
        label->setPixmap(QPixmap::fromImage(*renderer->image()));
        layout()->addWidget(label);
    }
}

QFont DigitsDemonstrator::generateFont() const
{
    QFont font = defaultStringsFont;
    font.setItalic(qrand() % 2);
    font.setBold(qrand() % 2);

    int dispersy = 10;
    int newSize = font.pixelSize() + (qrand() % dispersy) + 30;
    font.setPixelSize(newSize);
    return font;
}

QStyleOption DigitsDemonstrator::generateOption() const
{
    QStyleOption option;
    option.palette.setColor(QPalette::Text, Qt::black);
    option.rect = QRect(0, 0, 140, 140);

    return option;
}

