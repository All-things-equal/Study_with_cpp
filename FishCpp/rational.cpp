/* rational.cpp
      *- 运算符重载实现有理数的四则运算
      *- 重载 << 操作符实现 print 输出
            ** (官方叫法): << 插入器; >> 提取器,析取器.
*/

#include <iostream>
#include <string>

class Rational
{
public:
      Rational(int numerator, int denominator); // numerator 表 分子, denominator 表 分母

      // rhs == right hand side 表 右值
      Rational operator+(Rational &rhs); // 重载加法运算符
      Rational operator-(Rational &rhs); // 重载减法运算符
      Rational operator*(Rational &rhs); // 重载乘法运算符
      Rational operator/(Rational &rhs); // 重载除法运算符

      void print(void);

private:
      int numerator;
      int denominator;

      void normalize(void); // 负责分数化简

      friend std::ostream &operator<<(std::ostream &os, Rational f); // 重载 << 操作符
};

Rational::Rational(int numerator, int denominator)
{
      this->numerator = numerator;
      this->denominator = denominator;
      normalize();
}

// normalize() 函数负责分数化简, 其操作流程:
// 1. 只允许分子为负数, 如果分母为负数则把负数挪到分子部分, 如 1/-2 = -1/2
// 2. 利用欧几里德算法(辗转求余原理) 将分数化简, 如 2/10 ==> 1/5
void Rational::normalize(void)
{
      // 确保分母为正数
      if (denominator < 0)
      {
            numerator = -numerator;
            denominator = -denominator;
      }

      /*
      // Copilon 给出的辗转求余
      int gcd = numerator > denominator ? numerator : denominator;
      while (gcd > 1)
      {
            if (numerator % gcd == 0 && denominator % gcd == 0)
            {
                  numerator /= gcd;
                  denominator /= gcd;
                  gcd = numerator > denominator ? numerator : denominator;
            }
            else
            {
                  gcd--;
            }
      }
      // */

      // /*
      // 小甲鱼 给出的辗转求余
      int a = abs(numerator);
      int b = abs(denominator);

      // 求出最大公约数
      while (b != 0)
      {
            int temp = a % b;
            a = b;
            b = temp;
      }

      // 分子、分母分别除以最大公约数得到最简分数
      numerator /= a;
      denominator /= a;
      // */
}

Rational Rational::operator+(Rational &rhs)
{
      int numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
      int denominator = this->denominator * rhs.denominator;

      Rational result(numerator, denominator);
      result.normalize();

      return result;
}

// Rational Rational::operator-(Rational &rhs)
// {
//       int numerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
//       int denominator = this->denominator * rhs.denominator;

//       Rational result(numerator, denominator);
//       result.normalize();

//       return result;
// }

Rational Rational::operator-(Rational &rhs)
{
      Rational opposite(-rhs.numerator, rhs.denominator);
      return *this + opposite;
}

Rational Rational::operator*(Rational &rhs)
{
      int numer = this->numerator * rhs.numerator;
      int denom = this->denominator * rhs.denominator;

      Rational result(numer, denom);
      result.normalize();

      return result;
}

// Rational Rational::operator/(Rational &rhs)
// {
//       int numerator = this->numerator * rhs.denominator;
//       int denominator = this->denominator * rhs.numerator;

//       Rational result(numerator, denominator);
//       result.normalize();

//       return result;
// }

Rational Rational::operator/(Rational &rhs)
{
      Rational reciprocal(rhs.denominator, rhs.numerator);
      return operator*(reciprocal);
}

void Rational::print(void)
{
      if (numerator % denominator == 0)
      {
            std::cout << numerator / denominator;
      }
      else
      {
            std::cout << numerator << "/" << denominator;
      }
}

std::ostream &operator<<(std::ostream &os, Rational f);

int main(int argc, char const *argv[])
{
      Rational r1(2, 16);
      Rational r2(7, 8);

      std::cout << "r1 = ";
      r1.print();
      std::cout << std::endl;
      std::cout << "r2 = ";
      r2.print();
      std::cout << std::endl;

      // 测试有理数加法
      Rational r3 = r1 + r2;

      std::cout << "r1 + r2 = ";
      r3.print();
      std::cout << std::endl;
      std::cout << r1 << " + " << r2 << " = " << (r1 + r2) << std::endl;

      // 测试有理数减法
      Rational r4 = r1 - r2;

      std::cout << "r1 - r2 = ";
      r4.print();
      std::cout << std::endl;
      std::cout << r1 << " - " << r2 << " = " << (r1 - r2) << std::endl;

      // 测试有理数乘法
      Rational r5 = r1 * r2;

      std::cout << "r1 * r2 = ";
      r5.print();
      std::cout << std::endl;
      std::cout << r1 << " * " << r2 << " = " << (r1 * r2) << std::endl;

      // 测试有理数除法
      Rational r6 = r1 / r2;

      std::cout << "r1 / r2 = ";
      r6.print();
      std::cout << std::endl;
      std::cout << r1 << " / " << r2 << " = " << (r1 / r2) << std::endl;

      return 0;
}

std::ostream &operator<<(std::ostream &os, Rational f)
{
      if (f.numerator % f.denominator == 0)
      {
            os << f.numerator / f.denominator;
      }
      else
      {
            os << f.numerator << "/" << f.denominator;
      }

      return os;
}