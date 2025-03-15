#include "qtimgprocsr.h"

#include <QProcessEnvironment>
#include <QFileDialog>
#include <QMessageBox>

Qtimgprocsr::Qtimgprocsr(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout;
    yourImage = new QLabel;
    image = new QImage;
    buttonHolder = new QHBoxLayout;
    imageHolder = new QHBoxLayout;
    sliderHolder = new QHBoxLayout;
    redSliderHolder = new QVBoxLayout;
    blueSliderHolder = new QVBoxLayout;
    greenSliderHolder = new QVBoxLayout;

    uploadYourImage = new QPushButton("Upload Image");
    saveYourImage = new QPushButton("Save Image");
    redSlider = new QSlider;
    blueSlider = new QSlider;
    greenSlider = new QSlider;


    QLabel *red = new QLabel("Red");
    QLabel *blue = new QLabel("blue");
    QLabel *green = new QLabel("green");




    uploadYourImage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    imageHolder->addWidget(yourImage);
    buttonHolder->addWidget(uploadYourImage);
    imageHolder->insertStretch(0,1);
    imageHolder->insertStretch(2,1);
    buttonHolder->insertStretch(0,1);
    buttonHolder->insertStretch(1,1);
    buttonHolder->insertStretch(3,1);
    redSliderHolder->addWidget(redSlider);
    redSliderHolder->addWidget(red);
    blueSliderHolder->addWidget(blueSlider);
    blueSliderHolder->addWidget(blue);
    greenSliderHolder->addWidget(greenSlider);
    greenSliderHolder->addWidget(green);
    sliderHolder->insertStretch(0,1);
    sliderHolder->addLayout(redSliderHolder);
    sliderHolder->insertStretch(2,1);
    sliderHolder->addLayout(blueSliderHolder);
    sliderHolder->insertStretch(4,1);
    sliderHolder->addLayout(greenSliderHolder);
    sliderHolder->insertStretch(6,1);

    QPixmap pixmap(":/images/upload_img.jpg");
    pixmap = pixmap.scaledToHeight(400);
    yourImage->setPixmap(pixmap);

    //layout->addWidget(uploadImage);
    layout->addLayout(imageHolder);
    layout->addLayout(buttonHolder);
    layout->addLayout(sliderHolder);

    setLayout(layout);

    // connect signals and slots
    QObject::connect(uploadYourImage, SIGNAL(clicked(bool)), this, SLOT(uploadImage()));
    QObject::connect(saveYourImage, SIGNAL(clicked(bool)), this, SLOT(saveImage()));
    QObject::connect(redSlider, SIGNAL(valueChanged(int)), this, SLOT(updateImage()));
    QObject::connect(blueSlider, SIGNAL(valueChanged(int)), this, SLOT(updateImage()));
    QObject::connect(greenSlider, SIGNAL(valueChanged(int)), this, SLOT(updateImage()));

}

Qtimgprocsr::~Qtimgprocsr() {}

void Qtimgprocsr::uploadImage()
{

    QProcessEnvironment  env = QProcessEnvironment::systemEnvironment();
    QString pwd = env.value("PWD");

    fileName = QFileDialog::getOpenFileName(this, tr("Upload Image"),
                                            pwd,
                                            tr("Images (*.png *.jpg *.jpeg *.bmp *.ppm *.xbm *.xpm)"));
    if (fileName != nullptr){
        QPixmap pixmap(fileName);
        pixmap = pixmap.scaledToHeight(400);
        yourImage->setPixmap(pixmap);
        buttonHolder->insertWidget(1,saveYourImage);
        uploadYourImage->setText("Change Image");

        // set slider values
        redSlider->setMaximum(510);
        redSlider->setMinimum(0);
        redSlider->setValue(255);
        blueSlider->setMaximum(510);
        blueSlider->setMinimum(0);
        blueSlider->setValue(255);
        greenSlider->setMaximum(510);
        greenSlider->setMinimum(0);
        greenSlider->setValue(255);

    }
}

void Qtimgprocsr::updateImage()
{
    if (fileName.length() != 0) {
        image->load(fileName);

        int width = image->width();
        int height = image->height();
        int increase;

        for(int y = 0; y < height; ++y){
            for (int x = 0; x < width; ++x) {
                QRgb color = image->pixel(x,y);
                int red = qRed(color);
                int green = qGreen(color);
                int blue = qBlue(color);

                // modify intensities
                increase = redSlider->value() - 255;
                red = increase + red;
                if (red > 255)
                    red = 255;
                else if (red < 0)
                    red = 0;

                increase = blueSlider->value() - 255;
                blue = increase + blue;
                if (blue > 255)
                    blue = 255;
                else if (blue < 0)
                    blue = 0;

                increase = greenSlider->value() - 255;
                green = increase + green;
                if (green > 255)
                    green = 255;
                else if (green < 0)
                    green = 0;


                // set new color
                QRgb newColor = qRgb(red, green, blue);
                image->setPixel(x, y, newColor);

            }
        }

        QPixmap pixmap = QPixmap::fromImage(*image);
        pixmap = pixmap.scaledToHeight(400);
        yourImage->setPixmap(pixmap);
    }
}

void Qtimgprocsr::saveImage()
{
    QProcessEnvironment  env = QProcessEnvironment::systemEnvironment();
    QString pwd = env.value("PWD");

    QString newfileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
                                                       pwd,
                                                       tr("Images (*.png *.jpeg *.jpg *.bmp *.ppm *.xbm *xpm)"));
    if (newfileName != nullptr) {
        QFileInfo fiName(newfileName);
        QString ext = fiName.completeSuffix();
        if( ext != nullptr){
            if (ext == "png" || ext == "jpeg" || ext == "jpg" || ext == "bmp" || ext == "ppm" || ext == "xbm" || ext == "xpm"){
                image->save(newfileName);
            }
            else{
                QMessageBox msgBox;
                msgBox.setText( ext + " is not supported. May be because it's wrong extension or Qt doesnot supports the"
                                     " images with that extension");
                msgBox.exec();
            }
        }
        else {
            newfileName = newfileName + ".png";
            image->save(newfileName);
        }
    }
}
