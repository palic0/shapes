#pragma once
#include <vector>
#include <memory>
#include <d2d1.h>

#include "GameObject.h"

class Scene {
public:
	void insertGameObject(std::unique_ptr<GameObject>& object);

	void Update(double deltaTime);

	void Draw(ID2D1HwndRenderTarget& target);

	void setScreenSize(D2D1_SIZE_F result);

	const D2D1_SIZE_F& getScreenSize();

	void changeVelocity(MPoint2F velocity);

	const MPoint2F& getVelocity();

	void collision(MPoint2F currentPosition);

private:
	std::vector<std::unique_ptr<GameObject>> _gameObjects = {};
	D2D1_SIZE_F _result;
	MPoint2F _velocity;

	
};