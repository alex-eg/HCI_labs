#include <QDebug>
#include "statisticsmodel.h"
#include "statistics/statisticsaggregator.h"
#include "stylednums/stylednumsapi.h"

StatisticsModel::StatisticsModel(StatisticsAggregator *_statistics)
    : m_statistics(_statistics),
      m_statType(Total)
{
    for(int i = 0; i < rowCount(); i++)
        m_randomColors << randomColor();

    setStatType(m_statType);
}

QModelIndex StatisticsModel::index(int _row, int _column, const QModelIndex &_parent) const
{
    if(_column == 1)
    {
        double success = m_statistics->statistics(m_statType)->at(_row);// ->statistics()->at(_row).success;
        return createIndex(_row, _column, success);
    }
    else
        return createIndex(_row, _column);
}

QModelIndex StatisticsModel::parent(const QModelIndex&) const
{
    return QModelIndex();
}

int StatisticsModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "rowCount = " << currStatistics()->size();
    return currStatistics()->size();
}

int StatisticsModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant StatisticsModel::data(const QModelIndex& _index, int _role) const
{
    if(_index.column() == 1 && _role == Qt::DisplayRole)
    {
        qDebug() << _index.internalId();
        return _index.internalId();
    }
    else if(_index.column() == 0)
    {
        if(_role == Qt::DecorationRole)
            return QVariant(m_randomColors[_index.row()]);
        else
            return QVariant(currDescription()->at(_index.row()));
    }
    else
        qDebug() << Q_FUNC_INFO;

    return QVariant();
}

void StatisticsModel::setStatType(StatTypes _type)
{
    beginResetModel();
    m_statType = _type;
    endResetModel();
}

const QVector<int> *StatisticsModel::currStatistics() const
{
    return m_statistics->statistics(m_statType);
}

const QVector<QString> *StatisticsModel::currDescription() const
{
    return m_statistics->description(m_statType);
}


