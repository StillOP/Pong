#include "Game.h"


Game::Game() : window("Tetris", sf::Vector2u(800, 640)), player(800, 640), world(sf::Vector2u(800, 640))
{
	clock.restart();
	//srand(time(nullptr));
	elapsed = 0.0f;
}

Game::~Game() {}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player.SetDirection2(Direction::Up);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player.SetDirection2(Direction::Down);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		player.SetDirection1(Direction::Up);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.SetDirection1(Direction::Down);
}

void Game::Update()
{
	window.WindowUpdate();

	/*world.Update(player);
	player.Update();*/

	float timestep = 1.0f / 60.0f;
	if (elapsed >= timestep)
	{
		world.Update(player, timestep);
		player.Update(timestep);
	}
}

void Game::Render()
{
	window.BeginDraw();
	world.Render(*window.GetRenderWindow());
	player.Render(*window.GetRenderWindow());
	window.EndDraw();
}

void Game::RestartClock()
{
	elapsed += clock.restart().asSeconds();
}

Window* Game::GetWindow() { return &window; }