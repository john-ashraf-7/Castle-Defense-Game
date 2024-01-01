#include "bullet.h"


Bullet::Bullet(QGraphicsScene *main_scene, qreal x_initial, qreal y_initial, int damage, int speed, QString bulletpath)
{
    //initializations
    this -> damage = damage;
    this -> main_scene = main_scene;
    this -> speed = speed;
    this -> x_initial = x_initial;
    this -> y_initial = y_initial;

    QPixmap bullet(bulletpath);
    bullet = bullet.scaled(30,30);
    setPixmap(bullet);

    //Euclidean distance equation for bullet movement. (start position + unit vector*constant which is the increment value)
    float distance = qSqrt(qPow(getMousePosition().x()-x_initial,2)+qPow(getMousePosition().y()-y_initial,2));//calculates the distance between the mouse cursor and the initial position
    increment_x=((getMousePosition().x()-x_initial)/(distance))*4*speed; //the increment value and the equation inside must be float because if the factor is too high, it will round to zero and thus, not move.
    increment_y=((getMousePosition().y()-y_initial)/(distance))*4*speed;
}

QPoint Bullet::getMousePosition() {
    return QCursor::pos();
}

int Bullet::getDamage()
{
    return damage;
}

void Bullet::setDamage(int damage)
{
    this -> damage = damage;
}

void Bullet::makeMove()
{
    if (pos().x() > 0 && pos().y() > 0 && pos().x()+25 < scene()->sceneRect().right() && pos().y()+25 < scene()->sceneRect().bottom())//checks if the bullet is within the scene.
    {
       setPos(x()+increment_x, y()+increment_y);//setting the position of the based on the calculated increment variables(this is the line responsbile for the bullet movement).
    }
    else
    {
       scene()->removeItem(this);//when the bullet gets out the scene it is removed in order to prevent the expansion of the scene.
       delete this;
    }

}
