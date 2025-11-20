#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLabel>
#include <QLineEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMediaPlayer* player = nullptr;

    QLineEdit* filePathField = nullptr;
    QPushButton* loadButton = nullptr;

    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;

    QLabel* playerStatusDisplay = nullptr;

private slots:
    void loadButtonPressed();
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
};
#endif // MAINWINDOW_H
