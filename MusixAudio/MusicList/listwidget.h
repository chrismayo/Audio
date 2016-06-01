#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QUrl>
#include <QStringList>
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

private slots:
    void slotSearchSongClicked();   // 扫描歌曲按钮下押时出发
    void slotGetDirectName(QUrl url);        // 对话框下押
private:
    void initialization();
    void setWindosLayout();
    void setMyStyle();
    void connectSigAndSlot();
    void traversalFile(QString str);

private:
    QPushButton* p_singerBtn, *p_albumsBtn, *p_singBtn, *p_sacnf;
    MusicListDelegate* p_musicListDelegate;
    MusicListModel* p_musicListModel;
    MusicListView* p_musicListView;

    QHBoxLayout* p_titleLayout, *p_bottomLayout;
    QVBoxLayout* p_mainLayout;
    QStringList m_mp3PathList;
};

#endif // LISTWIDGET_H
