/* 静态属性 和 静态方法 */

/* 
      NotePad.
            * static -- private属性, public方法

            * 静态成员是所有对象共享的, 所以不能在静态方法里面访问非静态成员(this指针).
            * 非静态方法可以访问类的静态成员, 也可以访问非静态成员.
            
            * 在使用静态属性时, 必须在类的外部定义.
            * 调用静态方法时, 推荐使用 ClassName::MethodName().
*/

#include <iostream>
#include <string>

class Pet
{
public:
      Pet(std::string theName);
      ~Pet();

      static int GetCount();

protected:
      std::string name;

private:
      static int count;
};

class Dog : public Pet
{
public:
      Dog(std::string theName);
};

class Cat : public Pet
{
public:
      Cat(std::string theName);
};

int Pet::count = 0;

Pet::Pet(std::string theName)
{
      name = theName;
      count++;

      std::cout << "一只宠物出生了, 名字叫做: " << name << std::endl;
}

Pet::~Pet()
{
      count--;
      std::cout << name << "挂掉了!" << std::endl;
}

int Pet::GetCount()
{
      return count;
}

Dog::Dog(std::string theName) : Pet(theName)
{
}

Cat::Cat(std::string theName) : Pet(theName)
{
}

int main(int argc, char const *argv[])
{
      Dog dog1("Tom");
      Cat cat1("Jerry");

      std::cout << "现在有" << Pet::GetCount() << "只宠物" << std::endl;

      { // 局部作用域, 只有这个作用域里面的宠物才会被析构
            Dog dog2("Tom_2");
            Cat cat2("Jerry_2");

            std::cout << "现在有" << Pet::GetCount() << "只宠物" << std::endl;
      } // WARNING: 当前作用域结束, 宠物数量减少了

      std::cout << "\n现在还剩下" << Pet::GetCount() << "只宠物" << std::endl;

      return 0;
}
