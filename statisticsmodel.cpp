#include "statisticsmodel.h"
#include "statistics.h"

StatisticsModel::StatisticsModel(Statistics *_statistics)
    : m_statistics(_statistics)
{
    beginResetModel();
    endResetModel();
}

QModelIndex StatisticsModel::index(int _row, int _column, const QModelIndex &_parent) const
{
    if(_column == 1)
    {
        double success = m_statistics->statistics()->at(_row).success;
        return createIndex(_row, _column, success);
    }
    else
        return createIndex(_row, _column);
}

QModelIndex StatisticsModel::parent(const QModelIndex& _child) const
{
    return QModelIndex();
}

int StatisticsModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "rowCount = " << m_statistics->statistics()->size();
    return m_statistics->statistics()->size();
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
            return QVariant(randomColor());
        else
            return QVariant("bla-bla");
    }
    else
        qDebug() << Q_FUNC_INFO;

    return QVariant();
}


