#ifndef XPong_GameObject_h
#define XPong_GameObject_h

#include "Drawable.h"
#include "Geometry.h"

namespace Pong {
	
	// Base class for objects that are placed on the game field
	class GameObject : public Drawable {
		
	public:
		GameObject(Rectangle const &bounds, float speed = 0) :
		_bounds(bounds), _speed(speed) {}
		
		GameObject(GameObject const &gameObject) :
		_bounds(gameObject._bounds), _speed(gameObject._speed) {}
		
		virtual ~GameObject() {}

		// Makes a copy of the object
		virtual GameObject *clone() const = 0;
		
		float speed() const { return _speed; }
		void setSpeed(float speed) { _speed = speed; }

		// Move the object within the game field bounds
		virtual void moveByFrame(float fieldWidth, float fieldHeight) = 0;
		
		// Returns area which the object could occupy between this and the next frames
		Rectangle boundsInFrame(float fieldWidth, float fieldHeight) const;

		Rectangle const &bounds() const { return _bounds; }
		
	protected:
		Rectangle &bounds() { return _bounds; }
		
	private:
		Rectangle _bounds;
		float _speed; // pixels per frame
	};
	
}

#endif
