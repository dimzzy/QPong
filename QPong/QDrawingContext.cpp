#import "QDrawingContext.h"

QDrawingContext::QDrawingContext(QPainter *painter) : _qFillColor(0, 0, 0) {
	_painter = painter;
}

QDrawingContext::~QDrawingContext() {
}

void QDrawingContext::setFillColor(Pong::RGBColor const &color) {
	DrawingContext::setFillColor(color);
	_qFillColor = QColor(color.red * 255, color.green * 255, color.blue * 255);
}

void QDrawingContext::fillRectangle(Pong::Rectangle bounds) {
	_painter->setBrush(_qFillColor);
	QRectF qbounds = QRectFromRectangle(bounds);
	_painter->drawRect(qbounds);
}

void QDrawingContext::fillOval(Pong::Rectangle bounds) {
	_painter->setBrush(_qFillColor);
	QRectF qbounds = QRectFromRectangle(bounds);
	_painter->drawEllipse(qbounds);
}
