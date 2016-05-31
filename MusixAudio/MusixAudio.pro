#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T13:50:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusixAudio
TEMPLATE = app


SOURCES += main.cpp\
        winmain_menu.cpp \
    MusicList/musiclistmodel.cpp \
    MusicList/musiclistview.cpp \
    MusicList/musiclistdelegate.cpp \
    MusicList/listwidget.cpp

HEADERS  += winmain_menu.h \
    MusicList/musiclistmodel.h \
    MusicList/musiclistview.h \
    MusicList/musiclistdelegate.h \
    MusicList/listwidget.h \
    GlobalData/globalData.h

RESOURCES += \
    src.qrc
