/* 泛型 -- 类模板 */

/* Template_Class.cpp - 栈 */
// * 推荐用内联写法, --> Template_inline.cpp

#include <iostream>
#include <string>

template <class T>
class Stack
{
public:
      Stack(unsigned int size = 100);
      ~Stack();

      void push(T value);
      T pop(void);

private:
      unsigned int size;
      unsigned int top;
      T *data;
};

template <class T>
Stack<T>::Stack(unsigned int size)
{
      this->size = size;
      this->top = 0;
      this->data = new T[size];
}

template <class T>
Stack<T>::~Stack()
{
      delete[] this->data;
}

template <class T>
void Stack<T>::push(T value)
{
      if (this->top < this->size)
      {
            this->data[this->top++] = value;
      }
      else
      {
            std::cout << "Stack is full!" << std::endl;
      }
}

template <class T>
T Stack<T>::pop(void)
{
      if (this->top > 0)
      {
            return this->data[--this->top];
      }
      else
      {
            std::cout << "Stack is empty!" << std::endl;
            return 0;
      }
}

int main(int argc, char const *argv[])
{
      Stack<int> stack(3);
      
      stack.push(1);
      stack.push(2);
      stack.push(3);
      stack.push(4);

      std::cout << stack.pop() << std::endl;
      std::cout << stack.pop() << std::endl;
      std::cout << stack.pop() << std::endl;
      std::cout << stack.pop() << std::endl;
      
      return 0;
}
