#pragma once

#include <vector>

class Fraction
{
public:
	explicit Fraction(const int numerator = 0, const int denominator = 1);

	int get_numerator() const noexcept;
	int get_denominator() const noexcept;

	std::vector<int> get_elems() const noexcept;
	std::vector<int> get_numerators() const noexcept;
	std::vector<int> get_denominators() const noexcept;

	friend Fraction operator +(const Fraction& first, const Fraction& second);
	friend Fraction operator -(const Fraction& first, const Fraction& second);
	
	friend Fraction operator *(const Fraction& first, const Fraction& second);
	friend Fraction operator /(const Fraction& first, const Fraction& second);

	friend bool operator <(const Fraction& first, const Fraction& second);
	friend bool operator <=(const Fraction& first, const Fraction& second);

	friend bool operator >(const Fraction& first, const Fraction& second);
	friend bool operator >=(const Fraction& first, const Fraction& second);

	friend bool operator ==(const Fraction& first, const Fraction& second);
	friend bool operator !=(const Fraction& first, const Fraction& second);

	static int gcd(int first, int second) noexcept;

private:
	void fill_elems(int num, int den);
	void fill_numerators_denominators();

private:
	int numerator_;
	int denominator_; 

	std::vector<int> elems_;
	std::vector<int> numerators_;
	std::vector<int> denominators_;
};

