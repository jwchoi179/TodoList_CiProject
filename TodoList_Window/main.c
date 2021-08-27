#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BasicInfo.h"
#include "InputTodoList.h"
#include "CompleteCheck.h"
#include "EditTodoList.h"
#include "DeleteTodoList.h"
#pragma warning(disable : 4996)

enum
{
    INPUT = 1,
    COMPLETEDCHECK,
    MODIFY,
    DELETE,
    SHOWLIST,
    SHOWCOMPLIST,
    TERMINATE = 0
};

int ListNum = 0, CompNum = 0; // �Ϸ�ó���� �׸���� �����ϴ� �迭�� �ε���

int main()
{
    int choice;

    DataInit();

    while (1)
    {
        ShowMenu();
        printf("���� : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case (INPUT):
            INPUT_Function(ListNum);
            ++ListNum;
            break;

        case (COMPLETEDCHECK):
            CompleteCheck(ListNum, CompNum);
            --ListNum;
            ++CompNum;
            break;

        case (MODIFY):
            EditTodoList(ListNum);
            break;

        case (DELETE):
            DeleteTodoList(ListNum);
            --ListNum;
            break;

        case (SHOWLIST):
            ShowMyList(ListNum);
            CheckConfimed();
            break;

        case (SHOWCOMPLIST):
            ShowMyCompList(CompNum);
            CheckConfimed();
            break;

        case (TERMINATE):
            return 0;

        default:
            printf("�߸� �����ϼ̽��ϴ�.\n");
            printf("�ٽ� �����Ͻʽÿ�\n");
        }
    }
}