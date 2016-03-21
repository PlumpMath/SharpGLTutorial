#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	/*Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(Shader_Manager::GetShader("colorShader"));
	triangle->Create();
	gameModelList["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(Shader_Manager::GetShader("colorShader"));
	quad->Create();
	gameModelList["quad"] = quad;*/

	Models::Cube* cube = new Models::Cube(glm::vec3(0, -1, 0));
	cube->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube->Create();
	gameModelList["cube"] = cube;

	Models::Model* priest = new Models::Model("Rendering\\Models\\Priest.obj", glm::vec3(0, 0, 0));
	priest->SetProgram(Shader_Manager::GetShader("colorShader"));
	gameModelList["priest"] = priest;
}

Models_Manager::~Models_Manager()
{
	for (auto model : gameModelList)
	{
		delete model.second;
	}

	gameModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

void Models_Manager::Update()
{
	for (auto model : gameModelList)
	{
		model.second->Update();
	}
}

void Models_Manager::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const float& time)
{
	for (auto model : gameModelList)
	{
		model.second->Draw(projection_matrix, view_matrix, time);
	}
}