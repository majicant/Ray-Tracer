#include <fstream>

#include "image.h"

Image::Image(int h, int w)
	: height(h), width(w), image_buffer(h * w * 3)
{
}

void Image::SetPixel(int x, int y, Colour colour)
{
	int position = (x + y * width) * 3;
	image_buffer[position] = static_cast<int>(255.999 * colour.r);
	image_buffer[position + 1] = static_cast<int>(255.999 * colour.g);
	image_buffer[position + 2] = static_cast<int>(255.999 * colour.b);
}

void Image::SaveImage(const std::string& filename) const
{
	std::ofstream image(filename);
	image << "P3\n" << width << ' ' << height << "\n255\n";
	for (int pixel = 0; pixel < height * width; pixel++) {
		int position = pixel * 3;
		image << image_buffer[position] << ' ' << image_buffer[position + 1] << ' ' << image_buffer[position + 2] << '\n';
	}
	image.close();
}