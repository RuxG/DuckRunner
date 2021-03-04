#pragma once
#include <Component/SimpleScene.h>
#include "Laboratoare/Laborator5/LabCamera.h"
#include "Laboratoare/Tema2/Platform.h"
#include "Player.h"
#include <TextRenderer/TextRenderer.h>


#define CAMERA_SPEED_UP 5
#define CAMERA_MAX_SPEED 3
#define CAMERA_MIN_SPEED 1

#define Z_LIM 19

#define MAX_JUMP 1.3

#define MAX_PLATFORM_LENGTH 5
#define MIN_PLATFORM_LENGTH 3

#define TILE_GAP 1.3

#define CONFIGURATIONS_NUM 6

#define MAX_FUEL 100 

#define BUFF_TIME 10

#define BLUE_BUFF 0
#define GREEN_BUFF 1
#define YELLOW_BUFF 2
#define ORANGE_BUFF 3
#define RED_BUFF 4
#define LIFE_BUFF 5
#define PURPLE_BUFF 6
#define OBSTACLE_BUFF 7

#define RESPAWN_TIME 3

#define OBSTACLE_DISTANCE 10

#define OBSTACLE_PROB 0.6




#define SCORE_COLLECTABLE 50

struct configuration {
	int number;
	bool left;
	bool middle;
	bool right;

	std::vector<int> invalid_configurations;
};

struct fuel_bar {
	Mesh* rectangle_back;
	Mesh* rectangle_front;
};


class Tema2 : public SimpleScene
{
public:
	Tema2();
	~Tema2();

	void Init() override;
	glm::mat4 orthoMatrix;



private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

	void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix);
	void RenderMesh2D(Mesh* mesh, Shader* shader, const glm::mat3& modelMatrix) override;


	void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D* texture1, Texture2D* texture2, glm::vec3 color = glm::vec3(-1, -1, -1), int light_source = 0);

	void getConfigurations();
	void get_configuration_number(int& config_num, int& prev_config_num);

	void modify_platform(std::vector<Platform*>& platform_line, int ct, glm::vec3 position_offset, double platform_length, int config_num, int color_name, bool special,  bool obstacle, std::string collectable_type);
	void Tema2::replace_platform(std::vector<Platform*>& platform_line, std::vector<Platform*>& platform);
	void delete_old_platforms(std::vector<int> to_delete);
	float generatePlatformLength();
	void generateInitialPlatforms();
	void generate_color(int& color_name);

	void apply_buff(float deltaTimeSeconds);
	void translateSphere(float deltaTimeSeconds);
	void renderFuelBar();
	void renderPlatforms();
	void renderDecor();

	void deadAnimation(float deltaTimeSeconds);

	Mesh* createRectangle(glm::vec3 color);
	Mesh* Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);
	void createLives();
	void Tema2::createQuad();
	void createCircle(int grades, std::string name);
	Mesh* createCube();
	


	struct configuration createConfiguration(int num, bool left, bool right, bool midde);

	void Tema2::render_plants(float offset, bool direction);

	void Tema2::loadTextures();

protected:
	Laborator::Camera* camera;
	Laborator::Camera* camera2D;

	glm::mat4 projectionMatrix;
	bool renderCameraTarget = false;
	int factor = 100;

	float left, right, bottom, top, zNear, zFar, fov;

	bool perspective = true;

	glm::vec3 camera_first_offset = glm::vec3(0, 0, 0);

	glm::vec3 camera_offset = glm::vec3(0, 2, -2);

	double times = 0;

	// array with possible platforms configurations
	std::vector<struct configuration> configurations;

	std::vector<std::vector<Platform*>> platforms;

	Mesh* water;

	std::vector<float> z_offset_watter;
	Mesh* rectangle_grass;

	int lives = 3;

	bool firstPerson = true;

	Mesh* rectangle;
	Mesh* life1;
	Mesh* life2;
	Mesh* life3;

	Mesh* extraLife;

	struct fuel_bar fuelBar;

	Player* player;

	bool fell;

	bool back = true;

	float time_sec = 0;

	float angle = 0;

	int score = 0;



	std::unordered_map<std::string, Texture2D*> mapTextures;

	std::vector<std::string> vegetation_names = { "green" , "cattail" , "cattail" , "grass2" , "grass2", "grass_mirror" ,"yellow_grass" ,"grass2" , "grass2", "yellow_grass",
		"grass_mirror" , "ciuperca", "white", "ciuperca", "white", "ciuperca", "white", "ciuperca", "white" };
         
	std::vector<glm::vec3> vegetation_position = { glm::vec3(0, 0.5,0) , glm::vec3(0, 1.5,0), glm::vec3(0, 2.1,0), glm::vec3(0.2, 1.3,0.5), glm::vec3(0.2, 1.3,0.5), glm::vec3(0.3, 1.3,0.5), 
		glm::vec3(0.6, 1.3,0.75), glm::vec3(0.4, 1,0) ,glm::vec3(0.2, 1.3, -0.4), glm::vec3(0.6, 1.8,-0.3),glm::vec3(0.2, 0.75,-0.7), glm::vec3(0.3, 0.2,0), glm::vec3(0.3, 0.1,0), 
		glm::vec3(0.75, 0.15,-1.1), glm::vec3(0.75, 0.0875,-1.1), glm::vec3(0.1, 0.3, -0.7), glm::vec3(0.1, 0.15, -0.7), glm::vec3(1.2, 0.22,-1.3), glm::vec3(1.2, 0.11,-1.3) };

	std::vector<glm::vec3> vegetation_position_mirror = { glm::vec3(0.1, 0.5,0) , glm::vec3(0.1, 1.5,0), glm::vec3(0.1, 2.1,0), glm::vec3(0.2, 1.3,-0.5), glm::vec3(0.2, 1.3,-0.5), glm::vec3(-0.3, 1.3,-0.5),
		glm::vec3(-0.65, 1.3, -0.75), glm::vec3(-0.4, 1, 0) ,glm::vec3(-0.2, 1.3, 0.6), glm::vec3(-0.65, 1.8, 0.3),glm::vec3(-0.2, 0.75,0.7), glm::vec3(-0.2, 0.2,1), glm::vec3(-0.2, 0.1,1),
		glm::vec3(-0.5, 0.15,-1.1), glm::vec3(-0.5, 0.0875,-1.1), glm::vec3(-0.8, 0.3, -0.7), glm::vec3(-0.8, 0.15, -0.7), glm::vec3(-0.1, 0.22,-1.3), glm::vec3(-0.1, 0.11,-1.3) };


	std::vector<glm::vec3> vegetation_scale = { glm::vec3(0.02, 1, 0.02), glm::vec3(0.07f, 1.2, 0.07f), glm::vec3(0.013, 0.3f, 0.013f), glm::vec3(0.2f, 2.2f, 0.5f), glm::vec3(0.2f, 2.2f, 0.5f)
		, glm::vec3(0.2f,2.1f, 0.5f), glm::vec3(0.2f, 2.9f, 0.5f) , glm::vec3(0.2f, 2.1f, 0.5f), glm::vec3(0.2f, 2.3f, 0.5f) , glm::vec3(0.1f, 2.6f, 0.5f), glm::vec3(0.2f, 2.f, 0.5f)
		, glm::vec3(0.20, 0.20f, 0.20) , glm::vec3(0.1, 0.20f, 0.1) , glm::vec3(0.15, 0.15, 0.15), glm::vec3(0.07, 0.15f, 0.08) , glm::vec3(0.15, 0.15, 0.15) , glm::vec3(0.075, 0.15, 0.075) ,
		glm::vec3(0.15, 0.15, 0.15), glm::vec3(0.07, 0.15f, 0.08) };

	std::vector<glm::vec3> vegetation_rotation = { glm::vec3(0, 0, 0), glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0), glm::vec3(0.3, 0, 0) , glm::vec3(0.3, 0.4, 0) , glm::vec3(0.15, 0.8, -0.3) , 
		glm::vec3(0.3, -1, -0.35) , glm::vec3(0, 1.7, -0.4) , glm::vec3(-0.3, 2.45,-0.2) , glm::vec3(-0.2, 2,-0.35) , glm::vec3(-0.6, 2.67, -0.2) ,
		glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0), glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0) , glm::vec3(0, 0, 0) };
	

	std::vector<std::string> faces = 
	{
		   "right.jpg",
			"left.jpg",
			"top.jpg",
			"bottom.jpg",
			"front.jpg",
			"back.jpg"
	};

	std::unordered_map<int, std::string> lilypad_colours = { {GREEN_BUFF, "lilypad"}, {BLUE_BUFF, "lilypad_blue"}, {YELLOW_BUFF, "lilypad_yellow"}, {ORANGE_BUFF, "lilypad_orange"},
		{RED_BUFF, "lilypad_red"}, {LIFE_BUFF, "lilypad_pink"}, {PURPLE_BUFF, "lilypad_purple"} };

	glm::vec3 lightPosition[20];
	glm::vec3 lightDirection[20];
	glm::vec3 lightColours[20] = { glm::vec3(1, 0, 0), glm::vec3(1, 1, 1), glm::vec3(1, 1, 0),  glm::vec3(1, 0, 0.5), glm::vec3(0.5, 0, 1),glm::vec3(1, 0, 0),  glm::vec3(1, 1, 1), glm::vec3(1, 0, 0),  glm::vec3(1, 0, 0.5), glm::vec3(0.5, 0, 1),
	glm::vec3(1, 0, 0), glm::vec3(1, 1, 0), glm::vec3(1, 1, 1),  glm::vec3(1, 0, 0.5), glm::vec3(0.5, 1, 0), glm::vec3(1, 0, 0),  glm::vec3(1, 1, 1),glm::vec3(1, 0, 0),  glm::vec3(1, 0, 0.5), glm::vec3(1, 0.5, 1), };

	glm::vec3 init_lightColours[20] = { glm::vec3(1, 0, 0), glm::vec3(1, 1, 1),glm::vec3(1, 1, 0),  glm::vec3(1, 0, 0.5), glm::vec3(0.5, 0, 1),glm::vec3(1, 0, 0),  glm::vec3(1, 1, 1),  glm::vec3(1, 0, 0),glm::vec3(1, 0, 0.5), glm::vec3(0.5, 0, 1),
	glm::vec3(1, 0, 0), glm::vec3(1, 1, 0), glm::vec3(1, 1, 1),  glm::vec3(1, 0, 0.5), glm::vec3(0.5, 1, 0), glm::vec3(1, 0, 0),  glm::vec3(1, 1, 1),glm::vec3(1, 0, 0),  glm::vec3(1, 0, 0.5), glm::vec3(1, 0.5, 1), };

	int spotlight[20];
	int lightCount = 0;

	unsigned int materialShininess;
	float materialKd;
	float materialKs;



	Mesh* sphere;

	TextRenderer* textRenderer;

	glm::vec2 textPosition;
};
