#include "Fraction.h"

#include <stdexcept>
#include <cmath>

Fraction::Fraction(const int numerator, const int denominator) {
	if (denominator == 0) throw std::runtime_error("ERROR: denominator = 0\n");

	int gcd_num_den = gcd(std::abs(numerator), std::abs(denominator));

	numerator_ = numerator / gcd_num_den;
	denominator_ = denominator / gcd_num_den;

	if (denominator < 0) {
		numerator_ *= -1;
		denominator_ *= -1;
	}
}

int Fraction::get_numerator() const noexcept {
	return numerator_;
}

int Fraction::get_denominator() const noexcept {
	return denominator_;
}

Fraction operator +(const Fraction& first, const Fraction& second) {
	return Fraction(first.numerator_ * second.denominator_ + second.numerator_ * first.denominator_, first.denominator_ * second.denominator_);
}

Fraction operator -(const Fraction& first, const Fraction& second) {
	return Fraction(first.numerator_ * second.denominator_ - second.numerator_ * first.denominator_, first.denominator_ * second.denominator_);
}

Fraction operator *(const Fraction& first, const Fraction& second) {
	return Fraction(first.numerator_ * second.numerator_, first.denominator_ * second.denominator_);
}

Fraction operator /(const Fraction& first, const Fraction& second) {
	return first * Fraction(second.denominator_, second.numerator_);
}

bool operator <(const Fraction& first, const Fraction& second) {
	return first.numerator_ * second.denominator_ < first.denominator_* second.numerator_;
}

bool operator <=(const Fraction& first, const Fraction& second) {
	return first < second || first == second;
}

bool operator >(const Fraction& first, const Fraction& second) {
	return second < first;
}

bool operator >=(const Fraction& first, const Fraction& second) {
	return !(first < second);
}

bool operator ==(const Fraction& first, const Fraction& second) {
	return first.numerator_ == second.numerator_ && first.denominator_ == second.denominator_ ;
}

bool operator !=(const Fraction& first, const Fraction& second) {
	return !(first == second);
}

int Fraction::gcd(int first, int second) noexcept {
	if (first < second) return gcd(second, first);
	if (second == 0) return first;
	return gcd(second, first % second);
}