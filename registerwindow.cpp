#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->errorMsg->setVisible(false);
    ui->labelMadeAcc->setVisible(false);
    ui->passwordLE->setEchoMode(QLineEdit::Password);
    username.push_back("admin");
    passwords.push_back("admin");
    username.push_back("john");
    passwords.push_back("123");
    username.push_back("omar");
    passwords.push_back("123");
    username.push_back("tony");
    passwords.push_back("123");

    registeroutput = new QAudioOutput();
    registeroutput->setVolume(1);
    registersound = new QMediaPlayer();
    registersound->setAudioOutput(registeroutput);
    registersound->setSource(QUrl("qrc:/sound/Sound/login.mp3")); //after QUrl we add ::fromLocalFile(//path) if we want to add music from a local path rather than resource file
    registersound->play();

    QPixmap pix (":/images/textures/login.jpg");
    int w = ui->labelpix->width();
    int h = ui->labelpix->height();
    ui->labelpix->setPixmap(pix.scaled(w,h));

    ui->pushButton->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: transparent; color: white; } QPushButton:hover { background-color: rgba(0, 0, 0, 20%); }");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(QColor(0, 0, 0, 180));
    shadow->setOffset(0, 0);
    ui->pushButton->setGraphicsEffect(shadow);
    ui->pushButton_2->setGraphicsEffect(shadow);
    ui->usernameLE->setStyleSheet("QLineEdit {"
                                  "background-color: darkgray;"
                                  "border: 1px solid darkgray;"
                                  "border-radius: 5px;"
                                  "padding: 0 8px;"
                                  "selection-background-color: darkgray;"
                                  "}");
    ui->passwordLE->setStyleSheet("QLineEdit {"
                                  "background-color: darkgray;"
                                  "border: 1px solid gray;"
                                  "border-radius: 5px;"
                                  "padding: 0 8px;"
                                  "selection-background-color: darkgray;"
                                  "}");
    ui->passwordLE->setEchoMode(QLineEdit::Password);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked() //login
{
    QString user = ui->usernameLE->text();
    QString pass = ui->passwordLE->text();
    if(user == "" || pass == ""){
        ui->errorMsg->setVisible(true);
        return;
    }
    bool found = false;
    for(int i = 0; i < username.size(); i++){
        if(user == username[i]){
            if(pass == passwords[i]){
                found = true;
            }
        }
    }
    if(found){
        hide();
        registersound->stop();
        MainMenu *menu = new MainMenu();
        menu->show();
    }
    else {
        ui->errorMsg->setVisible(true);
        delay(1);
        ui->errorMsg->setVisible(false);
        return;
    }
}

void RegisterWindow::delay(int sec)
{
    QTime dieTime=  QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}


void RegisterWindow::on_pushButton_2_clicked() //register
{
    bool AlreadyExists = false;
    QString user = ui->usernameLE->text();
    QString pass = ui->passwordLE->text();
    if(user == "" || pass == ""){
        ui->errorMsg->setVisible(true);
        return;
    }
    for(int i = 0; i < username.size(); i++){
        if(user == username[i]){
            AlreadyExists=true;
        }
    }
    if(AlreadyExists)
    {
        ui->errorMsg->setVisible(true);
        delay(1);
        ui->errorMsg->setVisible(false);
    }
    else
    {
        ui->labelMadeAcc->setVisible(true);
        ui->errorMsg->setVisible(false);
        //delay
        username.push_back(user);
        passwords.push_back(pass);
        delay(1);
        ui->labelMadeAcc->setVisible(false);

    }

}

