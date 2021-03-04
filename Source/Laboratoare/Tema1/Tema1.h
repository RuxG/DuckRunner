#pragma once
#include <Component/SimpleScene.h>

#include "../../../Visual Studio/Bow.h"
#include "Transform2D.h"
#include "../../../Visual Studio/Shuriken.h"
#include "../../../Visual Studio/Balloon.h"

#define SCORE_TARGET 50
#define MAX_LIVES 3
#define NUM_BALLOONS 5
#define NUM_SHURIKENS 7

class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;

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
	bool Collision(int x1, int y1, int x2, int y2, int r1, int r2);

	void renderPowerBar();


protected:
	Bow* bow;
	std::vector<Shuriken*> shurikens;
	std::vector<Balloon*> balloons;

	glm::mat3 modelMatrix;

	float angularStepOX, angularStepOY;
	float angularStepShuriken;
	float factor = 100;

	bool bowPressed;
	bool bowReleased;
	int bowPressedFrames;

	float angularStepOXArrow;
	float translateYArrow;
	float translateY;

	int speedUp = 0;

	int score;
	int lives;
};
