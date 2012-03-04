#include <vector>
#include "GameField.h"

namespace Pong {
	
	GameField::GameField(float width, float height) : _width(width), _height(height) {
		_ball = new Ball(Rectangle(width / 2, height / 2, kBallSize, kBallSize));
		_ball->setAngle(M_PI_4 / 2);
		_leftPaddle = new Paddle(Rectangle(0, height / 4 - kPaddleHeight / 2, kPaddleWidth, kPaddleHeight));
		_rightPaddle = new Paddle(Rectangle(width - kPaddleWidth, 3 * height / 4 - kPaddleHeight / 2, kPaddleWidth, kPaddleHeight));
	}

	GameField::~GameField() {
		delete _ball;
		delete _leftPaddle;
		delete _rightPaddle;
	}
	
	void GameField::moveByFrame() {
		_ball->moveByFrame(_width, _height,
						   _leftPaddle->boundsInFrame(_width, _height),
						   _rightPaddle->boundsInFrame(_width, _height));
		_leftPaddle->moveByFrame(_width, _height);
		_rightPaddle->moveByFrame(_width, _height);
	}

	void GameField::draw(DrawingContext &context) const {
		context.setFillColor(RGBColor(1));
		context.fillRectangle(Rectangle(0, 0, width(), height()));
		ball()->draw(context);
		leftPaddle()->draw(context);
		rightPaddle()->draw(context);
	}
}
