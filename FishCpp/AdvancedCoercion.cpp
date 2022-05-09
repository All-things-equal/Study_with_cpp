/* 高级强制类型转换 */

/*
      * 语法:
            * const_cast<类型>(变量)            用来改变 变量 的 "常量性"
            * dynamic_cast<类型>(变量)          用来把一种类型的对象指针安全地强制转换为另一种类型的对象指针, 如果转换失败,则返回nullptr.
            * reinterpret_cast<类型>(变量)      在不进行任何实质性的转换的情况下, 把一种类型的指针解释为另一种类型的指针 或者 把一种整数解释为另一种整数.
            * static_cast<类型>(变量)           用来进行强制类型转换而不做任何运行时的检查, 老式强制类型转换操作的替代品.
*/

#include <iostream>
#include <string>

class Company
{
public:
      Company(std::string theName, std::string product);

      virtual void PrintInfo(void);

protected:
      std::string name;
      std::string product;
};

class TechCompany : public Company
{
public:
      TechCompany(std::string theName, std::string product);

      virtual void PrintInfo(void);
};

Company::Company(std::string theName, std::string product)
{
      name = theName;
      this->product = product;
}

void Company::PrintInfo(void)
{
      std::cout << "公司名称: " << name << std::endl;
      std::cout << "产品名称: " << product << std::endl;
}

TechCompany::TechCompany(std::string theName, std::string product) : Company(theName, product)
{
}

void TechCompany::PrintInfo(void)
{
      std::cout << "公司大量生产了" << product << std::endl;
}

int main(int argc, char const *argv[])
{
      Company *company = new Company("Apple", "iphone");
      TechCompany *techCompany = dynamic_cast<TechCompany *>(company);

      if (nullptr == techCompany)
      {
            std::cout << "没有找到技术公司" << std::endl;
            return -1;
      }

      techCompany->PrintInfo();

      delete company;

      company = nullptr;
      techCompany = nullptr;

      return 0;
}
