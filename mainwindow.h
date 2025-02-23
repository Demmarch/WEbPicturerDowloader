#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QVector>
#include <QNetworkRequest>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void SendRequest();
    void prossesReply(QNetworkReply *reply);
    void ShowNextImage();
    void ShowPreviousImage();
    void DownloadCurrentImage();

private:
    int currentIndex;
    QNetworkAccessManager *networkManager;
    QVector<QUrl> imagesUrl;
    void showImage();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
