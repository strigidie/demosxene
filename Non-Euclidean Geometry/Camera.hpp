#pragma once

#include <memory>

class Camera
{

};

// Let's declare a camera as shared resource
using CameraShPtr = std::shared_ptr<Camera>;