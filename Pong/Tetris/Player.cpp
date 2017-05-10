#include "Player.h"

Player::Player(unsigned int winW, unsigned int winH)
{
	for (int i = 0; i < 2; i++)
	{
		player[i].setFillColor(sf::Color::White);
		player[i].setSize(sf::Vector2f(15.0f, 70.0f));
		player[i].setOrigin(player[i].getSize() / 2.0f);

		if (i < 1)
			player[i].setPosition(1.5f, winH / 2);
		else
			player[i].setPosition(winW - 1.5f, winH / 2);
	}
	direction1 = Direction::None;
	direction2 = Direction::None;
}

Player::~Player() {}

void Player::Update(float time)
{
	movePlayer1(time);
	movePlayer2(time);
}

void Player::movePlayer1(float time)
{
	if (direction1 == Direction::Up && player[0].getPosition().y > 51)
	{
		player[0].setPosition(player[0].getPosition().x, player[0].getPosition().y - 15.0f * time);
		direction1 = Direction::None;
	}
	else if (direction1 == Direction::Down && player[0].getPosition().y < 589)
	{
		player[0].setPosition(player[0].getPosition().x, player[0].getPosition().y + 15.0f * time);
		direction1 = Direction::None;
	}
}

void Player::movePlayer2(float time)
{
	if (direction2 == Direction::Up && player[1].getPosition().y > 51)
	{
		player[1].setPosition(player[1].getPosition().x, player[1].getPosition().y - 15.0f * time);
		direction2 = Direction::None;
	}
	else if (direction2 == Direction::Down && player[1].getPosition().y < 589)
	{
		player[1].setPosition(player[1].getPosition().x, player[1].getPosition().y + 15.0f * time);
		direction2 = Direction::None;
	}
}

void Player::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(player[i]);
	}
}

void Player::SetDirection1(Direction dir) { direction1 = dir; }

Direction Player::GetDirection1() { return direction1; }

void Player::SetDirection2(Direction dir) { direction2 = dir; }

Direction Player::GetDirection2() { return direction2; }