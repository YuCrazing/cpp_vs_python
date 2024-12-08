#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

void cpp_scaling(double matrix[4][4], double scale_x, double scale_y, double scale_z, double scale_w) {
    for(int i = 0; i < 4; ++i) {
        matrix[0][i] *= scale_x;
        matrix[1][i] *= scale_y;
        matrix[2][i] *= scale_z;
        matrix[3][i] *= scale_w;
    }
}

int main() {
    const int N = 1000000;
    double scale_x = 1.1, scale_y = 0.9, scale_z = 1.05, scale_w = 1.0;
    double matrix[4][4];
    // Initialize matrix with random values
    std::srand(static_cast<unsigned>(std::time(0)));
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            matrix[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }

    double total = 0.0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int n = 0; n < N; ++n) {
        // Clone matrix to simulate fresh matrix each time
        double m[4][4];
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                m[i][j] = matrix[i][j];
            }
        }
        cpp_scaling(m, scale_x, scale_y, scale_z, scale_w);
        // Accumulate sum to prevent compiler optimization
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                total += m[i][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_seconds = std::chrono::duration<double>(end - start).count();
    std::cout << "Total time: " << elapsed_seconds << " seconds\n";
    std::cout << "Total sum: " << total << std::endl;
    return 0;
}