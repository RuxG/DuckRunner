#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>


namespace Object2D
{

	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);

	// Create triangle with given bottom left corner, length and color
	Mesh* CreateTriangle(std::string name, glm::vec3 position, glm::vec3 color, bool fill = false);

	Mesh* CreateBowLine(std::string name, glm::vec3 position, glm::vec3 color, bool fill = false);

}

