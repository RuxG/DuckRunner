#include "Laborator9.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>

#include "Laboratoare/Laborator4/Transform3D.h"


using namespace std;

Laborator9::Laborator9()
{
}

Laborator9::~Laborator9()
{
}



void Laborator9::Init()
{
	const string textureLoc = "Source/Laboratoare/Laborator9/Textures/";

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grass_bilboard.png").c_str(), GL_REPEAT);
		mapTextures["grass"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grass.png").c_str(), GL_REPEAT);
		mapTextures["grass2"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grass_mirror.png").c_str(), GL_REPEAT);
		mapTextures["grass_mirror"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "water2.jpg").c_str(), GL_REPEAT);
		mapTextures["water"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "stufaris.png").c_str(), GL_REPEAT);
		mapTextures["stufaris"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "stufaris2.jpg").c_str(), GL_REPEAT);
		mapTextures["stufaris2"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "stufaris3.png").c_str(), GL_REPEAT);
		mapTextures["stufaris3"] = texture;
	}

	// Load textures
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "stufaris4.png").c_str(), GL_REPEAT);
		mapTextures["stufaris4"] = texture;
	}

	

	/*{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "crate.jpg").c_str(), GL_REPEAT);
		mapTextures["crate"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "earth.png").c_str(), GL_REPEAT);
		mapTextures["earth"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Models/Vegetation/Bamboo/bamboo.png", GL_REPEAT);
		mapTextures["bamboo"] = texture;
	}


	{
		mapTextures["random"] = CreateRandomTexture(32, 32);
	}*/

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/chicken.png", GL_REPEAT);
		mapTextures["chicken"] = texture;
	}
	
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/Textures/yellow_grass.png", GL_REPEAT);
		mapTextures["yellow_grass"] = texture;
	}
	
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/lilypad.png", GL_REPEAT);
		mapTextures["lilypad"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/cattail.jpg", GL_REPEAT);
		mapTextures["cattail"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/green.jpg", GL_REPEAT);
		mapTextures["green"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/Textures/ciuperca.png", GL_REPEAT);
		mapTextures["ciuperca"] = texture;
	}
	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Source/Laboratoare/Laborator9/Textures/white.jpg", GL_REPEAT);
		mapTextures["white"] = texture;
	}

	// Load meshes
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("bamboo");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Vegetation/Bamboo/", "bamboo.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("chicken");
		mesh->LoadMesh("Source/Laboratoare/Laborator9/" , "chicken.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	



	// Create a simple quad
	{
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

		// TODO : Complete texture coordinates for the square
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

		Mesh* mesh = new Mesh("square");
		mesh->InitFromData(vertices, normals, textureCoords, indices);
		meshes[mesh->GetMeshID()] = mesh;
	}

	// Create a cool quad
	{
		vector<glm::vec3> vertices2
		{
			glm::vec3(0.5f,   2.5f, 0.0f),	// Top Right
			glm::vec3(0.5f,  1.5f, 0.0f),	// Bottom Right
			glm::vec3(-0.5f,  1.5f, 0.0f),	// Bottom Left
			glm::vec3(-0.5f,  2.5f, 0.0f),	// Top Left
		};

		vector<glm::vec3> normals2
		{
			glm::vec3(0, 1, 1),
			glm::vec3(1, 0, 1),
			glm::vec3(1, 0, 0),
			glm::vec3(0, 1, 0)
		};

		// TODO : Complete texture coordinates for the square
		glm::vec3 offset(0.5f, 0.5f, 0.0f);

		vector<glm::vec2> textureCoords2
		{
			glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1), glm::vec2(0, 0)
		};

		vector<unsigned short> indices2 =
		{
			0, 1, 3,
			1, 2, 3
		};

		Mesh* mesh2 = new Mesh("cool_square");
		mesh2->InitFromData(vertices2, normals2, textureCoords2, indices2);
		meshes[mesh2->GetMeshID()] = mesh2;
	}

	
	Mesh* circle = new Mesh("circle");
	circle->SetDrawMode(GL_TRIANGLE_FAN);

	std::vector<glm::vec3> vertices;
	std::vector<unsigned short> indices;

	std::vector<glm::vec2> textCoord;

	float radius = 1;

	std::vector <glm::vec3> normals{ glm::vec3(0, 1, 0) };

	double angle;
	for (int i = 0; i <= 50; i++) {

		angle = 180 * (float)i / (float)50 - 90;
		angle = RADIANS(angle);
		//angle = 1.8 * 3.14 * i / 50 + 100;

		float y = radius * sin(angle) ;
		float x = radius * cos(angle) ;


		float tx = (cos(angle) / radius + 1) * 0.5;
		float ty = (sin(angle) / radius + 1) * 0.5;
		textCoord.push_back(glm::vec2(tx, ty));

		
		vertices.push_back(glm::vec3(x, 0, y));
		
		indices.push_back(i);
		
		
	}

	

	circle->InitFromData(vertices, normals, textCoord, indices);

	meshes[circle->GetMeshID()] = circle;
	vector<glm::vec3> vertices2
	{
		glm::vec3(-1, -1,  1),
		glm::vec3(0, -1,  1),
		glm::vec3(-1, 0,  1),
		glm::vec3(0, 0,  1),
		glm::vec3(-1, -1,  0),
		glm::vec3(0, -1,  0),
		glm::vec3(-1, 0,  0),
		glm::vec3(0, 0,  0)
	};

	vector<unsigned short> indices2 =
	{
		0, 1, 2,
		1, 3, 2,
		2, 3, 7,
		2, 7, 6,
		1, 7, 3,
		1, 5, 7,
		6, 7, 4,
		7, 5, 4,
		0, 4, 1,
		1, 4, 5,
		2, 6, 4,
		0, 2, 4
	};

	
	std::vector<glm::vec2> textCoord2 = {
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1),
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1),
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1),
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1),
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1),
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1)
	};



	Mesh* cube = new Mesh("cube1");
	cube->InitFromData(vertices2, normals, textCoord2, indices2);
	meshes[cube->GetMeshID()] = cube;


	// Create a new mesh from buffer data
	//Mesh* cube = CreateMesh("cube3", vertices, indices);


	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader *shader = new Shader("ShaderLab9");
		shader->AddShader("Source/Laboratoare/Laborator9/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Laborator9/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
}

void Laborator9::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);	
}

void Laborator9::Update(float deltaTimeSeconds)
{
	/*{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(1, 1, -3));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(2));
		RenderSimpleMesh(meshes["sphere"], shaders["ShaderLab9"], modelMatrix, mapTextures["earth"]);
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(2, 0.5f, 0));
		modelMatrix = glm::rotate(modelMatrix, RADIANS(60.0f), glm::vec3(1, 0, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f));
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["crate"]);
	}*/

	/*{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-2, 0.5f, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.75f));
		modelMatrix = glm::rotate(modelMatrix, RADIANS(75.0f), glm::vec3(1, 1, 0));
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["random"]);
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.5f, 0.0f));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass"]);
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-2, -0.5f, -3));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
		RenderSimpleMesh(meshes["bamboo"], shaders["ShaderLab9"], modelMatrix, mapTextures["bamboo"]);
	}*/

	/*{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.5f, 0.0f));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
		RenderSimpleMesh(meshes["cool_square"], shaders["ShaderLab9"], modelMatrix, mapTextures["earth"], mapTextures["random"]);
	}*/

	
	/*{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 2, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
		RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["random"]);
		RenderSimpleMesh(meshes["circle2"], shaders["ShaderLab9"], modelMatrix, mapTextures["random"]);
		RenderSimpleMesh(meshes["chestie"], shaders["ShaderLab9"], modelMatrix, mapTextures["random"]);
	} */


	


			/*
			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.3f, 0.8f, 2 + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.4f);
			modelMatrix *= Transform3D::RotateOY(1.7f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 1.9f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.3f);
			modelMatrix *= Transform3D::RotateOX(-0.1f);
			modelMatrix *= Transform3D::RotateOY(2.2f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 1.7f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.2f);
			modelMatrix *= Transform3D::RotateOX(-0.3f);
			modelMatrix *= Transform3D::RotateOY(2.45f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);*/

			

		
		float offset = 0;
		
		{

			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(0));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(72));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(144));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(216));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(288));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(360));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			/// <summary>
			/// ////
			/// </summary>
			/// <param name="deltaTimeSeconds"></param>

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(0));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(20));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(72));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(20));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(144));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(20));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(216));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(30));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(288));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(20));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(360));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(20));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			/// <summary>
		/// ////
		/// </summary>
		/// <param name="deltaTimeSeconds"></param>

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(0));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(40));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(72));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(20));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(144));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(40));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(216));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(40));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(288));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(40));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2);
			modelMatrix *= Transform3D::RotateOY(RADIANS(360));
			modelMatrix *= Transform3D::RotateOZ(RADIANS(40));
			modelMatrix *= Transform3D::Scale(1.5f, 1, 0.5);
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

		}
		


		offset = 1;
		
		{

			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2 + offset);
			modelMatrix *= Transform3D::Scale(0.01f, 1, 0.01f);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 1.2f, 2 + offset);
			modelMatrix *= Transform3D::Scale(0.03f, 0.7f, 0.03f);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["cattail"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 1.5f, 2 + offset);
			modelMatrix *= Transform3D::Scale(0.008f, 0.3f, 0.008f);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["cattail"]);

			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.8f, 2.2f + offset));
			modelMatrix *= Transform3D::RotateOX(0.3f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 2.2f + offset));
			modelMatrix *= Transform3D::RotateOY(0.4f);
			modelMatrix *= Transform3D::RotateOX(0.3f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.6f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.3f, 0.8f, 2.1f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.3f);
			modelMatrix *= Transform3D::RotateOX(0.15f);
			modelMatrix *= Transform3D::RotateOY(0.8f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.4f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);



			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.3f, 0.8f, 2 + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.4f);
			modelMatrix *= Transform3D::RotateOY(1.7f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.7f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 1.7f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.2f);
			modelMatrix *= Transform3D::RotateOX(-0.3f);
			modelMatrix *= Transform3D::RotateOY(2.45f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 1.9f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.3f);
			modelMatrix *= Transform3D::RotateOX(-0.1f);
			modelMatrix *= Transform3D::RotateOY(2.2f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.3f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);

		}

		offset = 1.7;

		{

			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 0.5f, 2 + offset);
			modelMatrix *= Transform3D::Scale(0.01f, 1, 0.01f);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 1.2f, 2 + offset);
			modelMatrix *= Transform3D::Scale(0.03f, 0.7f, 0.03f);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["cattail"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f, 1.5f, 2 + offset);
			modelMatrix *= Transform3D::Scale(0.008f, 0.3f, 0.008f);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["cattail"]);

			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.8f, 2.2f + offset));
			modelMatrix *= Transform3D::RotateOX(0.3f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 2.2f + offset));
			modelMatrix *= Transform3D::RotateOY(0.4f);
			modelMatrix *= Transform3D::RotateOX(0.3f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.6f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.3f, 0.8f, 2.1f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.3f);
			modelMatrix *= Transform3D::RotateOX(0.15f);
			modelMatrix *= Transform3D::RotateOY(0.8f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.4f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);



			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(0.3f, 0.8f, 2 + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.4f);
			modelMatrix *= Transform3D::RotateOY(1.7f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.7f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 1.7f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.2f);
			modelMatrix *= Transform3D::RotateOX(-0.3f);
			modelMatrix *= Transform3D::RotateOY(2.45f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= glm::translate(modelMatrix, glm::vec3(0.2f, 0.8f, 1.9f + offset));
			modelMatrix *= Transform3D::RotateOZ(-0.3f);
			modelMatrix *= Transform3D::RotateOX(-0.1f);
			modelMatrix *= Transform3D::RotateOY(2.2f);
			modelMatrix *= Transform3D::Scale(0.1f, 1.3f, 0.5f);
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);

		}
		offset = 0;

		// INVERS


		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-4.5, 0.5f, 2 + offset);
		modelMatrix *= Transform3D::Scale(0.01f, 1, 0.01f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["green"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-4.5, 1.2f, 2 + offset);
		modelMatrix *= Transform3D::Scale(0.03f, 0.7f, 0.03f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["cattail"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(-4.5, 1.5f, 2 + offset);
		modelMatrix *= Transform3D::Scale(0.008f, 0.3f, 0.008f);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["cattail"]);

		modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-4.5, 0.8f, 2.2 + offset));
		modelMatrix *= Transform3D::RotateOX(0.3f);
		modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

		modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-4.5 - 0.1f, 0.8f, 2.32 + offset));
		modelMatrix *= Transform3D::RotateOY(-0.4f);
		modelMatrix *= Transform3D::RotateOX(0.3f);
		modelMatrix *= Transform3D::Scale(0.1f, 1.6f, 0.5f);
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);

		modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-4.5 - 0.2f, 0.8f, 1.8+ offset));
		modelMatrix *= Transform3D::RotateOZ(+0.3f);
		modelMatrix *= Transform3D::RotateOX(-0.15f);
		modelMatrix *= Transform3D::RotateOY(-0.8f);
		modelMatrix *= Transform3D::Scale(0.1f, 1.4f, 0.5f);
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= glm::translate(modelMatrix, glm::vec3(-4.5f - 0.15f, 0.8f, 2 + offset));
		modelMatrix *= Transform3D::RotateOZ(+0.3f);
		modelMatrix *= Transform3D::RotateOX(0.1f);
		modelMatrix *= Transform3D::RotateOY(-1.4f);
		modelMatrix *= Transform3D::Scale(0.1f, 1.3f, 0.5f);
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass_mirror"]);

		modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(-4.5 - 0.3f, 0.8f, 2 + offset));
		modelMatrix *= Transform3D::RotateOZ(0.4f);
		modelMatrix *= Transform3D::RotateOY(-1.7f);
		modelMatrix *= Transform3D::Scale(0.1f, 1.7f, 0.5f);
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= glm::translate(modelMatrix, glm::vec3(-4.5 - 0.2f, 0.8f, 2.3 + offset));
		modelMatrix *= Transform3D::RotateOZ(0.2f);
		modelMatrix *= Transform3D::RotateOX(0.3f);
		modelMatrix *= Transform3D::RotateOY(-2.45f);
		modelMatrix *= Transform3D::Scale(0.1f, 1.8f, 0.5f);
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["grass2"]);

		


		// DUCK
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-1.f, 0.4f, 2.8f));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05f));
			RenderSimpleMesh(meshes["chicken"], shaders["ShaderLab9"], modelMatrix, mapTextures["chicken"]);
		}



		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-1.f, 0.001, 2.8f));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["lilypad"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-2.1f, 0.001, 2.1f));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["lilypad"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(-3.1f, 0.001, 3.1f));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
			RenderSimpleMesh(meshes["circle"], shaders["ShaderLab9"], modelMatrix, mapTextures["lilypad"]);
		}



		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 0.5, -0.05, 2);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 1.5, -0.05, 2);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 2.5, -0.05, 2);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 3.5, -0.05, 2);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 1.5, -0.05, 2 + 1);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 0.5, -0.05, 3);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 2.5, -0.05, 2 + 1);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 3.5, -0.05, 2 + 1);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 1.5, -0.05, 4);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 0.5, -0.05, 4);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 2.5, -0.05,4);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}
		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f - 3.5, -0.05, 4);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["water"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f + 0.5, -0.05, 2);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f + 0.5, -0.05, 3);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0.0f + 0.5, -0.05, 4);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}


		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(-4 - 0.5, -0.05, 2);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(-4 - 0.5, -0.05, 3);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}

		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(-4- 0.5, -0.05, 4);
			modelMatrix *= Transform3D::Scale(1, 0.1f, 1);
			RenderSimpleMesh(meshes["box"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}


		{
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(4, 2, 4);

			RenderSimpleMesh(meshes["cube1"], shaders["ShaderLab9"], modelMatrix, mapTextures["stufaris"]);
		}


}

void Laborator9::FrameEnd()
{
	DrawCoordinatSystem();
}

void Laborator9::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1, Texture2D* texture2)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

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

Texture2D* Laborator9::CreateRandomTexture(unsigned int width, unsigned int height)
{
	GLuint textureID = 0;
	unsigned int channels = 3;
	unsigned int size = width * height * channels;
	unsigned char* data = new unsigned char[size];

	// TODO: generate random texture data
	srand(time(NULL));
	
	textureID = randomTextureID;

	for (int i = 0; i < size; i++) {
		data[i] = rand() % 256;
	}
	// Generate and bind the new texture ID
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// TODO: Set the texture parameters (MIN_FILTER, MAG_FILTER and WRAPPING MODE) using glTexParameteri
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // modul de wrapping pe orizontala
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // modul de wrapping pe verticala


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);

	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	CheckOpenGLError();

	// TODO: Use glTextImage2D to set the texture data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// TODO: Generate texture mip-maps
	glGenerateMipmap(GL_TEXTURE_2D);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	CheckOpenGLError();

	// Save the texture into a wrapper Texture2D class for using easier later during rendering phase
	Texture2D* texture = new Texture2D();
	texture->Init(textureID, width, height, channels);

	SAFE_FREE_ARRAY(data);
	return texture;
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator9::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = GetSceneCamera()->transform->GetLocalOXVector();
		glm::vec3 forward = GetSceneCamera()->transform->GetLocalOZVector();
		forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));
	}
}

void Laborator9::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Laborator9::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator9::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator9::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator9::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator9::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator9::OnWindowResize(int width, int height)
{
}
