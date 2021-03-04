#pragma once
#include  <Core/Engine.h>

/* Class for defining a platform: position, color, length, buffs
*/
class Platform
{
public:
	Platform(glm::vec3 position_offset, double length, int configuration, bool special = false, int color_name = 0, float obstacleDistance = 0, std::string collectable = "none");
	~Platform();

	Mesh* getPlatform();
	Mesh* getObstacle();


	glm::vec3 getPos();

	glm::vec3 getColor();
	int getColorName();

	double getLength();
	float getAngle();

	bool getUsedPower();

	bool getCollectedCollectable();

	bool getSpecial();

	int getConfiguration();

	float getObstacleDistance();
	bool getHitObstacle();

	std::string getCollectableType();

	void setPosition(glm::vec3 position_offset);

	void setLength(double length);

	void setConfiguration(int configuration);

	void setSpecial(bool special);

	void setObstacle();
	void setHitObstacle(bool obstacle);
	void setObstacleDistance(float distance);

	void setColor(glm::vec3 color);
	void setColorName(int color_name);

	void setUsedPower(bool power);
	void setCollected(bool collected);

	void setCollectable(std::string type);

private:
	Mesh* platform;
	Mesh* water;
	Mesh* obstacle;

	// position in world
	glm::vec3 position_offset;

	glm::vec3 color;
	double length;
	float angle;

	// variable to check if the platform's buff was already applied
	bool usedPower;

	// variable to check if the platform has any special effects
	bool special;

	bool collectedColleactable;

	int color_name;

	int configuration;

	float obstacle_distance;
	bool hit_obstacle;

	std::string collectable;

protected:
	
};
