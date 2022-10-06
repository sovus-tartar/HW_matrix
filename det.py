import numpy as np;



def main():

    n = int(input())

    A = []

    for i in range(n):
        A.append(list(map(int, input().split())))

    print(round(np.linalg.det(A), 6))

main()

