#include "dialog.h"
#include "ui_dialog.h"
#include "BotanCrypt.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->contrasenyaLineEdit->setEchoMode(QLineEdit::Password);
    ui->usuarioNormalRadioButton->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    BotanCrypt k;
    k.setPassword(generaContrasenya());
    k.setSalt(generaContrasenya());
    qDebug() << k.encrypt(ui->usuarioLineEdit->text());
    qDebug() << k.encrypt(ui->contrasenyaLineEdit->text());

    qDebug() << k.decrypt(k.encrypt(ui->usuarioLineEdit->text()));
    qDebug() << k.decrypt(k.encrypt(ui->contrasenyaLineEdit->text()));

   // accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

QString Dialog::generaContrasenya()
{
    QString contrasenya
            = "abcdefg1234567890°!#$%&/()=?¡¿;,.-}{[]+´";
    return contrasenya;
}
