/* 泛型 -- 内联函数 模板 */

/* Template_inline.cpp - 栈 */
#include <iostream>
#include <string>

template <class T>
class Stack
{
public:
      Stack(unsigned int size = 100)
      {
            this->size = size;
            this->top = 0;
            this->data = new T[size];
      }
      ~Stack()
      {
            delete[] this->data;
      }

      void push(T value)
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

      T pop(void)
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

private:
      unsigned int size;
      unsigned int top;
      T *data;
};

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
