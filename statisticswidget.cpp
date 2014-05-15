#include <QDebug>
#include <QStandardItemModel>

#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "statistics/statisticsaggregator.h"
#include "statisticsmodel.h"

#include "mainwindow.h"

StatisticsWidget::StatisticsWidget(MainWindow* _mainWindow, QWidget* _parent) :
    QWidget(_parent),
    ui(new Ui::StatisticsWidget),
    m_mainWindow(_mainWindow),
    m_statistics(_mainWindow->statistics()),
    m_model(new QStandardItemModel())
{
    ui->setupUi(this);

    foreach (QString str, m_mainWindow->users())
    {
        ui->userChoose->addItem(str);
    }

//    m_model->setColumnCount(2);
    ui->diagramm->setModel(m_model);

    connect(ui->type, SIGNAL(currentIndexChanged(int)), this, SLOT(showOtherStatistics(int)));

    showOtherStatistics(ui->type->currentIndex());
}

StatisticsWidget::~StatisticsWidget()
{
    delete ui;
}

void StatisticsWidget::showOtherStatistics(int _index)
{
    StatTypes currentStatType = StatTypes(_index);

    const QVector<int>* stats = m_statistics->statistics(currentStatType);
    const QVector<QString>* description = m_statistics->description(currentStatType);

    Q_ASSERT(stats->size() == description->size());

    resetModel();
    m_model->setRowCount(stats->size());
    for(int i = 0; i < stats->size(); i++)
    {
        m_model->insertRows(i, 1, QModelIndex());

        m_model->setData(m_model->index(i, 0, QModelIndex()), description->at(i) + " - " + QString::number(stats->at(i)));
        m_model->setData(m_model->index(i, 1, QModelIndex()), stats->at(i));
        m_model->setData(m_model->index(i, 0, QModelIndex()), getColorForChart(i), Qt::DecorationRole);
    }
    ui->diagramm->dataChanged(QModelIndex(), QModelIndex());
}

void StatisticsWidget::closeEvent(QCloseEvent *)
{
    emit finished();
}

void StatisticsWidget::resetModel()
{
    m_model->removeColumn(0);
    m_model->removeColumn(1);
    m_model->setColumnCount(2);
}

QColor StatisticsWidget::getColorForChart(int _pos)
{
    static QVector<QColor> colors;
    if(colors.isEmpty())
    {
        colors  << QString("#99e600")
                << QString("#99cc00")
                << QString("#99b300")
                << QString("#9f991a")
                << QString("#a48033")
                << QString("#a9664d")
                << QString("#ae4d66")
                << QString("#b33380")
                << QString("#a64086")
                << QString("#994d8d")
                << QString("#8d5a93")
                << QString("#806699")
                << QString("#8073a6")
                << QString("#8080b3") ;
    }
    return colors.at(_pos % colors.size());
}
