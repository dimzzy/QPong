#ifndef XPong_Paddle_h
#define XPong_Paddle_h

#include "GameObject.h"

namespace Pong {

	const float kPaddleSpeed = 2.0;
	
	class Paddle : public GameObject {
		
	public:
		Paddle(Rectangle const &bounds, float speed = 0) : GameObject(bounds, speed) {}
		
		Paddle(Paddle const &paddle) : GameObject(paddle) {}

		virtual GameObject *clone() const;
		
		// Move the paddle within the game field bounds
		void moveByFrame(float fieldWidth, float fieldHeight);
		
		virtual void draw(DrawingContext &context) const;
	};
	
}

#endif
