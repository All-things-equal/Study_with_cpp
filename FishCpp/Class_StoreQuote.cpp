/* 构造器 和 析构器 */

#include <iostream>
#include <string>
#include <fstream>

class StoreQuote
{
private:
public:
      std::string quote;
      std::string speaker;
      std::ofstream fileOutput;

      StoreQuote(void);
      ~StoreQuote();

      void InputQuote(void);
      void InputSpeaker(void);
      bool Write(void);
};

StoreQuote::StoreQuote(void)
{
      fileOutput.open("test.txt", std::ios::app);
}

StoreQuote::~StoreQuote()
{
      fileOutput.close();
}

void StoreQuote::InputQuote(void)
{
      std::getline(std::cin, quote);
}

void StoreQuote::InputSpeaker(void)
{
      std::getline(std::cin, speaker);
}

bool StoreQuote::Write(void)
{
      if (fileOutput.is_open())
      {
            fileOutput << quote << "|" << speaker << "\n";
            return true;
      }
      else
      {
            return false;
      }
}

int main(int argc, char const *argv[])
{
      StoreQuote quote;

      std::cout << "请输入一句名言: ";
      quote.InputQuote();

      std::cout << "请输入作者: ";
      quote.InputSpeaker();

      if (quote.Write())
      {
            std::cout << "成功写入文件^_^\n";
      }
      else
      {
            std::cout << "写入文件失败T_T\n";
            return 1;
      }

      return 0;
}
