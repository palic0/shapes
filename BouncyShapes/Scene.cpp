#include "Scene.h"

//dem globals
MPoint2F velocity{ 1.0f,1.0f };




void Scene::insertGameObject(std::unique_ptr<GameObject>& object)
{
	_gameObjects.push_back(std::move(object));
}


void Scene::Update(double deltaTime)
{

	for (auto& object : _gameObjects)
	{
		MPoint2F  currentPosition = object->getLocation();
		collision(currentPosition);
		MPoint2F finalPosition = { currentPosition.x + getVelocity().x * (deltaTime / 7) - 1 , currentPosition.y + getVelocity().y * (deltaTime / 7) - 1 };
		object->changeLocation(finalPosition);
	}
}

void Scene::Draw(ID2D1HwndRenderTarget & target)
{
	for (auto& object : _gameObjects)
	{
		const auto& renderer = object->getRenderer();
		renderer.Render(target, object->getLocation());	
		auto result = target.GetSize();
		setScreenSize(result);
	}
}

void Scene::setScreenSize(D2D1_SIZE_F result)
{
	_result = result;
}

const D2D1_SIZE_F & Scene::getScreenSize()
{
	return _result;
}

void Scene::changeVelocity(MPoint2F velocity)
{
	_velocity = velocity;
}

const MPoint2F & Scene::getVelocity()
{
	return _velocity;
}

void Scene::collision(MPoint2F currentPosition)
{
	if (currentPosition.y > getScreenSize().height)
	{
		velocity.y = -1.0f;
		changeVelocity(velocity);
	}
	if (currentPosition.y < getScreenSize().height*0)
	{
		velocity.y = 1.0f;
		changeVelocity(velocity);
	}
	if (currentPosition.x > getScreenSize().width)
	{
		velocity.x = -1.0f;
		changeVelocity(velocity);
	}
	if (currentPosition.x < getScreenSize().width * 0)
	{
		velocity.x = 1.0f;
		changeVelocity(velocity);
	}
}
