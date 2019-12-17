#pragma once

#include <algorithm>
#include "matrix.h"

namespace lr6 {
    template <typename T>
    class Matrix2DArray : public Matrix<T> {
    public:
        T **src;

        Matrix2DArray(int n, int m) : Matrix<T>(n, m) {
            src = new T*[n];
            for (int i = 0; i < n; ++i) {
                src[i] = new T[m];
            }
        }

        virtual T &get(int i, int j) {
            return src[i][j];
        }

        virtual const T &get_const(int i, int j) const {
            return src[i][j];
        }

        virtual void swap_rows(int i, int j) {
            std::swap(src[i], src[j]);
        }

        virtual void copy_row(int i, int j) {
            src[j] = src[i];
        }

        virtual void copy_row_duplicate(int i, int j) {
            src[j] = src[i];
            src[j] = new T[this->m];
            std::copy_n(src[i], this->m, src[j]);
        }

        virtual void resize_height(int n) {
            T **new_src = new T*[n];
            std::copy_n(src, std::min(n, this->n), new_src);
            for (int i = this->n; i < n; ++i) {
                new_src[i] = nullptr;
            }
            delete[] src;
            this->src = new_src;
            this->n = n;
        }

        virtual ~Matrix2DArray() {
            for (int i = 0; i < this->n; ++i) {
                delete[] src[i];
            }
            delete[] src;
        }
    };
}