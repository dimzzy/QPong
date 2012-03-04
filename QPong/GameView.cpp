#include <QtGui/QtGui>
#include "QDrawingContext.h"
#include "GameView.h"

GameView::GameView(QWidget *parent) : QWidget(parent) {
	setWindowTitle(tr("QPong"));
	resize(600, 300);
	_game = new Pong::Game(600, 300);
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleGameFrame()));
	timer->start(1000.0 / kGameFPS);	
}

void GameView::handleGameFrame() {
	_game->handleFrame();
	update();
}

void GameView::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);
	QDrawingContext context(&painter);
	_game->draw(context);
	
	painter.setPen(QPen(QColor(200, 200, 200)));
	painter.setFont(QFont("Helvetica", 20, QFont::Bold));
	QString leftScore = QString("%1").arg(_game->leftScore());
	painter.drawText(50, 50, leftScore);
	QString rightScore = QString("%1").arg(_game->rightScore());
	painter.drawText(530, 50, rightScore);
}

void GameView::keyPressEvent(QKeyEvent *event) {
	QString text = event->text();
	if (text.length() > 0) {
		const char c = text.data()[0].toAscii();
		_game->handleKey(c);
	}
}
