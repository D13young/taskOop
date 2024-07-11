#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        simplify();
    }

    void input() {
        cout << "Enter the numerator: ";
        cin >> numerator;
        cout << "Enter the denominator: ";
        cin >> denominator;
        simplify();
    }

    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Fraction add(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction subtract(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction multiply(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction divide(const Fraction& other) const {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction fraction1, fraction2;

    cout << "Enter the first fraction:" << endl;
    fraction1.input();

    cout << "Enter the second fraction:" << endl;
    fraction2.input();

    cout << "Sum of fractions: ";
    fraction1.add(fraction2).display();

    cout << "Difference of fractions: ";
    fraction1.subtract(fraction2).display();

    cout << "Product of fractions: ";
    fraction1.multiply(fraction2).display();

    cout << "Quotient of fractions: ";
    fraction1.divide(fraction2).display();

    return 0;
}