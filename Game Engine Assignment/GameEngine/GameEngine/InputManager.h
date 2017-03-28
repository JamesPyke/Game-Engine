#pragma once
class InputManager
{
public:

	/**
	 * \brief Get the current state of a key
	 * \param int key 
	 * \param bool keyState 
	 */
	void setKeyState(int key, bool keyState);
	/**
	 * \brief Check if a key if down
	 * \param int key 
	 * \return Returns a true or false value based on whether the key is down or up 
	 */
	bool isKeyDown(int key);
	/**
	 * \brief Check if a key is clicked
	 * \param int key 
	 * \return Returns a true or false value on whether the key clicked
	 */
	bool isKeyClicked(int key);
	/**
	 * \brief Swaps the key states so a key can not be detected mulitple times
	 */
	void swapKeyStates();

	/**
	 * \brief Get the current state of the mouse
	 * \param int mouseButton 
	 * \param bool mouseState 
	 */
	void setMouseState(int mouseButton, bool mouseState);
	/**
	 * \brief Check if the mouse buttons are down
	 * \param int mouseButton 
	 * \return Return a true or false value based on whether the mouse button is up or down
	 */
	bool isMouseDown(int mouseButton);
	/**
	 * \brief Check if the mouse button has been clicked
	 * \param int mouseButton 
	 * \return Return a true or false value based on whether the mouse button is clicked
	 */
	bool isMouseClicked(int mouseButton);
	/**
	 * \brief Swap the mouse states so a key can not be detected mulitple times
	 */
	void swapMouseStates();

private:

	/**
	 * \brief Checks the states of the three mouse buttons (Left, Right and Middle)
	 */
	bool mouseStates[3];
	/**
	 * \brief Used the swap the states of the three mouse buttons (Left, Right and Middle)
	 */
	bool prevMouseState[3];

	/**
	 * \brief Checks the states of the base 256 keys
	 */
	bool keyStates[256];
	/**
	 * \brief Used the swap the states of the base 256 keys
	 */
	bool prevKeyState[256];

};

