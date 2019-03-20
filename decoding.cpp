#include "decoding.h".h"

Decoding::Decoding(QWidget *parent) : QWidget(parent), mainLayout(new QGridLayout()), text(new QTextEdit()), text_label(new QLabel("Text")), decode_button(new QPushButton("Decode"))
  , right_layout(new QGridLayout()), font("Times new roman", 18),
    path_button(new QPushButton("Enter path")), path(new QLabel("Path haven't entered yet."))
{
    mainLayout->addWidget(text_label, 0, 0);
    mainLayout->addWidget(text, 1, 0);
    mainLayout->addLayout(right_layout, 1, 1);
    mainLayout->setRowStretch(0, 0);
    mainLayout->setRowStretch(1, 1);

    mainLayout->setColumnStretch(0, 9);
    mainLayout->setColumnStretch(1, 1);
    decode_button->setFont(font);
    text_label->setFont(font);
    this->setLayout(mainLayout);

    //right_layout->addWidget(file_name, 0, 0, 1, 0);
    //right_layout->addWidget(file_name_edit, 1, 0, 1, 0);
    right_layout->addWidget(path_button, 2, 0, 1, 0);
    right_layout->addWidget(path, 3, 0, 1 , 0);
    right_layout->addWidget(decode_button, 4, 0, 10, 0);

    right_layout->setRowStretch(0, 0);
    right_layout->setRowStretch(1, 0);
    right_layout->setRowStretch(2, 0);
    right_layout->setRowStretch(3, 0);

    connect(decode_button, SIGNAL(clicked(bool)), this, SLOT(decode()));
    connect(path_button, SIGNAL(clicked(bool)), this, SLOT(open_folder()));
}

Decoding::~Decoding()
{
    delete path;
    path = nullptr;
    delete path_button;
    path_button = nullptr;/*
    delete file_name_edit;
    file_name_edit = nullptr;*/
    /*delete file_name;
    file_name = nullptr;*/
    delete decode_button;
    decode_button = nullptr;
    delete text_label;
    text_label = nullptr;
    delete text;
    text = nullptr;
    delete right_layout;
    right_layout = nullptr;
    delete mainLayout;
    mainLayout = nullptr;
}

void Decoding::decode()
{
    //text->document()->setPlainText(HuffmanTextFile::read(path->text()));
    //HuffmanTextFile::write(path->text(), text->document()->toRawText());
    text->setText(HuffmanTextFile::read(path->text()));
}

void Decoding::open_folder()
{
    path->setText(QFileDialog::getOpenFileName(this, "Enter path to save file"));
}
