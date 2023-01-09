#include "Manager.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Source.h"
#include "Image.h"
#include <string>
#include "SFML/Graphics.hpp"

void Manager::navigate(int x, int y) {
	COORD c(x, y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Manager::diplay_particles(std::vector<Particle> particles) {
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Aplicatie", sf::Style::Titlebar | sf::Style::Close);
	Source source(sf::Vector2f(800, 500), 3500, sf::Color::Red, 10);


	while (window.isOpen()) {
		sf::Event e;
		bool pressed = false;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

		if (pressed) {
			source.update(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
		}
		for (int i = 0; i < particles.size(); ++i) {
			particles[i].update(source, pressed);
			particles[i].draw(window);
		}
		window.display();
	}
	cv::waitKey();
	cv::destroyAllWindows();
}

int Manager::prompt_ask_for_image(Image& image) {
	std::vector<std::string> available_images = image.get_available_images();

	if (!available_images.size()) {
		return -1;
	}

	std::vector<int> colors(available_images.size(), 7);
	colors[0] = 23;

	int current_position = 1;
	char key = '\0';

	std::cout << txt_ask_user;
	
	while (key != '\r') {

		for (int i = 0; i < available_images.size(); ++i) {
			navigate(0, i + 1);
			set_color(colors[i]);
			std::cout << i+1 << ") " << available_images[i];
		}

		key = _getch();

		if (key == 72 && current_position > 1) {
			current_position--;
		}
		if (key == 80 && current_position < 4) {
			current_position++;
		}

		colors = std::vector<int>(available_images.size(), 7);
		colors[current_position - 1] = 23;
	}
	set_color(7);
	return current_position;
}

void Manager::start() {
	Image image;
	int image_index = prompt_ask_for_image(image);

	if (image_index == -1) {
		set_color(31);
		std::cout << "Make sure you add at least one image to the folder!";
		std:getchar();
		return;
	}
	
	image.load_image(image_index);
	std::vector<Particle> img_as_particles = image.transform_image_into_particles();

	diplay_particles(img_as_particles);
	return;
}

void Manager::set_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


