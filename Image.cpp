#include "SFML/Graphics.hpp"
#include "Image.h"
#include <filesystem>
#include <iostream>
#include <Windows.h>
#include <opencv2/opencv.hpp>
#include "Particle.h"

//using std::string, std::vector;

Image::Image() {

}

void Image::load_image(int image_index) {
	this->image = cv::imread("./image_here/" + this->available_images[image_index - 1]);
}

std::vector<Particle> Image::transform_image_into_particles() {
	cv::Mat resized_image;

	//resize down
	cv::resize(this->image, resized_image, cv::Size(this->NUMBER_OF_PIXELS, this->NUMBER_OF_PIXELS), cv::INTER_LINEAR);

	int spacing_x = 100, spacing_y = 100;

	for (int i = 0; i < resized_image.rows; i++) {
		spacing_x = 100;
		for (int j = 0; j < resized_image.cols; j++) {
			// get pixel
			cv::Vec3b& color = resized_image.at<cv::Vec3b>(i, j);

			this->image_as_particles.push_back(Particle(sf::Vector2f(spacing_x + j, spacing_y + i), sf::Vector2f(0, 0), sf::Color(color[2], color[1], color[0]), 2));
			spacing_x += 1;
		}
		spacing_y += 1;
	}

	return this->image_as_particles;
}

std::vector<std::string> Image::get_available_images() {
	for (const auto& entry : std::filesystem::directory_iterator("./image_here")) {
		available_images.push_back(entry.path().filename().string());
	}
	return available_images;
}
