#include <SFML/Graphics.hpp>

#pragma once
class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);
	bool mIsMovingUp=false;
	bool mIsMovingDown=false;
	bool mIsMovingRight=false;
	bool mIsMovingLeft=false;
	float PlayerSpeed = 100.f;
	sf::Time TimerPerFrame = sf::seconds(1.f / 60.f);


private:
	sf::Sprite mPlayer;
	sf::Texture mTexture;
	sf::RenderWindow mWindow;
	

};

