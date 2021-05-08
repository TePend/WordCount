#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-c") == 0)
    {
        FILE* fp;    //�ļ�ָ��
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
        printf("������---%d\n", words);
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        FILE* fp;    //�ļ�ָ��
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
        printf("�ַ���---%d\n", chars);
    }
    return 0;
}

