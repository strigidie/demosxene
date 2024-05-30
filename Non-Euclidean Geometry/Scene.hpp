#pragma once

#include <vector>
#include <memory>

#include "Object.hpp"

class Scene
{
private:
	std::vector<Object> _objs;

public:
	Scene(void);
	~Scene(void);
	
	void append(const ObjectShPtr& object);
	//ObjectShPtr operator[](std::size_t i);
};

// Let's declare a scene as shared resource
using SceneShPtr = std::shared_ptr<Scene>;
