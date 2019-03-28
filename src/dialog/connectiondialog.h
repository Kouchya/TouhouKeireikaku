#ifndef _CONNECTION_DIALOG_H
#define _CONNECTION_DIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QComboBox>
#include <QButtonGroup>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class UdpDetector;

namespace Ui
{
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    ConnectionDialog(QWidget *parent);
    ~ConnectionDialog();
    void hideAvatarList();
    void showAvatarList();

private:
    Ui::ConnectionDialog *ui;

private slots:
    void on_detectLANButton_clicked();
    void on_clearHistoryButton_clicked();
    void on_connectButton_clicked();
};

class UdpDetectorDialog : public QDialog
{
    Q_OBJECT

public:
    UdpDetectorDialog(QDialog *parent);

private:
    QListWidget *list;
    UdpDetector *detector;
    QPushButton *detect_button;

private slots:
    void startDetection();
    void stopDetection();
    void chooseAddress(QListWidgetItem *item);
    void addServerAddress(const QString &server_name, const QString &address);

signals:
    void address_chosen(const QString &address);
};

#endif

