#include <QDebug>
#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "statistics/statisticsaggregator.h"
#include "statisticsmodel.h"

#include "mainwindow.h"

const int hundertPercent = 16 * 360;

StatisticsWidget::StatisticsWidget(MainWindow* _mainWindow, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::StatisticsWidget),
    m_mainWindow(_mainWindow),
    m_statistics(_mainWindow->statistics()),
    m_model(new StatisticsModel(m_statistics))
{
    ui->setupUi(this);

    foreach (QString str, m_mainWindow->users())
    {
        ui->userChoose->addItem(str);
    }

    ui->diagramm->setModel(m_model);
    ui->diagramm->dataChanged(QModelIndex(), QModelIndex());

    connect(ui->type, SIGNAL(currentIndexChanged(int)), this, SLOT(showOtherStatistics(int)));
}

StatisticsWidget::~StatisticsWidget()
{
    delete ui;
}

void StatisticsWidget::showOtherStatistics(int _index)
{
    m_model->setStatType(StatTypes(_index));
}

void StatisticsWidget::closeEvent(QCloseEvent *)
{
    emit finished();
}
