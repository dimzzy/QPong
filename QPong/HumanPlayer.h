#ifndef XPong_HumanPlayer_h
#define XPong_HumanPlayer_h

#include "Player.h"

namespace Pong {
	
	class HumanPlayer : public Player {
		
	public:
		HumanPlayer(string const &name, Paddle *paddle, char upChar, char downChar) :
		Player(name, paddle), _upChar(upChar), _downChar(downChar) {}
		
		virtual void handleKey(const char c);
		virtual void handleField(GameField const *field) {}

	private:
		char _upChar;
		char _downChar;
	};
	
}

#endif
