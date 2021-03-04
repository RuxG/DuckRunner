#include "Player.h"

Player::Player(glm::vec3 pos, float speed, float initial_fuel)
{
	this->sphere_position = glm::vec3(pos);
	this->sphere_rotation = glm::vec3(0, 0, 0);
	this->offset = glm::vec3(0, 0, 0);

	this->sphere_speed = speed;
	this->inAir = false;
	this->descend = false;
	this->dead = false;

	sphere = new Mesh("duck");
	sphere->LoadMesh(RESOURCE_PATH::MODELS, "chicken.obj");

	this->fuel = initial_fuel;
}

Player::~Player()
{
}

glm::vec3 Player::getRotationAngle()
{
	return sphere_rotation;
}

glm::vec3 Player::getOffset()
{
	return offset;
}

glm::vec3 Player::getPosition()
{
	return this->sphere_position;
}

float Player::getSpeed()
{
	return sphere_speed;
}

float Player::getFuel()
{
	return fuel;
}

float Player::getBuffTime()
{
	return buff_time;
}

int Player::getBuffType()
{
	return buff_type;
}

bool Player::isInAir()
{
	return inAir;
}

bool Player::isDescending()
{
	return descend;
}

bool Player::isDead()
{
	return dead;
}


Mesh* Player::getSphere()
{
	return sphere;
}

void Player::setSpherePosition(glm::vec3 position)
{
	this->sphere_position = position;
}

void Player::setSphereRotation(glm::vec3 angle)
{
	this->sphere_rotation = angle;
}

void Player::setOffset(glm::vec3 offset)
{
	this->offset = offset;
}

void Player::setSpeed(float speed)
{
	this->sphere_speed = speed;
}

void Player::setFuel(float fuel)
{
	this->fuel = fuel;
}

void Player::setInAir(bool inAir)
{
	this->inAir = inAir;
}

void Player::setDescend(bool descend)
{
	this->descend = descend;
}

void Player::setDead(bool dead)
{
	this->dead = dead;
}

void Player::setBuffTime(float buff_time)
{
	this->buff_time = buff_time;
}

void Player::setBuffType(int buff_type)
{
	this->buff_type = buff_type;
}

