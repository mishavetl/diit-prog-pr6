#include <double.h>
#include <matrix_2d_array.h>
#include "matrix_1d_array.h"
#include "catch.hpp"

using namespace lr6;

TEST_CASE("Matrix's behaviour is valid", "[matrix_1d_array]") {
    SECTION("count_multiple_of works correctly") {
        Matrix1DArray<Double> matrix1 (3, 3);

        matrix1.get(0, 0) = 12.3;
        matrix1.get(0, 1) = 7.2;
        matrix1.get(0, 2) = 4.3;

        matrix1.get(1, 0) = -1.3;
        matrix1.get(1, 1) = 6.2;
        matrix1.get(1, 2) = 2.3;

        matrix1.get(2, 0) = 1.3;
        matrix1.get(2, 1) = 0.2;
        matrix1.get(2, 2) = -2.3;

        REQUIRE(matrix1.count_multiple_of(3) == 3);
        REQUIRE(matrix1.count_multiple_of(2) == 6);
        REQUIRE(matrix1.count_multiple_of(1) == 9);

        Matrix2DArray<Double> matrix2 (3, 3);

        matrix2.get(0, 0) = 12.3;
        matrix2.get(0, 1) = 7.2;
        matrix2.get(0, 2) = 4.3;

        matrix2.get(1, 0) = -1.3;
        matrix2.get(1, 1) = 6.2;
        matrix2.get(1, 2) = 2.3;

        matrix2.get(2, 0) = 1.3;
        matrix2.get(2, 1) = 0.2;
        matrix2.get(2, 2) = -2.3;

        REQUIRE(matrix2.count_multiple_of(3) == 3);
        REQUIRE(matrix2.count_multiple_of(2) == 6);
        REQUIRE(matrix2.count_multiple_of(1) == 9);
    }

    SECTION("product_with_hundreds_not_bigger_than works correctly") {
        Matrix1DArray<Double> matrix1 (3, 3);

        matrix1.get(0, 0) = -122.3;
        matrix1.get(0, 1) = 711.2;
        matrix1.get(0, 2) = 422.3;

        matrix1.get(1, 0) = 3031.3;
        matrix1.get(1, 1) = -612333.2;
        matrix1.get(1, 2) = 123.3;

        matrix1.get(2, 0) = 257.3;
        matrix1.get(2, 1) = 230.2;
        matrix1.get(2, 2) = 34382.3;

        auto products_pair = matrix1.product_with_hundreds_not_bigger_than(2);
        REQUIRE(products_pair.first == Double(22137934675.9734));
        REQUIRE(products_pair.second[0] == Double(1));
        REQUIRE(products_pair.second[1] == Double(373759.29));
        REQUIRE(products_pair.second[2] == Double(59230.46));

        delete[] products_pair.second;

        Matrix2DArray<Double> matrix2 (3, 3);

        matrix2.get(0, 0) = -122.3;
        matrix2.get(0, 1) = 711.2;
        matrix2.get(0, 2) = 422.3;

        matrix2.get(1, 0) = 3031.3;
        matrix2.get(1, 1) = -612333.2;
        matrix2.get(1, 2) = 123.3;

        matrix2.get(2, 0) = 257.3;
        matrix2.get(2, 1) = 230.2;
        matrix2.get(2, 2) = 34382.3;

        auto products_pair1 = matrix2.product_with_hundreds_not_bigger_than(2);
        REQUIRE(products_pair1.first == Double(22137934675.9734));
        REQUIRE(products_pair1.second[0] == Double(1));
        REQUIRE(products_pair1.second[1] == Double(373759.29));
        REQUIRE(products_pair1.second[2] == Double(59230.46));

        delete[] products_pair1.second;
    }

    SECTION("sort works correctly") {
        Matrix1DArray<Double> matrix1 (3, 3);

        matrix1.get(0, 0) = -122.3;
        matrix1.get(0, 1) = 711.2;
        matrix1.get(0, 2) = 422.3;

        matrix1.get(1, 0) = 3031.3;
        matrix1.get(1, 1) = -612333.2;
        matrix1.get(1, 2) = 123.3;

        matrix1.get(2, 0) = 257.3;
        matrix1.get(2, 1) = 230.2;
        matrix1.get(2, 2) = 34382.3;

        auto products_pair = matrix1.product_with_hundreds_not_bigger_than(2);

        matrix1.sort(products_pair.second, std::less<Double>());
        REQUIRE(products_pair.first == Double(22137934675.9734));
        REQUIRE(products_pair.second[0] == Double(373759.29));
        REQUIRE(products_pair.second[1] == Double(59230.46));
        REQUIRE(products_pair.second[2] == Double(1));

        REQUIRE(matrix1.get(0, 0) == 3031.3);
        REQUIRE(matrix1.get(0, 1) == -612333.2);
        REQUIRE(matrix1.get(0, 2) == 123.3);

        REQUIRE(matrix1.get(1, 0) == 257.3);
        REQUIRE(matrix1.get(1, 1) == 230.2);
        REQUIRE(matrix1.get(1, 2) == 34382.3);

        REQUIRE(matrix1.get(2, 0) == -122.3);
        REQUIRE(matrix1.get(2, 1) == 711.2);
        REQUIRE(matrix1.get(2, 2) == 422.3);

        delete[] products_pair.second;

        Matrix2DArray<Double> matrix2 (3, 3);

        matrix2.get(0, 0) = -122.3;
        matrix2.get(0, 1) = 711.2;
        matrix2.get(0, 2) = 422.3;

        matrix2.get(1, 0) = 3031.3;
        matrix2.get(1, 1) = -612333.2;
        matrix2.get(1, 2) = 123.3;

        matrix2.get(2, 0) = 257.3;
        matrix2.get(2, 1) = 230.2;
        matrix2.get(2, 2) = 34382.3;

        auto products_pair1 = matrix2.product_with_hundreds_not_bigger_than(2);

        matrix2.sort(products_pair1.second, std::less<Double>());
        REQUIRE(products_pair1.first == Double(22137934675.9734));
        REQUIRE(products_pair1.second[0] == Double(373759.29));
        REQUIRE(products_pair1.second[1] == Double(59230.46));
        REQUIRE(products_pair1.second[2] == Double(1));

        REQUIRE(matrix2.get(0, 0) == 3031.3);
        REQUIRE(matrix2.get(0, 1) == -612333.2);
        REQUIRE(matrix2.get(0, 2) == 123.3);

        REQUIRE(matrix2.get(1, 0) == 257.3);
        REQUIRE(matrix2.get(1, 1) == 230.2);
        REQUIRE(matrix2.get(1, 2) == 34382.3);

        REQUIRE(matrix2.get(2, 0) == -122.3);
        REQUIRE(matrix2.get(2, 1) == 711.2);
        REQUIRE(matrix2.get(2, 2) == 422.3);

        delete[] products_pair1.second;
    }

    SECTION("double_even_rows works correctly") {
        Matrix1DArray<Double> matrix1 (4, 3);

        matrix1.get(0, 0) = -122.3;
        matrix1.get(0, 1) = 711.2;
        matrix1.get(0, 2) = 422.3;

        matrix1.get(1, 0) = 3031.3;
        matrix1.get(1, 1) = -612333.2;
        matrix1.get(1, 2) = 123.3;

        matrix1.get(2, 0) = 257.3;
        matrix1.get(2, 1) = 230.2;
        matrix1.get(2, 2) = 34382.3;

        matrix1.get(3, 0) = 2572.3;
        matrix1.get(3, 1) = 2302.2;
        matrix1.get(3, 2) = 343282.3;

        matrix1.double_even_rows();

        REQUIRE(matrix1.get(0, 0) == -122.3);
        REQUIRE(matrix1.get(0, 1) == 711.2);
        REQUIRE(matrix1.get(0, 2) == 422.3);

        REQUIRE(matrix1.get(1, 0) == 3031.3);
        REQUIRE(matrix1.get(1, 1) == -612333.2);
        REQUIRE(matrix1.get(1, 2) == 123.3);

        REQUIRE(matrix1.get(2, 0) == 3031.3);
        REQUIRE(matrix1.get(2, 1) == -612333.2);
        REQUIRE(matrix1.get(2, 2) == 123.3);

        REQUIRE(matrix1.get(3, 0) == 257.3);
        REQUIRE(matrix1.get(3, 1) == 230.2);
        REQUIRE(matrix1.get(3, 2) == 34382.3);

        REQUIRE(matrix1.get(4, 0) == 2572.3);
        REQUIRE(matrix1.get(4, 1) == 2302.2);
        REQUIRE(matrix1.get(4, 2) == 343282.3);

        REQUIRE(matrix1.get(5, 0) == 2572.3);
        REQUIRE(matrix1.get(5, 1) == 2302.2);
        REQUIRE(matrix1.get(5, 2) == 343282.3);

        Matrix2DArray<Double> matrix2 (4, 3);

        matrix2.get(0, 0) = -122.3;
        matrix2.get(0, 1) = 711.2;
        matrix2.get(0, 2) = 422.3;

        matrix2.get(1, 0) = 3031.3;
        matrix2.get(1, 1) = -612333.2;
        matrix2.get(1, 2) = 123.3;

        matrix2.get(2, 0) = 257.3;
        matrix2.get(2, 1) = 230.2;
        matrix2.get(2, 2) = 34382.3;

        matrix2.get(3, 0) = 2572.3;
        matrix2.get(3, 1) = 2302.2;
        matrix2.get(3, 2) = 343282.3;

        matrix2.double_even_rows();

        REQUIRE(matrix2.get(0, 0) == -122.3);
        REQUIRE(matrix2.get(0, 1) == 711.2);
        REQUIRE(matrix2.get(0, 2) == 422.3);

        REQUIRE(matrix2.get(1, 0) == 3031.3);
        REQUIRE(matrix2.get(1, 1) == -612333.2);
        REQUIRE(matrix2.get(1, 2) == 123.3);

        REQUIRE(matrix2.get(2, 0) == 3031.3);
        REQUIRE(matrix2.get(2, 1) == -612333.2);
        REQUIRE(matrix2.get(2, 2) == 123.3);

        REQUIRE(matrix2.get(3, 0) == 257.3);
        REQUIRE(matrix2.get(3, 1) == 230.2);
        REQUIRE(matrix2.get(3, 2) == 34382.3);

        REQUIRE(matrix2.get(4, 0) == 2572.3);
        REQUIRE(matrix2.get(4, 1) == 2302.2);
        REQUIRE(matrix2.get(4, 2) == 343282.3);

        REQUIRE(matrix2.get(5, 0) == 2572.3);
        REQUIRE(matrix2.get(5, 1) == 2302.2);
        REQUIRE(matrix2.get(5, 2) == 343282.3);
    }
}