#ifndef CODING_H
#define CODING_H

#include <QWidget>
//#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>


class Coding : public QWidget
{
    Q_OBJECT
    QGridLayout* mainLayout;
    QPlainTextEdit* text;
    QLabel* text_label;
    QPushButton* encode_button;
    QGridLayout* right_layout;

    QFont font;
    QLabel* file_name;
    QLineEdit* file_name_edit;
    QPushButton* path_button;
    QLabel* path;

public:
    explicit Coding(QWidget *parent = nullptr);
    ~Coding();
signals:

public slots:
    void encode();
    void open_folder();
};

#endif // CODING_H
