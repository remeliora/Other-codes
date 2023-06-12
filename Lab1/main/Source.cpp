#include <matrix.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void printhelp()
{
    printf("�������\n -c <��� �����>\n -f <����� ���������>\n -n <�������� (-'add';-'min';-'max')>\n");
}

void printerror()
{
    printf("������\n -h - ����� �������\n");
}

int main(int argc, char* argv[])
{
    mtrx a;
    char name[100] = "";
    int num = 5;
    char op[4] = "";

    int rs;
    //opterr = 0;
    while ((rs = getopt(argc, argv, ":c:f:n:h")) != -1)
        switch (rs)
        {
        case 'c': strcpy(name, optarg); break;
        case 'f': num = atoi(optarg); break;
        case 'n': strcpy(op, optarg); break;
        case 'h': printhelp(); return 0;
        default: printerror(); return 1;
        }
    printf("%s\n", name);
    printf("%d\n", num);
    printf("%s\n", op);
    if (name[0] == 0)
    {
        printerror();
        return 1;
    }
    if (!((strcmp(op, "add") == 0) || (strcmp(op, "min") == 0) || (strcmp(op, "max") == 0)))
    {
        printerror();
        return 1;
    }
    if (op[3] != 0)
    {
        printerror();
        return 1;
    }
    if ((num < 1) || (num > 4))
    {
        printerror();
        return 1;
    }
    if (readfile(name, &a) != 0)
    {
        printf("������ ������\n");
        return 1;
    }

    if (strcmp(op, "add") == 0)
    {
        printf("����� ����� %f\n", add(&a, num));
        return 0;
    }

    if (strcmp(op, "min") == 0)
    {
        printf("������� ����� %f\n", min(&a, num));
        return 0;
    }

    if (strcmp(op, "max") == 0)
    {
        printf("�������� ����� %f\n", max(&a, num));
        return 0;
    }
}
