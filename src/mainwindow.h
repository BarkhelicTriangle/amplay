#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>

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
    QToolButton* fileDialogButton = nullptr;

    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;

    QLabel* playerStatusDisplay = nullptr;

private slots:
    void presentPlayerSourceFileDialog();
    void updatePlayerSource();
    void updatePlayerStatusDisplay(QMediaPlayer::MediaStatus status);
};
#endif // MAINWINDOW_H
