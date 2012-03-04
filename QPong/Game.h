#ifndef XPong_Game_h
#define XPong_Game_h

#include "GameField.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

namespace Pong {
	
	class Game : public Drawable, public InputHandler {
		
	public:
		Game(float fieldWidth, float fieldHeight);
		~Game();
		
		// Process game frame
		void handleFrame();

		virtual void draw(DrawingContext &context) const;
		virtual void handleKey(const char c);
		
		unsigned leftScore() const { return _leftScore; }
		unsigned rightScore() const { return _rightScore; }
		
	private:
		GameField *_field;
		Player *_leftPlayer;
		Player *_rightPlayer;
		unsigned _leftScore;
		unsigned _rightScore;
		
		void reset();
	};
	
}

#endif
