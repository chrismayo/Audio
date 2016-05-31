#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
class MusicListDelegate;
class MusicListModel;
class MusicListView;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class ListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = 0);

private:
    void initialization();
    void setWindosLayout();
    void setMyStyle();

private:
    QPushButton* p_singerBtn, *p_albumsBtn, *p_singBtn, *p_sacnf;
    MusicListDelegate* p_musicListDelegate;
    MusicListModel* p_musicListModel;
    MusicListView* p_musicListView;

    QHBoxLayout* p_titleLayout, *p_bottomLayout;
    QVBoxLayout* p_mainLayout;
};

#endif // LISTWIDGET_H
