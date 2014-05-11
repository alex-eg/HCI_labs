#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "statistics.h"

#include "mainwindow.h"

const int hundertPercent = 16 * 360;

StatisticsWidget::StatisticsWidget(MainWindow* _mainWindow, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::StatisticsWidget),
    m_mainWindow(_mainWindow),
    m_statistics(_mainWindow->statistics())
{
    ui->setupUi(this);

    foreach (QString str, m_mainWindow->users())
    {
        ui->userChoose->addItem(str);
    }

    QPainter painter(ui->diagrammView);
    //painter.drawPie(diagrammRect(), );

    //   ui->diagrammView->pa

}

StatisticsWidget::~StatisticsWidget()
{
    delete ui;
}

void StatisticsWidget::closeEvent(QCloseEvent *)
{
    emit finished();
}

QRect StatisticsWidget::diagrammRect() const
{
    return ui->diagrammView->rect();
}

int StatisticsWidget::total() const
{

}
