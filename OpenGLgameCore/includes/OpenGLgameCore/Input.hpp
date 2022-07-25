#pragma once
#include "Keys.hpp"

namespace Engine
{
	class Input
	{
	public:
		static bool IsKeyPressed(const KeyCode key_code);
		static void PressKey(const KeyCode key_code);
		static void ReleaseKey(const KeyCode key_code);

	private:
		static bool KeysPressed[static_cast<size_t>(KeyCode::KEY_LAST)];
	};
}