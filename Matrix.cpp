#pragma once
#include <iostream>
#include <random>


namespace matr {


    class matrix {
    private:
        int _s;
        int _c;
        float** m;
    public:
        matrix() { _s = 0; _c = 0; m = nullptr; }
        matrix(int s, int c, float* temp) {
            _s = s;
            _c = c;
            m = new float* [s];
            for (int i = 0; i < s; i++) { m[i] = new float[c]; }
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < c; j++) {
                    m[i][j] = temp[i * _c + j];
                }
            }
        }
        matrix(int s, int c, float min, float max) {
            _s = s;
            _c = c;
            m = new float* [s];
            for (int i = 0; i < s; i++) { m[i] = new float[c]; }
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < c; j++) {
                    std::random_device random_device;
                    std::mt19937 generator(random_device());
                    std::uniform_int_distribution<> distribution(min, max);
                    float x = distribution(generator);
                   
                }
            }
        }
    }
};
