#ifndef XPong_Ball_h
#define XPong_Ball_h

#include "GameObject.h"

namespace Pong {

	const float kBallSpeed = 4.0;
	
	class Ball : public GameObject {
		
	public:
		Ball(Rectangle const &bounds, float speed = kBallSpeed, float angle = 0) :
		GameObject(bounds, speed), _angle(angle) {}
		
		Ball(Ball const &ball) : GameObject(ball), _angle(ball._angle) {}

		virtual GameObject *clone() const;

		float angle() const { return _angle; }
		void setAngle(float angle);
		
		// Move the ball within the game field bounds
		void moveByFrame(float fieldWidth, float fieldHeight);

		// Move the ball within the game field bounds and bounce from paddles
		void moveByFrame(float fieldWidth, float fieldHeight,
						 Rectangle const &leftPaddleBounds,
						 Rectangle const &rightPaddleBounds);
		
		bool inLeftOut() { return bounds().x < 0; }
		bool inRightOut(float fieldWidth) { return bounds().right() >= fieldWidth; }
		
		virtual void draw(DrawingContext &context) const;
		
	private:
		float _angle; // rad; 0 means east, PI/2 means south
		
		void bounceAngle();
	};
	
}

#endif
