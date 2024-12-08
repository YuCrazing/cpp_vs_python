import numpy as np
import time

def python_scaling(matrix, scale_x, scale_y, scale_z, scale_w):
    matrix[0, :] *= scale_x
    matrix[1, :] *= scale_y
    matrix[2, :] *= scale_z
    matrix[3, :] *= scale_w

def main():
    N = 1000000
    scale_x, scale_y, scale_z, scale_w = 1.1, 0.9, 1.05, 1.0
    # Create a 4x4 matrix
    matrix = np.random.rand(4, 4).astype(np.float64)
    total = 0.0
    start = time.time()
    for _ in range(N):
        # Clone matrix to simulate fresh matrix each time
        m = matrix.copy()
        python_scaling(m, scale_x, scale_y, scale_z, scale_w)
        total += m.sum()  # Accumulate sum to prevent optimization
    end = time.time()
    print(f"Total time: {end - start:.2f} seconds")
    print(f"Total sum: {total:.2f}")

if __name__ == '__main__':
    main()