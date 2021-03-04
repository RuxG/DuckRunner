#pragma once

#include <Component/SimpleScene.h>

class Laborator1 : public SimpleScene
{
	public:
		Laborator1();
		~Laborator1();

		void Init() override;

		bool changeColour;
		// variable for comuting between 3 types of objects
		int object = 0;

		// coordinates for the cube that is going to move continously
		float cubeX = 0, cubeY = 0, cubeZ = 0;

		// coordinates for the teapot that is going to move with ctrl
		float teapotX = 2, teapotY = 2, teapotZ = 0;

		int factor = 2;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;
};
