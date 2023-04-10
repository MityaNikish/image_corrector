#pragma once
#include "BitmapPlusPlus.hpp"
#include <string>

enum class Rotation {
	half_pi = 90,
	pi = 180,
	three_halves_of_pi = 270
};

enum class Reflection {
	horizontal,
	vertical
};

bmp::Bitmap imageRotation(bmp::Bitmap const& image, Rotation rotation_degree);
bmp::Bitmap imageReflection(bmp::Bitmap const& image, Reflection axis);
void saveImageRotation(bmp::Bitmap& image, std::string file_name, Rotation angle);
void saveImageReflection(bmp::Bitmap& image, std::string file_name, Reflection axis);