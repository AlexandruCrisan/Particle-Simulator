#include "Source.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Source::Source(sf::Vector2f pos, float pwr, sf::Color fill_color, int radius) {
	this->position = pos;
	this->power = pwr;

	this->shape.setPosition(pos);
	this->shape.setFillColor(fill_color);
	this->shape.setRadius(radius);
}

void Source::draw(sf::RenderWindow& window, float pos_x, float pos_y) {
	//std::cout << pos_x << " " << pos_y << '\n';
	
	this->shape.setPosition(sf::Vector2f(pos_x, pos_y));
	window.draw(this->shape);
}

void Source::update(sf::Vector2f pos) {
	this->position = pos;
}

// Getters & Setters

sf::Vector2f Source::get_position() {
	return this->position;
}

void Source::set_position(sf::Vector2f pos) {
	this->position = pos;
}

float Source::get_power() {
	return this->power;
}

void Source::set_power(float pwr) {
	this->power = pwr;
}