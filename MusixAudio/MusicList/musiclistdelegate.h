#ifndef MUSICLISTDELEGATE_H
#define MUSICLISTDELEGATE_H

#include <QAbstractItemDelegate>

class MusicListDelegate : public QAbstractItemDelegate
{
public:
    MusicListDelegate();
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool helpEvent(QHelpEvent *event, QAbstractItemView *view, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    void setLayout(const QStyleOptionViewItem &option, QRect &singNameRect, QRect &singerNameRect, QRect &AlbumsRect) const;
    void drawBackground(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void drawSingName(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index, const QRect& singNameRect) const;
    void drawSingerName(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index, const QRect& singerNameRect) const;
    void drawAlbumsName(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index, const QRect& albumsRect) const;
};

#endif // MUSICLISTDELEGATE_H
