#include "corrector.hpp"
#include <iostream>
#include <string>

int main(void)
{
	try
	{
		std::string file_name;
		std::cout << "Input file name (*.bmp): ";
		while (true) {
			getline(std::cin, file_name);
			if (file_name.rfind(".bmp") == (file_name.size() - 4)) break;
			std::cout << "Repeat input file name (*.bmp): " << std::endl;
		}

		bmp::Bitmap image(file_name);

		imageReflection(image, Reflection::horizontal);
		imageReflection(image, Reflection::vertical);

		imageRotation(image, Rotation::half_pi);
		imageRotation(image, Rotation::pi);
		imageRotation(image, Rotation::three_halves_of_pi);
	}
	catch (const bmp::Exception& e)
	{
		std::cerr << "[BMP ERROR]: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}