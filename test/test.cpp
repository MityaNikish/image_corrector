#include "pch.h"
#include "corrector.hpp"
#include "BitmapPlusPlus.hpp"
#include <iostream>
#include <vector>

void test_pixels(int r, int g, int b) {
	EXPECT_EQ(r, 255);
	EXPECT_EQ(g, 255);
	EXPECT_EQ(b, 255);
}

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