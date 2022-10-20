#pragma once

#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
// TODO: методы присвоения, и проч
// TODO: тип данных чтобы был str и поинтер на этот типа массив, аналогично с row. т.о. достигается swap str за о(1)
namespace matrixes
{

    template <typename T>
    class square_matrix
    {
    private:
        int size_;
        T *arr;

        int *str_order;
        int *collumn_order;

        struct proxy_matrix
        {
            T *str;
            int *str_order;
            int *collumn_order;
            T &operator[](int i)
            {
                int index = collumn_order[i];
                return str[index];
            };

            const T &operator[](int i) const
            {
                int index = collumn_order[i];
                return str[index];
            };
        };

        bool is_equal(T n1, T n2)
        {
            return (n1 - n2) < 1e-8;
        }

        T abs(T num)
        {
            return (num < 0) ? -num : num;
        }

    public:

        square_matrix(const square_matrix<T> &other) : size_(other.size_)
        {
            arr = new T[size_ * size_];

            str_order = new int[size_];
            collumn_order = new int[size_];

           std::memcpy(arr, other.arr, size_ * size_ * sizeof(T));
           std::memcpy(str_order, other.str_order, size_ * sizeof(int));
           std::memcpy(collumn_order, other.collumn_order, size_ * sizeof(int));

        }

        square_matrix(square_matrix && other) : 
        size_(other.size), arr(other.arr), str_order(other.str_order), collumn_order(other.collumn_order)
        {
            other.collumn_order = nullptr;
            other.str_order = nullptr;
            other.arr = nullptr;
        }

        square_matrix<T>& operator=(square_matrix<T>&& other)
        {
            if (this == &other)
                return *this;

            std::swap(str_order, other.str_order);
            std::swap(collumn_order, other.collumn_order);
            std::swap(arr, other.arr);
            std::swap(size_, other.size_);

            return *this;
        }

        square_matrix<T>& operator=(const square_matrix<T>& other)
        {
            if (&other == this)
                return *this;

            delete [] arr;
            delete [] str_order;
            delete [] collumn_order;

            arr = new T[size_ * size_];

            str_order = new int[size_];
            collumn_order = new int[size_];

           std::memcpy(arr, other.arr, size_*size_);
           std::memcpy(str_order, other.str_order, size_);
           std::memcpy(collumn_order, other.collumn_order, size_);
        }

        square_matrix(int n) : size_(n)
        {
            arr = new T[n * n];
            collumn_order = new int[n];
            str_order = new int[n];

            for (int i = 0; i < n; ++i)
            {
                collumn_order[i] = i;
                str_order[i] = i;
            }
        }

        ~square_matrix()
        {
            delete [] collumn_order;
            delete [] str_order;
            delete [] arr;
        }

        void max_submatrix_element(int curr, T &pivot, int &line, int &collumn)
        {
            pivot = 0;
            T temp;
            for (int i = curr; i < size_; ++i)
                for (int j = curr; j < size_; ++j)
                    if ((temp = abs((*this)[i][j])) > abs(pivot))
                    {
                        pivot = temp;
                        line = i;
                        collumn = j;
                    }
        }

        void eliminate(int curr)
        {
            for (int i = curr + 1; i < size_; ++i)
            {
                T k = -(*this)[i][curr] / (*this)[curr][curr];

                for (int j = curr; j < size_; ++j)
                    (*this)[i][j] = (*this)[i][j] + k * (*this)[curr][j];
            }
        }

        proxy_matrix operator[](int i)
        {
            proxy_matrix temp;
            assert(i < size_);
            temp.str = arr + str_order[i] * size_;
            temp.str_order = str_order;
            temp.collumn_order = collumn_order;
            return temp;
        }

        const proxy_matrix operator[](int i) const
        {
            proxy_matrix temp;
            assert(i < size_);
            temp.str = arr + str_order[i] * size_;
            temp.str_order = str_order;
            temp.collumn_order = collumn_order;

            return temp;
        }

        void swap_str(int s1, int s2)
        {
            std::swap(str_order[s1], str_order[s2]);
        }

        void swap_collumn(int c1, int c2)
        {
            std::swap(collumn_order[c1], collumn_order[c2]);
        }

        double det()
        {
            square_matrix<T> temp(*this);

            double d = temp.det_count();
            
            return d;
        }

        double det_count()
        {
            int sign = 0;

            for (int i = 0; i < size_; ++i)
            {
                T pivot;
                int line, collumn;

                max_submatrix_element(i, pivot, line, collumn);

                //print_matrix();

                if (is_equal(pivot, 0))
                    return 0;

                swap_str(i, line);

                if (i != line)
                    ++sign;

                swap_collumn(i, collumn);

                if (i != collumn)
                    ++sign;

                eliminate(i);
            }

            double determinant = (*this)[0][0];

            for (int i = 1; i < size_; ++i)
                determinant *= (*this)[i][i];

            //print_matrix();

            return (sign % 2) ? -determinant : determinant;
        }

        void print_matrix()
        {

            for (int i = 0; i < size_; ++i)
            {
                for (int j = 0; j < size_; ++j)
                    std::cout << "|" << std::setw(6) << std::setprecision(1) << (*this)[i][j] << "| ";

                std::cout << std::endl;
            }

            std::cout << "------------------------------------------" << std::endl;
        }
    };

};
