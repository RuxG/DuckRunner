#pragma once

#include <include/glm.h>

namespace Transform3D
{
	// Translate matrix
	inline glm::mat4 Translate(float tx, float ty, float tz)
	{
		// TODO implement translate matrix
		return glm::transpose(glm::mat4(1, 0, 0, tx, 0, 1, 0, ty, 0, 0, 1, tz, 0, 0, 0, 1));
	}

	// Scale matrix
	inline glm::mat4 Scale(float sx, float sy, float sz)
	{
		// TODO implement scale matrix
		return glm::transpose(glm::mat4(sx,0, 0, 0, 0, sy, 0, 0, 0, 0, sz, 0, 0, 0, 0, 1));
	}

	// Rotate matrix relative to the OZ axis
	inline glm::mat4 RotateOZ(float radians)
	{
		// TODO implement rotate matrix
		return glm::transpose(glm::mat4(cos(radians), (-1) * sin(radians), 0, 0,
			sin(radians),  cos(radians), 0, 0,
			0, 0, 1, 0, 0, 0, 0, 1));
	}

	// Rotate matrix relative to the OY axis
	inline glm::mat4 RotateOY(float radians)
	{
		// TODO implement rotate matrix
		return glm::transpose(glm::mat4(cos(radians), 0, sin(radians), 0,
						0, 1, 0, 0, (-1) * sin(radians), 0 , cos(radians), 0,
						0, 0, 0, 1));
	}

	// Rotate matrix relative to the OX axis
	inline glm::mat4 RotateOX(float radians)
	{
		// TODO implement rotate matrix
		return glm::transpose(glm::mat4(1, 0, 0, 0, 0, cos(radians), (-1) * sin(radians), 0,
						0, sin(radians), cos(radians), 0, 0, 0, 0, 1));
	}
}
