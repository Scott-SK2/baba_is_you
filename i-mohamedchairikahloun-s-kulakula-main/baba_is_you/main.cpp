#include <QApplication>
#include "./view/gui/app_gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view_gui::App_Gui app;

    app.start_game();

    return a.exec();
}
