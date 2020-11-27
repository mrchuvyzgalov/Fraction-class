#pragma once

class Fraction
{
public:
	Fraction(const int numerator = 0, const int denominator = 1);

	int get_numerator() const noexcept; // получить числитель
	int get_denominator() const noexcept; // получить знаменатель

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

	static int gcd(int first, int second) noexcept; // нод двух чисел

private:
	int numerator_; // числитель
	int denominator_; // знаменатель
};

