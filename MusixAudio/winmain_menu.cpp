#include "winmain_menu.h"
#include "MusicList/listwidget.h"
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
WinMain_Menu::WinMain_Menu(QWidget *parent)
    : QWidget(parent)
    , p_musicListButton(NULL), p_voiceButton(NULL), p_playSequnceButton(NULL)
    , p_closeButton(NULL), p_nextButton(NULL), p_preButton(NULL), p_stopButton(NULL)
    , p_imageWidget(NULL), p_wordWidget(NULL), p_soundSpectrum(NULL), p_listWidget(NULL)
    , p_songInfoLabel(NULL), p_groupButton(NULL), p_titleLayout(NULL)
    , p_bottomLayout(NULL), p_mainLayout(NULL), p_stackWidget(NULL)
{
    initialization();
    windowLayout();
    setMyStyleSheet();
    loadImage();
}

WinMain_Menu::~WinMain_Menu()
{

}

void WinMain_Menu::initialization()
{
    resize(600, 400);
    this->setWindowFlags(Qt::FramelessWindowHint);
    move((QApplication::desktop()->width() - this->width()) / 2, \
         (QApplication::desktop()->height() - this->height()) / 2 );
    p_musicListButton = new QPushButton;
    p_voiceButton = new QPushButton;
    p_playSequnceButton = new QPushButton;
    p_closeButton = new QPushButton;
    p_nextButton = new QPushButton;
    p_preButton = new QPushButton;
    p_stopButton = new QPushButton;
    p_imageWidget = new QWidget;
    p_wordWidget = new QWidget;
    p_soundSpectrum = new QWidget;
    p_listWidget = new ListWidget;
    p_songInfoLabel = new QLabel;
    p_groupButton = new QButtonGroup;
    p_titleLayout = new QHBoxLayout;
    p_bottomLayout = new QHBoxLayout;
    p_stackWidget = new QStackedWidget;
    p_mainLayout = new QVBoxLayout(this);

    p_groupButton->addButton(p_closeButton, 0);
    p_groupButton->addButton(p_playSequnceButton, 1);
    p_groupButton->addButton(p_musicListButton, 2);
    p_groupButton->addButton(p_preButton, 3);
    p_groupButton->addButton(p_stopButton, 4);
    p_groupButton->addButton(p_nextButton, 5);
    p_groupButton->addButton(p_voiceButton, 6);

    p_stackWidget->addWidget(p_listWidget);
    p_stackWidget->addWidget(p_imageWidget);
    p_stackWidget->addWidget(p_wordWidget);
    p_stackWidget->addWidget(p_soundSpectrum);

    p_songInfoLabel->setAlignment(Qt::AlignCenter);

    for(int i = 0; i < p_groupButton->buttons().size(); ++i) {
        p_groupButton->button(i)->setMinimumSize(QSize(40, 40));
        p_groupButton->button(i)->setMaximumSize(QSize(40, 40));
        p_groupButton->button(i)->setFocusPolicy(Qt::NoFocus);
    }

    /** TEMP INFORMATION  **/
//    p_closeButton->setText("Close");
    p_playSequnceButton->setText("Sequnce");
    p_musicListButton->setText("List");
    p_preButton->setText("Pre");
    p_songInfoLabel->setText("Information");
    p_stopButton->setText("Stop");
    p_nextButton->setText("Next");
    p_voiceButton->setText("Voice");
    /**                 Over                         **/
}

void WinMain_Menu::windowLayout()
{
    /** title layout  **/
    p_titleLayout->setSpacing(0);
    p_titleLayout->setMargin(0);
    p_titleLayout->addWidget(p_closeButton);
    p_titleLayout->addWidget(p_songInfoLabel);
    p_titleLayout->addWidget(p_playSequnceButton);

    /** bottom layout **/
    p_bottomLayout->setSpacing(0);
    p_bottomLayout->setMargin(0);
    p_bottomLayout->addWidget(p_musicListButton);
    p_bottomLayout->addStretch(0);
    p_bottomLayout->addWidget(p_preButton);
    p_bottomLayout->addWidget(p_stopButton);
    p_bottomLayout->addWidget(p_nextButton);
    p_bottomLayout->addStretch(0);
    p_bottomLayout->addWidget(p_voiceButton);

    /** main layout  **/
    p_mainLayout->setMargin(0);
    p_mainLayout->setSpacing(0);
    p_mainLayout->addLayout(p_titleLayout);
    p_mainLayout->addWidget(p_stackWidget);
    p_mainLayout->addLayout(p_bottomLayout);

}

void WinMain_Menu::setMyStyleSheet()
{
    setStyleSheet("QWidget{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                  "stop: 0 rgb(120, 120, 120), stop: 0.5 rgb(158, 158, 160), "\
                  "stop:0.89 rgb(130, 130, 135), stop:1 rgb(120, 120, 120));}"\
                  "QPushButton{border: 0px solid rgb(0, 0, 0);"\
                  "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                  "stop: 0 rgb(100, 100, 100), stop: 0.5 rgb(0, 0, 0),"\
                  "stop:1 rgb(100, 100, 100));}");
}

void WinMain_Menu::loadImage()
{
//    p_closeButton->setIcon(QIcon(":/Image/close.png"));
//    p_closeButton->setIconSize(QSize(p_closeButton->width(), p_closeButton->height()));
}
