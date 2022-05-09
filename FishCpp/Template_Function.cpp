/* 泛型 -- 函数模板示例 */

#include <iostream>
#include <string>

template <class T>
void Swap(T &a, T &b)
{
      T temp = a;
      a = b;
      b = temp;
}

int main(int argc, char const *argv[])
{
      int a = 1, b = 2;

      std::cout << "a = " << a << ", b = " << b << std::endl;
      Swap(a, b);
      std::cout << "a = " << a << ", b = " << b << std::endl;

      std::string s1 = "hello", s2 = "world";

      std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
      Swap<std::string>(s1, s2); // ==> Swap(s1, s2);
      std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;

      return 0;
}
