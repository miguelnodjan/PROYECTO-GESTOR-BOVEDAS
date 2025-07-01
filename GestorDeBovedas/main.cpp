#include <QApplication>
#include "mainwindow.h"
#include "SistemaGestor.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Inicializar sistema
    SistemaGestor sistema;

    // Mostrar ventana principal
    MainWindow w(&sistema);
    w.show();

    return a.exec();
}
