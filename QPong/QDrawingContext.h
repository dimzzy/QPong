#ifndef QPong_QDrawingContext_h
#define QPong_QDrawingContext_h

#include <QtGui/QtGui>
#include "DrawingContext.h"

inline QRectF QRectFromRectangle(Pong::Rectangle rectangle) {
	return QRect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
}

class QDrawingContext : public Pong::DrawingContext {
	
public:
	QDrawingContext(QPainter *painter);
	virtual ~QDrawingContext();
	virtual void setFillColor(Pong::RGBColor const &color);
	virtual void fillRectangle(Pong::Rectangle bounds);
	virtual void fillOval(Pong::Rectangle bounds);
	
private:
	QPainter *_painter;
	QColor _qFillColor;
};

#endif
