/* factoril.cpp - 求阶乘 */

#include <iostream>
#include <climits>

class Factoril
{
public:
      Factoril(unsigned short num);

      unsigned long GetFactoril(void);
      bool InRange(void);

private:
      unsigned short num;
};

Factoril::Factoril(unsigned short num)
{
      this->num = num;
}

unsigned long Factoril::GetFactoril(void)
{
      unsigned long factoril = 1;

      for (int i = 1; i <= num; ++i)
      {
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
      unsigned short num = 0;

      std::cout << "Please input a integer: ";
      std::cin >> num;

      Factoril factoril(num);

      if (factoril.InRange())
      {
            std::cout << "The factoril of " << num << " is " << factoril.GetFactoril() << std::endl;
      }
      else
      {
            std::cout << "The factoril of " << num << " is too large to calculate." << std::endl;
      }
      
      return 0;
}
