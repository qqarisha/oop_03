#include <gtest/gtest.h>
#include "../src/Triangle/Triangle.h"
#include "../src/Square/Square.h"
#include "../src/Rectangle/Rectangle.h"
#include "../src/Array/FigureArray.h"

TEST(TriangleTest, AreaCalculation) {
    Triangle triangle({{{0, 0}, {4, 0}, {0, 3}}});
    EXPECT_DOUBLE_EQ(6.0, triangle.area());
}

TEST(SquareTest, AreaCalculation) {
    Square square({{{0, 0}, {2, 0}, {2, 2}, {0, 2}}});
    EXPECT_DOUBLE_EQ(4.0, square.area());
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle({{{0, 0}, {4, 0}, {4, 3}, {0, 3}}});
    EXPECT_DOUBLE_EQ(12.0, rectangle.area());
}

TEST(FigureArrayTest, AddAndRemove) {
    FigureArray array;
    auto triangle = std::make_unique<Triangle>(std::array<std::pair<double, double>, 3>{
        std::make_pair(0, 0), std::make_pair(4, 0), std::make_pair(0, 3)
    });
    
    array.addFigure(std::move(triangle));
    EXPECT_EQ(1, array.size());
    
    array.removeFigure(0);
    EXPECT_EQ(0, array.size());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}