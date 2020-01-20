# Uses python3
import sys

import numpy as my_np


def optimal_weight(W, w):
    # write your code here

    my_mat = my_np.zeros(shape=(len(w), W + 1), dtype=int)

    for counter in range(0, len(w)):
        for ii in range(1, W + 1):
            if w[counter] > ii:
                my_mat[counter, ii] = my_mat[counter - 1, ii]
            else:
                my_mat[counter, ii] = max(w[counter] + my_mat[counter - 1, ii - w[counter]], my_mat[counter - 1, ii])
    return my_mat[len(w) - 1, W]


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))