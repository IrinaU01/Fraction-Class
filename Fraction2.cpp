#include <iostream>
#include "Fraction2.h"
using namespace std;
#include <cstdlib>


int Fraction::gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce()
{
    int gcdVal{ gcd(num, denom) };
    num /= gcdVal;
    denom /= gcdVal;

    if (denom < 0)
    {
        denom *= -1;
        num *= -1;
    }
}

Fraction::Fraction(int num, int denom) : num{ num }, denom{ denom ? denom : 1 }
{
    reduce();
};

Fraction::Fraction() : Fraction(1, 1)
{
};

void Fraction::print() const
{
    cout << '(' << num << " / " << denom << ")";
}

int Fraction::getNum() const
{
    return num;
}

int Fraction::getDenom() const
{
    return denom;
}

void Fraction::setNum(int newNum)
{
    num = newNum;
    reduce();
};

void Fraction::setDenom(int newDenom)
{
    denom = newDenom ? newDenom : 1;
    reduce();
}

void Fraction::show() const {
    cout << num;
}


Fraction operator+(const Fraction& left,
    const Fraction& right)
{
    return Fraction
    {
        left.getNum() * right.getDenom() + right.getNum() * left.getDenom(),
        left.getDenom() * right.getDenom()
    };
}

Fraction operator+(const Fraction& left, int right)
{
    return Fraction
    {
        left.getNum() + right * left.getDenom(), left.getDenom()
    };
}

Fraction operator+(int left, const Fraction& right)
{
    return right + left;
}

Fraction operator-(const Fraction& left,
    const Fraction& right)
{
    return Fraction
    {
        left.getNum() * right.getDenom() - right.getNum() * left.getDenom(), left.getDenom() * right.getDenom()
    };
}

Fraction operator-(const Fraction& left, int right)
{
    return Fraction
    {
        left.getNum() - right * left.getDenom(), left.getDenom()
    };
}

Fraction operator-(int left, const Fraction& right)
{
    return Fraction
    {
        left * right.getDenom() - right.getNum(), right.getDenom()
    };
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
    return Fraction
    {
        left.getNum() * right.getNum(),
        left.getDenom() * right.getDenom()
    };
}


Fraction operator*(const Fraction& left, int right)
{
    return Fraction{
        left.getNum() * right, left.getDenom()
    };
}


Fraction operator*(int left, const Fraction& right)
{
    return right * left;
}


Fraction operator/(const Fraction& left, const Fraction& right)
{
    return Fraction
    {
        left.getNum() * right.getDenom(),
        left.getDenom() * right.getNum()
    };
}


Fraction operator/(const Fraction& left, int right)
{
    return Fraction
    {
        left.getNum(), left.getDenom() * right
    };
}

Fraction operator/(int left, const Fraction& right)
{
    return Fraction{
        left * right.getDenom(), right.getNum()
    };
}

void display_operation(const Fraction& f1, const Fraction& f2, char op)
{
    cout << "f1 ";
    f1.print();
    cout << " " << op << " f2 ";
    f2.print();
    cout << " = ";

    Fraction result;
    switch (op) {
    case '+': result = f1 + f2; break;
    case '-': result = f1 - f2; break;
    case '*': result = f1 * f2; break;
    case '/':
        if (f2.getNum() == 0) {
            cout << "Error: Division by zero is undefined.";
            return;
        }
        result = f1 / f2;
        break;
    default:
        cout << "Error: Invalid operator.";
        return;
    }
    result.print();
    cout << '\n';
}