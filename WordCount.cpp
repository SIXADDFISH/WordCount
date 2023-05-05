#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STATE_WORD 1
#define STATE_NONWORD 0

int main(int argc, char *argv[])
{
   

    FILE *fp = fopen("D:\\现代软件工程\\word.txt", "r");
    if (fp == NULL)
    {
        printf("打开文件失败：%s\n", "D:\\现代软件工程\\word.txt");
        return 1;
    }

    char c;
    int count = 0, wordCount = 0;
    bool inWord = false;

    while ((c = getc(fp)) != EOF)
    {
        count++;
        if (isspace(c))
        {
            if (inWord)
            {
                inWord = false;
                wordCount++;
            }
        }
        else
        {
            inWord = true;
        }
    }

    if (inWord)  // 处理最后一个单词
    {
        wordCount++;
    }

    printf("字符数：%d，单词数：%d\n", count, wordCount);
    fclose(fp);
    return 0;
}
