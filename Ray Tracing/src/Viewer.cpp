

#include "Viewer.h"

Viewer::Viewer()
{
}


Viewer::~Viewer()
{
}

void Viewer::displayImage()
{
	if (_texture.getSize().x != 0) {
		_window.create(sf::VideoMode(1280, 720, 32), "PPM Viewer");
		updateImage();
		sf::Event e;
		bool bWindowShouldClose = false;
		while (!bWindowShouldClose) {
			while (_window.pollEvent(e)) {
				switch (e.type) {
				case sf::Event::Closed:
					bWindowShouldClose = true;
					break;
				case sf::Event::MouseWheelScrolled:
					zoom(e);
					updateImage();
					break;
				case sf::Event::Resized:
					_window.setSize(sf::Vector2u(_window.getSize().x, (_window.getSize().x / 16 * 9)));
					updateImage();
					break;
				}

			}
		}
	}
}

void Viewer::setImage(PPM& image)
{
	sf::Image sfImage;
	uint64_t uWidth = image.uGetWidth();
	uint64_t uHeight = image.uGetHeight();
	uint64_t uXPosition = 0;
	uint64_t uYPosition = 0;
	sfImage.create(image.uGetWidth(), image.uGetHeight(), sf::Color::Black);

	for (auto p : image.arrRGBGetPixelArray()) {
		sfImage.setPixel(uXPosition, uYPosition, sf::Color(p.uR(), p.uG(), p.uB()));
		uXPosition++;
		if (uXPosition == uWidth) {
			uXPosition = 0;
			uYPosition++;
		}
	}
	_texture.loadFromImage(sfImage);
	_sprite.setTexture(_texture);
	_sprite.setPosition(0, 0);
}

void Viewer::saveImage(const char *pchFilePath)
{
	_sprite.getTexture()->copyToImage().saveToFile(pchFilePath);
}

void Viewer::updateImage()
{
	_sprite.setScale(_window.getSize().x / _sprite.getTexture()->getSize().x,
		_window.getSize().y / _sprite.getTexture()->getSize().y);
	_window.clear();
	_window.draw(_sprite);
	_window.display();
}

void Viewer::zoom(const sf::Event& eventScrollEvent)
{
	_dbCurrentZoom += eventScrollEvent.mouseWheelScroll.y;
	if (_dbCurrentZoom < 0.5) {
		_dbCurrentZoom = 0.5;
	}
	else if (_dbCurrentZoom > 2) {
		_dbCurrentZoom = 2;
	}
}

void Viewer::pan(const sf::Event& eventPanEvent)
{

}