#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

// using namespace std;

int main(int argc, char const *argv[])
{
      // std::cout << "hello 劳模" << std::endl;

      /*
      // 要求用户输入一行整数后求和
      int sum = 0;

      cout << "请输入一串整数和任意数目的空格: ";

      int number;
      while (cin >> number)
      {
            sum += number;
            while (cin.peek() == ' ')
            {
                  cin.get();
            }
            if (cin.peek() == '\n')
            {
                  break;
            }
      }
      cout << "sum= " << sum << endl;
      // */

      /*
      // cin cout
      const int SIZE = 128;
      char buf[SIZE] = {'\0'};

      cout << "请输入一行文本: ";

      // cin.ignore(7);        //在 cin 输入流 忽略 7个字符
      // cin.getline(buf, 10); //从 cin 输入流 提取 10个字符 流向 buf
      cin.read(buf, 20); //从 cin 输入流 读取 20个字符

      cout << "字符串收集到的字符数为: "
           << cin.gcount() //计数
           << endl;

      cout << "输入的文本信息是: ";

      cout.write(buf, 20); //从 buf 取 20个字符 流向 cout 输出流
      cout << endl;
      cout << buf << endl;
      // */

      /*
      //
      double result = sqrt(3.0);

      cout << "对 3 开方保留小数点后 0~9 位, 结果如下:" << endl;
      int printOnce = 0;
      cout << "默认的输出精度为: " << cout.precision() << ", " << result << endl;
      cout.precision(0);
      for (size_t i = 0; i < 10; i++)
      {
            if (printOnce++ == 0)
            {
                  continue;
            }

            cout << "No." << i << "的输出精度为: " << cout.precision(i) << ", " << result << endl;
            cout.precision(i);
            cout << result << endl;
      }
      cout << "当前的输出精度为: " << cout.precision() << endl;
      // */

      /*
      //
      int width = 4;
      char str[4];

      cout << "请输入一段文本: \n";
      cin.width(5);

      while (cin >> str)
      {
            cout.width(width++);
            cout << str << endl;
            cin.width(5);
      }
      // */

      /*
      // 文件流 读, ifstream
      // ! 文件中的空白字符会被忽略
      ifstream fp_in;
      fp_in.open("FishFile.txt");
      if (!fp_in)
      {
            cerr << "打开文件失败" << endl;
            return 0;
      }
      char ch;
      while (fp_in >> ch)
      {
            cout << ch;
      }
      cout << endl;
      fp_in.close();
      // */

      /*
      // 文件流 写, ofstream
      ofstream fp_out;
      fp_out.open("FishFile.txt");
      if (!fp_out)
      {
            cerr << "打开文件失败" << endl;
            return 0;
      }
      for (int i = 0; i < 12; i++)
      {
            fp_out << i << '\n';
      }
      fp_out << endl;
      fp_out.close();
      // */

      // 几种常见的文件打开模式
      // * ios::in        打开一个可读取文件
      // * ios::out       打开一个可写入文件
      // * ios::binary    以二进制的形式打开一个文件
      // * ios::app       写入的所有数据将被追加到文件的末尾
      // * ios::trunc     删除文件原来已存在的内容
      // * ios::nocreate  如果要打开的文件并不存在,那么以此参数调用open函数将无法进行
      // * ios::noreplace 如果要打开的文件已存在,试图用open函数打开时将返回一个错误

      /*
      // 文件打开模式的使用
      ofstream fp_out("FishFile.txt", ios::app);
      if (!fp_out)
      {
            cerr << "文件打开失败!" << endl;
            return 0;
      }
      for (int i = 0; i < 10; i++)
      {
            fp_out << i;
      }
      fp_out << endl;
      fp_out.close();
      // */

      /*
      // 多个打开模式
      fstream fp("FishFile.txt", ios::in | ios::out);
      if (!fp)
      {
            cerr << "文件打开失败!" << endl;
            return 0;
      }
      fp << "iLoveFishC.com!";
      static char str[100];

      // 使文件指针指向文件头
      fp.seekg(ios::beg);
      // * ios::beg   文件头
      // * ios::end   文件尾

      fp >> str;
      cout << str << endl;
      fp.close();
      // */

      /*   Diy: fileCopy.cpp
      // fileCopy sourceFile destFile
      std::ifstream src;
      std::ofstream dst;
      int data;
      if (argc != 3)
      {
            std::cerr << "./a.out sourceFile destFile" << std::endl;
            return 1;
      }
      src.open(argv[1]);
      if (!src)
      {
            std::cerr << "Can open file: " << argv[1] << std::endl;
            perror("Error info");
            return 1;
      }
      dst.open(argv[2]);
      if (!dst)
      {
            std::cerr << "Can open file: " << argv[2] << std::endl;
            perror("Error info");
            src.close();
            return 1;
      }
      while ((data = src.get()) != EOF)
      {
            dst.put(data);
      }
      if (src.eof())
      {
            std::cout << "success" << std::endl;
      }
      // */

      /*
      !题目 : 向用户提出一个 "Y/N"问题, 然后把用户输入的值赋值给answer变量.
            *要求 : 针对用户输入 'y' / 'n'或者 'Y' / 'N'进行过滤.
      */
      /*
      //     ! 未处理IO缓冲区残留问题
      char answer;
      std::cout << "please enter [y/n]: ";
      std::cin >> answer;
      while ('\n' != std::cin.get())
      {
            continue;
      }
      switch (answer)
      {
      case 'Y':
      case 'y':
            std::cout << "yes" << std::endl;
            break;
      case 'N':
      case 'n':
            std::cout << "no" << std::endl;
            break;
      default:
            std::cout << "loser!" << std::endl;
            break;
      }
      // */

      /*
      ! 题目:
            编写一个"温度单位转换程序",提示用户以 xx.x C 或 xx.x F 的格式输入.
      * F == C * (9.0 / 5.0) + 32
      */
      /*
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;
      double valueInput, valueOutput;
      char typeInput, typeOutput;

      std::cout << "输入格式: xx.x C 或 xx.x F\nplease enter: ";
      std::cin >> valueInput >> typeInput;
      while ('\n' != std::cin.get())
      {
            continue;
      }
      switch (typeInput)
      {
      case 'C':
      case 'c':
            valueOutput = valueInput * RATIO + ADD_SUBTRACT;
            typeOutput = 'F';
            typeInput = 'C';
            break;
      case 'F':
      case 'y':
            valueOutput = (valueInput - ADD_SUBTRACT) / RATIO;
            typeOutput = 'C';
            typeInput = 'F';
            break;
      default:
            typeOutput = 'E';
            break;
      }
      if (typeOutput != 'E')
      {
            std::cout << valueInput << typeInput << '=' << valueOutput << typeOutput << std::endl;
      }
      else
      {
            std::cout << "输入错误!" << std::endl;
      }
      // */

      /*
      ! 对输入数据进行合法性检查
      * std::cin
            * .eof()   如果到达文件(或输入)末尾, 返回true
            * .fail()  如果std::cin无法工作, 返回true
            * .bad()   如果std::cin因为比较严重的原因(例如内存不足)而无法工作, 返回true
            * .good()  如果以上情况都没发生, 返回true
      */

      /*
      ! 题目: 定义一个数组容纳10个整数, 这些整数来自用户输入.我们将计算这些值的 累加和、平均值 并输出.
      */
      /*
      const unsigned short ITEM = 10;

      int num[ITEM];
      int total = 0;

      std::cout << "输入" << ITEM << "个整型数据: ";
      for (int i = 0; i < ITEM; i++)
      {
            while (!(std::cin >> num[i]))
            {
                  // while ('\n' != std::cin.get())
                  // {
                  //       continue;
                  // }  // ? 无法输出下一句的cout

                  std::cin.clear();
                  std::cin.ignore(128, '\n');

                  std::cout << "输入不合法, Retry: ";
            }

            total += num[i];
      }

      std::cout << "总和: " << total << "\n";
      std::cout << "平均值: " << total / 10.0 << "\n";
      // */

      /*
      // 字符串 std::string
      std::string str;
      std::cout << "Enter a string: ";

      // std::cin >> str;     // ! std::cout 不接受空白字符
      std::getline(std::cin, str);

      std::cout << str << std::endl;
      // */

      /*
      // 指针和数组
      const unsigned short ITEMS = 5;

      int intArray[ITEMS] = {1, 2, 3, 4, 5};
      char charArray[ITEMS] = {'F', 'i', 's', 'h', 'C'};

      int *intPtr = intArray;
      char *charPtr = charArray;

      std::cout << "整型数组输出:" << '\n';
      for (int i = 0; i < ITEMS; i++)
      {
            std::cout << *intPtr << " at " << reinterpret_cast<unsigned long>(intPtr) << '\n';
            intPtr++;
      }

      std::cout << "字符型数组输出:" << '\n';
      for (int i = 0; i < ITEMS; i++)
      {
            std::cout << *charPtr << " at " << reinterpret_cast<unsigned long>(charPtr) << '\n';
            charPtr++;
      }
      // std::cout << charPtr << " at " << reinterpret_cast<unsigned long>(charPtr) << std::endl;
      // */

      return 0;
}
