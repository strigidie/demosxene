#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <sstream>

#include "Vector.hpp"

// Types of the objects on the render scene
enum class ObjectType
{
	OBJECT_NONE,
	OBJECT_MESH,
	OBJECT_LIGHT,
	OBJECT_PORTAL
};

// Base object class -----------------------------------------------------------
class Object
{
protected:
	ObjectType _type;
	Vector3 _pos; /* Position in the World Space */

	std::string _name;
	std::vector<double> _vertices; /* Position in the Local Space */
	std::vector<int> _indicies;

public:
	// Default methods ---------------------------------------------------------
	explicit Object(void);
	virtual ~Object(void);

	// Sets methods ------------------------------------------------------------
	void setPos(Vector3 pos);
	void setName(std::string& name);
	void setVertices(const std::vector<double>& vertices);
	void setIndicies(const std::vector<int>& indicies);
	
	// Gets methods ------------------------------------------------------------
	ObjectType getType(void);
	Vector3 getPos(void);
	std::string getName(void);
	std::vector<double> getVertices(void);
	std::vector<int> getIndicies(void);

	// Custom methods ----------------------------------------------------------
	void loadObject(const std::string path);
};

// Declare the mesh object -----------------------------------------------------
class ObjectMesh : public Object
{
public:
	ObjectMesh(void) : Object()
	{
		_type = ObjectType::OBJECT_MESH;
	}
};

// Declare the light point -----------------------------------------------------
class ObjectLight : public Object
{
public:
	ObjectLight(void) : Object()
	{
		_type = ObjectType::OBJECT_LIGHT;
	}

	void setBrightness(double brightness);
};

// Let's declare the object as shared resource ---------------------------------
using ObjectShPtr = std::shared_ptr<Object>;
