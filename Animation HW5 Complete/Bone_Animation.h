#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	

class Bone_Animation
{
public:
	Bone_Animation();
	~Bone_Animation();

	void init();
	void calculate_rotation_matrices();
	glm::mat4 yellow_bone_matrix();
	glm::mat4 purple_bone_matrix();
	glm::mat4 blue_bone_matrix();
	void update(float delta_time);
	void reset();

public:

	// Here the head of each vector is the root bone
	std::vector<glm::vec3> scale_vector;
	std::vector<glm::vec3> rotation_degree_vector;
	std::vector<glm::vec4> colors;
	std::vector<glm::vec3> position_vector;

	std::vector<glm::mat4> rotation_matrix;

	glm::vec3 root_position;

};
