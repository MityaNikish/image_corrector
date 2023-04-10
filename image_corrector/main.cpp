#include "corrector.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>


int main(void)
{
	try
	{
		std::string file_name;
		std::cout << "Input file name (*.bmp): ";
		while (true) {
			getline(std::cin, file_name);
			if (std::filesystem::exists(file_name) && std::filesystem::path(file_name).extension() == ".bmp") break;
			std::cout << "Repeat input file name (*.bmp): " << std::endl;
		}

		bmp::Bitmap image(file_name);
		std::vector<Reflection> reflection_axis{ Reflection::horizontal , Reflection::vertical };
		std::vector<Rotation> reflection_angle{ Rotation::half_pi, Rotation::pi, Rotation::three_halves_of_pi };

		for (auto axis : reflection_axis) {
			imageReflection(image, axis);
			saveImageReflection(image, file_name, axis);	
		}

		for (auto angle : reflection_angle) {
			imageRotation(image, angle);
			saveImageRotation(image, file_name, angle);
		}
	}
	catch (const bmp::Exception& e)
	{
		std::cerr << "[BMP ERROR]: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}