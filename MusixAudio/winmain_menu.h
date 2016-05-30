#ifndef WINMAIN_MENU_H
#define WINMAIN_MENU_H

#include <QWidget>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
class QPushButton;
class QLabel;
class ListWidget;
class WinMain_Menu : public QWidget
{
    Q_OBJECT

public:
    WinMain_Menu(QWidget *parent = 0);
    ~WinMain_Menu();

private:
    void initialization();      // 初始化控件
    void windowLayout();
    void setMyStyleSheet();
    void loadImage();
private:
    QPushButton *p_musicListButton, * p_voiceButton, *p_playSequnceButton, \
                                *p_closeButton, *p_nextButton, *p_preButton, *p_stopButton;
    QWidget* p_imageWidget, *p_wordWidget, *p_soundSpectrum;
    ListWidget* p_listWidget;
    QLabel* p_songInfoLabel;
    QButtonGroup* p_groupButton;
    QHBoxLayout* p_titleLayout, *p_bottomLayout;
    QVBoxLayout* p_mainLayout;
    QStackedWidget* p_stackWidget;
};

#endif // WINMAIN_MENU_H
