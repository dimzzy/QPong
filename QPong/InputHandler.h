#ifndef XPong_InputHandler_h
#define XPong_InputHandler_h

namespace Pong {
	
	// Interface of an object that could handle user input
	class InputHandler {
		
	public:
		virtual ~InputHandler() {}
		virtual void handleKey(const char c) = 0;
	};
	
}

#endif
