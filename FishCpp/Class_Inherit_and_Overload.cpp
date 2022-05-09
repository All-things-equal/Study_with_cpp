/* 类 的继承, 父类(基类、超类) 和 子类 */
/* class SubClass : public SuperClass {...} */

/* 
      重载方法
            * 在同一个类中
            * 函数名相同
            * 参数列表不同
            * virtual 关键字可有可无
*/

#include <iostream>
#include <string>

class Animal
{
public:
      Animal(std::string theName);
      ~Animal();

      void Eat(void);
      void Eat(int eatCount); // 重载 Eat 方法

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
};

class Turtle : public Animal
{
public:
      Turtle(std::string theName);

      void Swim(void);
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

void Animal::Eat(int eatCount)
{
      std::cout << "I am eated " << eatCount << " food!" << std::endl;
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

void Turtle::Swim(void)
{
      std::cout << "我是一只小甲鱼, 当母猪想抓我的时候, 我就游到海里。。哈哈。。" << std::endl;
}

int main(int argc, char const *argv[])
{
      Pig pig("母猪");
      Turtle turtle("小甲鱼");

      pig.Eat();
      std::cout << '\n';

      turtle.Eat();
      std::cout << '\n';

      pig.Eat(15);
      std::cout << '\n';

      pig.Climb();
      std::cout << '\n';

      turtle.Swim();
      std::cout << '\n';

      return 0;
}
