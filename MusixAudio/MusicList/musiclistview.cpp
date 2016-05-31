#include "musiclistview.h"
#include <QHeaderView>
#include <QScrollBar>
#include <QScroller>
MusicListView::MusicListView()
{
    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setShowGrid(false);
    this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->verticalHeader()->setDefaultSectionSize(35);

    /** 滑屏操作  **/
    QScroller* scroller = QScroller::scroller(this->viewport());
    QScrollerProperties prop = scroller->scrollerProperties();
    prop.setScrollMetric(QScrollerProperties::OvershootDragDistanceFactor,0);
    prop.setScrollMetric(QScrollerProperties::OvershootDragResistanceFactor,0.1);
    prop.setScrollMetric(QScrollerProperties::OvershootScrollDistanceFactor,0);
    prop.setScrollMetric(QScrollerProperties::OvershootScrollTime,0.3);
    prop.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy,QScrollerProperties::OvershootAlwaysOff);
    prop.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy,QScrollerProperties::OvershootAlwaysOff);
    scroller->setScrollerProperties(prop);
    scroller->grabGesture(this->viewport(), QScroller::TouchGesture);
    scroller->grabGesture(this->viewport(), QScroller::LeftMouseButtonGesture);
}
