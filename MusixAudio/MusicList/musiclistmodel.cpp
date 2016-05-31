#include "musiclistmodel.h"
#include "GlobalData/globalData.h"
MusicListModel::MusicListModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int MusicListModel::rowCount(const QModelIndex &parent) const
{
    return m_rowCount;
}

int MusicListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant MusicListModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case SingNameRole:
        return m_singNameList.at(index.row());
    case SingerRole:
        return m_singerList.at(index.row());
    case AlbumsRole:
        return m_albumsList.at(index.row());
    default:
        break;
    }
}

bool MusicListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

void MusicListModel::setRowCount(int count)
{
    m_rowCount = count;
}

void MusicListModel::setSingName(const QList<QString> &singName)
{
    m_singNameList.clear();
    m_singNameList.operator =(singName);
}

void MusicListModel::setSingerName(const QList<QString> &singerName)
{
    m_singerList.clear();
    m_singerList.operator =(singerName);
}

void MusicListModel::setAlbumsName(const QList<QString> &albumsName)
{
    m_albumsList.clear();
    m_albumsList.operator =(albumsName);
}
