#pragma once

#pragma once

class Fraction
{
private:
    int num;
    int denom;
    int gcd(int a, int b);
    void reduce();
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    friend Fraction operator-(const Fraction& left,
        const Fraction& right);
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, const Fraction& right);

public:
    Fraction();
    void show() const;
    Fraction(int num, int denom);
    void setNum(int newNum);
    int getNum() const;
    void setDenom(int newDenom);
    int getDenom() const;
    void print() const;
};

Fraction operator+(const Fraction& left, int right);
void display_operation(const Fraction& f1, const Fraction& f2, char op);
