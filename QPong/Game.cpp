#include "Game.h"
#include <iostream>

namespace Pong {
	
	Game::Game(float fieldWidth, float fieldHeight) : _leftScore(0), _rightScore(0) {
		_field = new GameField(fieldWidth, fieldHeight);
		_leftPlayer = new HumanPlayer("User", _field->leftPaddle(), 'q', 'a');
		//_leftPlayer = new ComputerPlayer("Computer", _field->leftPaddle());
		_rightPlayer = new ComputerPlayer("Computer", _field->rightPaddle());
	}

	Game::~Game() {
		delete _field;
		delete _leftPlayer;
		delete _rightPlayer;
	}

	void Game::reset() {
		const float fieldWidth = _field->width();
		const float fieldHeight = _field->height();
		delete _field;
		_field = new GameField(fieldWidth, fieldHeight);
		_leftPlayer->setPaddle(_field->leftPaddle());
		_rightPlayer->setPaddle(_field->rightPaddle());
	}

	void Game::handleFrame() {
		_field->moveByFrame();
		_leftPlayer->handleField(_field);
		_rightPlayer->handleField(_field);
		if (_field->ball()->inLeftOut()) {
			_rightScore++;
			reset();
		}
		if (_field->ball()->inRightOut(_field->width())) {
			_leftScore++;
			reset();
		}
	}

	void Game::draw(DrawingContext &context) const {
		_field->draw(context);
	}
	
	void Game::handleKey(const char c) {
		_leftPlayer->handleKey(c);
		_rightPlayer->handleKey(c);
	}

}
