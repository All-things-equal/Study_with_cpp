#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

struct FishOil
{
      std::string name;
      std::string uid;
      char sex; // F == Female, M == Male
};

int main(int argc, char const *argv[])
{
      FishOil jiaYv;
      jiaYv.name = "小甲鱼";
      jiaYv.uid = "fishc_00000";
      jiaYv.sex = 'M';

      /*
      // ? 实现不了
      std::cout << "\n正在输出记录数据...... ";
      for (int i = 0; i <= 100; i++) // 打印百分比
      {
            std::cout.width(3);
            std::cout << i << "%%";
            // sleep(5);
            // usleep(10000);
            std::cout << "\b\b\b\b";
      }
      std::cout << "\n\n";
      // */

      return 0;
}
