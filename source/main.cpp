#include <iostream>
#include "../headers/matrix.hpp"


int main() {
    int N;

    std::cin >> N;

    class matrixes::square_matrix<double> A(N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            std::cin >> A[i][j];

    std::cout << A.det() << std::endl;

    return 0;
    
}
