// #include "loginwindow.h"
// #include "ui_loginwindow.h"

// LoginWindow::LoginWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::LoginWindow)
// {
//     ui->setupUi(this);
//     ui->errorMsg->setVisible(false);
//     ui->passwordLE->setEchoMode(QLineEdit::Password);
// }

// LoginWindow::~LoginWindow()
// {
//     delete ui;
// }


// void LoginWindow::on_pushButton_clicked()
// {
//     QString user = ui->usernameLE->text();
//     QString pass = ui->passwordLE->text();
//     if(user == "" || pass == ""){
//         ui->errorMsg->setVsible(true);
//         return;
//     }
//     bool found = false;
//     for(int i = 0; i < 5; i++){
//         if(user == username[i]){
//             if(pass == passwords[i]){
//                 found = true;
//             }
//         }
//     }
//     if(found){
//         hide();
//         MainMenu *menu = new MainMenu();
//     }
//     else {
//         ui->errorMsg->setVisible(true);
//         return;
//     }
// }
