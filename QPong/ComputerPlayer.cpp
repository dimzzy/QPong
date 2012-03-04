#include "ComputerPlayer.h"

namespace Pong {
	
	// Rather simple logic for the computer:
	// It does not calculate where the ball is coming to but just follows it
	// Turns out it mostly works and because ball is faster than
	// paddles there is a chance for computer to loose
	void ComputerPlayer::handleField(GameField const *field) {
		Ball const *ball = field->ball();
		Point ballCenterPoint = ball->bounds().center();
		Point paddleCenterPoint = ((Paddle const *)paddle())->bounds().center();
		if (ballCenterPoint.y < paddleCenterPoint.y) {
			paddle()->setSpeed(-kPaddleSpeed);
		} else if (ballCenterPoint.y > paddleCenterPoint.y) {
			paddle()->setSpeed(kPaddleSpeed);
		} else {
			paddle()->setSpeed(0);
		}
	}

}
