#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled) {
	ground.x = 8;
	ground.y = 375;
	ground.w = 846;
	ground.h = 66;

	background.x = 120;
	background.y = 177;
	background.w = 617;
	background.h = 134;

	roof.x = 91;
	roof.y = 9;
	roof.w = 767;
	roof.h = 49;

	hotTub.x = 314;
	hotTub.y = 312;
	hotTub.w = 334;
	hotTub.h = 58;
	
	mountain.frames.push_back({ 222, 61, 223, 108 });
	mountain.frames.push_back({ 455, 61, 223, 108 });
	mountain.speed = 0.08f;

	hotTubBorder.frames.push_back({ 8, 447, 283, 8 });
	hotTubBorder.frames.push_back({ 295, 447, 283, 8 });
	hotTubBorder.frames.push_back({ 586, 447, 283, 8 });
	hotTubBorder.speed = 0.08f;
}

ModuleSceneHonda::~ModuleSceneHonda() {}

bool ModuleSceneHonda::Start() {
	LOG("Loading honda scene");

	graphics = App->textures->Load("honda_stage.png");
	App->player->Start();
	App->audio->PlayMusic("honda.ogg");

	return true;
}

bool ModuleSceneHonda::CleanUp() {
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

update_status ModuleSceneHonda::Update() {

	App->renderer->Blit(graphics, -100, 10, &roof, 2.0f);
	App->renderer->Blit(graphics, -100, 160, &ground, 2.0f);
	App->renderer->Blit(graphics, -10, 50, &background, 2.0f);
	App->renderer->Blit(graphics, 180, 54, &(mountain.GetCurrentFrame()), 2.0f);
	App->renderer->Blit(graphics, 180, 140, &hotTub, 2.0f);
	App->renderer->Blit(graphics, 180, 155, &(hotTubBorder.GetCurrentFrame()), 2.0f);

	App->player->Update();

	if (App->input->GetKey(SDL_SCANCODE_SPACE)) {
		App->fade->FadeToBlack(App->scene_ken, App->scene_honda, 3.0f);
	}
	return UPDATE_CONTINUE;
}
