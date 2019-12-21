#include "coding.h"

Coding::Coding(QWidget *parent) : QWidget(parent), mainLayout(new QGridLayout()), text(new QPlainTextEdit()), text_label(new QLabel("Text")), encode_button(new QPushButton("Encode"))
  , right_layout(new QGridLayout()), font("Times new roman", 18), file_name(new QLabel("File name:")), file_name_edit(new QLineEdit()),
    path_button(new QPushButton("Enter path")), path(new QLabel("Path haven't entered yet.")), from_file(new QPushButton("From file"))//, progress(new QProgressBar)
{

    mainLayout->addWidget(text_label, 0, 0);
    //mainLayout->addWidget(progress, 0 , 1);
    mainLayout->addWidget(text, 1, 0);
    mainLayout->addLayout(right_layout, 1, 1);
    mainLayout->setRowStretch(0, 0);
    mainLayout->setRowStretch(1, 1);

    mainLayout->setColumnStretch(0, 9);
    mainLayout->setColumnStretch(1, 1);
    encode_button->setFont(font);
    from_file->setFont(font);
    text_label->setFont(font);
    this->setLayout(mainLayout);

    right_layout->addWidget(file_name, 0, 0, 1, 0);
    right_layout->addWidget(file_name_edit, 1, 0, 1, 0);
    right_layout->addWidget(path_button, 2, 0, 1, 0);
    right_layout->addWidget(path, 3, 0, 1 , 0);
    right_layout->addWidget(encode_button, 4, 0, 10, 0);
    right_layout->addWidget(from_file, 5, 0, 20, 0);


    right_layout->setRowStretch(0, 0);
    right_layout->setRowStretch(1, 0);
    right_layout->setRowStretch(2, 0);
    right_layout->setRowStretch(3, 0);
    right_layout->setRowStretch(4, 3);

    connect(encode_button, SIGNAL(clicked(bool)), this, SLOT(encode()));
    connect(from_file, SIGNAL(clicked(bool)), this, SLOT(from_file_onclick()));
    connect(path_button, SIGNAL(clicked(bool)), this, SLOT(open_folder()));
}

void Coding::from_file_onclick()
{
    auto path = QFileDialog::getOpenFileName(this, "Enter path to open file", "");
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line = in.readAll();//in.readLine();
    //text->setText(QString(bytes);
    text->setPlainText(line);
    this->update();

}

Coding::~Coding()
{/*
    delete progress;
    prorg*/
    delete from_file;
    from_file = nullptr;
    delete path;
    path = nullptr;
    delete path_button;
    path_button = nullptr;
    delete file_name_edit;
    file_name_edit = nullptr;
    delete file_name;
    file_name = nullptr;
    delete encode_button;
    encode_button = nullptr;
    delete text_label;
    text_label = nullptr;
    delete text;
    text = nullptr;
    delete right_layout;
    right_layout = nullptr;
    delete mainLayout;
    mainLayout = nullptr;
}

void qencode(const QString& text, const QString& path)
{
    auto code = text.toLatin1();
    QByteArray compData = qCompress(code, code.length());
    QFile f(path);
    f.open(QIODevice::WriteOnly);
    QDataStream dstr(&f);
    dstr << compData;
    f.close();
}

void Coding::encode()
{
    QMessageBox msb("Succes!", "Text has been sucessfuly encoded!", QMessageBox::Information, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    try
    {
        //qencode(text->document()->toRawText(), path->text() + ".qcode");
        io_func::write((path->text() + ".huf").toStdString(), text->document()->toRawText().toStdString());
    }
    catch(std::exception& e)
    {
        msb.setText(e.what());
        msb.setIcon(QMessageBox::Warning);
    }
    msb.exec();
}

void Coding::open_folder()
{
    path->setText(QFileDialog::getSaveFileName(this, "Enter path to save file", file_name_edit->text(), ".huf"));
}
