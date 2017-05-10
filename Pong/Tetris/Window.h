#ifndef WINDOW_H
#define WINDOW_H

#include <SFML\Graphics.hpp>

class Window
{
public:
	Window();
	Window(const std::string winTitle, sf::Vector2u winSize);
	~Window();

	void WindowUpdate();
	bool IsDone();

	void BeginDraw();
	void EndDraw();

	unsigned int GetWindowWidth();
	unsigned int GetWindowHeight();
	sf::RenderWindow* GetRenderWindow();

private:
	void CreateWindow(const std::string winTitle, sf::Vector2u winSize);
	void SetFullScreen();
	void ShutDown();

	sf::RenderWindow window;

	bool isDone;
	bool isFullscreen;

	std::string windowTitle;
	unsigned int windowWidth;
	unsigned int windowHeight;

	

};


#endif
