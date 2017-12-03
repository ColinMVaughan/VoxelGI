//--------------------------------------------------------------------------------------------------
//									DEMO APP
//								  Colin Vaughan 
//
//
//	Demo App includes selection of different lighting and material scenareos with
//	multiple point lights, voxel destruction, and physics. The demo showcases the ECS pattern design 
//  and a component / memory manager
//	
//---------------------------------------------------------------------------------------------------
#include <iostream>
#include <GL/glew.h>
#include <SDL\SDL.h>


class Demo
{

public:
	void Initalize()
	{

	}
	void Update()
	{
		while (SDL_PollEvent(&m_InputEvent))
		{
			switch (m_InputEvent.type)
			{
			case SDL_QUIT:
				Running = false;
				break;
			}
		}
	}
	void Unload()
	{

	}

public:
	SDL_Window* m_Window;
	SDL_Event m_InputEvent;
	bool Running = true;
};







int main(int argc, char *argv[])
{
	Demo* demo = new Demo;

	//-------------------------------------------------------------------------
	//		Init SDL
	//-------------------------------------------------------------------------
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		std::cout << "SDL was not Initalized.";
		return 1;
	}

	Uint32 WindowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


	demo->m_Window = SDL_CreateWindow("Ocean Engine", 100, 100, 1280, 720, WindowFlags);
	SDL_GL_CreateContext(demo->m_Window);
	//SDL_SetRelativeMouseMode(SDL_TRUE);

	//-----------------------------------------------------------
	//		Init GLEW
	//---------------------------------------------------------
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW was not initalized\n";
		system("pause");
		return 0;
	}


	//-----------------------------------------------------------
	//	Init & Run Application
	//------------------------------------------------------------
	demo->Initalize();
	while (demo->Running)
	{
		demo->Update();
	}
	demo->Unload();

	return 0;

}