#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTabWidget>
#include "coding.h"
#include "decoding.h"
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
    Coding* page1;
    Decoding* page2;
    QTabWidget* tab;
    QVBoxLayout* main_layout;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
