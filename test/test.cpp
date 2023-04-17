#include "pch.h"
#include "rotation_reflection.hpp"
#include "BitmapPlusPlus.hpp"
#include <vector>
#include <random>

void test_pixels(int r, int g, int b) {
	EXPECT_EQ(r, 255);
	EXPECT_EQ(g, 255);
	EXPECT_EQ(b, 255);
}

bmp::Bitmap generate_image(const int width, const int height)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> value(0, 255);

	bmp::Bitmap image(width, height);
	for (std::int32_t pos_y = 0; pos_y < height; pos_y++) {
		for (std::int32_t pos_x = 0; pos_x < width; pos_x++) {
			const auto color = static_cast<const std::uint8_t>(value(rng));
			const bmp::Pixel rand_pixel { color, color, color };
			image.set(pos_x, pos_y, rand_pixel);
		}
	}

	return image;
}

std::vector<bmp::Pixel> getLineX(bmp::Bitmap const& image, const int32_t begin_pos_x, const int32_t end_pos_x, const int32_t pos_y)
{
	std::vector<bmp::Pixel> line;
	EXPECT_TRUE((begin_pos_x <= image.width()) && (end_pos_x <= image.width()) && (pos_y <= image.height()));

	if (begin_pos_x > end_pos_x)
	{
		for (std::int32_t pos_x = begin_pos_x; pos_x <= end_pos_x; pos_x++) {
			line.push_back(image.get(pos_x, pos_y));
		}
	}
	else
	{
		for (std::int32_t pos_x = begin_pos_x; pos_x >= end_pos_x; pos_x--) {
			line.push_back(image.get(pos_x, pos_y));
		}
	}

	return line;
}

std::vector<bmp::Pixel> getLineY(bmp::Bitmap const& image, const int32_t begin_pos_y, const int32_t end_pos_y, const int32_t pos_x)
{
	std::vector<bmp::Pixel> line;
	if ((begin_pos_y < image.height()) && (end_pos_y < image.height()) && (pos_x < image.width())) return line;

	if (begin_pos_y > end_pos_y)
	{
		for (std::int32_t pos_y = begin_pos_y; pos_y <= end_pos_y; pos_y++) {
			line.push_back(image.get(pos_x, pos_y));
		}
	}
	else
	{
		for (std::int32_t pos_y = begin_pos_y; pos_y >= end_pos_y; pos_y--) {
			line.push_back(image.get(pos_x, pos_y));
		}
	}

	return line;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------//

TEST(case_rotation_half_pi, to_the_same_plase) {
	const bmp::Bitmap image_before = generate_image(10, 20);

	bmp::Bitmap image_after = imageRotation(image_before, Rotation::half_pi);
	image_after = imageRotation(image_after, Rotation::half_pi);
	image_after = imageRotation(image_after, Rotation::half_pi);
	image_after = imageRotation(image_after, Rotation::half_pi);

	EXPECT_TRUE(image_after == image_before);
}

TEST(case_rotation_half_pi, test_1) {
	const bmp::Bitmap image_before = generate_image(10, 20);
	const bmp::Bitmap image_after = imageRotation(image_before, Rotation::half_pi);

	EXPECT_TRUE(image_before.width() * image_before.height() == image_after.width() * image_after.height());
	EXPECT_TRUE(getLineX(image_before, 0, image_before.width(), 0) == getLineY(image_after, 0, image_after.height(), image_before.width()));
}

TEST(case_rotation_half_pi, test_2) {
	const bmp::Bitmap image_before = generate_image(10, 20);
	bmp::Bitmap image_after = imageRotation(image_before, Rotation::half_pi);
	image_after = imageRotation(image_before, Rotation::half_pi);

	EXPECT_TRUE(image_before.width() * image_before.height() == image_after.width() * image_after.height());
	EXPECT_TRUE(getLineX(image_before, 0, image_before.width(), 0) == getLineX(image_after, image_after.width(), 0, image_after.height()));
}

//-----------------------------------------------------------------------------------------------------------------------------------------------//

TEST(case_rotation_pi, to_the_same_plase) {
	const bmp::Bitmap image_before = generate_image(10, 20);

	bmp::Bitmap image_after = imageRotation(image_before, Rotation::pi);
	image_after = imageRotation(image_after, Rotation::pi);

	EXPECT_TRUE(image_after == image_before);
}

TEST(case_rotation_pi, test_1) {
	const bmp::Bitmap image_before = generate_image(10, 20);
	const bmp::Bitmap image_after = imageRotation(image_before, Rotation::pi);

	EXPECT_TRUE(image_before.width() * image_before.height() == image_after.width() * image_after.height());
	EXPECT_TRUE(getLineX(image_before, 0, image_before.width(), 0) == getLineX(image_after, image_after.width(), 0, image_after.height()));
}

//-----------------------------------------------------------------------------------------------------------------------------------------------//

TEST(case_rotation_three_halves_of_pi, to_the_same_plase) {
	const bmp::Bitmap image_before = generate_image(10, 20);

	bmp::Bitmap image_after = imageRotation(image_before, Rotation::three_halves_of_pi);
	image_after = imageRotation(image_after, Rotation::three_halves_of_pi);
	image_after = imageRotation(image_after, Rotation::three_halves_of_pi);
	image_after = imageRotation(image_after, Rotation::three_halves_of_pi);

	EXPECT_TRUE(image_after == image_before);
}

TEST(case_rotation_three_halves_of_pi, test_1) {
	const bmp::Bitmap image_before = generate_image(10, 20);
	const bmp::Bitmap image_after = imageRotation(image_before, Rotation::three_halves_of_pi);

	EXPECT_TRUE(image_before.width() * image_before.height() == image_after.width() * image_after.height());
	EXPECT_TRUE(getLineX(image_before, 0, image_before.width(), 0) == getLineY(image_after, image_after.height(), 0, 0));
}

//-----------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------//

TEST(case_rotation_horizontal, to_the_same_plase) {
	const bmp::Bitmap image_before = generate_image(10, 20);

	bmp::Bitmap image_after = imageReflection(image_before, Reflection::horizontal);
	image_after = imageReflection(image_after, Reflection::horizontal);

	EXPECT_TRUE(image_after == image_before);
}

TEST(case_reflection_horizontal, test_1) {
	const bmp::Bitmap image_before = generate_image(10, 20);
	const bmp::Bitmap image_after = imageReflection(image_before, Reflection::horizontal);

	EXPECT_TRUE(image_before.width() * image_before.height() == image_after.width() * image_after.height());
	EXPECT_TRUE(getLineX(image_before, 0, image_before.width(), 0) == getLineX(image_after, 0, image_after.width(), image_after.height()));
	EXPECT_TRUE(getLineY(image_before, 0, image_before.height(), 0) == getLineY(image_after, image_after.height(), 0, 0));
}

//-----------------------------------------------------------------------------------------------------------------------------------------------//

TEST(case_rotation_vertical, to_the_same_plase) {
	const bmp::Bitmap image_before = generate_image(10, 20);

	bmp::Bitmap image_after = imageReflection(image_before, Reflection::vertical);
	image_after = imageReflection(image_after, Reflection::vertical);

	EXPECT_TRUE(image_after == image_before);
}

TEST(case_reflection_vertical, test_1) {
	const bmp::Bitmap image_before = generate_image(10, 20);
	const bmp::Bitmap image_after = imageReflection(image_before, Reflection::vertical);

	EXPECT_TRUE(image_before.width() * image_before.height() == image_after.width() * image_after.height());
	EXPECT_TRUE(getLineX(image_before, 0, image_before.width(), 0) == getLineX(image_after, image_after.width(), 0, 0));
	EXPECT_TRUE(getLineY(image_before, 0, image_before.height(), 0) == getLineY(image_after, 0, image_after.height(), image_after.height()));
}

//-----------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------//

TEST(pi_double_two, one_X_one) {
	bmp::Bitmap image(1, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(pi_double_two, one_X_two) {
	bmp::Bitmap image(2, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(pi_double_two, two_X_two) {
	bmp::Bitmap image(2, 2);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(pi_double_two, one_X_three) {
	bmp::Bitmap image(3, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(pi_double_two, two_X_three) {
	bmp::Bitmap image(3, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(pi_double_two, two_X_four) {
	bmp::Bitmap image(4, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 1, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
}
TEST(pi_double_two, three_X_two) {
	bmp::Bitmap image(2, 3);
	image.set(1, 0, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
}
TEST(pi_double_two, five_X_four) {
	bmp::Bitmap image(4, 5);
	image.set(3, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 3, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(3, 1).r, image.get(3, 1).g, image.get(3, 1).b);
	test_pixels(image.get(1, 2).r, image.get(1, 2).g, image.get(1, 2).b);
	test_pixels(image.get(4, 3).r, image.get(4, 3).g, image.get(4, 3).b);
}
TEST(pi_double_two, three_X_three) {
	bmp::Bitmap image(3, 3);
	image.set(0, 0, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
}
TEST(pi_double_two, four_X_four) {
	bmp::Bitmap image(4, 4);
	image.set(0, 0, bmp::White);
	image.set(3, 1, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageRotation(image, Rotation::half_pi);
	test_pixels(image.get(3, 0).r, image.get(3, 0).g, image.get(3, 0).b);
	test_pixels(image.get(2, 3).r, image.get(2, 3).g, image.get(2, 3).b);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
}

TEST(pi, one_X_one) {
	bmp::Bitmap image(1, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(pi, one_X_two) {
	bmp::Bitmap image(2, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(pi, two_X_two) {
	bmp::Bitmap image(2, 2);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
}
TEST(pi, one_X_three) {
	bmp::Bitmap image(3, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
}
TEST(pi, two_X_three) {
	bmp::Bitmap image(3, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(pi, two_X_four) {
	bmp::Bitmap image(4, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 1, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(3, 1).r, image.get(3, 1).g, image.get(3, 1).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
}
TEST(pi, three_X_two) {
	bmp::Bitmap image(2, 3);
	image.set(1, 0, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
}
TEST(pi, five_X_four) {
	bmp::Bitmap image(4, 5);
	image.set(3, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 3, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
	test_pixels(image.get(0, 4).r, image.get(0, 4).g, image.get(0, 4).b);
	test_pixels(image.get(2, 3).r, image.get(2, 3).g, image.get(2, 3).b);
}
TEST(pi, three_X_three) {
	bmp::Bitmap image(3, 3);
	image.set(0, 0, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(2, 2).r, image.get(2, 2).g, image.get(2, 2).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(pi, four_X_four) {
	bmp::Bitmap image(4, 4);
	image.set(0, 0, bmp::White);
	image.set(3, 1, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageRotation(image, Rotation::pi);
	test_pixels(image.get(3, 3).r, image.get(3, 3).g, image.get(3, 3).b);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
}

TEST(tree_pi_double_two, one_X_one) {
	bmp::Bitmap image(1, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(tree_pi_double_two, one_X_two) {
	bmp::Bitmap image(2, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
}
TEST(tree_pi_double_two, two_X_two) {
	bmp::Bitmap image(2, 2);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
}
TEST(tree_pi_double_two, one_X_three) {
	bmp::Bitmap image(3, 1);
	image.set(0, 0, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
}
TEST(tree_pi_double_two, two_X_three) {
	bmp::Bitmap image(3, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
}
TEST(tree_pi_double_two, two_X_four) {
	bmp::Bitmap image(4, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 1, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
	test_pixels(image.get(1, 2).r, image.get(1, 2).g, image.get(1, 2).b);
	test_pixels(image.get(0, 3).r, image.get(0, 3).g, image.get(0, 3).b);
}
TEST(tree_pi_double_two, three_X_two) {
	bmp::Bitmap image(2, 3);
	image.set(1, 0, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(tree_pi_double_two, five_X_four) {
	bmp::Bitmap image(4, 5);
	image.set(3, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 3, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
	test_pixels(image.get(1, 2).r, image.get(1, 2).g, image.get(1, 2).b);
	test_pixels(image.get(3, 1).r, image.get(3, 1).g, image.get(3, 1).b);
}
TEST(tree_pi_double_two, three_X_three) {
	bmp::Bitmap image(3, 3);
	image.set(0, 0, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
}
TEST(tree_pi_double_two, four_X_four) {
	bmp::Bitmap image(4, 4);
	image.set(0, 0, bmp::White);
	image.set(3, 1, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageRotation(image, Rotation::three_halves_of_pi);
	test_pixels(image.get(0, 3).r, image.get(0, 3).g, image.get(0, 3).b);
	test_pixels(image.get(2, 2).r, image.get(2, 2).g, image.get(2, 2).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}

TEST(H, one_X_one) {
	bmp::Bitmap image(1, 1);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(H, one_X_two) {
	bmp::Bitmap image(2, 1);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(H, two_X_two) {
	bmp::Bitmap image(2, 2);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(H, one_X_three) {
	bmp::Bitmap image(3, 1);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
}
TEST(H, two_X_three) {
	bmp::Bitmap image(3, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
}
TEST(H, two_X_four) {
	bmp::Bitmap image(4, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 1, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
	test_pixels(image.get(3, 0).r, image.get(3, 0).g, image.get(3, 0).b);
}
TEST(H, three_X_two) {
	bmp::Bitmap image(2, 3);
	image.set(1, 0, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(H, five_X_four) {
	bmp::Bitmap image(4, 5);
	image.set(3, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 3, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
	test_pixels(image.get(1, 3).r, image.get(1, 3).g, image.get(1, 3).b);
}
TEST(H, three_X_three) {
	bmp::Bitmap image(3, 3);
	image.set(0, 0, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
	test_pixels(image.get(1, 2).r, image.get(1, 2).g, image.get(1, 2).b);
}
TEST(H, four_X_four) {
	bmp::Bitmap image(4, 4);
	image.set(0, 0, bmp::White);
	image.set(3, 1, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageReflection(image, Reflection::horizontal);
	test_pixels(image.get(3, 0).r, image.get(3, 0).g, image.get(3, 0).b);
	test_pixels(image.get(2, 2).r, image.get(2, 2).g, image.get(2, 2).b);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
}

TEST(V, one_X_one) {
	bmp::Bitmap image(1, 1);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(V, one_X_two) {
	bmp::Bitmap image(2, 1);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(V, two_X_two) {
	bmp::Bitmap image(2, 2);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
}
TEST(V, one_X_three) {
	bmp::Bitmap image(3, 1);
	image.set(0, 0, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 0).r, image.get(0, 0).g, image.get(0, 0).b);
}
TEST(V, two_X_three) {
	bmp::Bitmap image(3, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(V, two_X_four) {
	bmp::Bitmap image(4, 2);
	image.set(0, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 1, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 1).r, image.get(0, 1).g, image.get(0, 1).b);
	test_pixels(image.get(2, 0).r, image.get(2, 0).g, image.get(2, 0).b);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
}
TEST(V, three_X_two) {
	bmp::Bitmap image(2, 3);
	image.set(1, 0, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(1, 2).r, image.get(1, 2).g, image.get(1, 2).b);
}
TEST(V, five_X_four) {
	bmp::Bitmap image(4, 5);
	image.set(3, 0, bmp::White);
	image.set(1, 1, bmp::White);
	image.set(2, 3, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(3, 4).r, image.get(3, 4).g, image.get(3, 4).b);
	test_pixels(image.get(2, 1).r, image.get(2, 1).g, image.get(2, 1).b);
	test_pixels(image.get(1, 3).r, image.get(1, 3).g, image.get(1, 3).b);
}
TEST(V, three_X_three) {
	bmp::Bitmap image(3, 3);
	image.set(0, 0, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(1, 0).r, image.get(1, 0).g, image.get(1, 0).b);
	test_pixels(image.get(0, 2).r, image.get(0, 2).g, image.get(0, 2).b);
}
TEST(V, four_X_four) {
	bmp::Bitmap image(4, 4);
	image.set(0, 0, bmp::White);
	image.set(3, 1, bmp::White);
	image.set(1, 2, bmp::White);

	
	image = imageReflection(image, Reflection::vertical);
	test_pixels(image.get(0, 3).r, image.get(0, 3).g, image.get(0, 3).b);
	test_pixels(image.get(3, 2).r, image.get(3, 2).g, image.get(3, 2).b);
	test_pixels(image.get(1, 1).r, image.get(1, 1).g, image.get(1, 1).b);
}

//int main(int argc, char** argv) {
//	::testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();
//}