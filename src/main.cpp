#include "Fraction.h"
#include "Unit_test_framework.h"

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

	tr.RunTest(TestConstr, "TestConstr");
	tr.RunTest(TestSum, "TestSum");
	tr.RunTest(TestDiff, "TestDiff");
	tr.RunTest(TestMul, "TestMul");
	tr.RunTest(TestDiv, "TestDiv");
	tr.RunTest(TestLess, "TestLess");
	tr.RunTest(TestLessOrEqual, "TestLessOrEqual");
	tr.RunTest(TestMore, "TestMore");
	tr.RunTest(TestMoreOrEqual, "TestMoreOrEqual");
	tr.RunTest(TestEqual, "TestEqual");
	tr.RunTest(TestNotEqual, "TestNotEqual");
}

void TestConstr() {
	{
		try {
			Fraction fr(0, 0);
			Assert(false, "TestConstr #1");
		}
		catch (const std::exception& err) {
			Assert(true, "TestConstr #1");
		}
	}

	{
		Fraction fr;
		Assert(fr.get_numerator() == 0 && fr.get_denominator() == 1, "TestConstr #2.1");
		AssertEqual(fr.get_elems(), std::vector<int>{ 0 }, "TestConstr #2.2");
		AssertEqual(fr.get_numerators(), std::vector<int>{ 0 }, "TestConstr #2.3");
		AssertEqual(fr.get_denominators(), std::vector<int>{ 1 }, "TestConstr #2.4");
	}

	{
		Fraction fr(4, 5);
		Assert(fr.get_numerator() == 4 && fr.get_denominator() == 5, "TestConstr #3.1");
		AssertEqual(fr.get_elems(), std::vector<int>{ 0, 1, 4 }, "TestConstr #3.2");
		AssertEqual(fr.get_numerators(), std::vector<int>{ 0, 1, 4 }, "TestConstr #3.3");
		AssertEqual(fr.get_denominators(), std::vector<int>{ 1, 1, 5 }, "TestConstr #3.4");
	}

	{
		Fraction fr(4, 10);
		Assert(fr.get_numerator() == 2 && fr.get_denominator() == 5, "TestConstr #4.1");
		AssertEqual(fr.get_elems(), std::vector<int>{ 0, 2, 2 }, "TestConstr #4.2");
		AssertEqual(fr.get_numerators(), std::vector<int>{ 0, 1, 2 }, "TestConstr #4.3");
		AssertEqual(fr.get_denominators(), std::vector<int>{ 1, 2, 5 }, "TestConstr #4.4");
	}

	{
		Fraction fr(4, -10);
		Assert(fr.get_numerator() == -2 && fr.get_denominator() == 5, "TestConstr #5.1");
		AssertEqual(fr.get_elems(), std::vector<int>{ -1, 1, 1, 2 }, "TestConstr #5.2");
		AssertEqual(fr.get_numerators(), std::vector<int>{ -1, 0, -1, -2 }, "TestConstr #5.3");
		AssertEqual(fr.get_denominators(), std::vector<int>{ 1, 1, 2, 5 }, "TestConstr #5.4");
	}

	{
		Fraction fr(-4, 10);
		Assert(fr.get_numerator() == -2 && fr.get_denominator() == 5, "TestConstr #6.1");
		AssertEqual(fr.get_elems(), std::vector<int>{ -1, 1, 1, 2 }, "TestConstr #6.2");
		AssertEqual(fr.get_numerators(), std::vector<int>{ -1, 0, -1, -2 }, "TestConstr #6.3");
		AssertEqual(fr.get_denominators(), std::vector<int>{ 1, 1, 2, 5 }, "TestConstr #6.4");
	}

	{
		Fraction fr(-4, -10);
		Assert(fr.get_numerator() == 2 && fr.get_denominator() == 5, "TestConstr #7.1");
		AssertEqual(fr.get_elems(), std::vector<int>{ 0, 2, 2 }, "TestConstr #7.2");
		AssertEqual(fr.get_numerators(), std::vector<int>{ 0, 1, 2 }, "TestConstr #7.3");
		AssertEqual(fr.get_denominators(), std::vector<int>{ 1, 2, 5 }, "TestConstr #7.4");
	}
}

void TestSum() {
	{
		Fraction first;
		Fraction second(4, 5);
		Fraction result = first + second;
		Assert(result.get_numerator() == 4 && result.get_denominator() == 5, "TestSum #1");
	}

	{
		Fraction first(4, 5);
		Fraction second(4, 5);
		Fraction result = first + second;
		Assert(result.get_numerator() == 8 && result.get_denominator() == 5, "TestSum #2");
	}

	{
		Fraction first(6, 5);
		Fraction second(4, 5);
		Fraction result = first + second;
		Assert(result.get_numerator() == 2 && result.get_denominator() == 1, "TestSum #3");
	}

	{
		Fraction first(-7, 10);
		Fraction second(4, 5);
		Fraction result = first + second;
		Assert(result.get_numerator() == 1 && result.get_denominator() == 10, "TestSum #4");
	}

	{
		Fraction first(-8, 10);
		Fraction second(4, 5);
		Fraction result = first + second;
		Assert(result.get_numerator() == 0 && result.get_denominator() == 1, "TestSum #5");
	}
}

void TestDiff() {
	{
		Fraction first;
		Fraction second(4, 5);
		Fraction result = first - second;
		Assert(result.get_numerator() == -4 && result.get_denominator() == 5, "TestDiff #1");
	}

	{
		Fraction first(4, 5);
		Fraction second(4, 5);
		Fraction result = first - second;
		Assert(result.get_numerator() == 0 && result.get_denominator() == 1, "TestDiff #2");
	}

	{
		Fraction first(9, 10);
		Fraction second(4, 5);
		Fraction result = first - second;
		Assert(result.get_numerator() == 1 && result.get_denominator() == 10, "TestDiff #3");
	}

	{
		Fraction first(9, 10);
		Fraction second(-3, 5);
		Fraction result = first - second;
		Assert(result.get_numerator() == 3 && result.get_denominator() == 2, "TestDiff #4");
	}
}

void TestMul() {
	{
		Fraction first;
		Fraction second(4, 5);
		Fraction result = first * second;
		Assert(result.get_numerator() == 0 && result.get_denominator() == 1, "TestMul #1");
	}

	{
		Fraction first(5, 2);
		Fraction second(4, 5);
		Fraction result = first * second;
		Assert(result.get_numerator() == 2 && result.get_denominator() == 1, "TestMul #2");
	}

	{
		Fraction first(-5, 3);
		Fraction second(4, 5);
		Fraction result = first * second;
		Assert(result.get_numerator() == -4 && result.get_denominator() == 3, "TestMul #3");
	}

	{
		Fraction first(-5, 3);
		Fraction second(-4, 5);
		Fraction result = first * second;
		Assert(result.get_numerator() == 4 && result.get_denominator() == 3, "TestMul #4");
	}
}

void TestDiv() {
	{
		Fraction first;
		Fraction second(4, 5);
		Fraction result = first / second;
		Assert(result.get_numerator() == 0 && result.get_denominator() == 1, "TestDiv #1");
	}

	{
		try {
			Fraction first(4, 5);
			Fraction second;
			Fraction result = first / second;
			(void)result;
			Assert(false, "TestDiv #2");
		}
		catch (const std::exception& err) {
			Assert(true, "TestDiv #2");
		}
	}

	{
		Fraction first(4, 5);
		Fraction second(4, 5);
		Fraction result = first / second;
		Assert(result.get_numerator() == 1 && result.get_denominator() == 1, "TestDiv #3");
	}

	{
		Fraction first(2, 10);
		Fraction second(4, 5);
		Fraction result = first / second;
		Assert(result.get_numerator() == 1 && result.get_denominator() == 4, "TestDiv #4");
	}

	{
		Fraction first(-2, 10);
		Fraction second(4, 5);
		Fraction result = first / second;
		Assert(result.get_numerator() == -1 && result.get_denominator() == 4, "TestDiv #5");
	}

	{
		Fraction first(2, 10);
		Fraction second(-4, 5);
		Fraction result = first / second;
		Assert(result.get_numerator() == -1 && result.get_denominator() == 4, "TestDiv #6");
	}

	{
		Fraction first(-2, 10);
		Fraction second(-4, 5);
		Fraction result = first / second;
		Assert(result.get_numerator() == 1 && result.get_denominator() == 4, "TestDiv #7");
	}
}

void TestLess() {
	{
		Assert(Fraction() < Fraction(4, 5), "TestLess #1");
	}

	{
		Assert(Fraction(7, 10) < Fraction(4, 5), "TestLess #2");
	}

	{
		Assert(Fraction(-7, 10) < Fraction(4, 5), "TestLess #3");
	}

	{
		Assert(Fraction(-9, 10) < Fraction(-4, 5), "TestLess #4");
	}

	{
		Assert(!(Fraction(8, 10) < Fraction(4, 5)), "TestLess #5");
	}

	{
		Assert(!(Fraction(9, 10) < Fraction(4, 5)), "TestLess #6");
	}
}

void TestLessOrEqual() {
	{
		Assert(Fraction() <= Fraction(4, 5), "TestLessOrEqual #1");
	}

	{
		Assert(Fraction(7, 10) <= Fraction(4, 5), "TestLessOrEqual #2");
	}

	{
		Assert(Fraction(-7, 10) <= Fraction(4, 5), "TestLessOrEqual #3");
	}

	{
		Assert(Fraction(-9, 10) <= Fraction(-4, 5), "TestLessOrEqual #4");
	}

	{
		Assert(Fraction(8, 10) <= Fraction(4, 5), "TestLessOrEqual #5");
	}

	{
		Assert(!(Fraction(9, 10) <= Fraction(4, 5)), "TestLessOrEqual #6");
	}
}

void TestMore() {
	{
		Assert(Fraction(4, 5) > Fraction(), "TestMore #1");
	}

	{
		Assert(Fraction(4, 5) > Fraction(7, 10), "TestMore #2");
	}

	{
		Assert(Fraction(4, 5) > Fraction(-7, 10), "TestMore #3");
	}

	{
		Assert(Fraction(-4, 5) > Fraction(-9, 10), "TestMore #4");
	}

	{
		Assert(!(Fraction(8, 10) > Fraction(4, 5)), "TestMore #5");
	}

	{
		Assert(!(Fraction(4, 5) > Fraction(9, 10)), "TestMore #6");
	}
}

void TestMoreOrEqual() {
	{
		Assert(Fraction(4, 5) >= Fraction(), "TestMoreOrEqual #1");
	}

	{
		Assert(Fraction(4, 5) >= Fraction(7, 10), "TestMoreOrEqual #2");
	}

	{
		Assert(Fraction(4, 5) >= Fraction(-7, 10), "TestMoreOrEqual #3");
	}

	{
		Assert(Fraction(-4, 5) >= Fraction(-9, 10), "TestMoreOrEqual #4");
	}

	{
		Assert(Fraction(8, 10) >= Fraction(4, 5), "TestMoreOrEqual #5");
	}

	{
		Assert(!(Fraction(4, 5) >= Fraction(9, 10)), "TestMoreOrEqual #6");
	}
}

void TestEqual() {
	{
		Assert(Fraction(4, 5) == Fraction(4, 5), "TestEqual #1");
	}

	{
		Assert(!(Fraction(-4, 5) == Fraction(4, 5)), "TestEqual #2");
	}
}

void TestNotEqual() {
	{
		Assert(!(Fraction(4, 5) != Fraction(4, 5)), "TestNotEqual #1");
	}

	{
		Assert(Fraction(-4, 5) != Fraction(4, 5), "TestNotEqual #2");
	}
}