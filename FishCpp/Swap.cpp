/*
      ? 220127 - ElemType &variable =?= ElemType *const pointVariable
*/

#include <iostream>

void Swap(int &x, int &y);

int main(int argc, char const *argv[])
{
      int a = 22;
      int b = 33;

      std::cout << "In " << __func__ << " - " << __LINE__ << ":\n";
      std::cout << "\t&a = " << &a << ", &b = " << &b << '\n';
      std::cout << "\tsizeof(&a) = " << sizeof(&a) << ", sizeof(&b) = " << sizeof(&b) << '\n';
      std::cout << "\ta = " << a << ", b = " << b << '\n';

      Swap(a, b);

      std::cout << "Swap over, now in " << __func__ << " - " << __LINE__ << ":\n";
      std::cout << "\ta = " << a << ", b = " << b << '\n';
      std::cout << "\t&a = " << &a << ", &b = " << &b << '\n';

      return 0;
}

void Swap(int &x, int &y)
{
      std::cout << "In " << __func__ << " - " << __LINE__ << ":\n";
      std::cout << "\t&x = " << &x << ", &y = " << &y << '\n';
      std::cout << "\tsizeof(x) = " << sizeof(x) << ", sizeof(y) = " << sizeof(y) << '\n';

      x ^= y ^= x ^= y;
}

#if 0
void Swap(int *x, int *y)
{
      *x ^= *y;
      *y ^= *x;
      *x ^= *y;
}
#endif