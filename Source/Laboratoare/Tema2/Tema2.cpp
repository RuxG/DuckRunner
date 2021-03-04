#include "Tema2.h"
#include "Laboratoare/Laborator4/Transform3D.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <ctime>
#include "Laboratoare/Laborator3/Object2D.h"
#include "Laboratoare/Laborator3/Laborator3_Vis2D.h"
#include "Laboratoare/Laborator3/Transform2D.h"
#include <vector>

#include <Core/Engine.h>
#include <stb/stb_image.h>


using namespace std;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

int coinToss(float prob) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution d(prob);
	int res = d(gen);

	return res;
}

std::string generate_collectable() {
	bool bad = coinToss(0.1);
	if (!bad) {
		bool good = coinToss(0.3);
		if (good) {
			return "bread";
		}
		else {
			return "none";
		}
	}

	return"moldy_bread";
}

bool check_collision(float x1, float y1, float r1, float x2, float y2, float r2) {
	float dx = x2 - x1;
	float dy = y2 - y1;

	float d = sqrt(pow(dx, 2) + pow(dy, 2));

	if (d < (r1 + r2)) return true;

	return false;
}


int randomNum(int max) {
	int randomNumber = 0;
	
	if (max == 0) {
		max = 1;
	}
	randomNumber += ((rand() + rand() + rand()) % max) + 1;

	return randomNumber;
}




void Tema2::loadTextures() {
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "bread8.png").c_str(), GL_REPEAT);
		mapTextures["bread"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "bread_moldy.png").c_str(), GL_REPEAT);
		mapTextures["moldy_bread"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad_blue.png").c_str(), GL_REPEAT);
		mapTextures["lilypad"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad_red.png").c_str(), GL_REPEAT);
		mapTextures["lilypad_red"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad.png").c_str(), GL_REPEAT);
		mapTextures["lilypad_blue"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad_orange.png").c_str(), GL_REPEAT);
		mapTextures["lilypad_orange"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad_yellow.png").c_str(), GL_REPEAT);
		mapTextures["lilypad_yellow"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad_pink.png").c_str(), GL_REPEAT);
		mapTextures["lilypad_pink"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "lilypad_purple.png").c_str(), GL_REPEAT);
		mapTextures["lilypad_purple"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "cattail.jpg").c_str(), GL_REPEAT);
		mapTextures["cattail"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "green.jpg").c_str(), GL_REPEAT);
		mapTextures["green"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "ciuperca_red.png").c_str(), GL_REPEAT);
		mapTextures["ciuperca_red"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "ciuperca_yellow.png").c_str(), GL_REPEAT);
		mapTextures["ciuperca_yellow"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "ciuperca_purple.png").c_str(), GL_REPEAT);
		mapTextures["ciuperca_purple"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "ciuperca_blue.png").c_str(), GL_REPEAT);
		mapTextures["ciuperca_blue"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "ciuperca_pink.png").c_str(), GL_REPEAT);
		mapTextures["ciuperca_pink"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "white.jpg").c_str(), GL_REPEAT);
		mapTextures["white"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "grass.png").c_str(), GL_REPEAT);
		mapTextures["grass2"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "grass_mirror.png").c_str(), GL_REPEAT);
		mapTextures["grass_mirror"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "water2.jpg").c_str(), GL_REPEAT);
		mapTextures["water"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "stufaris.png").c_str(), GL_REPEAT);
		mapTextures["stufaris"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "chicken.png").c_str(), GL_REPEAT);
		mapTextures["duck"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "yellow_grass.png").c_str(), GL_REPEAT);
		mapTextures["yellow_grass"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "firefly.jpg").c_str(), GL_REPEAT);
		mapTextures["firefly"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "moon.png").c_str(), GL_REPEAT);
		mapTextures["moon"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "sky.jpg").c_str(), GL_REPEAT);
		mapTextures["sky"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((RESOURCE_PATH::TEMA3_TEXTURES + "floare.png").c_str(), GL_REPEAT);
		mapTextures["floare"] = texture;
	}

}

void Tema2::createQuad() {
	vector<glm::vec3> vertices
	{
		glm::vec3(0.5f,   0.5f, 0.0f),	// Top Right
		glm::vec3(0.5f,  -0.5f, 0.0f),	// Bottom Right
		glm::vec3(-0.5f, -0.5f, 0.0f),	// Bottom Left
		glm::vec3(-0.5f,  0.5f, 0.0f),	// Top Left
	};

	vector<glm::vec3> normals
	{
		glm::vec3(0, 1, 1),
		glm::vec3(1, 0, 1),
		glm::vec3(1, 0, 0),
		glm::vec3(0, 1, 0)
	};

	// Complete texture coordinates for the square
	glm::vec3 offset(0.5f, 0.5f, 0.0f);

	vector<glm::vec2> textureCoords
	{
		glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1), glm::vec2(0, 0)
	};

	vector<unsigned short> indices =
	{
		0, 1, 3,
		1, 2, 3
	};

	rectangle_grass = new Mesh("square");
	rectangle_grass->InitFromData(vertices, normals, textureCoords, indices);
	meshes[rectangle_grass->GetMeshID()] = rectangle_grass;
}

void Tema2::createCircle(int grades, std::string name) {
	Mesh* circle = new Mesh(name);
	circle->SetDrawMode(GL_TRIANGLE_FAN);

	std::vector<glm::vec3> vertices;
	std::vector<unsigned short> indices;

	std::vector<glm::vec2> textCoord;

	float radius = 1;

	std::vector <glm::vec3> normals;


	double angle;
	for (int i = 0; i <= 50; i++) {

		angle = grades * (float)i / (float)50 - 90;
		angle = RADIANS(angle);

		float y = radius * sin(angle);
		float x = radius * cos(angle);


		float tx = (cos(angle) / radius + 1) * 0.5;
		float ty = (sin(angle) / radius + 1) * 0.5;
		textCoord.push_back(glm::vec2(tx, ty));

		vertices.push_back(glm::vec3(x, 0, y));

		indices.push_back(i);
		normals.push_back(glm::vec3(0, 1, 0));

	}

	circle->InitFromData(vertices, normals, textCoord, indices);

	meshes[circle->GetMeshID()] = circle;
}

Mesh* Tema2::createCube() {
	vector<glm::vec3> vertices
	{
		glm::vec3(-0.5, -0.5, 0.5), // 0
		glm::vec3(0.5, -0.5, 0.5), // 1
		glm::vec3(0.5, 0.5, 0.5), // 2
		glm::vec3(-0.5, 0.5, 0.5), // 3

		glm::vec3(0.5, -0.5, 0.5), // 4
		glm::vec3(0.5, -0.5, -0.5), // 5
		glm::vec3(0.5, 0.5, -0.5), // 6
		glm::vec3(0.5, 0.5, 0.5), // 7

		glm::vec3(0.5, -0.5, -0.5), // 8
		glm::vec3(-0.5, -0.5, -0.5), // 9
		glm::vec3(-0.5, 0.5, -0.5), // 10
		glm::vec3(0.5, 0.5, -0.5), // 11

		glm::vec3(-0.5, -0.5, -0.5), // 12
		glm::vec3(-0.5, -0.5, 0.5), // 13
		glm::vec3(-0.5, 0.5, 0.5), // 14
		glm::vec3(-0.5, 0.5, -0.5), // 15

		glm::vec3(-0.5, 0.5, 0.5), // 16
		glm::vec3(0.5, 0.5, 0.5), // 17
		glm::vec3(0.5, 0.5, -0.5), // 18
		glm::vec3(-0.5, 0.5, -0.5), // 19

		glm::vec3(-0.5, -0.5, 0.5), // 20
		glm::vec3(0.5, -0.5, 0.5), // 21
		glm::vec3(0.5, -0.5, -0.5), // 22
		glm::vec3(-0.5, -0.5, -0.5), // 23
	};

	vector<unsigned short> indices =
	{
		// fata 1
		0, 1, 2,
		0, 2, 3,

		// fata 2
		4, 5, 6,
		4, 6, 7,

		// fata 3
		8, 9, 10,
		8, 10, 11,

		// fata 4
		12, 13, 14,
		12, 14, 15,

		// fata 5
		16, 17, 18,
		16, 18, 19,

		// fata 6
		20, 22, 21,
		20, 23, 22

	};

	vector<glm::vec3> normals
	{
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),

		glm::vec3(1, 0, 0),
		glm::vec3(1, 0, 0),
		glm::vec3(1, 0, 0),
		glm::vec3(1, 0, 0),

		glm::vec3(0, 0, -1),
		glm::vec3(0, 0, -1),
		glm::vec3(0, 0, -1),
		glm::vec3(0, 0, -1),

		glm::vec3(-1, 0, 0),
		glm::vec3(-1, 0, 0),
		glm::vec3(-1, 0, 0),
		glm::vec3(-1, 0, 0),

		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),

		glm::vec3(0, -1, 0),
		glm::vec3(0, -1, 0),
		glm::vec3(0, -1, 0),
		glm::vec3(0, -1, 0)
	};

	// TODO : Complete texture coordinates for the square
	vector<glm::vec2> textureCoords
	{
		glm::vec2(0.f, 1.f),
		glm::vec2(1.f, 1.f),
		glm::vec2(1.f, 0.f),
		glm::vec2(0.f, 0.f),

		glm::vec2(0.f, 1.f),
		glm::vec2(1.f, 1.f),
		glm::vec2(1.f, 0.f),
		glm::vec2(0.f, 0.f),

		glm::vec2(0.f, 1.f),
		glm::vec2(1.f, 1.f),
		glm::vec2(1.f, 0.f),
		glm::vec2(0.f, 0.f),

		glm::vec2(0.f, 1.f),
		glm::vec2(1.f, 1.f),
		glm::vec2(1.f, 0.f),
		glm::vec2(0.f, 0.f),

		glm::vec2(0.f, 1.f),
		glm::vec2(1.f, 1.f),
		glm::vec2(1.f, 0.f),
		glm::vec2(0.f, 0.f),

		glm::vec2(0.f, 1.f),
		glm::vec2(1.f, 1.f),
		glm::vec2(1.f, 0.f),
		glm::vec2(0.f, 0.f)
	};

	Mesh* mesh = new Mesh("water");
	mesh->InitFromData(vertices, normals, textureCoords, indices);
	return mesh;
}
void Tema2::Init()
{

	loadTextures();

	// DRAW SHAPES
	createLives();
	createQuad();
	createCircle(360, "circle");
	createCircle(180, "semi_circle");
	
	
	// WATER
	water = createCube();
 
	// SPHERE
	sphere = new Mesh("sphere");
	sphere->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");

	
	// CAMERA

	camera = new Laborator::Camera();
	camera->Set(glm::vec3(0, 0.5, 0), glm::vec3(0, 0.5, -1), glm::vec3(0, 1, 0));

	glm::ivec2 resolution = window->GetResolution();
	camera2D = new Laborator::Camera();
	camera2D->Set(glm::vec3(0, 0, 50.f), glm::vec3(0, 0, 25.f), glm::vec3(0, 1.f, 0));
	
	// 2D and 3D camera projection matrixes
	orthoMatrix = glm::ortho(0.f, (float)resolution.x, 0.f, (float)resolution.y, 0.01f, 400.f);
	projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

	// player
	glm::vec3 position(0, 0.5, 0);
	player = new Player(position, 0, MAX_FUEL);
	
	// create tiles configurations
	getConfigurations();

	// generate platforms
	generateInitialPlatforms();

	// generate fuel bar
	fuelBar.rectangle_back = createRectangle(glm::vec3 (1, 1, 1));
	fuelBar.rectangle_front = createRectangle(glm::vec3(0, 1, 0));

	left = -10;
	right = 10;
	bottom = -10;
	top = 10;
	zNear = 0.01f;
	zFar = 200.0f;
	fov = RADIANS(60);

	// Shaders
	{
		Shader* shader = new Shader("ShaderTema2");
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema2/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;

		Shader* shader2 = new Shader("ShaderTema2Deformare");
		shader2->AddShader("Source/Laboratoare/Tema2/Shaders/VertexShader-Sphere.glsl", GL_VERTEX_SHADER);
		shader2->AddShader("Source/Laboratoare/Tema2/Shaders/FragmentShader-Sphere.glsl", GL_FRAGMENT_SHADER);
		shader2->CreateAndLink();
		shaders[shader2->GetName()] = shader2;

		Shader* shader3 = new Shader("ShaderTema2Text");
		shader3->AddShader("Source/Laboratoare/Tema2/Shaders/VertexShaderText.glsl", GL_VERTEX_SHADER);
		shader3->AddShader("Source/Laboratoare/Tema2/Shaders/FragmentShaderText.glsl", GL_FRAGMENT_SHADER);
		shader3->CreateAndLink();
		shaders[shader3->GetName()] = shader3;

	}
	

	// Light & material properties
	{
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}

	textRenderer = new TextRenderer(resolution.x, resolution.y);

	textRenderer->Load("Source/TextRenderer/Fonts/Arial.ttf", 25);

	textPosition = glm::vec2(resolution.x * 4.2 / 5, resolution.y * 1 / 5);

}


void Tema2::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}


void Tema2::Update(float deltaTimeSeconds) {	

	if (player->isDead()) {
		deadAnimation(deltaTimeSeconds);
	} 

	renderPlatforms();

	renderDecor();

	apply_buff(deltaTimeSeconds);

	translateSphere(deltaTimeSeconds);

	renderFuelBar();
	 
	angle += deltaTimeSeconds;

	textRenderer->RenderText("SCORE: " + to_string(score), textPosition.x, textPosition.y, 1.0f, glm::vec3(1.0, 1.0, 1.0)); 
}


void Tema2::FrameEnd()
{

}


void Tema2::OnInputUpdate(float deltaTime, int mods) {
		
		if (window->KeyHold(GLFW_KEY_W)) {
			// increase speed
			player->setSpeed(player->getSpeed() + deltaTime * CAMERA_SPEED_UP);
			if (player->getSpeed() > CAMERA_MAX_SPEED) {
				player->setSpeed(CAMERA_MAX_SPEED);
			}
		}

		if (window->KeyHold(GLFW_KEY_A) && !player->isDead()) {

			// ROTATE left
			if (!player->isDescending()) {
				player->setSphereRotation(player->getRotationAngle() + glm::vec3(0, deltaTime * player->getSpeed(), 0));
				if (player->getRotationAngle().y > RADIANS(45)) {
					player->setSphereRotation(glm::vec3(0, RADIANS(45),0));
				}
			}
			
			// Translate left
			float sign = back ? 1 : -1;

			camera->TranslateRight((-1) * deltaTime * player->getSpeed());
			player->setSpherePosition(player->getPosition() - sign * glm::vec3(deltaTime * player->getSpeed(), 0, 0));
			player->setOffset(player->getOffset() - sign * glm::vec3(deltaTime * player->getSpeed(), 0, 0));
				
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			// decrease speed
			player->setSpeed(player->getSpeed() - deltaTime * CAMERA_SPEED_UP);
			if (player->getSpeed() < CAMERA_MIN_SPEED) {
				player->setSpeed(CAMERA_MIN_SPEED);
			}
		}

		if (window->KeyHold(GLFW_KEY_D) && !player->isDead()) {
			// ROTATE right
			if (!player->isDescending()) {
				player->setSphereRotation(player->getRotationAngle() - glm::vec3(0, deltaTime * player->getSpeed(), 0));
				if (player->getRotationAngle().y < -RADIANS(45)) {
					player->setSphereRotation(glm::vec3(0, -RADIANS(45), 0));
				}
			}
			
			// Translate right
			float sign = back ? 1 : -1;

			camera->TranslateRight(deltaTime * player->getSpeed());
			player->setSpherePosition(player->getPosition() + sign * glm::vec3(deltaTime * player->getSpeed(), 0, 0));
			player->setOffset(player->getOffset() + sign * glm::vec3(deltaTime * player->getSpeed(), 0, 0));

		}

		if (window->KeyHold(GLFW_KEY_SPACE) && !player->isDead()) {
			double offset = player->getOffset().y + deltaTime * player->getSpeed();
			player->setInAir(true);

			// if max height was reached, start descending
			if (offset >= MAX_JUMP) player->setDescend(true);

			// move upword
			if (!player->isDescending()) {
				camera->TranslateUpword(deltaTime * player->getSpeed());
				player->setSpherePosition(player->getPosition() + glm::vec3(0, deltaTime * player->getSpeed(), 0));
				player->setOffset(player->getOffset() + glm::vec3(0,deltaTime * player->getSpeed(),  0));

			}
		}
}

void Tema2::OnKeyPress(int key, int mods)
{	
	// change camera perspective
	if (key == GLFW_KEY_Q && back) {

		renderCameraTarget = !renderCameraTarget;
		if (renderCameraTarget) {
			camera->TranslateForward(camera_offset.z);
			camera->TranslateUpword(camera_offset.y);
			camera->RotateThirdPerson_OX(RADIANS(-30));

		}
		else {
			camera->RotateThirdPerson_OX(RADIANS(30));
			camera->TranslateUpword(-camera_offset.y);
			camera->TranslateForward(-camera_offset.z);

		}
	}

}

void Tema2::OnKeyRelease(int key, int mods)
{
	if (key == GLFW_KEY_SPACE) {
		player->setDescend(true);
		player->setInAir(true);
	}
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}

void Tema2::render_plants(float offset, bool direction) {
	
	// skip mushroom rendering
	bool skip_mushrooms;
	{
		skip_mushrooms = false;

		if (abs(((int)offset) / 3) % 2 == 1) {
			if (direction) {
				skip_mushrooms = true;
			}
		} else if (abs(((int)offset) / 3) % 2 == 0) {
			if (!direction) {
				skip_mushrooms = true;
			}
		}
	}

	// plants offsets
	float lateral_offset = direction ? 5.5 : -5.5;
	float ciuperca_offset = 0;
	float ox = 0;
	float oz = 0;
	
	bool minus = true;

	for (int j = 0; j < 3; j++) {
		if (direction && j > 0) {
			ox += 1;
		} else if (!direction && j > 0) {
			ox -= 1;
		}

		if (j % 2 == 0) {
			oz = -0.5;

		} else {
			oz = 0.5;
		}

		// render plants
		for (int i = 0; i < 19; i++) {
			glm::mat4 modelMatrix = glm::mat4(1);

			if (i >= 11  && skip_mushrooms) {
				continue;
			}

			bool ciuperca = false;
			if (vegetation_names[i] == "ciuperca") {

				switch (i) {
				case 11:  
					vegetation_names[i] = "ciuperca_red";
					break;
				case 13:
					vegetation_names[i] = "ciuperca_pink";
					break;
				case 15:
					vegetation_names[i] = "ciuperca_yellow";
					break;
				case 17:
					vegetation_names[i] = "ciuperca_purple";
					break;
				
				default:
					vegetation_names[i] = "ciuperca_blue";
					break;
				}
				ciuperca = true;
			}	

			// right side
			if (direction) {
				modelMatrix *= Transform3D::Translate(vegetation_position[i].x + lateral_offset + ox, vegetation_position[i].y, vegetation_position[i].z + offset + oz);

			}
			// left side
			else {
				modelMatrix *= Transform3D::Translate(vegetation_position_mirror[i].x + lateral_offset + ox, vegetation_position_mirror[i].y, vegetation_position_mirror[i].z + offset + oz);

			}

			float sign = direction ? 1 : -1;
			if (vegetation_rotation[i].z != 0) {
				modelMatrix *= Transform3D::RotateOZ(sign * vegetation_rotation[i].z);
			}
			if (vegetation_rotation[i].x != 0) {
				modelMatrix *= Transform3D::RotateOX(sign * vegetation_rotation[i].x);
			}
			if (vegetation_rotation[i].y != 0) {
				modelMatrix *= Transform3D::RotateOY(sign * vegetation_rotation[i].y);
			}

			modelMatrix *= Transform3D::Scale(vegetation_scale[i].x, vegetation_scale[i].y, vegetation_scale[i].z);

			Mesh* mesh = water;
			if (vegetation_names[i] == "grass2" || vegetation_names[i] == "grass_mirror" || vegetation_names[i] == "yellow_grass") {
				mesh = rectangle_grass;
			}

			RenderSimpleMesh(mesh, shaders["ShaderTema2Text"], modelMatrix, mapTextures[vegetation_names[i]], NULL);

			if (ciuperca) {
				vegetation_names[i] = "ciuperca";
			}

			if (j == 0 && i == 2) {
				modelMatrix = glm::mat4(1);

				if (direction) {
					modelMatrix *= Transform3D::Translate(vegetation_position[i].x + lateral_offset + ox, vegetation_position[i].y + 0.17, vegetation_position[i].z + offset + oz);

				}
				else {
					modelMatrix *= Transform3D::Translate(vegetation_position_mirror[i].x + lateral_offset + ox, vegetation_position_mirror[i].y + 0.17, vegetation_position_mirror[i].z + offset + oz);

				}

				modelMatrix *= Transform3D::Scale(0.05, 0.05, 0.05);
				RenderSimpleMesh(sphere, shaders["ShaderTema2Text"], modelMatrix, mapTextures["firefly"], NULL, glm::vec3(-1, -1, -1), 1);
			}	
		}
	}
}


double min(double a, double b) {
	return a < b ? a : b;
}

double max(double a, double b) {
	return a > b ? a : b;
}

void Tema2::renderPlatforms() {

	int size = platforms.size();

	// platforms that will be deleted after current frame
	std::vector<int> to_delete;

	// variable used for detecting the collision between player and platforms
	bool collision = false;

	std::pair<int, int> on_platform(-1, -1);
	for (int i = 0; i < size; i++) {
		std::vector<Platform*> platform_line = platforms[i];

		float z_scale = 3;

		// variable used for detecting if a platform is behind the player
		// and should be deleted
		bool rendered = false;
		for (int j = 0; j < platform_line.size(); j++) {

			// platform z offset from start 
			glm::vec3 offset = platform_line[j]->getPos();

			// platform length
			double length = platform_line[j]->getLength();

			// distance from player
			double distance = player->getOffset().z + (-1) * Z_LIM;

			// platform is not in sight, skip it
			if ((-1) * offset.z < distance) {
				break;
			}

			// platform is behind the player, mark it as "rendered" and skip
			else if (player->getPosition().z < -offset.z - 5) {
				rendered = true;
				to_delete.push_back(i);
				break;
			}

			// platform is in sight 
			else {
				// save platform color
				glm::vec3 original_color = platform_line[j]->getColor();
				int original_color_name = platform_line[j]->getColorName();

				// check if player is on a platform
				if ((player->getPosition().z <= -offset.z + length  + 0.125) && (player->getPosition().z >= -offset.z - length  - 0.125) &&
					player->getPosition().x <= offset.x + 1.36 && player->getPosition().x >= offset.x - 1.36 && player->getPosition().y < 1 && !player->isInAir()) {

					// give special powers
					{
						if (platform_line[j]->getSpecial() && !platform_line[j]->getUsedPower()) {
							// set buff type
							player->setBuffType(original_color_name);
							// mark power as used
							platform_line[j]->setUsedPower(true);
							// set buff type
							player->setBuffTime(BUFF_TIME);

							if (player->getBuffType() == ORANGE_BUFF) {
								player->setSpeed(1);
							}

							// life tile 
							if (player->getBuffType() == LIFE_BUFF) {
								lives = min(lives + 1, 3);
								player->setBuffTime(0);
							}
						}
					}
				
					

					// collect collectable
					{ 
						if (platform_line[j]->getCollectableType().compare("bread") == 0) {

							if (!platform_line[j]->getCollectedCollectable()) {
								score += SCORE_COLLECTABLE;
								platform_line[j]->setCollected(true);
							}

						}
						else if (platform_line[j]->getCollectableType().compare("moldy_bread") == 0) {
							if (!platform_line[j]->getCollectedCollectable()) {
								score -= SCORE_COLLECTABLE;
								platform_line[j]->setCollected(true);
							}

						}
					}
					
					// make platform purple
					platform_line[j]->setColor(glm::vec3(0.7, 0, 1));

					// the player is on the platform
					if (!collision) {
						platform_line[j]->setColorName(PURPLE_BUFF);
						collision = true;
					}

				}

				// render collectable
				{
					if (platform_line[j]->getCollectableType().compare("none") != 0 && !platform_line[j]->getCollectedCollectable()) {

						glm::mat4 modelMatrix = glm::mat4(1);
						modelMatrix *= Transform3D::Translate(offset.x - 0.1, 0.6, -offset.z);
						modelMatrix *= Transform3D::RotateOY(angle);
						modelMatrix *= Transform3D::Scale(0.5, 0.5, 0.1);

						if (platform_line[j]->getCollectableType().compare("bread") == 0) {
							RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["bread"], NULL);
						}
						else {
							RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["moldy_bread"], NULL);
						}
					}

				}
			


				// render the platform
				{
					glm::mat4 modelMatrix = glm::mat4(1);
					modelMatrix *= Transform3D::Translate(offset.x, offset.y + 0.1, -offset.z);
					modelMatrix *= Transform3D::Scale(1, 0.2, 0.9);
					modelMatrix *= Transform3D::RotateOY(platform_line[j]->getAngle());

					std::string lilypad_type = lilypad_colours[platform_line[j]->getColorName()];

					RenderSimpleMesh(meshes["circle"], shaders["ShaderTema2Text"], modelMatrix, mapTextures[lilypad_type.c_str()], NULL);
				}
				
				
				platform_line[j]->setColor(original_color);
				platform_line[j]->setColorName(original_color_name);

				// render obstacle
				if (platform_line[j]->getObstacleDistance() > 0 && platform_line[j]->getColorName() != BLUE_BUFF) {

					// the player hit the obstacle
					if ((player->getPosition().z <= -offset.z + length + 0.125) && (player->getPosition().z >= -offset.z - length - 0.125) &&
						player->getPosition().x <= offset.x + 1.36 && player->getPosition().x >= offset.x - 1.36 && player->getPosition().y < 1) {

						if (!platform_line[j]->getHitObstacle()) {
							// decrease lives
							lives--;
						}

						// mark obstacle as hit
						platform_line[j]->setHitObstacle(true);
						platform_line[j]->setObstacleDistance(0);

					}

					// create obstacle  
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 6; j++) {
							glm::mat4 modelMatrix = glm::mat4(1);
							modelMatrix *= Transform3D::Translate(offset.x, offset.y +0.2, -offset.z);
							modelMatrix *= Transform3D::RotateOY(RADIANS(74 * j));
							modelMatrix *= Transform3D::RotateOZ(RADIANS(20 * i));
							modelMatrix *= Transform3D::Scale(0.5, 1, 0.2);
							RenderSimpleMesh(meshes["semi_circle"], shaders["ShaderTema2Text"], modelMatrix, mapTextures["floare"], NULL);
						}
					}
				}
			}
		}

		// generate a new line of platforms if it is behind the player
		if (rendered) {
			std::vector<Platform*> platform;
			replace_platform(platform_line, platform);
			platforms.push_back(platform);
		}
	}

	// delete old platforms
	delete_old_platforms(to_delete);

	// mark player as dead if he fell
	if (!collision && !player->isInAir() && !player->isDead()) {
		player->setDead(true);
	}

}

void Tema2::renderDecor()
{
	// Replace water
	int last = -1;
	float z = z_offset_watter[z_offset_watter.size() - 1];
	for (int i = 0; i < z_offset_watter.size(); i++) {
		if (z_offset_watter[i] < platforms[0][0]->getPos().z) {
			last++;
		}
	}

	int count = 0;
	for (auto it = z_offset_watter.begin(); it != z_offset_watter.end(); ) {
		bool del = false;
		if (count <= last) {
			it = z_offset_watter.erase(it);
		}
		else {
			it++;
		}
		count++;
	}

	float size2 = z_offset_watter.size();

	for (int i = 0; i < 8 - size2; i++) {
		z_offset_watter.push_back(z + 3 * (i + 1));
	}

	// Replace light colours
	if (last != -1) {
		for (int i = 0; i < lightCount - 1; i++) {
			lightColours[i] = lightColours[i + 1];
		}
		lightColours[15] = init_lightColours[(randomNum(5) + randomNum(23) + randomNum(53) + randomNum(153)) % 20];
		lightColours[16] = init_lightColours[(randomNum(5) + randomNum(23) + randomNum(53) + randomNum(153)) % 20];
	}

	lightCount = z_offset_watter.size() * 2;

	for (int i = 0; i < lightCount / 2; i++) {
		lightDirection[i] = glm::vec3(0, -1, 0);
		lightPosition[i] = vegetation_position[3] - glm::vec3(-5.5, -1.45, z_offset_watter[i]);

		spotlight[i] = 1;

	}

	for (int i = lightCount / 2; i < lightCount; i++) {
		lightDirection[i] = glm::vec3(0, -1, 0);
		lightPosition[i] = vegetation_position_mirror[3] - glm::vec3(5.5, -1.45, z_offset_watter[i - lightCount / 2]);
		spotlight[i] = 1;

	}

	// Moon light position and colour
	lightCount++;
	lightColours[lightCount - 1] = glm::vec3(1, 1, 1);
	spotlight[lightCount - 1] = 0;
	lightDirection[lightCount - 1] = glm::vec3(0, -1, 0);
	lightPosition[lightCount - 1] = glm::vec3(2, 2.2, camera->GetTargetPosition().z - 3);

	// Render moon
	glm::mat4 modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(camera->GetTargetPosition().x + lightPosition[lightCount - 1].x + 1, camera->GetTargetPosition().y + lightPosition[lightCount - 1].y + 1, lightPosition[lightCount - 1].z - 4);
	if (!renderCameraTarget) RenderSimpleMesh(sphere, shaders["ShaderTema2Text"], modelMatrix, mapTextures["moon"], NULL, glm::vec3(-1, -1, -1), 1);

	// Render sky
	for (int i = -2; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(camera->GetTargetPosition().x + 10 * i, camera->GetTargetPosition().y + 10 * j, -Z_LIM + camera->GetTargetPosition().z - 1);
			modelMatrix *= Transform3D::Scale(10, 10, 0);
			if (j % 2 == 1) {
				modelMatrix *= Transform3D::RotateOZ(RADIANS(180));
			}
			RenderSimpleMesh(rectangle_grass, shaders["ShaderTema2Text"], modelMatrix, mapTextures["sky"], NULL);
		}
	}

	// Render water, ground and plants
	for (int i = 0; i < z_offset_watter.size(); i++) {

		// Render water

		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate((-2) * TILE_GAP + 0.2, 0, -z_offset_watter[i]);
		modelMatrix *= Transform3D::Scale(3.5, 0.2, 3);
		RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["water"], NULL);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0.2, 0, -z_offset_watter[i]);
		modelMatrix *= Transform3D::Scale(3.5, 0.2, 3);
		RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["water"], NULL);


		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(2.4 * TILE_GAP + 0.5, 0, -z_offset_watter[i]);
		modelMatrix *= Transform3D::Scale(3.5, 0.2, 3);
		RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["water"], NULL);


		// Render ground

		for (int j = 0; j < 5; j++) {
			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(-5 - 3 * j, 0, -z_offset_watter[i]);
			modelMatrix *= Transform3D::Scale(3, 0.2, 3);
			RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["stufaris"], NULL);
		}

		for (int j = 0; j < 5; j++) {
			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(6 + 3 * j, 0, -z_offset_watter[i]);
			modelMatrix *= Transform3D::Scale(3, 0.2, 3);
			RenderSimpleMesh(water, shaders["ShaderTema2Text"], modelMatrix, mapTextures["stufaris"], NULL);
		}

		// Render plants

		render_plants(-z_offset_watter[i], true);
		render_plants(-z_offset_watter[i], false);

	}
}

void Tema2::generateInitialPlatforms() {
	int prev_config_num = -1;
	int config_num = -1;

	double gap = 0;
	double max_offset = 0;

	// create initial platforms
	for (int i = 0; i < 8; i++) {
		std::vector<Platform*> platform;

		// generate a platform line configuration number
		prev_config_num = config_num;
		get_configuration_number(config_num, prev_config_num);

		if (i == 0) config_num = 0;

		// generate platform length
		double platform_length = 1;

		// generate platform gap
		gap = coinToss(0.5) ;
		if (!gap) gap = 0.1;

		if (i == 0) gap = 0;
		max_offset += gap ;

		if (i != 0) max_offset += platform_length ;

		// generate platform color
		int color_name = BLUE_BUFF;
		generate_color(color_name);
	

		// left tile
		if (configurations[config_num].left) {
			std::string collectable_type = generate_collectable();
			platform.push_back(new Platform(glm::vec3((-1.7) * TILE_GAP + 0.3, 0.02, max_offset), platform_length, config_num, false, BLUE_BUFF, 0, collectable_type));
		}
		else {
			// randomize if another tile will be spawn
			int additional_tile = coinToss(0.5);
			if (additional_tile) {
				std::string collectable_type = generate_collectable();
				platform.push_back(new Platform(glm::vec3((-1.7) * TILE_GAP + 0.3, 0.02, max_offset), platform_length, config_num,  true, color_name, 0, collectable_type));
			}
		}

		// middle tile
		if (configurations[config_num].middle) {
			std::string collectable_type = generate_collectable();
			platform.push_back(new Platform(glm::vec3(0.3, 0.02, max_offset), platform_length, config_num,  false, BLUE_BUFF, 0, collectable_type));
		}
		else {
			// randomize if another tile will be spawn
			int additional_tile = coinToss(0.5);
			if (additional_tile) {
				std::string collectable_type = generate_collectable();
				platform.push_back(new Platform(glm::vec3(0.3, 0.02, max_offset), platform_length, config_num,  true, color_name, 0, collectable_type));
			}
		}

		// right tile
		if (configurations[config_num].right) {
			std::string collectable_type = generate_collectable();
			platform.push_back(new Platform(glm::vec3(1.7 * TILE_GAP + 0.3, 0.02, max_offset), platform_length, config_num, false, BLUE_BUFF, 0, collectable_type));
		}
		else {
			// randomize if another tile will be spawn
			int additional_tile = coinToss(0.5);
			if (additional_tile) {
				std::string collectable_type = generate_collectable();
				platform.push_back(new Platform(glm::vec3(1.7 * TILE_GAP +0.3, 0.02, max_offset), platform_length, config_num,  true, color_name, 0, collectable_type));
			}
		}

		platforms.push_back(platform);
		max_offset += platform_length ;
		z_offset_watter.push_back(i * 3);
	}


	
}

void Tema2::translateSphere(float deltaTimeSeconds) {
	if (!player->isDead()) {

		// descend
		if (player->isDescending() == true) {
			player->setInAir(true);
			player->setSpherePosition(player->getPosition() - glm::vec3(0, deltaTimeSeconds * player->getSpeed(), 0));
			player->setOffset(player->getOffset() - glm::vec3(0, deltaTimeSeconds * player->getSpeed(), 0));
			camera->TranslateUpword(-deltaTimeSeconds * player->getSpeed());

			if(player->getRotationAngle().y > RADIANS(0)) {
				player->setSphereRotation(player->getRotationAngle() - glm::vec3(0, deltaTimeSeconds * player->getSpeed(), 0));
				if (player->getRotationAngle().y < RADIANS(0)) {
					player->setSphereRotation(glm::vec3(0, RADIANS(0), 0));
				}
			} else if (player->getRotationAngle().y < RADIANS(0)) {
				player->setSphereRotation(player->getRotationAngle() + glm::vec3(0, deltaTimeSeconds * player->getSpeed(), 0));
				if (player->getRotationAngle().y > RADIANS(0)) {
					player->setSphereRotation(glm::vec3(0, RADIANS(0), 0));
				}
			}
		}

		// stop sphere from descending
		if (player->getOffset().y <= 0) {
			player->setInAir(false);
			player->setDescend(false);
		}

		if (back) {
			// translate forward
			camera->TranslateForward(deltaTimeSeconds * player->getSpeed());
		}
		else {
			// translate forward
			camera->TranslateForward(-deltaTimeSeconds * player->getSpeed());
		}
		
		
		player->setSpherePosition(player->getPosition() - glm::vec3(0, 0, deltaTimeSeconds * player->getSpeed()));

		player->setOffset(player->getOffset() - glm::vec3(0, 0, deltaTimeSeconds * player->getSpeed()));

		// consume fuel
		player->setFuel(player->getFuel() - deltaTimeSeconds * player->getSpeed());

		if (player->getFuel() <= 0) {
			lives--;
			player->setFuel(MAX_FUEL);
		}

		if (lives ==  0) {
			exit(1);
		}
	}

	// render sphere 
	if (renderCameraTarget && player->getBuffTime() <= 0) {
		glm::mat4 modelMatrix(1);
		modelMatrix *= Transform3D::Translate(player->getPosition().x, player->getPosition().y, player->getPosition().z);
		modelMatrix *= Transform3D::Scale(0.05, 0.05, 0.05);
		modelMatrix *= Transform3D::RotateOY(RADIANS(180));
		modelMatrix *= Transform3D::RotateOY(player->getRotationAngle().y);

		RenderSimpleMesh(player->getSphere(), shaders["ShaderTema2Text"], modelMatrix, mapTextures["duck"], NULL);
		
	}
}

void Tema2::renderFuelBar() {

	float fuel_proc = player->getFuel() / (float) MAX_FUEL;

	float scale_x = window->GetResolution().x / 10.f;
	float scale_y = window->GetResolution().y / 20;

	float translate_x = window->GetResolution().x / 12;
	float translate_y = window->GetResolution().y / 9 * 8;

	// render front rectangle
	glm::mat3 modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translate_x - (scale_x / 2) + (scale_x * fuel_proc) / 2, translate_y);
	modelMatrix *= Transform2D::Scale(scale_x * fuel_proc, scale_y);
	Tema2::RenderMesh2D(fuelBar.rectangle_front, shaders["VertexNormal"], modelMatrix);

	// render back rectangle
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translate_x, translate_y);
	modelMatrix *= Transform2D::Scale(scale_x, scale_y);
	Tema2::RenderMesh2D(fuelBar.rectangle_back, shaders["VertexNormal"], modelMatrix);

	float x = window->GetResolution().x / 10 * 8;
	float y = window->GetResolution().y / 10 * 9;

	if (lives > 0) {
		// render back rectangle
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(x, y);
		modelMatrix *= Transform2D::Scale(0.5, 0.5);
		Tema2::RenderMesh2D(life1, shaders["VertexNormal"], modelMatrix);
	}
	
	if (lives > 1) {
		// render back rectangle
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(x + window->GetResolution().x / 20 * 1.5, y);
		modelMatrix *= Transform2D::Scale(0.5, 0.5);
		Tema2::RenderMesh2D(life2, shaders["VertexNormal"], modelMatrix);
	}
	
	if (lives > 2) {
		// render back rectangle
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(x + window->GetResolution().x / 20 * 3, y);
		modelMatrix *= Transform2D::Scale(0.5, 0.5);
		Tema2::RenderMesh2D(life3, shaders["VertexNormal"], modelMatrix);
	}
}

void Tema2::apply_buff(float deltaTimeSeconds) {
	// check buffs
	if (player->getBuffTime() > 0 && player->getBuffType() != BLUE_BUFF && player->getBuffType() != LIFE_BUFF) {

		glm::vec3 color;

		int buff_type = player->getBuffType();
		switch (buff_type) {
		case GREEN_BUFF:
			player->setFuel(min(player->getFuel() + 2 * deltaTimeSeconds * player->getSpeed(), MAX_FUEL));
			color = glm::vec3(0, 0, 1);
			break;
		case YELLOW_BUFF:
			player->setFuel(max(player->getFuel() - deltaTimeSeconds * player->getSpeed(), 0));
			color = glm::vec3(1, 1, 0);
			break;
		case ORANGE_BUFF:
			player->setSpeed(CAMERA_MAX_SPEED);
			color = glm::vec3(1, 0.6, 0);
			break;
		case RED_BUFF:
			exit(1);
			break;
		}

		player->setBuffTime(player->getBuffTime() - deltaTimeSeconds);
		if (player->getBuffTime() <= 0 && player->getBuffType() == ORANGE_BUFF) {
			player->setSpeed(CAMERA_MIN_SPEED);
		}

		glm::mat4 modelMatrix(1);
		modelMatrix *= Transform3D::Translate(player->getPosition().x, player->getPosition().y, player->getPosition().z);
		modelMatrix *= Transform3D::Scale(0.05, 0.05, 0.05);
		modelMatrix *= Transform3D::RotateOY(RADIANS(180));
		modelMatrix *= Transform3D::RotateOY(player->getRotationAngle().y);
		
		if(renderCameraTarget) RenderSimpleMesh(player->getSphere(), shaders["ShaderTema2Deformare"], modelMatrix, mapTextures["duck"], NULL, color);

	}

}

void Tema2::deadAnimation(float deltaTimeSeconds) {
	
		if (player->getPosition().y > -MAX_JUMP) {
			camera->TranslateUpword(-deltaTimeSeconds * 1);
			player->setSpherePosition(player->getPosition() - glm::vec3(0, deltaTimeSeconds * 1, 0));
			player->setOffset(player->getOffset() - glm::vec3(0, deltaTimeSeconds * 1, 0));
		}
		else {
			exit(1);
		}
}

void Tema2::getConfigurations()
{
	srand((time(NULL)));

	// configuration 0
	configurations.push_back(createConfiguration(0, true, true, true));

	// configuration 1
	configurations.push_back(createConfiguration(1, true, true, false));

	// configuration 2
	configurations.push_back(createConfiguration(2, false, true, true));

	// configuration 3
	configurations.push_back(createConfiguration(3, true, false, true));
	configurations[3].invalid_configurations.push_back(4);
	configurations[3].invalid_configurations.push_back(6);

	// configuration 4
	configurations.push_back(createConfiguration(4, true, false, false));
	configurations[4].invalid_configurations.push_back(6);

	// configuration 5
	configurations.push_back(createConfiguration(5, false, true, false));

	// configuration 6
	configurations.push_back(createConfiguration(6, false, false, true));
	configurations[6].invalid_configurations.push_back(4);

}

struct configuration Tema2::createConfiguration(int num, bool left, bool middle, bool right)
{
	struct configuration conf;
	conf.number = num;
	conf.left = left;
	conf.middle = middle;
	conf.right = right;
	return conf;
}

void Tema2::get_configuration_number(int& config_num, int& prev_config_num)
{
	while (1) {
		config_num = randomNum(CONFIGURATIONS_NUM + 1);

		if (config_num != 0) config_num = config_num - 1;

		if (prev_config_num == -1) return;
		int size = configurations[prev_config_num].invalid_configurations.size();
		int j;
		for (j = 0; j < size; j++) {
			if (configurations[prev_config_num].invalid_configurations[j] == config_num) {
				break;
			}
		}
		if (j == size) {
			break;
		}
	}
}



void Tema2::replace_platform(std::vector<Platform*>& platform_line, std::vector<Platform*>& platform)
{
	// position of the farthest platform
	glm::vec3 offset = platforms[platforms.size() - 1][0]->getPos();
	
	// generate a configuration number
	int config_num;
	int prev_config_num = platforms[platforms.size() - 1][0]->getConfiguration();

	get_configuration_number(config_num, prev_config_num);

	// generate platform length
	double platform_length = 1;

	// compute platform position
	float gap = (float) coinToss(0.2) ;
	if (gap == 0) gap = 0.1;

	if (platforms[platforms.size() - 1][0]->getObstacleDistance() > 0) gap = 0.1;

	double new_offset = platforms[platforms.size() - 1][0]->getPos().z + platforms[platforms.size() - 1][0]->getLength()  + platform_length  + gap;

	int ct = 0;
	int size = platform_line.size();
	
	// generate default_color
	glm::vec3 default_color = glm::vec3(0, 1, 0);
	int default_color_name = BLUE_BUFF;


	int sum = configurations[config_num].left + configurations[config_num].middle + configurations[config_num].right;
	if (configurations[config_num].left) {

		bool green = coinToss(0.10);

		if (green) {
			default_color_name = GREEN_BUFF;
		}

		std::string collectable_type = "none";
		collectable_type = generate_collectable();

		glm::vec3 position_offset = glm::vec3((-1.7) * TILE_GAP + 0.2, 0.02, new_offset);
		modify_platform(platform_line, ct, position_offset, platform_length, config_num,  default_color_name, green, 0, collectable_type);

		Platform* plat = platform_line[ct];
		platform.push_back(plat);

		ct++;
	} else {
		// randomize if another tile will be spawn
		int additional_tile = coinToss(0.3);
		if (additional_tile) {
			// generate auxiliary_platform color
			int color_name = -1;

			generate_color(color_name);

			// generate obstacle
			float obstacleDistance = 0;

			// randomize the spawning of an obstacle
			bool obstacle = coinToss(OBSTACLE_PROB);
			
			// spawn green
			bool green = coinToss(0.10);

			if (green) {
				color_name = GREEN_BUFF;
			}

			// spawn obstacle
			if (obstacle) {
				if (!((int)gap)) {
					obstacleDistance = OBSTACLE_DISTANCE;
				}
				else {
					obstacle = false;
				}
			}

			// spawn obstacle
			std::string collectable_type = "none";
			if (!obstacle) collectable_type = generate_collectable();

			glm::vec3 position_offset = glm::vec3((-1.7) * TILE_GAP + 0.2, 0.02, new_offset);

			Platform* middle = new Platform(position_offset, platform_length, config_num, true, color_name, obstacleDistance, collectable_type);
			platform.push_back(middle);

			ct++;
			sum++;
		}
	}

	if (configurations[config_num].middle) {
		default_color_name = BLUE_BUFF;
		bool green = coinToss(0.10);

		if (green) {
			default_color_name = GREEN_BUFF;
		}

		glm::vec3 position_offset = glm::vec3(0.3, 0.02, new_offset);

		std::string collectable_type = "none";
		collectable_type = generate_collectable();

		if (ct < size) {
			modify_platform(platform_line, ct, position_offset, platform_length, config_num,  default_color_name, green, 0, collectable_type);
			platform.push_back(platform_line[ct]);
		}
		else {
			Platform* middle = new Platform(position_offset, platform_length, config_num,  green, default_color_name, 0, collectable_type);
			platform.push_back(middle);
		}
		ct++;

	} else {
		// randomize if another tile will be spawn
		int additional_tile = coinToss(0.3);
		if (additional_tile) {

			bool special = false;
			// generate auxiliary_platform color
			int color_name = BLUE_BUFF;
			generate_color(color_name);

			// generate obstacle
			float obstacleDistance = 0;

			// randomize the spawning of an obstacle
			bool obstacle = coinToss(OBSTACLE_PROB);

			// spawn green
			bool green = coinToss(0.10);

			if (green) {
				color_name = GREEN_BUFF;
			}

			// spawn obstacle
			if (obstacle) {
				if (!(int)gap) {
					obstacleDistance = OBSTACLE_DISTANCE;
				}
				else {
					obstacle = false;
				}
			}

			// spawn obstacle

			std::string collectable_type = "none";
			if (!obstacle) collectable_type = generate_collectable();

			glm::vec3 position_offset = glm::vec3(0.3, 0.02, new_offset);

			Platform* middle = new Platform(position_offset, platform_length, config_num, true, color_name, obstacleDistance, collectable_type);
			platform.push_back(middle);
			sum++;

		}
	}

	if (configurations[config_num].right) {
		default_color_name = BLUE_BUFF;
		bool green = coinToss(0.10);

		if (green) {
			default_color_name = GREEN_BUFF;
		}

		std::string collectable_type = "none";
		collectable_type = generate_collectable();

		glm::vec3 position_offset = glm::vec3(1.7 * TILE_GAP + 0.2, 0.02, new_offset);
		if (ct < size){
			modify_platform(platform_line, ct, position_offset, platform_length, config_num, default_color_name, green, 0, collectable_type);
			platform.push_back(platform_line[ct]);
		}
		else {
			Platform* right = new Platform(position_offset, platform_length, config_num, green, default_color_name, 0, collectable_type);
			platform.push_back(right);
		}
	} else {
		// randomize if another tile will be spawn
		int additional_tile = coinToss(0.3);
		if (additional_tile) {

			
			// generate auxiliary_platform color
			int color_name = BLUE_BUFF;
			generate_color(color_name);

			// generate obstacle
			float obstacleDistance = 0;

			// randomize the spawning of an obstacle
			bool obstacle = coinToss(OBSTACLE_PROB);

			// spawn green
			bool green = coinToss(0.10);

			if (green) {
				color_name = GREEN_BUFF;
			}

			// spawn obstacle
			if (obstacle) {

				if (!(int)gap) {
					obstacleDistance = OBSTACLE_DISTANCE;
				}
				else {
					obstacle = false;
				}
			}

			// spawn obstacle

			std::string collectable_type = "none";
			if (!obstacle) collectable_type = generate_collectable();

			glm::vec3 position_offset = glm::vec3(1.7 * TILE_GAP + 0.2, 0.02, new_offset);

			Platform* middle = new Platform(position_offset, platform_length, config_num, true, color_name, obstacleDistance, collectable_type);
			platform.push_back(middle);

		}
	}

}

void Tema2::modify_platform(std::vector<Platform*>& platform_line, int ct, glm::vec3 position_offset, double platform_length, int config_num, 
	int color_name, bool special, bool obstacle, std::string collectable_type) {

	platform_line[ct]->setPosition(position_offset);
	platform_line[ct]->setLength(platform_length);
	platform_line[ct]->setConfiguration(config_num); 
	platform_line[ct]->setSpecial(special);
	platform_line[ct]->setColorName(color_name);
	platform_line[ct]->setObstacleDistance(0);
	platform_line[ct]->setHitObstacle(false);
	platform_line[ct]->setCollectable(collectable_type);
	platform_line[ct]->setCollected(false);

	if (obstacle) {
		platform_line[ct]->setObstacle();
		platform_line[ct]->setObstacleDistance(OBSTACLE_DISTANCE);
	}
}

void Tema2::generate_color( int& color_name) {
	color_name = randomNum(5);
}

float Tema2::generatePlatformLength() {
	double platform_length = randomNum(MAX_PLATFORM_LENGTH);
	if (platform_length < MIN_PLATFORM_LENGTH) {
		platform_length += MIN_PLATFORM_LENGTH - platform_length;
	}
	platform_length *= 0.7;
	return platform_length;
}

void Tema2::delete_old_platforms(std::vector<int> to_delete)
{
	int count = 0;
	if (to_delete.size() > 0) {
		int to_del = to_delete[to_delete.size() - 1];
		for (auto it = platforms.begin(); it != platforms.end(); ) {
			bool del = false;
			if (count <= to_del) {
				it = platforms.erase(it);
			}
			else {
				it++;
			}
			count++;
		}
	}
}

Mesh* Tema2::createRectangle(glm::vec3 color)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(-0.5, -0.5,  0), glm::vec3(1, 1, 1), color),
		VertexFormat(glm::vec3(0.5, -0.5,  0), glm::vec3(1, 1, 1), color),
		VertexFormat(glm::vec3(-0.5, 0.5,  0), glm::vec3(1, 1, 1), color),
		VertexFormat(glm::vec3(0.5,  0.5,  0), glm::vec3(1, 1, 1), color),
	};

	std::vector<unsigned short> indices = { 0, 1, 2,		1, 3, 2, };

	return CreateMesh("rectangle", vertices, indices);
}

void Tema2::createLives() {
	std::vector<VertexFormat> vertices1;
	std::vector<unsigned short> indices1;

	std::vector<VertexFormat> vertices2;
	std::vector<unsigned short> indices2;

	std::vector<VertexFormat> vertices3;
	std::vector<unsigned short> indices3;

	float angle;
	float radius = window->GetResolution().x / 20;
	for (unsigned short i = 0; i < 1000; i++)
	{
		angle = 2 * 3.14 * i / 50;

		vertices1.emplace_back(glm::vec3(cos(angle) * radius, sin(angle) * radius, 1), glm::vec3(1, 0, 0));
		indices1.push_back(i);

		vertices2.emplace_back(glm::vec3(cos(angle) * radius, sin(angle) * radius, 1), glm::vec3(1, 0, 0));
		indices2.push_back(i);

		vertices3.emplace_back(glm::vec3(cos(angle) * radius, sin(angle) * radius, 1), glm::vec3(1, 0, 0));
		indices3.push_back(i);
	}

	vertices1.emplace_back(glm::vec3(cos(0.785) * radius, sin(0.785) * radius, 1), glm::vec3(1, 0, 0));
	indices1.push_back(50);

	vertices2.emplace_back(glm::vec3(cos(0.785) * radius, sin(0.785) * radius, 1), glm::vec3(1, 0, 0));
	indices2.push_back(50);

	vertices3.emplace_back(glm::vec3(cos(0.785) * radius, sin(0.785) * radius, 1), glm::vec3(1, 0, 0));
	indices3.push_back(50);

	life1 = new Mesh("life1");
	life1->SetDrawMode(GL_TRIANGLE_FAN);
	life1->InitFromData(vertices1, indices1);

	life2 = new Mesh("life2");
	life2->SetDrawMode(GL_TRIANGLE_FAN);
	life2->InitFromData(vertices2, indices2);

	life3 = new Mesh("life3");
	life3->SetDrawMode(GL_TRIANGLE_FAN);
	life3->InitFromData(vertices3, indices3);

	extraLife = new Mesh("extraLife");
	extraLife->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
}


Mesh* Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	unsigned int VAO = 0;
	// TODO: Create the VAO and bind it
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// TODO: Create the VBO and bind it
	unsigned int VBO = 0;
	glGenBuffers(1, &VBO);	// se genereaza ID-ul (numele) bufferului
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// TODO: Send vertices data into the VBO buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// TODO: Crete the IBO and bind it
	unsigned int IBO = 0;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	// ========================================================================

	// TODO: Unbind the VAO
	glBindVertexArray(0);
	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes[name];
}



void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D* texture1, Texture2D* texture2, glm::vec3 color, int light_source)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;


	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);


	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = camera->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	glUniform3fv(glGetUniformLocation(shader->program, "lightPosition"), lightCount, &lightPosition[0][0]);

	glUniform3fv(glGetUniformLocation(shader->program, "lightDirection"), lightCount, &lightDirection[0][0]);

	glUniform3fv(glGetUniformLocation(shader->program, "lightColours"), lightCount, &lightColours[0][0]);

	glUniform1iv(glGetUniformLocation(shader->program, "spotlight"), lightCount, spotlight);

	glUniform1i(glGetUniformLocation(shader->program, "lightCount"),
		lightCount);

	// TODO: Set eye position (camera position) uniform
	glm::vec3 eyePosition = camera->GetTargetPosition();
	int eye_position = glGetUniformLocation(shader->program, "eye_position");
	glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

	// TODO: Set material property uniforms (shininess, kd, ks, object color) 
	int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(material_shininess, materialShininess);

	int material_kd = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(material_kd, materialKd);


	int material_ks = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(material_ks, materialKs);

	glUniform1i(glGetUniformLocation(shader->program, "light_source"), light_source);

	// object color
	if (color != glm::vec3(-1, -1, -1)) {
		int object_color = glGetUniformLocation(shader->program, "object_color");
		glUniform3f(object_color, color.r, color.g, color.b);
	}

	int text2 = 0;
	if (texture2 != NULL) {
		text2 = 1;
	}
	// Bind texture 2 int
	GLint texture_2 = glGetUniformLocation(shader->program, "text_2");
	glUniform1i(texture_2, text2);


	if (texture1)
	{
		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());

		glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);

	}

	if (texture2)
	{

		glActiveTexture(GL_TEXTURE1);

		glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());

		glUniform1i(glGetUniformLocation(shader->program, "texture_2"), 1);
	}

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}


void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
	if (!mesh || !shader || !shader->program)
		return;

	// render an object using the specified shader and the specified position
	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	mesh->Render();
}

void Tema2::RenderMesh2D(Mesh* mesh, Shader* shader, const glm::mat3& modelMatrix)
{
	if (!mesh || !shader || !shader->program)
		return;

	shader->Use();

	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera2D->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(orthoMatrix));

	glm::mat3 mm = modelMatrix;
	glm::mat4 model = glm::mat4(
		mm[0][0], mm[0][1], mm[0][2], 0.f,
		mm[1][0], mm[1][1], mm[1][2], 0.f,
		0.f, 0.f, mm[2][2], 0.f,
		mm[2][0], mm[2][1], 0.f, 1.f);

	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(model));
	mesh->Render();
}

