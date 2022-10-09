import numpy as np;
import random

def print_matrix_cpp_style(n: int, A : list):
    print(n)

    for i in range(n):
        for j in range(n):
            print(round(A[i][j], 6), end = ' ')
        print()

def main():

    n = int(input())

    A = []

    for i in range(n):
        temp = []

        for j in range(n):
            temp.append(int(random.uniform(-5, 5)))

        A.append(temp)

    print_matrix_cpp_style(n, A)

    print(round(np.linalg.det(A), 6))

main()

