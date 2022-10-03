#pragma once

#include <vector>
#include <cassert>

// TODO: методы присвоения, и проч
// TODO: тип данных чтобы был collumn и поинтер на этот типа массив, аналогично с row. т.о. достигается swap collumn за о(1)
namespace matrixes
{
    template <typename T>
    class square_matrix
    {
    private:
        int size_;
        T *arr;



        struct proxy_matrix
        {
            T *collumn;

            T& operator[](int i)
            {
                return collumn[i];
            };

            const T& operator[] (int i) const
            {
                return collumn[i];
            };
        };

    public:
        square_matrix(int n) : size_(n)
        {
            arr = new T[n * n];
        }

        ~square_matrix()
        {
            delete[] arr;
        }

        proxy_matrix operator[] (int i)
        {
            proxy_matrix temp;
            assert(i < size_);
            temp.collumn = arr + i * size_;

            return temp;
        }

        const proxy_matrix operator[] (int i) const
        {
            proxy_matrix temp;
            assert(i < size_);
            temp.collumn = arr + i * size_;

            return temp;
        }

        void print_matrix()
        {
            for(int i = 0; i < size_; ++i)
            {
                for(int j = 0; j < size_; ++j)
                    std::cout << *((arr + i * size_) + j) << " ";

                std::cout << std::endl;

            }
        }

    };

};
