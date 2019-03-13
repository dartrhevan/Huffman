#ifndef DECODING_H
#define DECODING_H

#include <QWidget>
#include <QVBoxLayout>
//#include <QGridLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QToolButton>
#include <QLineEdit>
#include <QLabel>

class Decoding : public QWidget
{
    Q_OBJECT    
    QPlainTextEdit* text;
    QLabel* text_label;
    QPushButton* decode_button;

public:
    explicit Decoding(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // DECODING_H
