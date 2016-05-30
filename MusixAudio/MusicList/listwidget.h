#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
class QTableWidget;
class ListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = 0);

private:
    void initialization();

private:
    QTableWidget* p_typeWidget;

};

#endif // LISTWIDGET_H
