#pragma once
#include "BitmapPlusPlus.hpp"

enum class Rotation {
	half_pi = 90,
	pi = 180,
	three_halves_of_pi = 270
};

enum class Reflection {
	horizontal,
	vertical
};

bmp::Bitmap imageRotation(bmp::Bitmap const& image, const Rotation angle);
bmp::Bitmap imageReflection(bmp::Bitmap const& image, const Reflection axis);