#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;

		Mesh* mesh2 = new Mesh("teapot");
		mesh2->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mesh2->GetMeshID()] = mesh2;

		Mesh* mesh3 = new Mesh("sphere");
		mesh3->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh3->GetMeshID()] = mesh3;

		Mesh* pepe = new Mesh("pepe");
		pepe->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "pepe.obj");
		meshes[pepe->GetMeshID()] = pepe;
	}
}

void Laborator1::FrameStart()
{

}

void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	if (changeColour == true) {
		glClearColor(1, 1, 0, 1);
	}
	else {
		glClearColor(0, 0, 0, 1);
	}
	// sets the clear color for the color buffer

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// comute between objects
	switch (object % 3) {
		case 0:
			// render the object
			RenderMesh(meshes["box"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));
			break;
		case 1:
			// render the object
			RenderMesh(meshes["sphere"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));
			break;
		case 2:
			// render the object
			RenderMesh(meshes["teapot"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));
			break;
		default:
			break;
	}

	// render the object that is going to move continiously
	RenderMesh(meshes["box"], glm::vec3(cubeX, cubeZ, cubeY), glm::vec3(0.5f));

	// render the object that is going to move with CTRL
	RenderMesh(meshes["teapot"], glm::vec3(teapotX, teapotZ, teapotY));

	// render the object that is going to move with CTRL
	RenderMesh(meshes["pepe"], glm::vec3(4,4,4));

}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input

	// change object's coordinates
		if (window->KeyHold(GLFW_KEY_W)) {
			cubeX += deltaTime * factor;
		} else if(window->KeyHold(GLFW_KEY_A)) {
			cubeY -= deltaTime * factor;
		}
		else if (window->KeyHold(GLFW_KEY_S)) {
			cubeX -= deltaTime * factor;
		}
		else if (window->KeyHold(GLFW_KEY_D)) {
			cubeY += deltaTime * factor;
		}
		else if (window->KeyHold(GLFW_KEY_Q)) {
			cubeZ -=  deltaTime * factor;
		}
		else if (window->KeyHold(GLFW_KEY_E)) {
			cubeZ += deltaTime * factor;
		}
};

void Laborator1::OnKeyPress(int key, int mods)
{	
	// a key was pressed, the colour should be changed
	changeColour = !changeColour;
	
	// a key was pressed, change an object into another
	object = (object + 1) % 3;

	// check if CTRL + "KEY" was pressed and change object's coordinates
	if (mods == GLFW_MOD_CONTROL) {
		if (key == GLFW_KEY_W) {
			teapotX++;
		}
		else if (key == GLFW_KEY_A) {
			teapotY--;
		}
		else if (key == GLFW_KEY_S) {
			teapotX--;
		}
		else if (key == GLFW_KEY_D) {
			teapotY++;
		}
		else if (key == GLFW_KEY_Q) {
			teapotZ--;
		}
		else if (key == GLFW_KEY_E) {
			teapotZ++;
		}
	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}
