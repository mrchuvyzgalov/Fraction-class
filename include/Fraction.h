#pragma once

class Fraction
{
public:
	Fraction(const int numerator = 0, const int denominator = 1);

	int get_numerator() const noexcept; // �������� ���������
	int get_denominator() const noexcept; // �������� �����������

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

	static int gcd(int first, int second) noexcept; // ��� ���� �����

private:
	int numerator_; // ���������
	int denominator_; // �����������
};

