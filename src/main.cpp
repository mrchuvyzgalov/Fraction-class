#include "Fraction.h"
#include "test_runner.h"

#include <exception>

void TestAll ();

void TestConstr();
void TestSum();
void TestDiff();
void TestMul();
void TestDiv();
void TestLess();
void TestLessOrEqual();
void TestMore();
void TestMoreOrEqual();
void TestEqual();
void TestNotEqual();

int main() {
	TestAll();
	return 0;
}

void TestAll() {
	TestRunner tr;

	RUN_TEST(tr, TestConstr);
	RUN_TEST(tr, TestSum);
	RUN_TEST(tr, TestDiff);
	RUN_TEST(tr, TestMul);
	RUN_TEST(tr, TestDiv);
	RUN_TEST(tr, TestLess);
	RUN_TEST(tr, TestLessOrEqual);
	RUN_TEST(tr, TestMore);
	RUN_TEST(tr, TestMoreOrEqual);
	RUN_TEST(tr, TestEqual);
	RUN_TEST(tr, TestNotEqual);
	
}

void TestConstr() {
	{
		try {
			Fraction<int> fr(0, 0);
			ASSERT(false);
		}
		catch (const std::exception& err) {
			ASSERT(true);
		}
	}

	{
		Fraction<int> fr;
		ASSERT(fr.get_numerator() == 0 && fr.get_denominator() == 1);
		ASSERT_EQUAL(fr.get_elems(), std::vector<int>{ 0 });
		ASSERT_EQUAL(fr.get_numerators(), std::vector<int>{ 0 });
		ASSERT_EQUAL(fr.get_denominators(), std::vector<int>{ 1 });
	}

	{
		Fraction<int> fr(4, 5);
		ASSERT(fr.get_numerator() == 4 && fr.get_denominator() == 5);

		std::vector<int> v1 = {0, 1, 4};
		std::vector<int> v2 = { 1, 1, 5 };

		ASSERT_EQUAL(fr.get_elems(), v1);
		ASSERT_EQUAL(fr.get_numerators(), v1);
		ASSERT_EQUAL(fr.get_denominators(), v2);
	}

	{
		Fraction<int> fr(4, 10);
		ASSERT(fr.get_numerator() == 2 && fr.get_denominator() == 5);

		std::vector<int> v1 = {0, 2, 2};
		std::vector<int> v2 = { 0, 1, 2 };
		std::vector<int> v3 = { 1, 2, 5 };

		ASSERT_EQUAL(fr.get_elems(), v1);
		ASSERT_EQUAL(fr.get_numerators(), v2);
		ASSERT_EQUAL(fr.get_denominators(), v3);
	}

	{
		Fraction<int> fr(4, -10);
		ASSERT(fr.get_numerator() == -2 && fr.get_denominator() == 5);

		std::vector<int> v1 = { -1, 1, 1, 2 };
		std::vector<int> v2 = { -1, 0, -1, -2 };
		std::vector<int> v3 = { 1, 1, 2, 5 };

		ASSERT_EQUAL(fr.get_elems(), v1);
		ASSERT_EQUAL(fr.get_numerators(), v2);
		ASSERT_EQUAL(fr.get_denominators(), v3);
	}

	{
		Fraction<int> fr(-4, 10);
		ASSERT(fr.get_numerator() == -2 && fr.get_denominator() == 5);

		std::vector<int> v1 = { -1, 1, 1, 2 };
		std::vector<int> v2 = { -1, 0, -1, -2 };
		std::vector<int> v3 = { 1, 1, 2, 5 };

		ASSERT_EQUAL(fr.get_elems(), v1);
		ASSERT_EQUAL(fr.get_numerators(), v2);
		ASSERT_EQUAL(fr.get_denominators(), v3);
	}

	{
		Fraction<int> fr(-4, -10);
		ASSERT(fr.get_numerator() == 2 && fr.get_denominator() == 5);

		std::vector<int> v1 = {0, 2, 2};
		std::vector<int> v2 = { 0, 1, 2 };
		std::vector<int> v3 = { 1, 2, 5 };

		ASSERT_EQUAL(fr.get_elems(), v1);
		ASSERT_EQUAL(fr.get_numerators(), v2);
		ASSERT_EQUAL(fr.get_denominators(), v3);
	}
}

void TestSum() {
	{
		Fraction<int> first;
		Fraction<int> second(4, 5);
		Fraction<int> result = first + second;
		ASSERT(result.get_numerator() == 4 && result.get_denominator() == 5);
	}

	{
		Fraction<int> first(4, 5);
		Fraction<int> second(4, 5);
		Fraction<int> result = first + second;
		ASSERT(result.get_numerator() == 8 && result.get_denominator() == 5);
	}

	{
		Fraction<int> first(6, 5);
		Fraction<int> second(4, 5);
		Fraction<int> result = first + second;
		ASSERT(result.get_numerator() == 2 && result.get_denominator() == 1);
	}

	{
		Fraction<int> first(-7, 10);
		Fraction<int> second(4, 5);
		Fraction<int> result = first + second;
		ASSERT(result.get_numerator() == 1 && result.get_denominator() == 10);
	}

	{
		Fraction<int> first(-8, 10);
		Fraction<int> second(4, 5);
		Fraction<int> result = first + second;
		ASSERT(result.get_numerator() == 0 && result.get_denominator() == 1);
	}
}

void TestDiff() {
	{
		Fraction<int> first;
		Fraction<int> second(4, 5);
		Fraction<int> result = first - second;
		ASSERT(result.get_numerator() == -4 && result.get_denominator() == 5);
	}

	{
		Fraction<int> first(4, 5);
		Fraction<int> second(4, 5);
		Fraction<int> result = first - second;
		ASSERT(result.get_numerator() == 0 && result.get_denominator() == 1);
	}

	{
		Fraction<int> first(9, 10);
		Fraction<int> second(4, 5);
		Fraction<int> result = first - second;
		ASSERT(result.get_numerator() == 1 && result.get_denominator() == 10);
	}

	{
		Fraction<int> first(9, 10);
		Fraction<int> second(-3, 5);
		Fraction<int> result = first - second;
		ASSERT(result.get_numerator() == 3 && result.get_denominator() == 2);
	}
}

void TestMul() {
	{
		Fraction<int> first;
		Fraction<int> second(4, 5);
		Fraction<int> result = first * second;
		ASSERT(result.get_numerator() == 0 && result.get_denominator() == 1);
	}

	{
		Fraction<int> first(5, 2);
		Fraction<int> second(4, 5);
		Fraction<int> result = first * second;
		ASSERT(result.get_numerator() == 2 && result.get_denominator() == 1);
	}

	{
		Fraction<int> first(-5, 3);
		Fraction<int> second(4, 5);
		Fraction<int> result = first * second;
		ASSERT(result.get_numerator() == -4 && result.get_denominator() == 3);
	}

	{
		Fraction<int> first(-5, 3);
		Fraction<int> second(-4, 5);
		Fraction<int> result = first * second;
		ASSERT(result.get_numerator() == 4 && result.get_denominator() == 3);
	}
}

void TestDiv() {
	{
		Fraction<int> first;
		Fraction<int> second(4, 5);
		Fraction<int> result = first / second;
		ASSERT(result.get_numerator() == 0 && result.get_denominator() == 1);
	}

	{
		try {
			Fraction<int> first(4, 5);
			Fraction<int> second;
			Fraction<int> result = first / second;
			(void)result;
			ASSERT(false);
		}
		catch (const std::exception& err) {
			ASSERT(true);
		}
	}

	{
		Fraction<int> first(4, 5);
		Fraction<int> second(4, 5);
		Fraction<int> result = first / second;
		ASSERT(result.get_numerator() == 1 && result.get_denominator() == 1);
	}

	{
		Fraction<int> first(2, 10);
		Fraction<int> second(4, 5);
		Fraction<int> result = first / second;
		ASSERT(result.get_numerator() == 1 && result.get_denominator() == 4);
	}

	{
		Fraction<int> first(-2, 10);
		Fraction<int> second(4, 5);
		Fraction<int> result = first / second;
		ASSERT(result.get_numerator() == -1 && result.get_denominator() == 4);
	}

	{
		Fraction<int> first(2, 10);
		Fraction<int> second(-4, 5);
		Fraction<int> result = first / second;
		ASSERT(result.get_numerator() == -1 && result.get_denominator() == 4);
	}

	{
		Fraction<int> first(-2, 10);
		Fraction<int> second(-4, 5);
		Fraction<int> result = first / second;
		ASSERT(result.get_numerator() == 1 && result.get_denominator() == 4);
	}
}

void TestLess() {
	{
		ASSERT(Fraction<int>() < Fraction<int>(4, 5));
	}

	{
		ASSERT(Fraction<int>(7, 10) < Fraction<int>(4, 5));
	}

	{
		ASSERT(Fraction<int>(-7, 10) < Fraction<int>(4, 5));
	}

	{
		ASSERT(Fraction<int>(-9, 10) < Fraction<int>(-4, 5));
	}

	{
		ASSERT(!(Fraction<int>(8, 10) < Fraction<int>(4, 5)));
	}

	{
		ASSERT(!(Fraction<int>(9, 10) < Fraction<int>(4, 5)));
	}
}

void TestLessOrEqual() {
	{
		ASSERT(Fraction<int>() <= Fraction<int>(4, 5));
	}

	{
		ASSERT(Fraction<int>(7, 10) <= Fraction<int>(4, 5));
	}

	{
		ASSERT(Fraction<int>(-7, 10) <= Fraction<int>(4, 5));
	}

	{
		ASSERT(Fraction<int>(-9, 10) <= Fraction<int>(-4, 5));
	}

	{
		ASSERT(Fraction<int>(8, 10) <= Fraction<int>(4, 5));
	}

	{
		ASSERT(!(Fraction<int>(9, 10) <= Fraction<int>(4, 5)));
	}
}

void TestMore() {
	{
		ASSERT(Fraction<int>(4, 5) > Fraction<int>());
	}

	{
		ASSERT(Fraction<int>(4, 5) > Fraction<int>(7, 10));
	}

	{
		ASSERT(Fraction<int>(4, 5) > Fraction<int>(-7, 10));
	}

	{
		ASSERT(Fraction<int>(-4, 5) > Fraction<int>(-9, 10));
	}

	{
		ASSERT(!(Fraction<int>(8, 10) > Fraction<int>(4, 5)));
	}

	{
		ASSERT(!(Fraction<int>(4, 5) > Fraction<int>(9, 10)));
	}
}

void TestMoreOrEqual() {
	{
		ASSERT(Fraction<int>(4, 5) >= Fraction<int>());
	}

	{
		ASSERT(Fraction<int>(4, 5) >= Fraction<int>(7, 10));
	}

	{
		ASSERT(Fraction<int>(4, 5) >= Fraction<int>(-7, 10));
	}

	{
		ASSERT(Fraction<int>(-4, 5) >= Fraction<int>(-9, 10));
	}

	{
		ASSERT(Fraction<int>(8, 10) >= Fraction<int>(4, 5));
	}

	{
		ASSERT(!(Fraction<int>(4, 5) >= Fraction<int>(9, 10)));
	}
}

void TestEqual() {
	{
		ASSERT(Fraction<int>(4, 5) == Fraction<int>(4, 5));
	}

	{
		ASSERT(!(Fraction<int>(-4, 5) == Fraction<int>(4, 5)));
	}
}

void TestNotEqual() {
	{
		ASSERT(!(Fraction<int>(4, 5) != Fraction<int>(4, 5)));
	}

	{
		ASSERT(Fraction<int>(-4, 5) != Fraction<int>(4, 5));
	}
}