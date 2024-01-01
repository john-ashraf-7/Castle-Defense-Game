#include "cannon.h"


Cannon::Cannon(QGraphicsScene *main_scene, qreal x_initial, qreal y_initial, QString cannonpath, QString shootpath, int shootdelayms, int bulletdamage, int bulletspeed, QString bulletpath)
{
    //initialize the the image, scale, position of the cannon.
    this -> main_scene = main_scene;
    this -> x_initial = x_initial;
    this -> y_initial = y_initial;
    this -> bulletdamage = bulletdamage;
    this -> bulletspeed = bulletspeed;
    this -> bulletpath = bulletpath;
    this-> shootpath = shootpath;

    main_scene->addItem(this);//adding the cannon to the scene.
    setPos(x_initial,y_initial);

    QPixmap cannon(cannonpath);
    cannon = cannon.scaled(70,70);
    setPixmap(cannon);

    //this timer is responsible for spawning a new bullet every second.
    QObject::connect(&timer,&QTimer::timeout,this,&Cannon::spawnBullet);
    timer.start(shootdelayms);
}

Cannon::~Cannon()
{
    QObject::disconnect(&timer,&QTimer::timeout,this,&Cannon::spawnBullet);
    delete bullet;
}

//in the spawn function we initialzie a new bullet every one second(it seems like the cannon is autoshooting a bullet).
void Cannon::spawnBullet()
{
    // shooting soundeffect
    shootoutput = new QAudioOutput();
    shootoutput->setVolume(20);
    shoot = new QMediaPlayer();
    shoot->setAudioOutput(shootoutput);
    shoot->setSource(QUrl(shootpath)); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
    shoot->stop();
    shoot->play();

    //spawn bullet and set its position to cannon's position.
    bullet = new Bullet(main_scene,x_initial,y_initial, bulletdamage, bulletspeed, bulletpath);
    bullet->setPos(x(), y());
    scene()->addItem(bullet);

    //QTimer for moving bullets and connect it to the  akemove function of the bullet.
    QObject::connect(&bulletmovetimer,&QTimer::timeout,bullet,&Bullet::makeMove);
    bulletmovetimer.start(25); //timer for moving bullets. QT GLITCH :- IF WE DECREASE MILLISECONDS TO A VERY LOW VALUE LIKE 5, A GLITCH HAPPENS WITH THE SPEED AFTER A FEW SECONDS WHILE THE PROGRAM IS RUNNING.

}

