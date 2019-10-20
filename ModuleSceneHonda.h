#ifndef ModuleSceneHonda_h
#define ModuleSceneHonda_h

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneHonda : public Module {
public:
	ModuleSceneHonda(bool start_enabled = true);
	~ModuleSceneHonda();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect roof;
	SDL_Rect hotTub;
	Animation mountain;
	Animation hotTubBorder;
};
#endif
