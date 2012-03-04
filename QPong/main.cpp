#include <QtGui/QtGui>
#include "GameView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
	GameView gameView;
	gameView.show();
	return app.exec();
}
