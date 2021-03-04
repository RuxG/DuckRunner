#pragma once
#include  <Core/Engine.h>

/* Class used for monitoring the player: position, lives, fuel, buffs
*/
class Player
{
public:
	Player(glm::vec3 sphere_position, float speed, float initial_fuel);
	~Player();
	glm::vec3 getRotationAngle();
	glm::vec3 getOffset();
	glm::vec3 getPosition();

	float getSpeed();
	float getFuel();
	float getBuffTime();
	int getBuffType();

	bool isInAir();
	bool isDescending();
	bool isDead();

	Mesh* getSphere();

	void setSpherePosition(glm::vec3 position);
	void setSphereRotation(glm::vec3 angle);
	void setOffset(glm::vec3 offset);

	void setSpeed(float speed);
	void setFuel(float fuel);

	void setInAir(bool inAir);
	void setDescend(bool descend);
	void setDead(bool dead);
	void setBuffTime(float buff_time);
	void setBuffType(int buff_type);

	glm::vec3 sphere_position;

private:
	// sphere rotation angle
	glm::vec3 sphere_rotation;

	// sphere Z offset
	glm::vec3 offset;

	// sphere speed
	float sphere_speed;

	// variable used for checking if the sphere is in mid-air
	bool inAir;

	// variable used for checking if the sphere is descending
	bool descend;

	// variable used for checking if the player is dead
	bool dead;

	// amount of fuel left
	float fuel;

	float buff_time;
	int buff_type = 0;

	Mesh* sphere;

};

