#include "Particle.h"
#include <cmath>
#include <iostream>

Particle::Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Color fill_color, int radius) {
	//fill_color = this->colors[rand() % 4];

	this->position = pos;
	this->velocity = vel;

	this->shape.setPosition(pos);
	this->shape.setFillColor(fill_color);
	this->shape.setRadius(radius);
}
void Particle::draw(sf::RenderWindow& window) {
	this->shape.setPosition(this->position);
	window.draw(this->shape);
}

void Particle::update2() {

	//std::cout << velocity.x << " " << velocity.y << "\n";

	
}

void Particle::update(Source& source, bool is_attracted) {
	if (is_attracted) {
		sf::Vector2f acceleration = source.get_position() - this->position;
		
		// Normalizam acceleratia
		acceleration /= std::sqrt(acceleration.x * acceleration.x + acceleration.y * acceleration.y);
		
		this->velocity += acceleration * 0.5f;
		this->velocity -= this->FRICTION * this->velocity;
	}
	else {
		int new_friction = this->FRICTION * 10;
		if (this->velocity.x > 0)
			this->velocity.x -= this->velocity.x * new_friction;
		if (this->velocity.y > 0)
			this->velocity.y -= this->velocity.y * new_friction;

		if (this->velocity.x < 0)
			this->velocity.x += this->velocity.x * new_friction;
		if (this->velocity.y < 0)
			this->velocity.y += this->velocity.y * new_friction;
	}
	this->position += velocity;
}

// Getters & Setters

sf::Vector2f Particle::get_position() {
	return this->position;
}

void Particle::set_position(sf::Vector2f pos) {
	this->position = pos;
}