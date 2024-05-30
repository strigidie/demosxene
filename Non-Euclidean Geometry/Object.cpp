#include "Object.hpp"

// Default methods -------------------------------------------------------------
Object::Object(void) :
	_type(ObjectType::OBJECT_NONE),
	_pos(0.0F, 0.0F, 0.0F),
	_name("Default"),
	_vertices({}),
	_indicies({})
{ }

Object::~Object(void) { }

// Sets methods ----------------------------------------------------------------
void Object::setName(std::string& name)
{
	_name = name;
}

void Object::setPos(Vector3 pos)
{
	_pos = pos;
}

void Object::setVertices(const std::vector<double>& vertices)
{
	_vertices = vertices;
}

void Object::setIndicies(const std::vector<int>& indicies)
{
	_indicies = indicies;
}

// Gets methods ----------------------------------------------------------------
ObjectType Object::getType(void)
{
	return _type;
}

std::string Object::getName(void)
{
	return _name;
}

Vector3 Object::getPos(void)
{
	return _pos;
}

std::vector<double> Object::getVertices(void)
{
	return _vertices;
}

std::vector<int> Object::getIndicies(void)
{
	return _indicies;
}

// Custom methods --------------------------------------------------------------
void Object::loadObject(const std::string path)
{
	// Load the wavefront file -------------------------------------------------
	std::fstream wavefront(path);
	std::string line;

	if (wavefront.is_open())
	{
		while (std::getline(wavefront, line))
		{
			if (line[0] == 'o')
			{
				// You are a wizard, Harry!
				_name = std::string(line.c_str() + 2);
				std::cout << line << std::endl;
			}
			else if (line[0] == 'v')
			{
				std::stringstream ss(line);
				double fnumb;

				while (ss >> fnumb)
				{
					_vertices.push_back(fnumb);
				}
				std::cout << line << std::endl;
			}
			else if (line[0] == 'f')
			{
				std::stringstream ss(line);
				int inumb;

				while (ss >> inumb)
				{
					_indicies.push_back(inumb);
				}
				std::cout << line << std::endl;
			}
		}

		wavefront.close();
	}
	else
	{
		throw std::runtime_error("Cannot open the file: " + path);
	}
}