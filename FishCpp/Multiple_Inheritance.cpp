/* 多继承 */

/*
      * 语法: class A : public B, public C {...}
*/

/* Multiple_Inheritance.cpp 
      *- Teacher子类 和 Student子类 分别 单继承 Person基类
      *- TeachingStudent子类 多继承 Teacher类 和 Student类
*/
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

class Teacher : public Person
{
public:
      Teacher(std::string theName, std::string theClassId);

      void Teach(void);
      void Introduce(void);

protected:
      std::string classId;
};

class Student : public Person
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

TeachingStudent::TeachingStudent(std::string theName, std::string classTeaching, std::string classAttending) : Teacher(theName, classTeaching), Student(theName, classAttending)
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
