#include "musiclistdelegate.h"
#include "GlobalData/globalData.h"
#include <QPainter>
MusicListDelegate::MusicListDelegate()
{
}

void MusicListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QRect singNameRect, singerNameRect, albumsNameRect;
    setLayout(option, singNameRect, singerNameRect, albumsNameRect);
    drawBackground(painter, option, index);
    drawSingName(painter, option, index, singNameRect);
    drawSingerName(painter, option, index, singerNameRect);
    drawAlbumsName(painter, option, index, albumsNameRect);
    painter->restore();
}

QSize MusicListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    return option.rect.size();
}

bool MusicListDelegate::helpEvent(QHelpEvent */*event*/, QAbstractItemView */*view*/, const QStyleOptionViewItem &/*option*/, const QModelIndex &/*index*/)
{
    return false;
}

void MusicListDelegate::setLayout(const QStyleOptionViewItem &option, QRect &singNameRect, QRect &singerNameRect, QRect &AlbumsRect) const
{
    /** sing name area  **/
    singNameRect = option.rect;
    singNameRect.setWidth(option.rect.width() * 0.4);
    singNameRect.moveLeft(option.rect.left());

    /** singer name area  **/
    singerNameRect = singNameRect;
    singerNameRect.setWidth(option.rect.width() * 0.2);
    singerNameRect.moveLeft(singNameRect.right());

    /** albums name area  **/
    AlbumsRect = singNameRect;
    AlbumsRect.setWidth(option.rect.width() * 0.4);
    AlbumsRect.moveLeft(singerNameRect.right());

}

void MusicListDelegate::drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QRect rect = option.rect;
    painter->setPen(QColor(200, 200, 200));
    painter->setBrush(QBrush(QColor(220, 220, 220)));
    painter->drawRoundedRect(rect, 0, 0);
    painter->restore();
}

void MusicListDelegate::drawSingName(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index, const QRect &singNameRect) const
{
    painter->save();
    int pixSize = singNameRect.height() * 0.5;
    QFont font = option.font;
    QTextOption txtAlign(Qt::AlignCenter);
    font.setPixelSize(pixSize);
    painter->setFont(font);
    painter->drawText(singNameRect, index.data(SingNameRole).toString(), txtAlign);
    painter->restore();
}

void MusicListDelegate::drawSingerName(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index, const QRect &singerNameRect) const
{
    painter->save();
    int pixSize = singerNameRect.height() * 0.5;
    QFont font = option.font;
    QTextOption txtAlign(Qt::AlignCenter);
    font.setPixelSize(pixSize);
    painter->setFont(font);
    painter->drawText(singerNameRect, index.data(SingerRole).toString(), txtAlign);
    painter->restore();
}

void MusicListDelegate::drawAlbumsName(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index, const QRect &albumsRect) const
{
    painter->save();
    int pixSize = albumsRect.height() * 0.5;
    QFont font = option.font;
    QTextOption txtAlign(Qt::AlignCenter);
    font.setPixelSize(pixSize);
    painter->setFont(font);
    painter->drawText(albumsRect, index.data(AlbumsRole).toString(), txtAlign);
    painter->restore();
}
