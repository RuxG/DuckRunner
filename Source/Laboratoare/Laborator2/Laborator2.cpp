#include "Laborator2.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

Laborator2::Laborator2()
{
}

Laborator2::~Laborator2()
{

}

void Laborator2::Init()
{	
	cullFace = GL_BACK;
	polygonMode = GL_FILL;

	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	// Create a mesh box using custom data
	{
		vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(-1, -1,  1), glm::vec3(0, 0.25f, 0)), 
			VertexFormat(glm::vec3(0, -1,  1), glm::vec3(1.45f, 0, 0.44f)),
			VertexFormat(glm::vec3(-1, 0,  1), glm::vec3(0, 1, 0)),
			VertexFormat(glm::vec3(0, 0,  1), glm::vec3(0.75f, 1, 0)),
			VertexFormat(glm::vec3(-1, -1,  0), glm::vec3(0, 0.1f, 1)),
			VertexFormat(glm::vec3(0, -1,  0), glm::vec3(0, 0.45f, 1)),
			VertexFormat(glm::vec3(-1, 0,  0), glm::vec3(0.2f, 1, 0.78f)),
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 0, 0))
		};

		vector<unsigned short> indices =
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

		meshes["cube1"] = new Mesh("generated cube 1");
		meshes["cube1"]->InitFromData(vertices, indices);

		// Create a new mesh from buffer data
		Mesh *cube = CreateMesh("cube3", vertices, indices);


		// vertecsi pentru tetraedru
		vector<VertexFormat> vertices2
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(1, 0.65f, 0.45f)),
			VertexFormat(glm::vec3(0, 0,  1), glm::vec3(0.23f, 0.65f, 0.34f)),
			VertexFormat(glm::vec3(1, 0,  1), glm::vec3(0.56f, 1, 0)),
			VertexFormat(glm::vec3(0, 1, 0), glm::vec3(0.45f, 0.77f, 0.34f))
			// TODO: Complete the information for the cube

		};

		// indici pentru tetraedru
		vector<unsigned short> indices2 =
		{
			0, 3, 2,	
			1, 3, 0,	
			2, 3, 1,
			0, 2, 1,
		};

		Mesh* tetra  = CreateMesh("tetra", vertices2, indices2);
		
		// vertecsi pt triunghiul 1
		vector<VertexFormat> triangle1_vertices
		{
			VertexFormat(glm::vec3(2, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(2, 2,  0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(4, 0,  0), glm::vec3(0, 1, 0)),
		};

		// indici pentru triunghiul 1
		vector<unsigned short> triangle1_indices
		{
			0, 1, 2,	
		};

		Mesh* triangle1 = CreateMesh("triangle1", triangle1_vertices, triangle1_indices);

		// vertecsi pt triunghiul 2
		vector<VertexFormat> triangle2_vertices
		{
			VertexFormat(glm::vec3(4, 0, 0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(4, 2,  0), glm::vec3(0, 0, 1)),
			VertexFormat(glm::vec3(2, 2,  0), glm::vec3(0, 1, 0)),
		};
		
		// indici pentru triunghiul 2
		vector<unsigned short> triangle2_indices
		{
			0, 1, 2,	
		};

		Mesh* triangle2 = CreateMesh("triangle2", triangle2_vertices, triangle2_indices);

		// vertecsi pentru piramida (bonus)
		vector<VertexFormat> bonus_vertices
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(1, 0, 0)),  // 0 cu 2 cu 8
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)),  // 1 cu 6 cu 9
			VertexFormat(glm::vec3(0, 0,  2), glm::vec3(1, 0, 0)), // 2 cu 0 cu 8
			VertexFormat(glm::vec3(0, 0,  2), glm::vec3(0, 0, 1)), // 3 cu 4 cu 10
			VertexFormat(glm::vec3(2, 0,  2), glm::vec3(0, 0, 1)), // 4 cu 3 cu 10
			VertexFormat(glm::vec3(2, 0,  2), glm::vec3(1, 1, 1)), // 5 cu 7 cu 11
			VertexFormat(glm::vec3(2, 0,  0), glm::vec3(0, 1, 0)), // 6
			VertexFormat(glm::vec3(2, 0,  0), glm::vec3(1, 1, 1)), // 7
			VertexFormat(glm::vec3(1, 2,  1), glm::vec3(1, 0, 0)), // 8
			VertexFormat(glm::vec3(1, 2,  1), glm::vec3(0, 1, 0)), // 9
			VertexFormat(glm::vec3(1, 2,  1), glm::vec3(0, 0, 1)), // 10
			VertexFormat(glm::vec3(1, 2,  1), glm::vec3(1, 1, 1)),  // 11
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0.5, 0, 0.5)),  // 12
			VertexFormat(glm::vec3(2, 0,  2), glm::vec3(0.5, 0, 0.5)),  // 13
			VertexFormat(glm::vec3(0, 0,  2), glm::vec3(0.5, 0, 0.5)),  // 14
			VertexFormat(glm::vec3(2, 0,  0), glm::vec3(0.5,  0, 0.5))  // 15

		};

		// indici pentru piramida (bonus)
		vector<unsigned short> bonus_indices
		{
			2, 8, 0,
			1, 9, 6,
			4, 10, 3,
			7, 11, 5,
			12, 13, 14,
			12, 15,13
		};

		Mesh* bonus = CreateMesh("bonus", bonus_vertices, bonus_indices);
	}
}

Mesh* Laborator2::CreateMesh(const char *name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices)
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

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data
	// It will be learned later, when GLSL shaders will be introduced
	// For the moment just think that each property value from our vertex format needs to be send to a certain channel
	// in order to know how to receive it in the GLSL vertex shader

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

void Laborator2::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Laborator2::Update(float deltaTimeSeconds)
{
	glLineWidth(3);
	glPointSize(5);
	glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

	glEnable(GL_CULL_FACE);
	glCullFace(cullFace);

	// render an object using face normals for color
	RenderMesh(meshes["box"], shaders["VertexNormal"], glm::vec3(0, 0.5f, -1.5f), glm::vec3(0.75f));

	// render an object using colors from vertex
	RenderMesh(meshes["cube1"], shaders["VertexColor"], glm::vec3(-1.5f, 0.5f, 0), glm::vec3(0.25f));

	RenderMesh(meshes["cube3"], shaders["VertexColor"], glm::vec3(5, 5, 0));

	// render tetraedru
	RenderMesh(meshes["tetra"], shaders["VertexColor"], glm::vec3(2, 0, 2));

	// render triunghiuri ce alcatuiesc patratul
	RenderMesh(meshes["triangle1"], shaders["VertexColor"], glm::vec3(-3, 0, 0));
	RenderMesh(meshes["triangle2"], shaders["VertexColor"], glm::vec3(-3, 0, 0));

	// render piramida pentru bonus
	RenderMesh(meshes["bonus"], shaders["VertexColor"], glm::vec3(3, 0, 0));
	
		
	glDisable(GL_CULL_FACE);

}

void Laborator2::FrameEnd()
{
	DrawCoordinatSystem();
}

void Laborator2::OnInputUpdate(float deltaTime, int mods)
{

}

void Laborator2::OnKeyPress(int key, int mods)
{
	// TODO: switch between GL_FRONT and GL_BACK culling
	// Save the state in "cullFace" variable and apply it in the Update() method not here

	if (key == GLFW_KEY_SPACE)
	{
		switch (polygonMode)
		{
		case GL_POINT:
			polygonMode = GL_FILL;
			break;
		case GL_LINE:
			polygonMode = GL_POINT;
			break;
		default:
			polygonMode = GL_LINE;
			break;
		}
	} else if (key == GLFW_KEY_F2) {
		if (cullFace == GL_BACK) {
			cullFace = GL_FRONT;
		}
		else {
			cullFace = GL_BACK;
		}
	}	
}

void Laborator2::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator2::OnWindowResize(int width, int height)
{
}
