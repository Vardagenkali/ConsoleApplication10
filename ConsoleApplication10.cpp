#include <iostream>
#include <sstream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            denominator = 1;
        }
    }

    std::string toString() const {
        std::stringstream ss;
        ss << numerator << "/" << denominator;
        return ss.str();
    }

    Fraction operator+(const Fraction& other) const {
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        return Fraction(resultNumerator, resultDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            return Fraction();
        }

        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        return Fraction(resultNumerator, resultDenominator);
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(3, 4);

    Fraction sum = a + b;
    std::cout << a.toString() << " + " << b.toString() << " = " << sum.toString() << std::endl;

    Fraction difference = a - b;
    std::cout << a.toString() << " - " << b.toString() << " = " << difference.toString() << std::endl;

    Fraction product = a * b;
    std::cout << a.toString() << " * " << b.toString() << " = " << product.toString() << std::endl;

    Fraction quotient = a / b;
    std::cout << a.toString() << " / " << b.toString() << " = " << quotient.toString() << std::endl;

    return 0;
}
