#include "BasicInfo.h"
#include <stdio.h>
#include <stdlib.h>

void DataInit()
{
    for (int i = 0; i < SIZE; ++i)
    {
        myList[i].Importance.importance = 0;
        myList[i].Importance.ImportanceChecker = 0;
        myList[i].Date.DateChecker = 0;
    }
}

void ShowMenu()
{
    // printf("\n");
    printf("----------------Menu----------------\n");
    printf("1. �� �� �Է��ϱ�\n");
    printf("2. �� �� �Ϸ� üũ�ϱ�\n");
    printf("3. �� �� �����ϱ�\n");
    printf("4. �� �� �����ϱ�\n");
    printf("5. ���� ���� �� �� ���\n");
    printf("6. �Ϸ�� ���� ���\n");
    printf("0. ���α׷� ����\n");
    printf("\n");

    return;
}

void ShowTodoList(int idx)
{
    printf("\n");

    printf("�׸� ��ȣ : %d\n", idx + 1);
    printf("�� �� �̸� : %s\n", myList[idx].Title);

    if (myList[idx].Date.DateChecker == 1)
        printf("��¥ : %d�� %d��\n", myList[idx].Date.date.month, myList[idx].Date.date.day);

    if (myList[idx].Importance.ImportanceChecker == 1)
        printf("�߿䵵 : %d\n", myList[idx].Importance.importance);

    printf("\n");
}

int ShowMyList(int ListNum)
{
    system("cls");
    int check;

    if (ListNum == 0)
    {
        printf("���� ���� �� ���� �����ϴ�\n");
        printf("\n");

        return -1;
    }

    for (int i = 0; i < ListNum; ++i)
    {
        ShowTodoList(i);
    }

    return 0;
}

void Select_IDX_In_List(int LastListIdx)
{
    int selectNum;

    ShowMyList(LastListIdx);
    printf("���� or ���� or �Ϸ�ó���� �ϰ� ���� �׸��� ��ȣ�� �Է��ϼ��� : ");

    getchar();

    scanf("%d", &selectNum);

    if (selectNum - 1 <= LastListIdx)
    {
        myList->TemporaryIdx = selectNum - 1;
    }
    else
    {
        printf("�ش� �׸��� �����ϴ�\n");
    }
}

void ShowRestWork(int ListNum)
{
    if (ListNum == 0)
    {
        return;
    }
    else
    {
        printf("���� �� ���Դϴ�\n");
        printf("\n");
        ShowMyList(ListNum);
    }
}

void CheckConfimed()
{
    int check;
    while (1)
    {
        printf("Ȯ���ϼ����� 1�� �Է����ּ��� : ");

        getchar();

        scanf("%d", &check);

        if (check == 1)
            return;
        else
        {
            printf("�ٽ� �������ּ���\n");
            printf("\n");
            continue;
        }
    }
}