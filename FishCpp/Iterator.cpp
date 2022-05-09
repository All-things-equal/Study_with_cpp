/* Iterator.cpp - 迭代器 */

/*
      * 语法: std::vector<Type>::iterator iter;
      * 实质是指针
      * 每一种容器都有其对应的迭代器
*/
#include <iostream>
#include <string>
#include <vector> // 向量容器

int main(int argc, char const *argv[])
{
      std::vector<std::string> vecStr;

      vecStr.push_back("Hello");
      vecStr.push_back("vector");

      // for (int i = 0; i < vecStr.size(); i++)
      // {
      //       std::cout << vecStr[i] << std::endl;
      // }

      std::vector<std::string>::iterator iter = vecStr.begin(); // 迭代器

      while (iter != vecStr.end())
      {
            std::cout << *iter << std::endl;

            iter++;
      }

      return 0;
}
