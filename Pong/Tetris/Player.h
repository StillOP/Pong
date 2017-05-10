#ifndef  PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>

enum class Direction {Up, Down,	None};

class Player
{
public:
	Player(unsigned int winW, unsigned int winH);
	~Player();

	void Update(float time);
	void Render(sf::RenderWindow& window);

	void SetDirection1(Direction dir);
	void SetDirection2(Direction dir);
	Direction GetDirection1();
	Direction GetDirection2();

	sf::RectangleShape player[2];

private:
	void movePlayer1(float time);
	void movePlayer2(float time);


	Direction direction1;
	Direction direction2;

	
};



#endif
