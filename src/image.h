#pragma once

#include <string>
#include <vector>

#include "colour.h"

class Image
{
public:
	Image(int h, int w);

	void SetPixel(int x, int y, Colour colour);
	void SaveImage(const std::string& filename) const;

private:
	int height;
	int width;

	std::vector<int> image_buffer;
};