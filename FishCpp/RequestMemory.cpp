/*
      动态内存管理
            * new 分配堆内存
                  * new执行失败将抛出 std::bad_alloc 异常
            * delete 释放堆内存
                  * 推荐delete后将指针置为 nullptr
*/

#include <iostream>
#include <string>

class Company
{
public:
      Company(std::string theName);

      virtual void PrintInfo(void);

protected:
      std::string name;
};

class TechCompany : public Company
{
public:
      TechCompany(std::string theName, std::string product);

      virtual void PrintInfo(void);

private:
      std::string product;
};

Company::Company(std::string theName)
{
      name = theName;
}

void Company::PrintInfo(void)
{
      std::cout << "Company name: " << name << std::endl;
}

TechCompany::TechCompany(std::string theName, std::string product) : Company(theName)
{
      this->product = product;
}

void TechCompany::PrintInfo(void)
{
      std::cout << "Product: " << product << std::endl;
}

int main(int argc, char const *argv[])
{
      Company *company = new Company("Apple");
      company->PrintInfo();

      delete company;
      company = nullptr;

      company = new TechCompany("Apple", "iPhone");
      company->PrintInfo();

      delete company;
      company = nullptr;
      
      return 0;
}
