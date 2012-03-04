#include "HumanPlayer.h"

namespace Pong {

	void HumanPlayer::handleKey(const char c) {
		if (c == _upChar) {
			if (paddle()->speed() > 0) {
				paddle()->setSpeed(0);
			} else {
				paddle()->setSpeed(-kPaddleSpeed);
			}
		} else if (c == _downChar) {
			if (paddle()->speed() < 0) {
				paddle()->setSpeed(0);
			} else {
				paddle()->setSpeed(kPaddleSpeed);
			}
		}
	}

}
