#ifndef XPong_GameField_h
#define XPong_GameField_h

#include "Ball.h"
#include "Paddle.h"

namespace Pong {
	
	const float kBallSize = 20.0;
	const float kPaddleWidth = 10.0;
	const float kPaddleHeight = 60.0;
	
	class GameField : public Drawable {
		
	public:
		GameField(float width, float height);
		~GameField();

		// Moves all game objects by frame
		void moveByFrame();

		virtual void draw(DrawingContext &context) const;

		float width() const { return _width; }
		float height() const { return _height; }
		Ball *ball() const { return _ball; }
		Paddle *leftPaddle() const { return _leftPaddle; }
		Paddle *rightPaddle() const { return _rightPaddle; }
		
	private:
		float _width;
		float _height;
		Ball *_ball;
		Paddle *_leftPaddle;
		Paddle *_rightPaddle;
	};
}

#endif
