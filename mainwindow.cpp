#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(ui->pushButtonBack, &QPushButton::clicked, this, &MainWindow::ShowPreviousImage);
    connect(ui->pushButtonDownloadImage, &QPushButton::clicked, this, &MainWindow::DownloadCurrentImage);
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &MainWindow::ShowNextImage);
    connect(ui->pushButtonSendRequest, &QPushButton::clicked, this, &MainWindow::SendRequest);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::prossesReply);
}

void MainWindow::SendRequest()
{
    try
    {
        QString textUrl = ui->lineEditWebAddres->text();
        QUrl url(textUrl);
        if(!url.isValid())
        {
            throw std::runtime_error("Invalid URL");
        }
        networkManager->get(QNetworkRequest(url));
    }

    catch(const std::exception e)
    {
        QMessageBox::critical(this, "Ошибка", e.what());
    }

    catch(...)
    {
        QMessageBox::warning(this, "Ошибка", "Неизвестная ошибка");
    }
}

void MainWindow::prossesReply(QNetworkReply *reply)
{
    try {
        if(reply->error() == QNetworkReply::NoError) {
            QString html = reply->readAll();
            QRegularExpression regex("<img[^>]+src=\"([^\">]+)\"");
            QRegularExpressionMatchIterator matches = regex.globalMatch(html);
            imagesUrl.clear();
            while(matches.hasNext()) {
                QRegularExpressionMatch match = matches.next();
                QString imageUrl = match.captured(1);
                imagesUrl.append(QUrl(imageUrl));
            }
            if(!imagesUrl.isEmpty()) {
                currentIndex = 0;
                showImage();
            }
        }
        else {
            throw std::runtime_error(reply->errorString().toStdString());
        }
    }
    catch(const std::exception e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
    reply->deleteLater();
}

void MainWindow::ShowPreviousImage()
{
    try {
        if(currentIndex > 0) {
            currentIndex--;
            showImage();
        }
    }
    catch(std::exception e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void MainWindow::ShowNextImage()
{
    try {
        if(currentIndex < imagesUrl.length() - 1) {
            currentIndex++;
            showImage();
        }
    }
    catch(std::exception e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void MainWindow::showImage()
{
    try {
        if (currentIndex >= 0 && currentIndex < imagesUrl.length()) {
            QUrl imageurl = imagesUrl[currentIndex];
            QNetworkReply *reply = networkManager->get(QNetworkRequest(imageurl));
            connect(reply, &QNetworkReply::finished, [reply, this]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QByteArray imageData = reply->readAll();
                    QImage image;
                    if (image.loadFromData(imageData)) {
                        ui->labelImage->setPixmap(QPixmap::fromImage(image));
                    }
                }
                reply->deleteLater();
            });
        }
    }
    catch(const std::exception e){
        QMessageBox::critical(this, "Ошибка", e.what());
    }

}

void MainWindow::DownloadCurrentImage()
{
    try {
        if (currentIndex >= 0 && currentIndex < imagesUrl.length()) {
            QUrl imageurl = imagesUrl[currentIndex];
            QNetworkReply *reply = networkManager->get(QNetworkRequest(imageurl));
            connect(reply, &QNetworkReply::finished, [reply, this]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QByteArray imageData = reply->readAll();
                    QImage image;
                    if (image.loadFromData(imageData)) {
                        QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg *.bmp)");
                        if (!fileName.isEmpty()) {
                            image.save(fileName);
                        }
                    }
                }
                reply->deleteLater();
            });
        }
    }
    catch(const std::exception e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
