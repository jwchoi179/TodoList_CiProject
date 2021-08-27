#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include "CompleteCheck.h"
#include "BasicInfo.h"

void CompleteCheck(int ListNum, int CompNum)
{
    if (ListNum == 0)
    {
        printf("�Ϸ�ó���� ������ �����ϴ�.\n");
        return;
    }

    CompleteLoop(ListNum, CompNum);
}

// �ǵ� : �� ���� �Ϸ�ó���ϴ� �Լ�
void CompleteLoop(int ListNum, int CompNum)
{
    int choice;

    while (1)
    {
        ShowMyList(ListNum);

        printf("�Ϸ�ó���� ������ ��ȣ�� �Է����ּ���: ");
        scanf("%d", &choice);
        printf("\n");

        // ���ڿ� ���� �Լ��� title�� ������ �ִ��� �Ǵ�

        if (choice > ListNum)
        {
            printf("�ش� ��ȣ�� �Ϸ��� ������ �����ϴ�.\n");
            printf("�ٽ� �����ϼ���\n");
            continue;
        }
        else if (choice <= ListNum)
        {
            break;
        }
    }

    choice -= 1;

    myCompList[CompNum] = myList[choice]; // �Ϸ� ó���� �׸���� �����ϴ� ����

    // �� ������ �۾�
    for (int i = choice; i < ListNum - choice; i++)
    {
        myList[i] = myList[i + 1];
    }
}

void ShowCompList(int idx)
{
    printf("\n");

    printf("�׸� ��ȣ : %d\n", idx + 1);
    printf("�� �� �̸� : %s\n", myCompList[idx].Title);

    if (myCompList[idx].Date.DateChecker == 1)
        printf("��¥ : %d�� %d��\n", myCompList[idx].Date.date.month, myCompList[idx].Date.date.day);

    if (myCompList[idx].Importance.ImportanceChecker == 1)
        printf("�߿䵵 : %d\n", myCompList[idx].Importance.importance);

    printf("\n");
}

void ShowMyCompList(int CompNum)
{
    for (int i = 0; i < CompNum; ++i)
    {
        ShowCompList(i);
    }
}