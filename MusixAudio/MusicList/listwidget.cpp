#include "listwidget.h"
#include <QTableWidget>
ListWidget::ListWidget(QWidget *parent) :
    QWidget(parent)
  , p_typeWidget(NULL)
{
    initialization();
}

void ListWidget::initialization()
{
    p_typeWidget = new QTableWidget;
    p_typeWidget->setRowCount(1);
    p_typeWidget->setColumnCount(3);
    p_typeWidget->setSelectionMode(QAbstractItemView::NoSelection);

    p_typeWidget->setMinimumSize(QSize(this->width(), this->height() / 10));
    p_typeWidget->setMaximumSize(QSize(this->width(), this->height() / 10));
}
