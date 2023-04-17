#include  "rename.hpp"

std::string pushPostfixRotation(std::string const& file_name, const Rotation angle) {
	std::string postfix, file_name_separation = file_name;
	if (file_name_separation.rfind(".bmp"))
	{
		file_name_separation.erase(file_name_separation.rfind(".bmp"));
	}

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
	return file_name_separation + postfix;
}

std::string pushPostfixReflection(std::string const& file_name, const Reflection axis) {
	std::string postfix, file_name_separation = file_name;
	if (file_name_separation.rfind(".bmp"))
	{
		file_name_separation.erase(file_name_separation.rfind(".bmp"));
	}

	switch (axis)
	{
	case Reflection::horizontal:
		postfix = "_h.bmp";
		break;
	case Reflection::vertical:
		postfix = "_v.bmp";
		break;
	default:
		postfix = ".bmp";
		break;
	}
	return file_name_separation + postfix;
}