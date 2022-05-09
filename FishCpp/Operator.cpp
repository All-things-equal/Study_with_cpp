/* 运算符重载 */

/*
      * 在C++中，运算符重载是指重载了运算符的函数。
      * 语法: 函数类型 operator 运算符名称(参数列表) { ..对运算符的重载处理.. }
      
      * 以下五个运算符不允许重载:
            * .         成员访问运算符
            * .*        成员指针访问运算符
            * ::        域运算符
            * sizeof    尺寸运算符
            * ?:        条件运算符

      * 重载不能改变运算符运算对象(操作数)的个数
      * 重载不能改变运算符的优先级
      * 重载不能改变运算符的结合性
      * 重载运算符的函数不能有默认的参数
      * 重载运算符的参数至少有一个是类对象或类对象的引用, 推荐两个参数都用类(或类的引用)
*/

/* Operator.cpp - 通过运算符的重载实现复数加法 */
#include <iostream>
#include <string>

/*
      * 功能: 打印函数调用日记
      * 效果: 打印出代码调用的函数名, 行号, 所在文件名.
       WARNING: 把 PRT_FUNC_CLOSE 设置为 0 即可关闭此功能.
*/
#define PRT_FUNC_CLOSE 1
#if PRT_FUNC_CLOSE
#define PRT_FUNC                         \
      {                                  \
            std::cout << "\033[0;30;47m" \
                      << "[FUNC] ["      \
                      << __func__        \
                      << " - line "      \
                      << __LINE__        \
                      << " -- "          \
                      << __FILE__        \
                      << "]\033[0m\n";   \
      }
#else
#define PRT_FUNC \
      {          \
            ;    \
      }
#endif

class Complex
{
public:
      Complex(void);
      Complex(double real, double imaginary);

      Complex operator+(const Complex &other); // 重载加法运算符

      friend Complex operator+(Complex &c1, Complex &c2); // 友元函数会破坏类的封装, 从原则上推荐尽量将运算符函数声明为成员函数.

      void print(void);

private:
      double real;
      double imaginary;
};

Complex::Complex(void)
{
      real = 0.0;
      imaginary = 0.0;
}

Complex::Complex(double real, double imaginary)
{
      this->real = real;
      this->imaginary = imaginary;
}

Complex Complex::operator+(const Complex &other)
{
      PRT_FUNC;

      Complex result;

      result.real = real + other.real;
      result.imaginary = imaginary + other.imaginary;

      return result;
}

void Complex::print(void)
{
      std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
}

// WARNING: 友元函数, 不属于类的成员函数, 不用::
Complex operator+(Complex &c1, Complex &c2)
{
      PRT_FUNC;
      return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

int main(int argc, char const *argv[])
{
      Complex c1(3.0, 4.0);
      Complex c2(5.0, -10.0);
      Complex c3;

      c3 = c1 + c2;

      std::cout << "c1 = ";
      c1.print();
      std::cout << "c2 = ";
      c2.print();

      std::cout << "c1 + c2 = ";
      c3.print();

      return 0;
}
