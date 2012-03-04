#ifndef XPong_Player_h
#define XPong_Player_h

#include <string>
#include "GameField.h"
#include "InputHandler.h"

namespace Pong {
	
	using std::string;
	
	class Player : public InputHandler {
		
	public:
		Player(string const &name, Paddle *paddle) : _name(name), _paddle(paddle) {}
		virtual ~Player() {}
		
		string const &name() { return _name; }
		void setName(string const &name) { _name = name; }

		// Process ball movements
		virtual void handleField(GameField const *field) = 0;
		
		Paddle *paddle() { return _paddle; }
		void setPaddle(Paddle *paddle) { _paddle = paddle; }
		
	private:
		string _name;
		Paddle *_paddle; // not owned
	};
	
}

#endif
