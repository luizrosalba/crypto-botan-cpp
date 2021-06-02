#include "dialog.h"
#include "ui_dialog.h"
#include "DuCrypt.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->contrasenyaLineEdit->setEchoMode(QLineEdit::Password);
    compruebaAdmin();
    ui->usuarioNormalRadioButton->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    DuCrypt k;
    k.setPassword(generaContrasenya());
    k.setSalt(generaContrasenya());
    qDebug() << k.encrypt(ui->usuarioLineEdit->text());
    qDebug() << k.encrypt(ui->contrasenyaLineEdit->text());

    qDebug() << k.decrypt(k.encrypt(ui->usuarioLineEdit->text()));
    qDebug() << k.decrypt(k.encrypt(ui->usuarioLineEdit->text()));

   // accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}



void Dialog::compruebaAdmin()
{
    QSqlQuery q;
    q.exec("SELECT count(*) FROM administrador");
    q.next();
    const int cantidadAdmins = q.value(0).toInt();
    if (cantidadAdmins == 0) {
        ui->registrarAdminPushButton->setEnabled(true);
    } else {
        ui->registrarAdminPushButton->setEnabled(false);
    }
}

QString Dialog::generaContrasenya()
{
    QString contrasenya
            = "abcdefg1234567890°!#$%&/()=?¡¿;,.-}{[]+´";
    return contrasenya;
}
