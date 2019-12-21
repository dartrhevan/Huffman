#ifndef DECODING
#define DECODING

#include <QWidget>
//#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>

#include "io_func.h"


class Decoding : public QWidget
{
    Q_OBJECT
    QGridLayout* mainLayout;
    QTextEdit* text;
    QLabel* text_label;
    QPushButton* decode_button;
    QGridLayout* right_layout;

    QFont font;
    //QLabel* file_name;
    //QLineEdit* file_name_edit;
    QPushButton* path_button;
    QLabel* path;

public:
    explicit Decoding(QWidget *parent = nullptr);
    ~Decoding();
signals:

public slots:
    void decode();
    void open_folder();
};

#endif
