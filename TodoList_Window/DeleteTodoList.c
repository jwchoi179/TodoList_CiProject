#include <stdio.h>
#include <stdlib.h>
#include "BasicInfo.h"
#include "DeleteTodoList.h"

int DeleteTodoList(int ListNum) //int������ ����
{
    system("clear");

    if (ListNum == 0)
    {
        printf("\n������ ������ �����ϴ�. \n");
        printf("\n");
        CheckConfimed();
        return 1; // �߰�
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

    // ���� ó�� ��Ȯ�� ����

    printf("\n�ش� ������ �����߽��ϴ�.\n");
    ShowTodoList(num);

    for (int i = num; i < ListNum - num; ++i)
    {
        myList[i] = myList[i + 1];
    }
    return 0; //�߰�
}