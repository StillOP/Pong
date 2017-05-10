#ifndef WORLD_H
#define WORLD_H

#include <SFML\Graphics.hpp>
#include "Player.h"
#include <sstream>

class World
{
public:
	World(sf::Vector2u winSize);
	~World();
	void RespawnBall();

	void Update(Player& p, float time);
	void Render(sf::RenderWindow& window);

	sf::CircleShape* GetBall();

private:
	void moveBall(float time);
	void Setvxvy();

	float elapsed;

	sf::CircleShape ball;
	sf::RectangleShape bounds[2];
	sf::RectangleShape middleBounds;
	sf::Vector2u windowSize;
	int blockSize;
	sf::Vector2f ballPosition;
	int Ballx;
	int Bally;
	float vx;
	float vy;

	int score1;
	int score2;

	sf::Font font;
	sf::Text text[2];

};



#endif