#ifndef MANAGER_HEADER
#define MANAGER_HEADER

#include <string>
#include "Image.h"
#include <Windows.h>

class Manager {
private:
	std::string txt_ask_user = "Please select the image you want to use:\n\n";
	
	void set_color(int color);
	void navigate(int x, int y);
	int prompt_ask_for_image(Image& image);
	void diplay_particles(std::vector<Particle> particles);

public:
	void start();
	
};

#endif
