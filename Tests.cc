#include "Matrix.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <complex>


using namespace std;
using namespace matr;

/*TEST(Func_Tests, SumStubTest1) {
	float min = 1;
	float max = 10;
	float t1[6]{1, 2, 3, 4, 5, 6};
	float t2 [6] { 7, 8, 9, 10, 11, 12 };
	float* p1 = &t1[0];
	float* p2 = &t2[0];
	matrix<float> a(2, 3, p1);
	matrix<float> b(2, 3, min, max);
	matrix<float> c(3, 2, p2);
	matrix<float> d(5, 5, min, max);
	std::cout << a;
	std::cout << c;
	std::cout << a(1,1) << "\n";
	std::cout << a*2;
	std::cout << (a + b);
	std::cout << (b - a);
	std::cout << (b / 2);
	std::cout << (a * c);
	std::cout << d;
	cout << d.trace() << "\n";
	EXPECT_TRUE(true);
}*/

/*TEST(Func_Tests, SumStubTest2) {
	int t1[6]{ 1, 2, 3, 4, 5, 6 };
	int t2[6]{ 7, 8, 9, 10, 11, 12 };
	int* p1 = &t1[0];
	int* p2 = &t2[0];
	int min = 1;
	int max = 10;
	matrix <int> a(2, 3, p1);
	matrix <int> b(2, 3, min, max);
	matrix <int> c(3, 2, p2);
	matrix <int> d(5, 5, min, max);
	std::cout << a;
	std::cout << c;
	std::cout << a(1, 1) << "\n";
	std::cout << (a * 2);
	std::cout << (a + b);
	std::cout << (b - a);
	std::cout << (b / 2);
	std::cout << (a * c);
	std::cout << d;
	cout << d.trace() << "\n";
	EXPECT_TRUE(true);
}*/

TEST(Func_Tests, SumStubTest3) {
	std::complex<float> t1[6] = { std::complex<float>(1,1) , std::complex<float>(2,2), std::complex<float>(3,3), std::complex<float>(4,4), std::complex<float>(5,5), std::complex<float>(6,6) };
	std::complex<float> t2[6] = { std::complex<float>(7,7) , std::complex<float>(8,8), std::complex<float>(9,9), std::complex<float>(10,10), std::complex<float>(11,11), std::complex<float>(12,12) };
	std::complex<float> t3[6] = { std::complex<float>(14,14) , std::complex<float>(15,15), std::complex<float>(16,16), std::complex<float>(17,17), std::complex<float>(18,18), std::complex<float>(19,19) };
	std::complex<float> t4[16] = { std::complex<float>(1,1) , std::complex<float>(2,2), std::complex<float>(3,3), std::complex<float>(4,4), std::complex<float>(5,5), std::complex<float>(6,6), std::complex<float>(7,7) , std::complex<float>(8,8), std::complex<float>(9,9), std::complex<float>(10,10), std::complex<float>(11,11), std::complex<float>(12,12), std::complex<float>(13,13),  std::complex<float>(14,14), std::complex<float>(15,15),  std::complex<float>(16,16) };
	std::complex<float>* p1 = &t1[0]; 
	std::complex<float>* p2 = &t2[0];
	std::complex<float>* p3 = &t3[0];
	std::complex<float>* p4 = &t4[0];
	std::complex<float> min = 1;
	std::complex<float> max = 10;
	matrix <std::complex<float>> a(2, 3, p1);
	matrix <std::complex<float>> b(2, 3, p3);
	matrix <std::complex<float>> c(3, 2, p2);
	matrix <std::complex<float>> d(4, 4, p4);
	matrix <std::complex<float>> i(2, 2, min, max, min, max);
	std::cout << a;
	std::cout << c;
	std::cout << a(1, 1) << "\n";
	std::cout << (a * 2);
	std::cout << (a + b);
	std::cout << (b - a);
	std::cout << (b / 2);
	std::cout << (a * c);
	std::cout << d;
	cout << d.trace() << "\n";
	EXPECT_TRUE(true);
	EXPECT_TRUE(true);
}