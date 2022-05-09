/* 虚继承 */

/*
      * 通过虚继承某个基类, 实现从此基类派生的子类只能拥有其基类的一个实例, 解决多继承后属性冲突的逻辑问题
      * 语法: class SubClass : virtual public BaseClass {...};
*/

/* Virtual_Inheritance.cpp - 虚继承使得从 Student类 和 Teacher类 再派生出来的子类只能拥有一份Person基类的属性(name) */
#include <iostream>
#include <string>

/*
      * 功能: 打印函数调用日记
      * 效果: 打印出代码调用的函数名, 行号, 所在文件名.
       WARNING: 把 PRT_FUNC_CLOSE 设置为 0 即可关闭此功能.
*/
#define PRT_FUNC_CLOSE 1
#if PRT_FUNC_CLOSE
#define PRT_FUNC                         \
      {                                  \
            std::cout << "\033[0;30;47m" \
                      << "[FUNC] ["      \
                      << __func__        \
                      << " - line "      \
                      << __LINE__        \
                      << " -- "          \
                      << __FILE__        \
                      << "]\033[0m\n";   \
      }
#else
#define PRT_FUNC \
      {          \
            ;    \
      }
#endif

class Person
{
public:
      Person(std::string theName);

      void Introduce(void);

protected:
      std::string name;
};

class Teacher : virtual public Person // 虚继承
{
public:
      Teacher(std::string theName, std::string theClassId);

      void Teach(void);
      void Introduce(void);

protected:
      std::string classId;
};

class Student : virtual public Person // 虚继承
{
public:
      Student(std::string theName, std::string theClassId);

      void AttendClass(void);
      void Introduce(void);

protected:
      std::string classId;
};

class TeachingStudent : public Student, public Teacher
{
public:
      TeachingStudent(std::string theName, std::string classTeaching, std::string classAttending);

      void Introduce(void);
};

Person::Person(std::string theName)
{
      name = theName;
}

void Person::Introduce(void)
{
      PRT_FUNC;
      std::cout << "My name is " << name << std::endl;
}

Teacher::Teacher(std::string theName, std::string theClassId) : Person(theName)
{
      classId = theClassId;
}

void Teacher::Teach(void)
{
      PRT_FUNC;
      std::cout << name << " teach class " << classId << std::endl;
}

void Teacher::Introduce(void)
{
      PRT_FUNC;
      std::cout << "My name is " << name << std::endl;
      std::cout << "I am a teacher. I teach class " << classId << std::endl;
}

Student::Student(std::string theName, std::string theClassId) : Person(theName)
{
      classId = theClassId;
}

void Student::AttendClass(void)
{
      PRT_FUNC;
      std::cout << name << " attend class " << classId << std::endl;
}

void Student::Introduce(void)
{
      PRT_FUNC;
      std::cout << "My name is " << name << std::endl;
      std::cout << "I am a student. I attend class " << classId << std::endl;
}

TeachingStudent::TeachingStudent(std::string theName, std::string classTeaching, std::string classAttending) : Teacher(theName, classTeaching), Student(theName, classAttending), Person(theName)
{
}

void TeachingStudent::Introduce(void)
{
      PRT_FUNC;
      std::cout << "My name is " << Student::name
                << ".\n I am a teacher. I teach class " << Teacher::classId
                << ".\n I am also a student. I attend class " << Student::classId
                << std::endl;
}

int main(int argc, char const *argv[])
{
      Teacher teacher("dmtsai", "gzmtu202");
      Student student("laomo", "gzmtu202");
      TeachingStudent teacherStudent("JJ", "teach201", "study202");

      teacher.Introduce();
      teacher.Teach();
      student.Introduce();
      student.AttendClass();
      teacherStudent.Introduce();
      teacherStudent.Teach();
      teacherStudent.AttendClass();

      return 0;
}
