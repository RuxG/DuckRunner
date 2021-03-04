#include "Tema1.h"

#include <vector>
#include <string>
#include <iostream>
#include "Object2D.h"

#include <Core/Engine.h>
#include <Laboratoare\Tema1\Object2D.h>
#include <time.h>       /* time */

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	this->lives = MAX_LIVES;

	// initial position of bow
	glm::vec3 corner = glm::vec3(100, (float)resolution.y / 2, 0);

	// initial rotation of bow
	angularStepOX = 0;
	angularStepOY = 0;

	// initial rotation of shuriken
	angularStepShuriken = 0;

	srand((int)time(0));

	// create bow
	bow = new Bow(corner, glm::vec3(0, 1, 0));
	
	// create shurikens
	for (int i = 0; i < NUM_SHURIKENS; i++) {
		int num = (rand() % resolution.y) + 1;
		shurikens.push_back(new Shuriken(glm::vec3(resolution.x + i * num / 4, resolution.y - num, 0), glm::vec3(0, 1, 0)));
	}


	// create balloons
	int dist = 10;
	
	glm::vec3 redColour = glm::vec3(1, 0, 0);
	glm::vec3 yellowColour = glm::vec3(1, 1, 0);

	for (int i = 0; i < NUM_BALLOONS; i++) {
		
		int num = rand() % (resolution.x / 2);
		glm::vec3 center = glm::vec3(resolution.x / 2 + num, (-1) * i * 10 * dist , 0);
		glm::vec3 center1 = glm::vec3(resolution.x / 2  - dist + num, (-1) * i * 10 * dist, 0);
		glm::vec3 center2 = glm::vec3(resolution.x / 2  + dist + num, (-1) * i * 10 * dist, 0);

		bool score = (i % 2 == 1) ? true : false;
		glm::vec3 color = (i % 2 == 1) ? redColour : yellowColour;

		balloons.push_back(new Balloon(center, center1, center2, color, score));
	}
	
}


void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
	if (lives <= 0) {
		std::cout << "\nGAME OVER\nFINAL SCORE: " << score << std::endl << std::endl;
		std::exit(0);
	}

	// BOW STRING AND ARC

	modelMatrix = glm::mat3(1);

	bow->setCircleY(bow->getCorner().y + bow->getArrowY());

	// rotate bow string and arc
	modelMatrix *= Transform2D::Translate(bow->getCorner().x + BOW_ARROW_DIST, bow->getCorner().y + bow->getArrowY());
	modelMatrix *= Transform2D::Rotate(angularStepOX);
	modelMatrix *= Transform2D::Translate((-1) * bow->getCorner().x + (-1) * BOW_ARROW_DIST, (-1) * bow->getCorner().y - bow->getArrowY());

	// set new bow circle center coordinates
	glm::vec3 coord = glm::vec3(bow->getCircleX(), bow->getCircleY(), 1);
	coord = modelMatrix * coord;

	// translate the bow vertically
	modelMatrix *= Transform2D::Translate(0, bow->getArrowY());

	// render bow string and arc
	RenderMesh2D(bow->getBowLine(), shaders["VertexColor"], modelMatrix);
	RenderMesh2D(bow->getBowArc(), shaders["VertexColor"], modelMatrix);

	renderPowerBar();



	// ARROW

	float arrow_point_x = 0, arrow_point_y = 0;

	modelMatrix = glm::mat3(1);

	// update arrow position in air
	if (bowReleased) {
		
		bow->setArrowX(bow->getArrowX() + deltaTimeSeconds * factor * speedUp);
		
		translateYArrow = bow->getArrowX() * tan(angularStepOXArrow);

		arrow_point_x = bow->getCircleX() + bow->getArrowX() + ARROWLENGTH + TRIANGLE_LENGTH;
		arrow_point_y = bow->getCorner().y + translateY + translateYArrow  + (ARROWLENGTH + TRIANGLE_LENGTH) * sin(angularStepOXArrow);
		
		// translate it
		modelMatrix *= Transform2D::Translate(bow->getArrowX(), translateYArrow + translateY);

		// rotate it
		modelMatrix *= Transform2D::Translate(bow->getCorner().x + BOW_ARROW_DIST, bow->getCorner().y);
		modelMatrix *= Transform2D::Rotate(angularStepOXArrow);
		modelMatrix *= Transform2D::Translate((-1) * bow->getCorner().x + (-1) * BOW_ARROW_DIST, (-1) * bow->getCorner().y);

	}
	else {
		modelMatrix *= Transform2D::Translate(0, bow->getArrowY());

		modelMatrix *= Transform2D::Translate(bow->getCorner().x + BOW_ARROW_DIST, bow->getCorner().y);
		modelMatrix *= Transform2D::Rotate(angularStepOX);
		modelMatrix *= Transform2D::Translate((-1) * bow->getCorner().x + (-1) * BOW_ARROW_DIST, (-1) * bow->getCorner().y);
	}
	
	// render arrow
	RenderMesh2D(bow->getArrowLine(), shaders["VertexColor"], modelMatrix);
	RenderMesh2D(bow->getTriangle(), shaders["VertexColor"], modelMatrix);
	
	// reset arrow parameters if it left the screen
	if (bow->getCorner().x + bow->getArrowX() > window->GetResolution().x) {
		speedUp = 0;
		bow->setArrowX(0);
		translateYArrow = 0;
		bowPressedFrames = 0;
		
		translateY = 0;

		bowReleased = false;
		bow->setPowerBarScale(1);
		bow->setInAir(false);
	}
	
	

	// SHURIKENS

	modelMatrix = glm::mat3(1);

	// update rotation angle
	angularStepShuriken += deltaTimeSeconds * factor;

	// check if there are any collisions between shuriken and arrow
	int radius = bow->getRadius();
	for (int i = 0; i < shurikens.size(); i++) {
		if (shurikens[i]->isDestroyed()) continue;
		if (Collision(bow->getCircleX() - ARROWLENGTH / 4
			, bow->getCircleY() , radius,
			shurikens[i]->getCircleX(), shurikens[i]->getCircleY(), shurikens[i]->getRadius())) {
			shurikens[i]->setDestroyed(true);

			score -= SCORE_TARGET;
			lives--;
			std::cout << "SCORE: " << score << std::endl;
		}
		else if (Collision(arrow_point_x, arrow_point_y, 0,
			shurikens[i]->getCircleX(), shurikens[i]->getCircleY(), shurikens[i]->getRadius())) {
			shurikens[i]->setDestroyed(true);

			score += SCORE_TARGET;
			std::cout << "SCORE: " << score << std::endl;
		}
	}

	for (int i = 0; i < shurikens.size(); i++) {
		glm::mat3 aux = modelMatrix;
		
		// if shuriken hit the arrow, start the destroying animation
		if (shurikens[i]->isDestroyed()) {
			// scale
			shurikens[i]->setScale(shurikens[i]->getScale() - 0.05);

			aux *= Transform2D::Translate(shurikens[i]->getCircleX(), shurikens[i]->getCircleY());
			aux *= Transform2D::Scale(shurikens[i]->getScale(), shurikens[i]->getScale());
			aux *= Transform2D::Translate((-1) * shurikens[i]->getCircleX(), (-1) * shurikens[i]->getCircleY());

			// maintain in the same position
			aux *= Transform2D::Translate((-1) * shurikens[i]->getTranslateOX(), 0);

			// reset shuriken parameters if fully destroyed
			if (shurikens[i]->getScale() <= 0) {

				shurikens[i]->setDestroyed(false);
				shurikens[i]->setScale(1);
				shurikens[i]->setTranslateOX(0);
				
				// spawn the shuriken at a different position
				int delta = rand() % (window->GetResolution().y / 5);

				int sign = rand() % 2;

				delta = (sign % 2 == 1) ? delta : (-1) * delta;
			

				shurikens[i]->setCenter(glm::vec3(shurikens[i]->getCenter().x, shurikens[i]->getCenter().y, 0));

				shurikens[i]->setCircleY(shurikens[i]->getCenter().y );
				shurikens[i]->setCircleX(shurikens[i]->getCenter().x);
			}
		} else {
			// translate the shuriken horrizontally to the left
			shurikens[i]->setTranslateOX(shurikens[i]->getTranslateOX() + deltaTimeSeconds * factor * 3);
			shurikens[i]->setCircleX(shurikens[i]->getCenter().x - shurikens[i]->getTranslateOX());

			// if the shuriken left the screen, spawn the shuriken at a different position
			if (shurikens[i]->getCircleX() < 0) {

				int delta = rand() % (window->GetResolution().y / 5);

				int sign = rand() % 2;

				delta = (sign % 2 == 1) ? delta : (-1) * delta;

				shurikens[i]->setCenter(glm::vec3(shurikens[i]->getCenter().x, shurikens[i]->getCenter().y, 0));
				shurikens[i]->setCircleY(shurikens[i]->getCenter().y);

				shurikens[i]->setTranslateOX(0);
				shurikens[i]->setCircleX(shurikens[i]->getCenter().x);				
			}

			aux *= Transform2D::Translate((-1) * shurikens[i]->getTranslateOX(), 0);

			// rotate the shuriken
			aux *= Transform2D::Translate(shurikens[i]->getCenter().x, shurikens[i]->getCenter().y);
			aux *= Transform2D::Rotate(angularStepShuriken);
			aux *= Transform2D::Translate((-1) * shurikens[i]->getCenter().x, (-1) * shurikens[i]->getCenter().y);
			
		}

		// render the shuriken
		RenderMesh2D(shurikens[i]->getTriangle1(), shaders["VertexColor"], aux);
		RenderMesh2D(shurikens[i]->getTriangle2(), shaders["VertexColor"], aux);
		RenderMesh2D(shurikens[i]->getTriangle3(), shaders["VertexColor"], aux);
		RenderMesh2D(shurikens[i]->getTriangle4(), shaders["VertexColor"], aux);
		
	}

	

	// BALLOONSs
	modelMatrix = glm::mat3(1);
	
	for (int i = 0; i < balloons.size(); i++) {
		
		balloons[i]->setY(balloons[i]->getY() + deltaTimeSeconds * factor);	
		
		// check for collisions and modify scale
		if (balloons[i]->isDestroyed()) {
			balloons[i]->setScale(balloons[i]->getScale() - 0.06);
			
		} else if (Collision(balloons[i]->getCenter().x, balloons[i]->getCenter().y + balloons[i]->getY()  , balloons[i]->getRadius(),
			arrow_point_x, arrow_point_y, 0)) {
			balloons[i]->setDestroyed(true);

			if (balloons[i]->isPositiveScore()) {
				score += SCORE_TARGET;
			}
			else {
				score -= SCORE_TARGET;
			}

			std::cout << "SCORE: " << score << std::endl;

		}

		// translate vertically
		glm::mat3 aux = modelMatrix;
		aux *= Transform2D::Translate(0, balloons[i]->getY());

		// scale
		aux *= Transform2D::Translate(balloons[i]->getCenter().x, balloons[i]->getCenter().y);
		aux *= Transform2D::Scale(balloons[i]->getScale(), balloons[i]->getScale());
		aux *= Transform2D::Translate((-1) * balloons[i]->getCenter().x, (-1) * balloons[i]->getCenter().y);

		// render
		RenderMesh2D(balloons[i]->getLeftHalf(), shaders["VertexColor"], aux);
		RenderMesh2D(balloons[i]->getRightHalf(), shaders["VertexColor"], aux);
		RenderMesh2D(balloons[i]->getLine(), shaders["VertexColor"], aux);

		// reset baloon params if it left the screen or it was destroyed 
		if (balloons[i]->getScale() <= 0 || balloons[i]->getY() + balloons[i]->getCenter().y - CIRCLE_RANGE > window->GetResolution().y) {
			balloons[i]->setScale(1);
			balloons[i]->setY((-1)* window->GetResolution().y / 9 * 10);
			balloons[i]->setDestroyed(false);
		}
	}

}

// check collision
bool Tema1::Collision(int x1, int y1, int r1, int x2, int y2,  int r2) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	float d = sqrt(pow(dx, 2) + pow(dy, 2)); 

	if (d < (r1 + r2)) return true;

	return false;
}


void Tema1::renderPowerBar()
{
	// update powerBar scale and arrow speedup
	if(bowPressed) {
		bowPressedFrames++;
		bow->setPowerBarScale(bow->getPowerBarScale() + 0.1);

		if (bow->getPowerBarScale() >= 5) {
			bow->setPowerBarScale(5);
			speedUp = 20;
		}
		else if (bow->getPowerBarScale() > 3) {
			speedUp = 10;
		}
		else if (bow->getPowerBarScale() > 1) {
			speedUp = 5;
		}
	}

	// scale and translate power bar
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(bow->getCorner().x - POWER_BAR_LENGTH, bow->getCorner().y + 2 * POWER_BAR_LENGTH);
	modelMatrix *= Transform2D::Scale(bow->getPowerBarScale(), 1);
	modelMatrix *= Transform2D::Translate((-1) * (bow->getCorner().x - POWER_BAR_LENGTH), (-1) * (bow->getCorner().y + 2 * POWER_BAR_LENGTH));

	modelMatrix *= Transform2D::Translate(0, bow->getArrowY());

	// render power bar
	RenderMesh2D(bow->getPowerBar(), shaders["VertexColor"], modelMatrix);
}



void Tema1::OnInputUpdate(float deltaTime, int mods) {

	if (window->KeyHold(GLFW_KEY_W))
	{
		bow->setArrowY(bow->getArrowY() + deltaTime * factor * 2);
	}
	else if (window->KeyHold(GLFW_KEY_S)) {
		bow->setArrowY(bow->getArrowY() - deltaTime * factor * 2);
	}

}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	double cosX = double(abs((double)mouseX - bow->getCorner().x)) / sqrt(pow(((double)mouseX - bow->getCorner().x), 2) + pow(((double)mouseY - bow->getCorner().y), 2));
	double sinX = double(abs((double)mouseY - bow->getCorner().y)) / sqrt(pow(((double)mouseX - bow->getCorner().x), 2) + pow(((double)mouseY - bow->getCorner().y), 2));

	double angle;
	if (mouseY < bow->getCorner().y) {
		if (mouseX < bow->getCorner().x) {
			angle = 1.57;
		}
		else {
			angle = acos(cosX);
		}
	}
	else {
		if (mouseX > bow->getCorner().x) {
			angle = (-1) * acos(cosX);
		}
		else {
			angle = -1.57;
		}
	}

	angularStepOX = angle;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	if (!bow->isInAir()) {
		bowPressed = true;
	}

}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
		if (bowPressed) {
			// reset params
			bowReleased = true;
			bowPressed = false;

			bow->setPowerBarScale(1);

			bow->setInAir(true);

			bow->setArrowX(0);

			angularStepOXArrow = angularStepOX;

			translateY = bow->getArrowY();

		}
	}
	

void Tema1::FrameEnd()
{
	DrawCoordinatSystem();
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{

}

void Tema1::OnWindowResize(int width, int height)
{

}


void Tema1::OnKeyPress(int key, int mods)
{

}

void Tema1::OnKeyRelease(int key, int mods)
{

}


