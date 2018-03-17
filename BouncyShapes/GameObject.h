#pragma once

#include <memory>
#include "GeometryPrimitives.h"
#include "IRenderer.h"

class GameObject {
public:
	GameObject(std::shared_ptr<IRenderer> renderer, MPoint2F location);

	const IRenderer& getRenderer();
	const MPoint2F& getLocation();
	void changeLocation(MPoint2F location);


private:
	std::shared_ptr<IRenderer> _rendererPtr;
	MPoint2F _location;
};