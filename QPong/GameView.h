#ifndef QPong_GameView_h
#define QPong_GameView_h

#include <QtGui/QtGui>
#include "Game.h"

const float kGameFPS = 60.0;

class GameView : public QWidget {
	Q_OBJECT
	
public:
	GameView(QWidget *parent = 0);
	
protected:
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	
private slots:
	void handleGameFrame();
	
private:
	Pong::Game *_game;
};

#endif
