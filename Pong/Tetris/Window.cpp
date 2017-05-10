#include "Window.h"

Window::Window()
{
	isFullscreen = false;
	CreateWindow("Tetris", sf::Vector2u(800, 640));	
}

Window::Window(const std::string winTitle, sf::Vector2u winSize)
{
	isFullscreen = false;
	CreateWindow(winTitle, winSize);
}

Window::~Window() { ShutDown(); }

void Window::CreateWindow(const std::string winTitle, sf::Vector2u winSize)
{
	isDone = false;

	windowTitle = winTitle;
	windowWidth = winSize.x;
	windowHeight = winSize.y;

	auto style = (isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);

	window.create({ windowWidth, windowHeight, 32 }, windowTitle, style);
}

void Window::WindowUpdate()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			isDone = true;
		else 
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
				SetFullScreen();
	}
}

void Window::SetFullScreen()
{
	isFullscreen = !isFullscreen;
	ShutDown();
	CreateWindow(windowTitle, sf::Vector2u(800, 640));

}

void Window::ShutDown()
{
	window.close();
}

void Window::BeginDraw() { window.clear(sf::Color::Black); }

void Window::EndDraw() { window.display(); }

bool Window::IsDone() { return isDone; }

unsigned int Window::GetWindowWidth() { return windowWidth; }

unsigned int Window::GetWindowHeight() { return windowHeight; }

sf::RenderWindow* Window::GetRenderWindow() { return &window; }
