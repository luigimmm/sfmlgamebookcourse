#include "Game.h"
#include <iostream>
Game::Game()
:mWindow(sf::VideoMode(640,480),"SFML Application")
, mTexture()
, mPlayer()
{
	/*mPlayer.setRadius(40.f);
	mPlayer.setPosition(0.f,0.f);
	mPlayer.setFillColor(sf::Color::Cyan);*/
	
	if (!mTexture.loadFromFile("Media/Texture/Eagle.png"))
	{
		// Handle loading error
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
}
void Game::run() 
{
	sf::Clock clock;
	sf::Time timesSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) 
	{
		
		timesSinceLastUpdate += clock.restart();
		while (timesSinceLastUpdate> TimerPerFrame)
		{
			timesSinceLastUpdate -= TimerPerFrame;
			processEvents();
			update(TimerPerFrame);
		}
		
		render();
	}

}
void Game::processEvents() 
{
	sf::Event evnt;
	while (mWindow.pollEvent(evnt)) 
	{
		switch (evnt.type)
		{
		case sf::Event::KeyReleased:
			handlePlayerInput(evnt.key.code, false);
			break;
		case sf::Event::KeyPressed:
			handlePlayerInput(evnt.key.code, true);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}		
	}
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
}
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	//printf("%s", "se esta moviendo");
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	mPlayer.move(movement * deltaTime.asSeconds());

}

void Game::render() 
{
	sf::Texture texture;
	if (!texture.loadFromFile("Media/Texture/Eagle.png"))
	{
		// Handle loading error
		std::cout << "no encontro el archivo";
	}
	sf::Sprite sprite(texture);
	sprite.setPosition(100.f, 100.f);
	
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}
Game::~Game()
{
}