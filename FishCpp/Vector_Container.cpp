/* Vector_Container.cpp - 向量容器 */

/*
      * 语法: std::vector<Type> vectorName;
*/

#include <iostream>
#include <string>
#include <vector> // 向量容器

int main(int argc, char const *argv[])
{
      std::vector<std::string> vecStr;

      vecStr.push_back("Hello");
      vecStr.push_back("vector");

      for (int i = 0; i < vecStr.size(); i++)
      {
            std::cout << vecStr[i] << std::endl;
      }

      return 0;
}
