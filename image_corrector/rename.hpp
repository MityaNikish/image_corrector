#pragma once
#include "rotation_reflection.hpp"
#include <string>

std::string pushPostfixRotation(std::string const& file_name, const Rotation angle);
std::string pushPostfixReflection(std::string const& file_name, const Reflection axis);