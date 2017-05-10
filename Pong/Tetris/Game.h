#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Window.h"
#include "Player.h"
#include "World.h"

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Render();
	void RestartClock();
	void HandleInput();

	Window* GetWindow();

private:
	Window window;
	Player player;
	World world;


	sf::Clock clock;
	float elapsed;
};


#endif