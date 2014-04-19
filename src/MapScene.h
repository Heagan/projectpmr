#pragma once

#include "Common.h"
#include "Constants.h"
#include "Scene.h"
#include "Map.h"
#include "OverworldEntity.h"
#include "NPC.h"
#include "PaletteTexture.h"
#include "Textbox.h"
#include "MenuCache.h"

class MapScene : public Scene
{
public:
	MapScene();
	~MapScene();

	void Update() override;
	void Render(sf::RenderWindow*) override;

	void SwitchMap(unsigned char index);
	void SetPlayerPosition(unsigned char x, unsigned int y);
	void Focus(signed char x, signed char y);
	void FocusFree(int x, int y);

	void DrawMap(sf::RenderWindow* window, Map& map, int connection_index, MapConnection* connection);
	void ClearEntities(bool focused = false);
	void SetPalette(sf::Color* palette);

	bool Interact();

	vector<OverworldEntity*>& GetEntities() { return entities; }

private:
	Map* active_map;
	sf::View viewport; //this is declared here because the maps are only places where the camera scrolls

	vector<OverworldEntity*> entities;
	OverworldEntity* focus_entity;
	//OverworldEntity* test_entity;

	bool can_warp;
	unsigned char previous_palette;
	unsigned char previous_map; //previous overworld map
	unsigned char elevator_map; //where to go when an elevator is exited

	void CheckWarp();
	void TryResetWarp();
};