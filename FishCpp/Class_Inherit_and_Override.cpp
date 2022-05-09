/* 类 的继承, 父类(基类、超类) 和 子类 */
/* class SubClass : public SuperClass {...} */

/* 
      覆盖方法
            * 分别位于派生类和基类
            * 函数名相同
            * 参数相同
            * 基类的函数必须为 virtual
*/

#include <iostream>
#include <string>

class Animal
{
public:
      Animal(std::string theName);
      ~Animal();

      void Eat(void);
      void Sleep(void);
      void Drool(void);

protected:
      std::string name;
};

class Pig : public Animal
{
public:
      Pig(std::string theName);

      void Climb(void);

      void Eat(void); // 覆盖父类的 Eat 方法
};

class Turtle : public Animal
{
public:
      Turtle(std::string theName);

      void Swim(void);

      void Eat(void); // 覆盖父类的 Eat 方法
};

Animal::Animal(std::string theName)
{
      name = theName;
}

Animal::~Animal()
{
}

Pig::Pig(std::string theName) : Animal(theName)
{
}

Turtle::Turtle(std::string theName) : Animal(theName)
{
}

void Animal::Eat(void)
{
      std::cout << "I am eating!" << std::endl;
}

void Animal ::Sleep(void)
{
      std::cout << "I'm sleeping! Don't disturb me!" << std::endl;
}

void Animal::Drool(void)
{
      std::cout << "我是公的, 看到母人我会流口水, 我会流口水...\n";
}

void Pig::Climb(void)
{
      std::cout << "我是一只漂亮的小母猪, 我会上树, 我正在爬树!\n";
}

void Pig::Eat(void)
{
      std::cout << "Pig " << name << " is eating!" << std::endl;
}

void Turtle::Swim(void)
{
      std::cout << "我是一只小甲鱼, 当母猪想抓我的时候, 我就游到海里。。哈哈。。" << std::endl;
}

void Turtle::Eat(void)
{
      Animal::Eat(); // 可以调用父类的 Eat 方法
      std::cout << "Turtle " << name << " is eating!" << std::endl;
}

int main(int argc, char const *argv[])
{
      Pig pig("母猪");
      Turtle turtle("小甲鱼");

      // ! class.name 权限 是protected, 只能在类和它的子类中访问
      // std::cout << "这只猪的名字是 " << pig.name << std::endl;
      // std::cout << "这只乌龟的名字是 " << turtle.name << std::endl;

      pig.Eat();
      std::cout << '\n';

      turtle.Eat();
      std::cout << '\n';

      pig.Climb();
      std::cout << '\n';

      turtle.Swim();
      std::cout << '\n';

      return 0;
}
