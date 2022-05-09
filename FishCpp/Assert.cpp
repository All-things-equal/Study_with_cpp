/* assert.cpp 
      *- assert函数捕获异常

      *- 捕获异常 try 和 catch
            * 如果try语句没有找到一个与之匹配的catch语句块, 它抛出的异常将终止程序的执行.
      *- 抛出异常 throw
            * 在某个try语句块里执行 throw 语句, 它后面的语句(截至这个try语句块的末尾)将不再执行.
      
      NotePad: 如果打算使用对象作为异常, 原则上
                  * 以"值传递"方式抛出对象
                  * 以"引用传递"方式捕获对象
*/

/*
      * 语法: assert(expression);
      * 功能: 如果表达式expression为false, 则抛出异常, 打印出错误信息, 并且终止程序运行.
*/

#include <iostream>
#include <cassert> // C -- <assert.h>
#include <climits>

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

class Factoril
{
public:
      Factoril(unsigned short num);

      unsigned long GetFactoril(void) throw(const std::string &);
      bool InRange(void);

private:
      unsigned short num;
};

Factoril::Factoril(unsigned short num)
{
      this->num = num;
}

unsigned long Factoril::GetFactoril(void) throw(const std::string &)
{
      PRT_FUNC;

      unsigned long factoril = 1;

      if (false == InRange())
      {
            PRT_FUNC;

            throw "Out of range!";
      }

      for (int i = 1; i <= num; ++i)
      {
            PRT_FUNC;

            factoril *= i;
      }

      return factoril;
}

bool Factoril::InRange(void)
{
      unsigned long max = ULONG_MAX;

      for (int i = num; i > 0; --i)
      {
            max /= i;
      }

      if (max < 1)
      {
            return false;
      }

      return true;
}

int main(int argc, char const *argv[])
{
      int i = 20;

      // assert(65 == i);

      unsigned short num = 0;

      std::cout << "Please input a integer: ";
      std::cin >> num;

      Factoril factoril(num);

      try
      {
            PRT_FUNC;

            std::cout << "The factoril of " << num << " is " << factoril.GetFactoril() << std::endl;
      }
      catch (const std::exception &e)
      {
            PRT_FUNC;

            std::cout << e.what() << std::endl; // 打印出错误信息

            PRT_FUNC;
      }

      PRT_FUNC;

      return 0;
}
