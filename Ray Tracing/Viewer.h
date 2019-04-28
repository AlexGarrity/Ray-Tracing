#pragma once

#include <SFML/Graphics.hpp>
#include "PPM.h"

class Viewer
{
public:
	Viewer();
	~Viewer();

	void displayImage();
	void setImage(PPM& image);
	void saveImage(const char* pchFilePath);

private:
	void updateImage();
	void zoom(const sf::Event& eventScrollEvent);
	void pan(const sf::Event& eventPanEvent);

	double_t _dbCurrentZoom = 1.0;
	sf::Vector2<double_t> _vec2ScreenPosition = sf::Vector2<double_t>(640.0, 360.0);

	sf::RenderWindow _window;
	sf::View _view;
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;
};