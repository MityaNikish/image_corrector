#include <iostream>
#include "corrector.hpp"

namespace {
	bmp::Bitmap builderImage(bmp::Bitmap const &image, bool change_sides_enable,
		std::int32_t(*rule_x)(const bmp::Bitmap&, std::int32_t),
		std::int32_t(*rule_y)(const bmp::Bitmap&, std::int32_t)) 
	{
		bmp::Bitmap result_image;

		if (change_sides_enable) {
			result_image = bmp::Bitmap{ image.height(), image.width() };
		}
		else
		{
			result_image = bmp::Bitmap{ image.width(), image.height() };
		}
		

		for (std::int32_t y = 0; y < image.height(); ++y)
		{
			for (std::int32_t x = 0; x < image.width(); ++x)
			{
				if (change_sides_enable) {
					result_image.set(rule_x(image, y), rule_y(image, x), image.get(x, y));
				}
				else
				{
					result_image.set(rule_x(image, x), rule_y(image, y), image.get(x, y));
				}
			}
		}

		return result_image;
	}
}


bmp::Bitmap imageRotation(bmp::Bitmap const& image, Rotation angle) {
	bmp::Bitmap result_image;
	std::string postfix;

	switch (angle)
	{
	case Rotation::half_pi:
		result_image = builderImage(image, true,
			[](bmp::Bitmap const& image, std::int32_t arg) { return image.height() - arg - 1; },
			[](bmp::Bitmap const& image, std::int32_t arg) { return arg; });
		postfix = "_90.bmp";
		break;
	case Rotation::pi:
		result_image = builderImage(image, false,
			[](bmp::Bitmap const& image, std::int32_t arg) { return image.width() - arg - 1; },
			[](bmp::Bitmap const& image, std::int32_t arg) { return image.height() - arg - 1; });
		postfix = "_180.bmp";
		break;
	case Rotation::three_halves_of_pi:
		result_image = builderImage(image, true,
			[](bmp::Bitmap const& image, std::int32_t arg) { return arg; },
			[](bmp::Bitmap const& image, std::int32_t arg) { return image.width() - arg - 1; });
		postfix = "_270.bmp";
		break;
	default:
		throw bmp::Exception("Incorrect enum const in \"imageRotation()\".");
		break;
	}

	return result_image;
}


bmp::Bitmap imageReflection(bmp::Bitmap const& image, Reflection axis) {
	bmp::Bitmap result_image;
	std::string postfix;

	switch (axis)
	{
	case Reflection::horizontal:
		result_image = builderImage(image, false,
			[](bmp::Bitmap const& image, std::int32_t arg) { return image.width() - arg - 1; },
			[](bmp::Bitmap const& image, std::int32_t arg) { return arg; });
		postfix = "_h.bmp";
		break;
	case Reflection::vertical:
		result_image = builderImage(image, false,
			[](bmp::Bitmap const& image, std::int32_t arg) { return arg; },
			[](bmp::Bitmap const& image, std::int32_t arg) { return image.height() - arg - 1; });
		postfix = "_v.bmp";
		break;
	default:
		throw bmp::Exception("Incorrect enum const in \"imageReflection()\".");
		break;
	}

	return result_image;
}


void saveImageRotation(bmp::Bitmap& image, std::string file_name, Rotation angle) {
	std::string postfix;
	switch (angle)
	{
	case Rotation::half_pi:
		postfix = "_90.bmp";
		break;
	case Rotation::pi:
		postfix = "_180.bmp";
		break;
	case Rotation::three_halves_of_pi:
		postfix = "_270.bmp";
		break;
	default:
		postfix = ".bmp";
		break;
	}

	image.save(file_name + postfix);
}

void saveImageRotation(bmp::Bitmap& image, std::string file_name, Reflection axis) {
	std::string postfix;

	//switch (angle)
	//{
	//case Rotation::half_pi:
	//	postfix = "_90.bmp";
	//	break;
	//case Rotation::pi:
	//	postfix = "_180.bmp";
	//	break;
	//case Rotation::three_halves_of_pi:
	//	postfix = "_270.bmp";
	//	break;
	//default:
	//	postfix = ".bmp";
	//	break;
	//}

	image.save(file_name + postfix);
}