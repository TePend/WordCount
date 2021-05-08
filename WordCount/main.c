#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int CountWords(char* fileName);     //ͳ�Ƶ�����
int CountChars(char* fileName);      //ͳ���ַ���

int main(int argc, char* argv[])
{

    if (strcmp(argv[1], "-c") == 0)
    {
        int words = CountWords(argv[2]);
        printf("������---%d\n", words);
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        int chars = CountChars(argv[2]);
        printf("�ַ���---%d\n", chars);
    }
    return 0;
}

int CountWords(char* fileName)
{
    FILE* fp;    //�ļ�ָ��
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
        // fgets() �ڶ��� 1024���ַ�֮ǰ���������з���EOF���������
        if (fgets(buffer, 1024, fp) != NULL)
        {
            len = strlen(buffer);
            words++;
            for (int i = 0; i < len - 1; i++)//len - 1 ��Ϊ��ȥ�����з���ռλ��
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
    FILE* fp;    //�ļ�ָ��
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
        // fgets() �ڶ��� 1024���ַ�֮ǰ���������з���EOF���������
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