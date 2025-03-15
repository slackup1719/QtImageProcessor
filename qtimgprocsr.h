#ifndef QTIMGPROCSR_H
#define QTIMGPROCSR_H

#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>

class Qtimgprocsr : public QWidget
{
    Q_OBJECT

public:
    Qtimgprocsr(QWidget *parent = nullptr);
    ~Qtimgprocsr();

private:
    QVBoxLayout *layout ;
    QLabel *yourImage;
    QImage *image;
    QPushButton *uploadYourImage;
    QPushButton *saveYourImage;
    QHBoxLayout *imageHolder;
    QHBoxLayout *buttonHolder;
    QHBoxLayout *sliderHolder;
    QVBoxLayout *redSliderHolder;
    QVBoxLayout *blueSliderHolder;
    QVBoxLayout *greenSliderHolder;
    QVBoxLayout *alphaSliderHolder;

    QSlider *redSlider;
    QSlider *greenSlider;
    QSlider *blueSlider;
    QString fileName;

private slots:
    void uploadImage();
    void updateImage();
    void saveImage();

};

#endif // QTIMGPROCSR_H
