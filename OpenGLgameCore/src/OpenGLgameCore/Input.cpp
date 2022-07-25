#include "OpenGLgameCore/Input.hpp"

namespace Engine
{
	bool Input::KeysPressed[static_cast<size_t>(KeyCode::KEY_LAST)] = {};

	bool Input::IsKeyPressed(const KeyCode key_code)
	{
		return KeysPressed[static_cast<size_t>(key_code)];
	}

	void Input::PressKey(const KeyCode key_code)
	{
		KeysPressed[static_cast<size_t>(key_code)] = true;
	}

	void Input::ReleaseKey(const KeyCode key_code)
	{
		KeysPressed[static_cast<size_t>(key_code)] = false;
	}
}