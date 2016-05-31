#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>
class MusicListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MusicListModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void setRowCount(int count);        // 设置行数
    void setSingName(const QList<QString> & singName);     // 设置歌曲名
    void setSingerName(const QList<QString> &singerName);       // 设置歌手名
    void setAlbumsName(const QList<QString> &albumsName);       // 设置专辑名


signals:

private:
    int m_rowCount;
    QList<QString> m_singerList, m_singNameList, m_albumsList;
};

#endif // MUSICLISTMODEL_H
