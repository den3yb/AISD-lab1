#include "Matrix.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <complex>

#include "Matrix.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <complex>


using namespace std;
using namespace matr;

TEST(Func_Tests, SumStubTest1) {
	float t1[6]{ 1, 2, 3, 4, 5, 6 };
	float t2[6]{ 7, 8, 9, 10, 11, 12 };
	float* p1 = &t1[0];
	float* p2 = &t2[0];
	float min = 1;
	float max = 10;
	matrix <float> a(2, 3, p1);
	matrix <float> b(2, 3, min, max);
	matrix <float> c(3, 2, p2);
	matrix <float> d(5, 5, min, max);
	a.type();
	c.type();
	std::cout << a(1, 1) << "\n";
	(a * 2).type();
	(a + b).type();
	(b - a).type();
	(b / 2).type();
	(a * b).type();
	(a * c).type();
	d.type();
	cout << d.trace() << "\n";
	(d.bot_tria()).type();
	EXPECT_TRUE(true);
}
