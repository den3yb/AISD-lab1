#pragma once
#include <iostream>
#include <random>


namespace matr {


    template <typename T>
    class matrix {
    private:
        int _s;
        int _c;
        T** m;
    public:
        matrix() { _s = 0; _c = 0; m = nullptr; }
        matrix(int s, int c, T* temp) {
            _s = s;
            _c = c;
            m = new T * [s];
            for (int i = 0; i < s; i++) { m[i] = new T[c]; }
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < c; j++) {
                    m[i][j] = temp[i * _c + j];
                }
            }
        }
        matrix(int s, int c, T min, T max) {
            _s = s;
            _c = c;
            m = new T * [s];
            for (int i = 0; i < s; i++) { m[i] = new T[c]; }
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < c; j++) {
                    std::random_device random_device;
                    std::mt19937 generator(random_device());
                    std::uniform_int_distribution<> distribution(min, max);
                    T x = distribution(generator);
                    m[i][j] = x;
                }
            }
        }
        T& operator() (int s, int c) { return m[s][c]; };
        matrix operator+ (matrix rhs) {
            if ((_s == rhs._s) && (_c == rhs._c)) {
                matrix temp;
                temp._s = _s;
                temp._c = _c;
                T** t = new T * [_s];;
                for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        t[i][j] = m[i][j] + rhs.m[i][j];
                    }
                }
                temp.m = t;
                return temp;
            }
            else { std::cout << "Can't be folded\n"; }
            return *this;
        }
        matrix operator- (matrix rhs) {
            if ((_s == rhs._s) && (_c == rhs._c)) {
                matrix temp;
                temp._s = _s;
                temp._c = _c;
                T** t = new T * [_s];;
                for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        t[i][j] = m[i][j] - rhs.m[i][j];
                    }
                }
                temp.m = t;
                return temp;
            }
            else {
                std::cout << "Can't be folded";
                return *this;
            }
        }
        matrix operator* (T mul) {
            matrix temp;
            temp._s = _s;
            temp._c = _c;
            T** t = new T * [_s];;
            for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
            for (int i = 0; i < _s; i++) {
                for (int j = 0; j < _c; j++) {
                    t[i][j] = m[i][j] * mul;
                }
            }
            temp.m = t;
            return temp;
        }
        matrix operator* (matrix rhs) {
            if (_c == rhs._s) {
                matrix temp;
                temp._s = _s;
                temp._c = rhs._c;
                T** t = new T * [_s];;
                for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < rhs._c; j++) {
                        t[i][j] = 0;
                    }
                }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < rhs._c; j++) {
                        for (int k = 0; k < _c; k++) {
                            t[i][j] += m[i][k] * rhs.m[k][j];
                        }
                    }
                }
                temp.m = t;
                return temp;

            }
            else { std::cout << "Can't be multyple\n"; }
            return *this;
        }
        matrix operator/ (T div) {
            /*if (div != 0) {
                matrix temp;
                temp._s = _s;
                temp._c = _c;
                T** t = new T* [_s];;
                for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        t[i][j] = m[i][j] / div;
                    }
                }
                temp.m = t;
                return temp;
            }
            else { std::cout << "Can't be division"; }
            return *this;*/
            matrix temp;
            temp._s = _s;
            temp._c = _c;
            T** t = new T * [_s];;
            for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
            for (int i = 0; i < _s; i++) {
                for (int j = 0; j < _c; j++) {
                    t[i][j] = m[i][j] / div;
                }
            }
            temp.m = t;
            return temp;
        }
        bool operator== (matrix rhs) {
            if (_s == rhs._s && _c == rhs._c) {
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        if (m[i][j] != rhs.m[i][j]) { return false; }
                    }
                }
            }
            return true;
        }
        bool operator!= (matrix rhs) {
            if (_s == rhs._s && _c == rhs._c) {
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        if (m[i][j] != rhs.m[i][j]) { return true; }
                    }
                }
            }
            return false;
        }
};
