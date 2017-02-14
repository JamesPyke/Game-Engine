#pragma once
class InputManager
{
public:

	//Keyboard Manager
	void setKeyState(int key, bool keyState);
	bool isKeyDown(int key);
	bool isKeyClicked(int key);
	void swapKeyStates();

	//Mouse Manager
	void setMouseState(int mouseButton, bool mouseState);
	bool isMouseDown(int mouseButton);
	bool isMouseClicked(int mouseButton);
	void swapMouseStates();

private:

	//Mouse Manager
	bool mouseStates[3];
	bool prevMouseState[3];

	//Keyboard Manager
	bool keyStates[256];
	bool prevKeyState[256];

};

