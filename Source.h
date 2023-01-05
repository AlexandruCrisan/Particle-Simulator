#ifndef SOURCE_HEADER
#define SOURCE_HEADER

#include <SFML/Graphics.hpp>

class Source{
private:
	sf::Vector2f position;
	sf::CircleShape shape;

	float power;
public:
	Source(sf::Vector2f pos, float pwr, sf::Color fill_color, int radius);
	
	void draw(sf::RenderWindow& window, float pos_x, float pos_y);
	void update(sf::Vector2f pos);

	// Getters & Setters

	sf::Vector2f get_position();
	void set_position(sf::Vector2f pos);

	float get_power();
	void set_power(float pwr);
};

#endif
