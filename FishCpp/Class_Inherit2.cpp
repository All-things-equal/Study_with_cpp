/* 基类的析构器在子类最后一条语句执行完后被调用 */

/* 
      * 访问控制 权限
            * public    公有  在任何地方都可以访问
            * protected 保护  在 类和它的子类 内部可以访问
            * private   私有  只有这个类内部可以访问
*/

#include <iostream>
#include <string>

class BaseClass
{
public:
      BaseClass();
      ~BaseClass();

      void DoSomething(void);
};

class SubClass : public BaseClass
{
public:
      SubClass(void);
      ~SubClass();
};

BaseClass::BaseClass(void)
{
      std::cout << "进入基类构造器..." << __func__ << " - " << __LINE__ << std::endl;
}

BaseClass::~BaseClass()
{
      std::cout << "进入基类析构器..." << __func__ << " - " << __LINE__ << std::endl;
}

void BaseClass::DoSomething(void)
{
      std::cout << " This is BaseClass function: " << __func__ << " - " << __LINE__ << std::endl;
}

SubClass::SubClass(void)
{
      std::cout << "进入子类构造器..." << __func__ << " - " << __LINE__ << std::endl;
}

SubClass::~SubClass()
{
      std::cout << "进入子类析构器..." << __func__ << " - " << __LINE__ << std::endl;
}

int main(int argc, char const *argv[])
{
      std::cout << '\n';

      SubClass sub;

      sub.DoSomething();

      std::cout << "\nThe program will over. " << __func__ << " - " << __LINE__ << '\n'
                << std::endl;

      return 0;
}
