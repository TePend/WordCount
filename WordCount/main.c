#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-c") == 0)
    {
        FILE* fp;    //文件指针
        int words = 0;
        char buffer[1024];
        int len = 0;
        fp = fopen(argv[2], "r");
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
        printf("单词数---%d\n", words);
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        FILE* fp;    //文件指针
        int words = 0;
        int chars = 0;
        char buffer[1024];
        int len = 0;
        fp = fopen(argv[2], "r");
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
        printf("字符数---%d\n", chars);
    }
    return 0;
}

