#pragma once

#include <vector>
#include <cassert>

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
            T& operator[](int i)
            {
                int index = collumn_order[i];
                return str[index];
            };

            const T& operator[] (int i) const
            {
                int index = square_matrix::collumn_order[i];
                return str[index];
            };
        };

        bool is_equal(T n1, T n2)
        {
            return (n1-n2) < 1e-8;
        }

        T abs(T num)
        {
            return (num < 0) ? -num : num;
        }

        void max_submatrix_element(int curr, T &pivot, int &line, int &collumn)
        {   
            pivot = 0;
            T temp;
            for(int i = curr; i < size_; ++i)
                for(int j = curr; j < size_; ++j)
                    if((temp = abs((*this)[i][j])) > abs(pivot))
                    {
                        pivot = temp;
                        line = i;
                        collumn = j;
                    }
        }

        void eliminate(int curr)
        {
            for(int i = curr + 1; i < size_; ++i)
            {
                T k = -(*this)[i][curr] / (*this)[curr][curr];

                for(int j = curr; j < size_; ++j)
                    (*this)[i][j] = (*this)[i][j] + k * (*this)[curr][j];
            }
        }

    public:
        square_matrix(int n) : size_(n)
        {
            arr = new T[n * n];
            collumn_order = new int[n];
            str_order = new int[n];

            for(int i = 0; i < n; ++i)
            {
                collumn_order[i] = i;
                str_order[i] = i;
            }
        }

        ~square_matrix()
        {
            delete[] arr;
            delete[] collumn_order;
            delete[] str_order;
        }

        proxy_matrix operator[] (int i)
        {
            proxy_matrix temp;
            assert(i < size_);
            temp.str = arr + str_order[i] * size_;
            temp.str_order = str_order;
            temp.collumn_order = collumn_order;
            return temp;
        }

        const proxy_matrix operator[] (int i) const
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
            int sign = 0;
            class square_matrix<double> A(size_);


            for(int i = 0; i < size_; ++i)
            {
                T pivot;
                int line, collumn;

                max_submatrix_element(i, pivot, line, collumn);

                if(is_equal(pivot, 0))
                    return 0;

                swap_str(i, line);

                if(i != line)
                    ++sign;

                swap_collumn(i, collumn);

                if(i != collumn)
                    ++sign;

                eliminate(i);
            }

            double determinant = (*this)[0][0];

            for(int i = 1; i < size_; ++i)
                determinant *= (*this)[i][i];

            return (sign % 2)? -determinant : determinant;
        }

        void print_matrix()
        {
            for(int i = 0; i < size_; ++i)
            {
                for(int j = 0; j < size_; ++j)
                    std::cout << arr[i][j] << " ";

                std::cout << std::endl;

            }
        }

    };

};
