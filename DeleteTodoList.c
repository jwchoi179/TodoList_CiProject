#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "BasicInfo.h"
#include "DeleteTodoList.h"

void DeleteTodoList(int ListNum)
{
    if (ListNum == 0)
    {
        printf("\n������ ������ �����ϴ�. \n");
        return;
    }

    ShowMyList(ListNum);

    int num;
    while (1)
    {
        printf("������ ������ ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &num);

        if (num < 1 || num > ListNum)
        {
            printf("������ ã�� ���Ͽ����ϴ�. \n");
            printf("�ٽ� �����ϼ���. \n");
        }
        else
        {
            break;
        }
    }

    num -= 1;

    printf("\n�ش� ������ �����߽��ϴ�.\n");
    ShowTodoList(num);

    for (int i = num; i < ListNum - num; ++i)
    {
        myList[i] = myList[i + 1];
    }
}