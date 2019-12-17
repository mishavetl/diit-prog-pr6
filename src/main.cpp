#include <iostream>

#include "config.h"
#include "matrix_1d_array.h"
#include "matrix_2d_array.h"
#include "double.h"

using namespace lr6;

int main() {
	srand(time(nullptr));

    int n, m, dimensions;
    Matrix<Double> *matrix = nullptr;

    std::cout << "Enter matrix height (n): ";
    std::cin >> n;
    std::cout << "Enter matrix width (m): ";
    std::cin >> m;

    while (true) {
        std::cout << "Enter matrix storage dimensions(1, 2): ";
        std::cin >> dimensions;

        if (dimensions == 1) {
            matrix = new Matrix1DArray<Double>(n, m);
        } else if (dimensions == 2) {
            matrix = new Matrix2DArray<Double>(n, m);
        } else {
            std::cout << "Storage dimensions count '" << dimensions << "' is not supported" << std::endl;
            continue;
        }

        break;
    }

	matrix->fill_with_random_values();
	std::cout << "The following matrix was generated: " << std::endl << *matrix;

    std::cout << "Count of elements with integer value being multiple of 3: " << matrix->count_multiple_of(3) << std::endl;

    auto products_pair = matrix->product_with_hundreds_not_bigger_than(2);
    std::cout << "Product of elements with digit in hundreds not bigger than 2: " << std::endl;
    for (int i = 0; i < matrix->n; ++i) {
        std::cout << products_pair.second[i] << ' ';
    }
    std::cout << std::endl << "Total: " << products_pair.first << std::endl;

    matrix->sort(products_pair.second, std::less<Double>());
    std::cout << "The sorted matrix looks like the following: " << std::endl << *matrix;

    delete[] products_pair.second;

    matrix->double_even_rows();
    std::cout << "The matrix with doubled even rows looks like the following: " << std::endl << *matrix;

    delete matrix;
}
