#include "InputManager.h"
#include <stdio.h>

void InputManager::setKeyState(int key, bool keyState)
{
//	printf("Key %d is down, it's state is now: %s\n", key, keyState ? "True" : "False");
	keyStates[keyState] = keyState;
}

bool InputManager::isKeyDown(int key)
{
	return keyStates[key];
}

bool InputManager::isKeyClicked(int key)
{
	return keyStates[key] && !prevKeyState[key];
}

void InputManager::swapKeyStates()
{
	for (int i = 0; i < 256; i++)
	{
		prevKeyState[i] = keyStates[i];
	}
}

void InputManager::setMouseState(int mouseButton, bool mouseState)
{
//	printf("Button %d's state is now: %s\n", mouseButton, mouseState ? "True" : "False");
	mouseStates[mouseButton] = mouseState;
}

bool InputManager::isMouseDown(int mouseButton)
{
	return mouseStates[mouseButton];
}

bool InputManager::isMouseClicked(int mouseButton)
{
	return mouseStates[mouseButton] && !prevMouseState[mouseButton];
}

void InputManager::swapMouseStates()
{
	for (int i = 0; i < 3; i++)
	{
		prevMouseState[i] = mouseStates[i];
	}
}

