/* 函数的重载 */

/*
    * 重载 不是 面向对象语言的特性
*/

#include <iostream>

// 温度单位转换程序
void converTemprature(double valueInput, char typeInput);
void converTemprature(int valueInput, char typeInput);

int main(int argc, char const *argv[])
{
      double valueInput;
      char typeInput;
      int InputValueInteger;

      std::cout << "输入格式: xx.x C 或 xx.x F\nplease enter: ";
      std::cin >> valueInput >> typeInput;
      while ('\n' != std::cin.get())
      {
            continue;
      }
      converTemprature(valueInput, typeInput);

      std::cout << "输入格式: xx C 或 xx F\nplease enter: ";
      std::cin >> InputValueInteger >> typeInput;
      while ('\n' != std::cin.get())
      {
            continue;
      }
      converTemprature(InputValueInteger, typeInput);

      return 0;
}

void converTemprature(double valueInput, char typeInput)
{
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;

      double valueOutput;
      char typeOutput;

      switch (typeInput)
      {
      case 'C':
      case 'c':
            valueOutput = valueInput * RATIO + ADD_SUBTRACT;
            typeOutput = 'F';
            typeInput = 'C';
            break;
      case 'F':
      case 'y':
            valueOutput = (valueInput - ADD_SUBTRACT) / RATIO;
            typeOutput = 'C';
            typeInput = 'F';
            break;
      default:
            typeOutput = 'E';
            break;
      }
      if (typeOutput != 'E')
      {
            std::cout << valueInput << typeInput << '=' << valueOutput << typeOutput << std::endl;
      }
      else
      {
            std::cout << "输入错误!" << std::endl;
      }
}

void converTemprature(int valueInput, char typeInput)
{
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;

      int valueOutput;
      char typeOutput;

      switch (typeInput)
      {
      case 'C':
      case 'c':
            valueOutput = valueInput * RATIO + ADD_SUBTRACT;
            typeOutput = 'F';
            typeInput = 'C';
            break;
      case 'F':
      case 'y':
            valueOutput = (valueInput - ADD_SUBTRACT) / RATIO;
            typeOutput = 'C';
            typeInput = 'F';
            break;
      default:
            typeOutput = 'E';
            break;
      }
      if (typeOutput != 'E')
      {
            std::cout << valueInput << typeInput << '=' << valueOutput << typeOutput << std::endl;
      }
      else
      {
            std::cout << "输入错误!" << std::endl;
      }
}
