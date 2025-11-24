#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include "player.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QQueue>

class PlayerWindow : public QWidget
{
    Q_OBJECT

public:
    PlayerWindow(QWidget *parent = nullptr);
    ~PlayerWindow();

private:
    Player* basePlayer;
/* Consolidate into PlayerControls
    QPushButton* playlistAddButton = nullptr;
    QPushButton* playButton = nullptr;
    QPushButton* pauseButton = nullptr;
*/

/*    Consolidate into MetadataInfo
 *    QLabel* metadataTextDisplay = nullptr; */

private slots:
    void updatePlaylistFromFileDialog();
    void updateMetadataTextDisplay(QMediaPlayer::MediaStatus status);
};
#endif // PLAYERWINDOW_H
