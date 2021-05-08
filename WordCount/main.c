#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int CountWords(char* fileName);     //统计单词数
int CountChars(char* fileName);      //统计字符数

int main(int argc, char* argv[])
{

    if (strcmp(argv[1], "-c") == 0)
    {
        int words = CountWords(argv[2]);
        printf("单词数---%d\n", words);
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        int chars = CountChars(argv[2]);
        printf("字符数---%d\n", chars);
    }
    return 0;
}

int CountWords(char* fileName)
{
    FILE* fp;    //文件指针
    int words = 0;
    char buffer[1024];
    int len = 0;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("error!");
        exit(0);
    }
    while (!feof(fp))
    {
        // fgets() 在读出 1024个字符之前，遇到换行符或EOF则读出结束
        if (fgets(buffer, 1024, fp) != NULL)
        {
            len = strlen(buffer);
            words++;
            for (int i = 0; i < len - 1; i++)//len - 1 是为了去掉换行符所占位置
            {
                if (buffer[i] == ' ')
                {
                    words++;
                }
            }
        }
    }
    fclose(fp);
    return words;
}

int CountChars(char* fileName)
{
    FILE* fp;    //文件指针
    int words = 0;
    int chars = 0;
    char buffer[1024];
    int len = 0;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("error!");
        exit(0);
    }
    while (!feof(fp))
    {
        // fgets() 在读出 1024个字符之前，遇到换行符或EOF则读出结束
        if (fgets(buffer, 1024, fp) != NULL)
        {
            len = strlen(buffer);
            words++;
            for (int i = 0; i < len; i++)
            {
                chars++;
            }
        }
    }
    fclose(fp);
    return chars;
}