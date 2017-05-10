#include "World.h"
#include <time.h>


World::World(sf::Vector2u winSize)
{
	blockSize = 16;
	windowSize = winSize;

	ball.setFillColor(sf::Color::White);
	ball.setRadius(blockSize/2);
	RespawnBall();

	middleBounds.setFillColor(sf::Color::White);
	middleBounds.setSize(sf::Vector2f(1, windowSize.y - 20));
	middleBounds.setOrigin(middleBounds.getSize() / 2.0f);
	middleBounds.setPosition(sf::Vector2f(windowSize) / 2.0f);

	for (int i = 0; i < 2; i++)
	{
		bounds[i].setFillColor(sf::Color::White);
		bounds[i].setSize(sf::Vector2f(windowSize.x, blockSize));

		if (i < 1)
			bounds[i].setPosition(0, 1);
		else
		{
			bounds[i].setOrigin(bounds[i].getOrigin().x, bounds[i].getSize().y);
			bounds[i].setPosition(0, windowSize.y);
		}
	}
	srand((int)time(NULL)); 

	font.loadFromFile("./police/arial.ttf");
	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);	
		text[i].setCharacterSize(40);
		text[i].setFillColor(sf::Color::White);
		text[i].setString("0");

		if (i < 1)
			text[i].setPosition(windowSize.x / 4, 40.0f);
		else 
			text[i].setPosition(3 * windowSize.x / 4, 40.0f);
	}
	
	score1 = 0;
	score2 = 0;
}

World::~World() {}

void World::RespawnBall()
{
	Ballx = windowSize.x / 2.0f;
	Bally = windowSize.y - 30;
	ballPosition = sf::Vector2f(Ballx, rand() % Bally + 2);
	ball.setPosition(ballPosition);
	Setvxvy();

	//moveBall();
}

void World::Setvxvy()
{
	float dx = rand() % 2;
	float dy = rand() % 2;
	vx = 10.0f;
	vy = 10.0f;
	if (dy == 0)
		vy = -vy;
	else
		vy = vy;

	if (dx == 0)
		vx = -vx;
	else
		vx = vx;
}

void World::moveBall(float time)
{
	if (ball.getPosition().y < bounds[0].getPosition().y + 16 && vy < 0 || ball.getPosition().y > bounds[1].getPosition().y - 32 && vy>0)
		vy = -vy;

	sf::Vector2f velocity = sf::Vector2f(vx * time, vy * time);
	ball.setPosition(ball.getPosition().x + velocity.x, ball.getPosition().y + velocity.y);
}

void World::Update(Player& p, float time)

{
	moveBall(time);
	if (ball.getPosition().x < p.player[0].getPosition().x && vx <0 && ball.getPosition().y > p.player[0].getPosition().y - 35 && ball.getPosition().y < p.player[0].getPosition().y + 35)
	{
		vx = -vx;
		sf::Vector2f velocity = sf::Vector2f(vx * time, vy * time);
		ball.setPosition(ball.getPosition().x + velocity.x, ball.getPosition().y + velocity.y);
	}
	else if (ball.getPosition().x > p.player[1].getPosition().x - 15 && vx >0 && ball.getPosition().y > p.player[1].getPosition().y - 35 && ball.getPosition().y < p.player[1].getPosition().y + 35)
	{
		vx = -vx;
		sf::Vector2f velocity = sf::Vector2f(vx * time, vy * time);
		ball.setPosition(ball.getPosition().x + velocity.x, ball.getPosition().y + velocity.y);
	}
	if (ball.getPosition().x < -16 || ball.getPosition().x > windowSize.x) //15, 70
	{
		for (int i = 0; i < 2; i++)
		{
			if (i < 1)
				p.player[i].setPosition(1.5f, 640 / 2);
			else
				p.player[i].setPosition(800 - 1.5f, 640 / 2);
		}
		sf::sleep(sf::seconds(0.5));
		if (ball.getPosition().x < -16)
		{
			score2++;
			std::string x = std::to_string(score2);
			text[1].setString(x);
	
		}
			
		else if (ball.getPosition().x > windowSize.x)
		{
			score1++;
			std::string y = std::to_string(score1);
			text[0].setString(y);
		}
			
		RespawnBall();
		sf::sleep(sf::seconds(0.2));

	}
}

void World::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(bounds[i]);
	}
	window.draw(middleBounds);
	window.draw(ball);
	for (int i = 0; i < 2; i++)
	{
		window.draw(text[i]);
	}
	
	
}

sf::CircleShape* World::GetBall() { return &ball; }

