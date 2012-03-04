#include "GameObject.h"

namespace Pong {
	
	Rectangle GameObject::boundsInFrame(float fieldWidth, float fieldHeight) const {
		GameObject *futureObject = clone();
		futureObject->moveByFrame(fieldWidth, fieldHeight);
		Rectangle r = bounds().enclosingRectangle(futureObject->bounds());
		delete futureObject;
		return r;
	}

}
