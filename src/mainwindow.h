#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLineEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit* filepath_field = nullptr;
    QPushButton* load_button = nullptr;

    QPushButton* play_button = nullptr;
    QPushButton* pause_button = nullptr;

    QMediaPlayer* player = nullptr;

private slots:
    void loadButtonPressed();
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
};
#endif // MAINWINDOW_H
