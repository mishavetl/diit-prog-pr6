#pragma once

#include <algorithm>
#include "matrix.h"

namespace lr6 {
    template <typename T>
    class Matrix1DArray : public Matrix<T> {
    public:
        T *src;

        Matrix1DArray(int n, int m) : Matrix<T>(n, m) {
            src = new T[n * m];
        }

        virtual T &get(int i, int j) {
            return src[i * this->m + j];
        }

        virtual const T &get_const(int i, int j) const {
            return src[i * this->m + j];
        }

        virtual void swap_rows(int i, int j) {
            for (int k = 0; k < this->m; ++k) {
                std::swap(get(i, k), get(j, k));
            }
        }

        virtual void copy_row(int i, int j) {
            for (int k = 0; k < this->m; ++k) {
                get(j, k) = get(i, k);
            }
        }

        virtual void copy_row_duplicate(int i, int j) {
            copy_row(i, j);
        }

        virtual void resize_height(int n) {
            T *new_src = new T[n * this->m];
            std::copy_n(src, std::min(n, this->n) * this->m, new_src);
            delete[] src;
            this->src = new_src;
            this->n = n;
        }

        virtual ~Matrix1DArray() {
            delete[] src;
        }
    };
}