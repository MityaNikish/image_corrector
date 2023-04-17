#include "rotation_reflection.hpp"
#include "rename.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>


int main()
{
	try
	{
		std::string file_name;
		std::cout << "Input file name (*.bmp): ";
		while (true) {
			getline(std::cin, file_name);
			if (std::filesystem::exists(file_name) && std::filesystem::path(file_name).extension() == ".bmp") break;
			std::cout << "Repeat input file name (*.bmp): ";
		}

		const bmp::Bitmap image(file_name);
		const std::vector reflection_axis{ Reflection::horizontal , Reflection::vertical };
		const std::vector reflection_angle{ Rotation::half_pi, Rotation::pi, Rotation::three_halves_of_pi };

		for (const auto axis : reflection_axis) {
			bmp::Bitmap result_image = imageReflection(image, axis);
			result_image.save(pushPostfixReflection(file_name, axis));
		}

		for (const auto angle : reflection_angle) {
			bmp::Bitmap result_image = imageRotation(image, angle);
			result_image.save(pushPostfixRotation(file_name, angle));
		}
	}
	catch (const bmp::Exception& e)
	{
		std::cerr << "[BMP ERROR]: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}