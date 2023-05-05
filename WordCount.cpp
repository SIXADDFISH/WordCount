#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STATE_WORD 1
#define STATE_NONWORD 0

int main(int argc, char *argv[])
{
   

    FILE *fp = fopen("D:\\�ִ��������\\word.txt", "r");
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�%s\n", "D:\\�ִ��������\\word.txt");
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

    if (inWord)  // �������һ������
    {
        wordCount++;
    }

    printf("�ַ�����%d����������%d\n", count, wordCount);
    fclose(fp);
    return 0;
}
