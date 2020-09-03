#include "Bone_Animation.h"



Bone_Animation::Bone_Animation()
{
}


Bone_Animation::~Bone_Animation()
{
}

void Bone_Animation::init()
{
	root_position = { 2.0f,1.0f,2.0f };

	position_vector =
	{
		{ 2.0f,1.0f,2.0f },
		{ 2.0f,3.5f,2.0f },
		{ 2.0f,7.0f,2.0f },
		{ 2.0f,9.5f,2.0f }
	};

	scale_vector =
	{
		{ 1.0f,1.0f,1.0f },
		{ 0.5f,4.0f,0.5f },
		{ 0.5f,3.0f,0.5f },
		{ 0.5f,2.0f,0.5f }
	};

	rotation_degree_vector =
	{
		{ 0.0f,0.0f,0.0f },
		{ 0.0f,0.0f,0.0f },
		{ 0.0f,0.0f,0.0f },
		{ 0.0f,0.0f,0.0f }
	};

	colors =
	{
		{ 0.7f,0.0f,0.0f,1.0f },
		{ 0.7f,0.7f,0.0f,1.0f },
		{ 0.7f,0.0f,0.7f,1.0f },
		{ 0.0f,0.7f,0.7f,1.0f }
	};

}

void Bone_Animation::calculate_rotation_matrices() {
	//reset_rotation_matrix
	rotation_matrix = std::vector<glm::mat4>();

	//red cube
	rotation_matrix.push_back(glm::mat4(1.0f));

	//yellow bone
	glm::mat4 yellow_rotation =
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[1][2]), glm::vec3(0.0f, 0.0f, 1.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[1][1]), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[1][0]), glm::vec3(1.0f, 0.0f, 0.0f));
	rotation_matrix.push_back(yellow_rotation);

	glm::mat4 purple_rotation =
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[2][2]), glm::vec3(0.0f, 0.0f, 1.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[2][1]), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[2][0]), glm::vec3(1.0f, 0.0f, 0.0f));
	rotation_matrix.push_back(purple_rotation);


	glm::mat4 blue_rotation =
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[3][2]), glm::vec3(0.0f, 0.0f, 1.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[3][1]), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[3][0]), glm::vec3(1.0f, 0.0f, 0.0f));
	rotation_matrix.push_back(blue_rotation);
}

glm::mat4 Bone_Animation::yellow_bone_matrix() {

	glm::mat4 model_mat = glm::mat4(1.0f);

	model_mat =
		//move the bottom yellow rotation join back
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -2.0f, 0.0f))*

		//translate to position relative to the root bone
		glm::translate(glm::mat4(1.0f), position_vector[1])*

		//apply yellow rotation
		rotation_matrix[1] *

		//move the bottom yellow rotation joint to the origin
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 2.0f, 0.0f))*

		//scale the model
		glm::scale(glm::mat4(1.0f), scale_vector[1]);

	return model_mat;
}

glm::mat4 Bone_Animation::purple_bone_matrix() {

	glm::mat4 model_mat = glm::mat4(1.0f);

	model_mat =
		//move the bottom purple joint back
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.5f, 0.0f)) *

		//move the top yellow joint back
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -4.0f, 0.0f)) *

		//translate to position relative to the root bone
		glm::translate(glm::mat4(1.0f), position_vector[2]) *

		//apply yellows rotation
		rotation_matrix[1] *

		//translate the top of the yellow joint to the origin
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 4.0f, 0.0f)) *

		//apply purple rotation
		rotation_matrix[2] *

		//move the bottom purple joint to the origin
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.5f, 0.0f)) *

		//scale the model
		glm::scale(model_mat, scale_vector[2]);

	return model_mat;
}

glm::mat4 Bone_Animation::blue_bone_matrix() {

	glm::mat4 model_mat = glm::mat4(1.0f);

	model_mat =
		//move the bottom blue joint back
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f)) *

		//move the top purple joint back
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -3.0f, 0.0f)) *

		//move the top yellow joint back
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0, -4.0f, 0.0f)) *

		//move bone relative to the root bone
		glm::translate(model_mat, position_vector[3]) *

		//apply yellows rotation
		rotation_matrix[1] *

		//move the top of the yellow joing to the origin
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 4.0f, 0.0f)) *

		//apply purple rotation
		rotation_matrix[2] *

		//translate the top of the purple joint to the origin
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 3.0f, 0.0f)) *

		//apply blue rotation
		rotation_matrix[3] *

		//move the bottom blue joint to the origin
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f)) *

		//scale the model
		glm::scale(model_mat, scale_vector[3]);

	return model_mat;
}



void Bone_Animation::update(float delta_time)
{
	calculate_rotation_matrices();
}

void Bone_Animation::reset()
{
}