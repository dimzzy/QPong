#include "Ball.h"
#include <cmath>
#include <iostream>

namespace Pong {

	GameObject *Ball::clone() const {
		return new Ball(*this);
	}
	
	void Ball::setAngle(float angle) {
		_angle = fmodf(angle, 2 * M_PI);
	}

	void Ball::bounceAngle() {
		const float deviation = (float)((random() % 200) - 100) / 1000.0 * M_PI;
		float angle = fmodf(_angle + M_PI + deviation, 2 * M_PI);
		if (angle == 0 ||
			abs(angle) == M_PI_2 ||
			abs(angle) == M_PI ||
			abs(angle) == M_PI + M_PI_2)
		{
			angle += 0.05;
		}
		_angle = angle;
	}

	void Ball::moveByFrame(float fieldWidth, float fieldHeight) {
		const float dx = speed() * cos(angle());
		const float dy = speed() * sin(angle());
		bounds().x += dx;
		bounds().y += dy;
		
		// Bounce from the top and bottom edges
		if (bounds().y < 0) {
			bounds().y = -bounds().y;
			setAngle(-angle());
		} else if (bounds().bottom() > fieldHeight) {
			const float bottom = (fieldHeight - bounds().height);
			bounds().y = bottom - (bounds().y - bottom);
			setAngle(-angle());
		}
	}
	
	void Ball::moveByFrame(float fieldWidth, float fieldHeight,
						   Rectangle const &leftPaddleBounds,
						   Rectangle const &rightPaddleBounds)
	{
		Rectangle ballBounds = boundsInFrame(fieldWidth, fieldHeight);
		moveByFrame(fieldWidth, fieldHeight);
		
		// Bounce from the paddles
		// Logic is imprecise and based on assumption that ball does not move much within a frame
		// 
		// Basically if during the frame rectangle enclosing ball positions intersects with
		// rectangle enclosing a paddle positions then ball should bounce from it
		if (ballBounds.intersectsRectangle(leftPaddleBounds)) {
			float dx = bounds().x - leftPaddleBounds.width;
			bounds().x = leftPaddleBounds.width - dx;
			bounceAngle();
		}
		if (ballBounds.intersectsRectangle(rightPaddleBounds)) {
			const float rightX = fieldWidth - leftPaddleBounds.width - bounds().width;
			float dx = bounds().x - rightX;
			bounds().x = rightX - dx;
			bounceAngle();
		}
	}
	
	void Ball::draw(DrawingContext &context) const {
		context.setFillColor(RGBColor(0.4));
		context.fillOval(bounds());
	}

}
