#pragma once
#include <iostream>
#include <random>
#include <complex>
using namespace std;


namespace matr {
    double epsilon = 0.0000001;
    template<typename T> class matrix;
    template<typename T>
    class matrix{
        int _s;
        int _c;
        T** m;
    public:
        matrix() { _s = 0; _c = 0; m = nullptr; };
        template<typename T>
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
        };

        template<typename S>
        matrix(int s, int c, S* temp) {
            _s = s;
            _c = c;
            m = new S * [s];
            for (int i = 0; i < s; i++) { m[i] = new S[c]; }
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < c; j++) {
                    m[i][j] = temp[i * _c + j];
                }
            }
        };

        template<typename T>
        Matrix(int s, int c, T br, T bi, T ur, T ui) {
            _s = s;
            _c = c;
            m = new T * [_s];
            for (int i = 0; i < _s; i++) { m[i] = new T[c]; }
            for (int i = 0; i < _s; i++) {
                for (int j = 0; j < _c; j++) {
                    m[i][j] = complex((br + rand() % (ur - br)), (bi + rand() % (ui - bi)));
                }
            }
        };

        template<typename T>
        matrix(matrix& rhs) {
            _s = rhs._s;
            _c = rhs._c;
            m = new T * [_s];
            for (int i = 0; i < _s; i++) { m[i] = new T[_c]; }
            for (int i = 0; i < _s; i++) {
                for (int j = 0; j < _c; j++) {
                    m[i][j] = rhs.m[i][j];
                }
            }
        };
        template <typename R>
        friend ostream& operator<<(ostream& out, const matrix<R>& a) {
            for (int i = 0; i < a._s; ++i) {
                for (int j = 0; j < a._c; ++j) {
                    out << a.m[i][j] << " ";
                }
                out << endl;
            }
            out << "\n";
            return out;

        };
        T& operator() (int s, int c) { return m[s][c]; };
        matrix<T> operator+ (matrix<T> rhs) {
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
            else { throw "Can't be folded"; }
        };
        matrix<T> operator- (matrix<T> rhs) {
            if ((_s == rhs._s) && (_c == rhs._c)) {
                matrix temp;
                temp._s = _s;
                temp._c = _c;
                T** t = new T* [_s];;
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
                throw "Can't be folded"; }
        }
        matrix<T> operator* (T mul) {
            matrix temp;
            temp._s = _s;
            temp._c = _c;
            T** t = new T* [_s];;
            for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
            for (int i = 0; i < _s; i++) {
                for (int j = 0; j < _c; j++) {
                    t[i][j] = m[i][j] * mul;
                }
            }
            temp.m = t;
            return temp;
        }
        matrix<T> operator* (matrix<T> rhs) {
            if (_c == rhs._s) {
                matrix temp;
                temp._s = _s;
                temp._c = rhs._c;
                T** t = new T* [_s];;
                for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < rhs._c; j++) {
                        t[i][j] = 0;
                    }
                }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < rhs._c; j++) {
                        for (int k = 0;k<_c;k++){
                            t[i][j] += m[i][k] * rhs.m[k][j];
                        }
                    }
                }
                temp.m = t;
                return temp;
           
            }
            else { throw"Can't be multyple"; }
        }
        matrix<T> operator/ (T div) {
            //if (div == 0) { throw "Cant division on 0"; }
            //else {
                matrix temp;
                temp._s = _s;
                temp._c = _c;
                T** t = new T * [_s];
                for (int i = 0; i < _s; i++) { t[i] = new T[_c]; }
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        t[i][j] = m[i][j] / div;
                    }
                }
                temp.m = t;
                return temp;
            //}
        }
        bool operator== (matrix<T> rhs) {
            if (_s == rhs._s && _c == rhs._c) {
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        if (m[i][j] != rhs.m[i][j]) { return false; }
                    }
                }
            }
            
            return true;
        }
        bool operator!= (matrix<T> rhs) {
            if (_s == rhs._s && _c == rhs._c) {
                for (int i = 0; i < _s; i++) {
                    for (int j = 0; j < _c; j++) {
                        if (m[i][j] != rhs.m[i][j]) { return true; }
                    }
                }
            }
            return false;
        }
        T trace() {
            if (_s == _c) {
                T tr = 0;
                for (int i = 0; i < _s; i++) {
                    tr += m[i][i];
                }
                return tr;
            }
            else { throw"Matrix trace cant be found"; }
        }    
       
    };
    template <typename T>
    matrix<T> bot_trian(matrix<T> a) {
        if (a._s == a._c) {
            matrix temp;
            temp._s = a._s;
            temp._c = a._c;
            T** t = new T * [a._s];;
            for (int i = 0; i < a._s; i++) { t[i] = new T[a._c]; }
            for (int i = 0; i < a._s; i++) {
                for (int j = 1; j < a._c; j++) {
                    t[i][j] = 0;
                }
            }
            for (int i = 0; i < a._s; i++) {
                t[i][0] = a.m[i][0];
            }

            for (int k = 1; k < a._c; k++) {
                if (a.m[k - 1][k - 1] == 0) { throw "Cant be into bottom triangle"; }
                T dif = a.m[k - 1][k] / a.m[k - 1][k - 1];
                for (int n = k; n < a._s; n++) {
                    t[n][k] = a.m[n][k] - (a.m[n][k - 1] * dif);
                }
            }
            temp.m = t;
            return temp;
        }
        else { throw "Incorrect size for bottom triangle"; }
        }
};


