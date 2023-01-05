#ifndef IMAGE_HEADER
#define IMAGE_HEADER

#include <string>
#include <vector>
#include "Particle.h"
#include <opencv2/opencv.hpp>

class Image {
private:
	const int NUMBER_OF_PIXELS = 100;
	std::vector<std::string> available_images;
	std::vector<Particle> image_as_particles;
	cv::Mat image;


public:
	Image();

	void load_image(int image_index);
	std::vector<std::string> get_available_images();
	std::vector<Particle> transform_image_into_particles();

	// Getters & Setters
};

#endif 

