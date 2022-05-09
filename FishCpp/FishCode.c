// * /FishCpp/main.cpp 的C语言写法.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
      /*
      // 要求用户输入一行整数后求和
      int number = 0;
      char ch;
      int sum = 0;
      while (scanf("%d", &number) == 1)
      {
            sum += number;

            while ((ch = getchar()) == ' ') //屏蔽空格
            {
                  ;
            }

            if (ch == '\n')
            // if ((ch = getchar()) == '\n')
            {
                  break;
            }

            ungetc(ch, stdin); //将变量 ch 储存的字符退回 stdin 输入流
      }
      printf("sum= %d\n", sum);
      // */

      /*
      // 复制文件
      // fileCopy sourceFile destFile
      FILE *input, *output;
      int data;

      if (argc != 3)
      {
            fprintf(stderr, "输入形式: FishCode sourceFile destFile\n");
            exit(EXIT_FAILURE);
      }

      if ((input = fopen(argv[1], "rb")) == NULL)
      {
            fprintf(stderr, "can't open file: %s\n", argv[1]);
            exit(EXIT_FAILURE);
      }

      if ((output = fopen(argv[2], "wb")) == NULL)
      {
            fprintf(stderr, "can't open file: %s\n", argv[2]);
            fclose(input);
            exit(EXIT_FAILURE);
      }

      while ((data = getc(input)) != EOF)
      {
            if (putc(data, output) == EOF)
            {
                  break;
            }
      }

      if (ferror(input))
      {
            printf("read file %s been bad!\n", argv[1]);
      }

      if (ferror(output))
      {
            printf("write file %s been bad!\n", argv[2]);
      }

      printf("success\n");

      fclose(input);
      fclose(output);
      // */

      /*
      // 结构体
      struct FishOil // 理应写在main外的声明
      {
            char name[20];
            char uid[20];
            char sex;
      };
      struct FishOil jiaYv;
      // */

      // /*
      // 
      // */
      return 0;
}
