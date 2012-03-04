#ifndef XPong_ComputerPlayer_h
#define XPong_ComputerPlayer_h

#include "Player.h"

namespace Pong {
	
	class ComputerPlayer : public Player {
		
	public:
		ComputerPlayer(string const &name, Paddle *paddle) : Player(name, paddle) {}
		
		virtual void handleKey(const char c) {}
		virtual void handleField(GameField const *field);
	};
	
}

#endif
