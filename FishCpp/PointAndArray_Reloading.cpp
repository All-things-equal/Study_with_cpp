/* 指针和数组, 重载, 泛型程序设计 */

#include <iostream>

// void Print(int *pBegin, int *pEnd);
// void Print(char *pBegin, char *pEnd);

template <typename ElemType>
void Print(ElemType *pBegin, ElemType *pEnd)
{
      while (pBegin != pEnd)
      {
            std::cout << *pBegin << ' ';
            ++pBegin;
      }
}

int main(int argc, char const *argv[])
{
      int num[5] = {1, 2, 3, 4, 5};
      char name[5] = {'F', 'i', 's', 'h', 'C'};

      Print(num, num + 5);
      std::cout << '\n';
      Print(name, name + 5);
      std::cout << '\n';

      return 0;
}

// void Print(int *pBegin, int *pEnd)
// {
//       while (pBegin != pEnd)
//       {
//             std::cout << *pBegin << ' ';
//             ++pBegin;
//       }
// }

// void Print(char *pBegin, char *pEnd)
// {
//       while (pBegin != pEnd)
//       {
//             std::cout << *pBegin << ' ';
//             ++pBegin;
//       }
// }
