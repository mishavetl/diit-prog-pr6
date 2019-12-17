#pragma once

#include <cstdlib>
#include <ostream>
#include "config.h"

namespace lr6 {
    template <typename T>
    class Matrix {
    public:
        int n, m;

        Matrix(int n, int m) : n(n), m(m) {}

        virtual T &get(int i, int j) = 0;
        virtual const T &get_const(int i, int j) const = 0;
        virtual void swap_rows(int i, int j) = 0;
        virtual void copy_row(int i, int j) = 0;
        virtual void copy_row_duplicate(int i, int j) = 0;
        virtual void resize_height(int n) = 0;

        void fill_with_random_values() {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    get(i, j) = (T)rand() / (T)RAND_MAX * (RANGE_MAX - RANGE_MIN) + RANGE_MIN;
                }
            }
        }

        int count_multiple_of(int number) {
            int amount = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    amount += to_integer(get_const(i, j)) % number == 0;
                }
            }
            return amount;
        }

        std::pair<T, T*> product_with_hundreds_not_bigger_than(int number) {
            T product = 1;
            T *products = new T[n];

            for (int i = 0; i < n; ++i) {
                products[i] = 1;
                for (int j = 0; j < m; ++j) {
                    if (get_const(i, j) > 0 && to_integer(get_const(i, j)) / 100 % 10 <= number) {
                        products[i] *= get_const(i, j);
                    }
                }
                product *= products[i];
            }
            return {product, products};
        }

        template <typename Compare>
        void sort(T *weight_array, const Compare &cmp) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (cmp(weight_array[j], weight_array[j + 1])) {
                        swap_rows(j, j + 1);
                        std::swap(weight_array[j], weight_array[j + 1]);
                    }
                }
            }
        }

        void double_even_rows() {
            int prev_n = n;
            resize_height(n + n / 2);
            for (int i = prev_n - 1; i >= 0; --i) {
                if (i % 2) {
                    copy_row(i, i + i / 2);
                    copy_row_duplicate(i, i + i / 2 + 1);
                } else {
                    copy_row(i, i + i / 2);
                }
            }
        }

        virtual ~Matrix() {};
    };
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const lr6::Matrix<T> &matrix) {
    for (int i = 0; i < matrix.n; ++i) {
        for (int j = 0; j < matrix.m; ++j) {
            stream.width(10);
            stream << matrix.get_const(i, j) << ' ';
        }
        stream << std::endl;
    }
    return stream;
}