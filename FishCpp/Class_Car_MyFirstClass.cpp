/* 类(class), 对象 */

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define SUCCESS 1
#define ERROR 0

#define FULL_GAS 85

typedef int Status;

class Car
{
private:
public:
      std::string color;
      std::string engine;
      float gas_tank;
      unsigned int wheel;

      Car(void);
      void SetColor(std::string cr);
      void SetEngine(std::string eng);
      void SetWheel(unsigned int whe);
      void FillTank(float liter);
      Status Running(void);
      void Warning(void);
};

Car::Car(void)
{
      color = "White";
      engine = "V8";
      wheel = 4;
      gas_tank = FULL_GAS;
}

void Car::SetColor(std::string cr)
{
      color = cr;
}

void Car::SetEngine(std::string eng)
{
      engine = eng;
}

void Car::SetWheel(unsigned int whe)
{
      wheel = whe;
}

void Car::FillTank(float liter)
{
      if (gas_tank + liter <= FULL_GAS)
      {
            gas_tank += liter;
      }
}

Status Car::Running(void)
{
      char ch;

      if (gas_tank >= 0)
      {
            std::cout << "我正在以120的时速往前移动。。。翻过那高山越过那河流。。。\n";
            gas_tank--;
            std::cout << "当前还剩 " << 100 * gas_tank / FULL_GAS << "%"
                      << "油量!\n";
      }

      if (gas_tank < 10)
      {
            std::cout << "请问是否加满油再行驶?(Y/N)\n";
            std::cin >> ch;
            if ('Y' == ch || 'y' == ch)
            {
                  FillTank(FULL_GAS - gas_tank);
            }

            if (gas_tank < 10)
            {
                  Warning();
            }

            if (0 == gas_tank)
            {
                  std::cout << "抛锚中。。。。。\n";
                  return ERROR;
            }
      }

      return SUCCESS;
}

void Car::Warning(void)
{
      std::cout << "WARNING!!"
                << "还剩 "
                << 100 * gas_tank / FULL_GAS
                << "%"
                << "油量!\n";
}

int main(int argc, char const *argv[])
{
      char ch;
      Car car;

      while (car.Running())
      {
            ;
      }

      return 0;
}
