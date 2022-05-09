/* Algorithm.cpp - 排序 */

#include <iostream>
#include <string>
#include <vector>    // 向量容器
#include <algorithm> // 排序算法

int main(int argc, char const *argv[])
{
      std::vector<std::string> vecStr;

      vecStr.push_back("zzz");
      vecStr.push_back("yyy");
      vecStr.push_back("xxx");

      vecStr.push_back("aaa");
      vecStr.push_back("bbb");
      vecStr.push_back("ccc");

      for (int i = 0; i < vecStr.size(); i++)
      {
            std::cout << vecStr[i] << std::endl;
      }
      std::cout << std::endl;

      std::sort(vecStr.begin(), vecStr.end()); // 升序排序

      std::vector<std::string>::iterator iter = vecStr.begin(); // 迭代器

      while (iter != vecStr.end())
      {
            std::cout << *iter << std::endl;

            iter++;
      }

      return 0;
}
