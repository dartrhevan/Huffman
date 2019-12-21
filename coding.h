#ifndef CODING
#define CODING


#include <QWidget>
//#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include <QDataStream>
#include <QByteArray>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QProgressBar>

#include "io_func.h"


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

    QPushButton* from_file;
    //QProgressBar* progress;
public:
    explicit Coding(QWidget *parent = nullptr);
    ~Coding();
signals:

public slots:
    void from_file_onclick();
    void encode();
    void open_folder();
};

#endif // CODING_H
