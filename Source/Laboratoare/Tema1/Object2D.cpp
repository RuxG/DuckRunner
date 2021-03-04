#include "Object2D.h"

#include <Core/Engine.h>

Mesh* Object2D::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };

	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Object2D::CreateTriangle(std::string name, glm::vec3 position, glm::vec3 color, bool fill) {
	Mesh* triangle = new Mesh("triangle");
	triangle->SetDrawMode(GL_TRIANGLES);
	std::vector<VertexFormat> vertices = {
		VertexFormat(position + glm::vec3(ARROWLENGTH, ARROWLENGTH / 5, 0), glm::vec3(0, 1, 0)),
		VertexFormat(position + glm::vec3(ARROWLENGTH + ARROWLENGTH / 5,0, 0), glm::vec3(0, 1, 0)),
		VertexFormat(position + glm::vec3(ARROWLENGTH, (-1) * ARROWLENGTH / 5, 0), glm::vec3(0, 1, 0)),
		
	};

	

	std::vector<unsigned short> indices = {
		
		0, 1, 2
	};

	triangle->InitFromData(vertices, indices);

	return triangle;
}

Mesh* Object2D::CreateBowLine(std::string name, glm::vec3 position, glm::vec3 color, bool fill)
{
	
	Mesh* line = new Mesh("line");

	line->SetDrawMode(GL_LINES);

	std::vector<VertexFormat> vertices = {
		VertexFormat(position, glm::vec3(0, 1, 0)),
		VertexFormat(position + glm::vec3(ARROWLENGTH, 0, 0), glm::vec3(0, 1, 0)),
	};



	std::vector<unsigned short> indices = {
		0, 1,
	};

	line->InitFromData(vertices, indices);

	return line;
	
}

