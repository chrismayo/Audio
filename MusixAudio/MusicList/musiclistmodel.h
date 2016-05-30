#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include <QAbstractTableModel>

class MusicListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MusicListModel(QObject *parent = 0);

signals:

public slots:

};

#endif // MUSICLISTMODEL_H
