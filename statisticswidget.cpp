#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "statistics.h"

StatisticsWidget::StatisticsWidget(Statistics* _statistics, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::StatisticsWidget),
    m_statistics(_statistics)
{
    ui->setupUi(this);
}

StatisticsWidget::~StatisticsWidget()
{
    delete ui;
}
