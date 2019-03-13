#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), page1(new Coding()), page2(new Decoding()), tab(new QTabWidget()), main_layout(new QVBoxLayout())
{
    main_layout->addWidget(tab);
    this->setLayout(main_layout);
    tab->addTab(page1, "Coding");
    tab->addTab(page2, "Decoding");
}

Widget::~Widget()
{
    delete page1;
    page1 = nullptr;
    delete page2;
    page2 = nullptr;
    delete tab;
    tab = nullptr;
    delete main_layout;
    main_layout = nullptr;
}
