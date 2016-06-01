#include "listwidget.h"
#include "musiclistdelegate.h"
#include "musiclistmodel.h"
#include "musiclistview.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
ListWidget::ListWidget(QWidget *parent) :
    QWidget(parent)
  , p_singerBtn(NULL), p_albumsBtn(NULL), p_singBtn(NULL)
  , p_sacnf(NULL)
  , p_musicListDelegate(NULL)
  , p_musicListModel(NULL)
  , p_musicListView(NULL)
  , p_titleLayout(NULL)
  , p_bottomLayout(NULL)
  , p_mainLayout(NULL)
{
    initialization();
    setWindosLayout();
    setMyStyle();
    connectSigAndSlot();
}

void ListWidget::slotSearchSongClicked()
{
    m_mp3PathList.clear();
    static QFileDialog fd;
    fd.setDirectory(QDir("/home/"));
    fd.setWindowTitle("扫描音乐文件");
    fd.setFileMode(QFileDialog::Directory);
    fd.show();
    connect(&fd, SIGNAL(urlSelected(QUrl)), this, SLOT(slotGetDirectName(QUrl)));
}

void ListWidget::slotGetDirectName(QUrl url)
{
    /** 获取mp3 文件路径  **/
    traversalFile(url.path());
}

void ListWidget::initialization()
{
    p_singerBtn = new QPushButton;
    p_albumsBtn = new QPushButton;
    p_singBtn = new QPushButton;
    p_sacnf = new QPushButton;
    p_titleLayout = new QHBoxLayout;
    p_bottomLayout = new QHBoxLayout;
    p_mainLayout = new QVBoxLayout(this);

    p_singerBtn->setFocusPolicy(Qt::NoFocus);
    p_albumsBtn->setFocusPolicy(Qt::NoFocus);
    p_singBtn->setFocusPolicy(Qt::NoFocus);
    p_sacnf->setFocusPolicy(Qt::NoFocus);

    p_singerBtn->setText("歌手");
    p_albumsBtn->setText("专辑");
    p_singBtn->setText("歌曲");
    p_sacnf->setText("扫描本地歌曲");

    p_singerBtn->setMinimumSize(QSize(this->width() * 0.3, this->height() * 0.1));
    p_singerBtn->setMaximumSize(QSize(this->width() * 0.3, this->height() * 0.1));

    p_albumsBtn->setMinimumSize(QSize(this->width() * 0.4, this->height() * 0.1));
    p_albumsBtn->setMaximumSize(QSize(this->width() * 0.4, this->height() * 0.1));

    p_singBtn->setMinimumSize(QSize(this->width() * 0.4, this->height() * 0.1));
    p_singBtn->setMaximumSize(QSize(this->width() * 0.4, this->height() * 0.1));

    p_sacnf->setMinimumSize(QSize(this->width() * 0.5, this->height() * 0.1));
    p_sacnf->setMaximumSize(QSize(this->width() * 0.5, this->height() * 0.1));

    p_musicListDelegate = new MusicListDelegate;
    p_musicListModel = new MusicListModel;
    p_musicListView = new MusicListView;

    p_musicListView->setModel(p_musicListModel);
    p_musicListView->setItemDelegate(p_musicListDelegate);



    /** TEST  **/
    QList<QString> str;
    for(int i = 0; i < 20; ++i) {
        str << "Mayo";
    }
    p_musicListModel->setRowCount(20);
    p_musicListModel->setSingName(str);
    p_musicListModel->setSingerName(str);
    p_musicListModel->setAlbumsName(str);

    /** OVER  **/

}

void ListWidget::setWindosLayout()
{
    setLayout(p_mainLayout);
    p_mainLayout->setSpacing(0);
    p_mainLayout->setMargin(0);
    p_mainLayout->addLayout(p_titleLayout);
    p_mainLayout->addWidget(p_musicListView);
    p_mainLayout->addLayout(p_bottomLayout);

    p_titleLayout->setSpacing(0);
    p_titleLayout->setMargin(0);
    p_titleLayout->addWidget(p_singBtn);
    p_titleLayout->addWidget(p_singerBtn);
    p_titleLayout->addWidget(p_albumsBtn);

    p_bottomLayout->setSpacing(0);
    p_bottomLayout->setMargin(0);
    p_bottomLayout->addStretch(0);
    p_bottomLayout->addWidget(p_sacnf);
    p_bottomLayout->addStretch(0);
}

void ListWidget::setMyStyle()
{
    setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);}");
}

void ListWidget::connectSigAndSlot()
{
    connect(p_sacnf, SIGNAL(clicked()), this, SLOT(slotSearchSongClicked()));
}

void ListWidget::traversalFile(QString str)
{
    QDir dir(str);
    foreach (QFileInfo mfi, dir.entryInfoList()) {
        if(mfi.isFile()) {
            if(mfi.fileName().contains(".mp3")) {
                m_mp3PathList << mfi.absoluteFilePath();
            }
        } else {
            if(mfi.fileName() == "." || mfi.fileName() == "..")
                continue;
            traversalFile(mfi.absoluteFilePath());
        }
    }
}
