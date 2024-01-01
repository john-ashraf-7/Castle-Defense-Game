#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "market.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButtonstart_clicked();

    void on_pushButtonexit_clicked();

    void on_pushButtonmanual_clicked();

    void on_pushButtoncredits_clicked();

private:
    Ui::MainMenu *ui;
    QAudioOutput *menuthemeoutput;
    QMediaPlayer *menutheme;
};

#endif // MAINMENU_H
