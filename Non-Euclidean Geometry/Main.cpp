#include <iostream>
#include <exception>

#include "Camera.hpp"
#include "Render.hpp"
#include "Window.hpp"

// Entry Point -----------------------------------------------------------------
int main(
	const int argc,
	const char* argv[])
{
	try
	{
		// Camera setup --------------------------------------------------------
		CameraShPtr camera = std::make_shared<Camera>();
		camera->setAspectRatio(
			static_cast<double>(M_VIEWPORT_WIDTH) / M_VIEWPORT_HEIGHT);

		// Scene setup ---------------------------------------------------------
		//SceneShPtr scene = std::make_shared<Scene>();

		ObjectShPtr mesh_cube = std::make_shared<ObjectMesh>();
		mesh_cube->loadObject("Asset/Mesh/mesh_cube.obj");
		//scene->append(cube);

		ObjectShPtr mesh_portal = std::make_shared<ObjectMesh>();
		mesh_portal->loadObject("Asset/Mesh/mesh_portal.obj");
		//scene->append(cube);
;
		// Render setup --------------------------------------------------------
		RenderShPtr render = std::make_shared<RenderEuclidean>(
			M_VIEWPORT_WIDTH, M_VIEWPORT_HEIGHT);
		render->setCamera(camera);
		/*render->setScene(scene);*/
		/*render->setSkybox(DEFAULT_SKYBOX_PATH);*/
		/*render->setWorldPlane(DEFAULT__PATH);*/

		// Window setup --------------------------------------------------------
		WindowUqPtr window = std::make_unique<Window>(render);
		window->runMainLoop();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
