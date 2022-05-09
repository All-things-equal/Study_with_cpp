/* 抽象方法、(纯虚函数) */

/*
      * 语法: virtual void 方法名(参数列表) = 0;
      * 功能: 声明一个抽象方法
      * 在派生类中必须实现, 无需在基类中实现
*/

#include <iostream>
#include <string>

class Pet
{
public:
      Pet(std::string theName);
      ~Pet();

      virtual void Eat(void);
      virtual void Sleep(void);

      virtual void Play(void) = 0; //抽象方法, 不需要给出定义

protected:
      std::string name;
};

class Cat : public Pet
{
public:
      Cat(std::string theName);

      void Climb(void);
      void Play(void);
};

class Dog : public Pet
{
public:
      Dog(std::string theName);

      void Bark(void);
      void Play(void);
};

Pet::Pet(std::string theName)
{
      name = theName;
}

Pet::~Pet()
{
      ;
}

void Pet::Eat(void)
{
      std::cout << name << "吃饭了!" << std::endl;
}

void Pet::Sleep(void)
{
      std::cout << name << "睡觉了!" << std::endl;
}

// void Pet::Play(void)
// {
//       std::cout << name << "玩耍了!" << std::endl;
// }

Cat::Cat(std::string theName) : Pet(theName)
{
}

void Cat::Climb(void)
{
      std::cout << name << "爬树了!" << std::endl;
}

void Cat::Play(void)
{
      std::cout << "喵 " << name << "玩毛球!" << std::endl;
}

Dog::Dog(std::string theName) : Pet(theName)
{
}

void Dog::Bark(void)
{
      std::cout << name << "汪汪叫了!" << std::endl;
}

void Dog::Play(void)
{
      std::cout << "汪 " << name << "玩骨头!" << std::endl;
}

int main(int argc, char const *argv[])
{
      Pet *cat = new Cat("加菲");
      Pet *dog = new Dog("欧迪");

      cat->Sleep();
      cat->Eat();
      cat->Play();

      dog->Sleep();
      dog->Eat();
      dog->Play();

      delete cat;
      delete dog;

      return 0;
}
