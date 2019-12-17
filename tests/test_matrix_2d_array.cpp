#include <double.h>
#include "matrix_2d_array.h"
#include "catch.hpp"

using namespace lr6;

TEST_CASE("Matrix2DArray's behaviour is valid", "[matrix_1d_array]") {
    SECTION("constructor/destructor works without errors") {
        Matrix2DArray<Double> matrix (10, 11);
        REQUIRE(matrix.n == 10);
        REQUIRE(matrix.m == 11);
        REQUIRE(matrix.src);

        Matrix2DArray<Double> matrix1 (0, 1);
        REQUIRE(matrix1.n == 0);
        REQUIRE(matrix1.m == 1);
        REQUIRE(matrix1.src);

        Matrix2DArray<Double> matrix2 (0, 0);
        REQUIRE(matrix2.n == 0);
        REQUIRE(matrix2.m == 0);
        REQUIRE(matrix2.src);
    }

    SECTION("get works correctly") {
        Matrix2DArray<Double> matrix (2, 2);
        matrix.src[0][0] = 1;
        matrix.src[0][1] = 2;
        matrix.src[1][0] = 3;
        matrix.src[1][1] = 4;

        REQUIRE(matrix.get(0, 0) == 1);
        REQUIRE(matrix.get(0, 1) == 2);
        REQUIRE(matrix.get(1, 0) == 3);
        REQUIRE(matrix.get(1, 1) == 4);

        matrix.get(1, 0) = 10;

        REQUIRE(matrix.get(0, 0) == 1);
        REQUIRE(matrix.get(0, 1) == 2);
        REQUIRE(matrix.get(1, 0) == 10);
        REQUIRE(matrix.get(1, 1) == 4);
    }

    SECTION("get_const works correctly") {
        Matrix2DArray<Double> matrix (2, 2);
        matrix.src[0][0] = 1;
        matrix.src[0][1] = 2;
        matrix.src[1][0] = 3;
        matrix.src[1][1] = 4;

        REQUIRE(matrix.get_const(0, 0) == 1);
        REQUIRE(matrix.get_const(0, 1) == 2);
        REQUIRE(matrix.get_const(1, 0) == 3);
        REQUIRE(matrix.get_const(1, 1) == 4);
    }
}