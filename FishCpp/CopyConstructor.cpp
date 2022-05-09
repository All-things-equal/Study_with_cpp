/* 副本构造器 和 重载赋值操作符 */

#if 0
/* Example 1 -- 重载赋值操作符 */
#include <iostream>
#include <string>

class MyClass
{
public:
      MyClass(int *p);
      ~MyClass();

      MyClass &operator=(const MyClass &rhs);
      void print(void);

private:
      int *ptr;
};

MyClass::MyClass(int *p)
{
      ptr = p;
}

MyClass::~MyClass()
{
      delete ptr;
}

MyClass &MyClass::operator=(const MyClass &rhs)
{
      if (this != &rhs)
      {
            delete ptr;

            ptr = new int(*rhs.ptr);
      }
      else
      {
            std::cout << "this == &rhs" << std::endl;
      }

      return *this;
}

void MyClass::print(void)
{
      std::cout << *ptr << std::endl;
}

int main(int argc, char const *argv[])
{
      MyClass obj1(new int(1));
      MyClass obj2(new int(2));

      obj1.print();
      obj2.print();

      obj2 = obj1;

      obj1.print();
      obj2.print();
      
      return 0;
}
#endif

/* Example 2 -- CopyConstructor副本构造器 */
#include <iostream>
#include <string>

class MyClass
{
private:
public:
      MyClass(int *p);
      MyClass(const MyClass &rhs); // 副本构造器
      ~MyClass();

      MyClass &operator=(const MyClass &rhs);
      void print(void);

private:
      int *ptr;
};

MyClass::MyClass(int *p)
{
      std::cout << "进入主构造器\n";
      
      ptr = p;
      
      std::cout << "离开主构造器\n";
}

MyClass::MyClass(const MyClass &rhs)
{
      std::cout << "进入副本构造器\n";

      this->ptr = nullptr;
      *this = rhs;

      std::cout << "离开副本构造器\n";
}

MyClass::~MyClass()
{
      std::cout << "进入析构器\n";
      
      delete ptr;
      
      std::cout << "离开析构器\n";
}

MyClass &MyClass::operator=(const MyClass &rhs)
{
      std::cout << "进入赋值语句重载\n";
      
      if (this != &rhs)
      {
            delete ptr;

            ptr = new int;
            *ptr = *rhs.ptr;
      }
      else
      {
            std::cout << "this == &rhs" << std::endl;
      }

      std::cout << "离开赋值语句重载\n";
      return *this;
}

void MyClass::print(void)
{
      std::cout << *ptr << std::endl;
}

int main(int argc, char const *argv[])
{
      MyClass obj1(new int(1));
      MyClass obj2(new int(2));

      obj2 = obj1;

      obj1.print();
      obj2.print();

      MyClass obj3(new int(3));
      MyClass obj4(obj3);

      obj3.print();
      obj4.print();

      MyClass obj5(new int(5));
      obj5 = obj5;
      obj5.print();

      return 0;
}
