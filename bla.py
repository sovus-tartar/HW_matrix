import numpy as np

def main():

    n = int(input())

    A = []

    for i in range(n):
        temp = []
        temp = (input().split())
        temp = [int(x) for x in temp]

        A.append(temp)


    #print_matrix_cpp_style(n, A)

    print(round(np.linalg.det(A), 6))

main()