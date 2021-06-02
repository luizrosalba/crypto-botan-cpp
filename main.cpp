#include "dialog.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle("fusion");
    Dialog login;
    if (login.exec() == QDialog::Rejected) {
        return -1;
    }
    return a.exec();
}
