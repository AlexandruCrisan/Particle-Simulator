#ifndef PARTICLE_HEADER
#define PARTICLE_HEADER

#include "SFML/Graphics.hpp"
#include "Source.h"

class Particle {
private:
	const float FRICTION = 0.001f;

	sf::Vector2f position, velocity;
	sf::CircleShape shape;

public:
	Particle(sf::Vector2f pos = sf::Vector2f(100 + rand() % 800, 100 + rand() % 800), sf::Vector2f vel = sf::Vector2f(0,0), sf::Color fill_color = sf::Color::Black, int radius = 2);

	void draw(sf::RenderWindow& window);
	
	void update(Source& source, bool is_attracted);

	// Getters & Setters

	sf::Vector2f get_position();
	void set_position(sf::Vector2f pos);
};

#endif

