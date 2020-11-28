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

	fill_elems(numerator_, denominator_);
	fill_numerators_denominators();
}

int Fraction::get_numerator() const noexcept {
	return numerator_;
}

int Fraction::get_denominator() const noexcept {
	return denominator_;
}

std::vector<int> Fraction::get_elems() const noexcept {
	return elems_;
}

std::vector<int> Fraction::get_numerators() const noexcept {
	return numerators_;
}

std::vector<int> Fraction::get_denominators() const noexcept {
	return denominators_;
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

void Fraction::fill_elems(int num, int den) {
	int q = num / den;
	int r = num - q * den;

	if (r < 0) {
		q--;
		r += den;
	}

	elems_.push_back(q);

	if (r > 0) {
		fill_elems(den, r);
	}
}

void Fraction::fill_numerators_denominators() {
	if (elems_.size() > 0) {
		numerators_.resize(elems_.size());
		denominators_.resize(elems_.size());

		numerators_[0] = elems_[0];
		denominators_[0] = 1;

		if (elems_.size() > 1) {
			numerators_[1] = numerators_[0] * elems_[1] + 1;
			denominators_[1] = denominators_[0] * elems_[1];

			for (size_t i = 2; i < elems_.size(); ++i) {
				numerators_[i] = numerators_[i - 1] * elems_[i] + numerators_[i - 2];
				denominators_[i] = denominators_[i - 1] * elems_[i] + denominators_[i - 2];
			}
		}
	}
}