#include <stdio.h>
#include <stdlib.h>
#include "BasicInfo.h"
#include "InputTodoList.h"
#include "CompleteCheck.h"
#include "EditTodoList.h"
#include "DeleteTodoListMac.h"

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
    int comchecker, deletechecker;

    DataInit();

    while (1)
    {
        system("clear");
        if (ListNum != 0)
        {
            ShowMyList(ListNum);
        }

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
            comchecker = CompleteCheck(ListNum, CompNum);
            if (comchecker == 1)
            {
                continue;
            }
            else
            {
                --ListNum;
                ++CompNum;
            }
            break;

        case (MODIFY):
            EditTodoList(ListNum);
            break;

        case (DELETE):
            deletechecker = DeleteTodoList(ListNum);
            if (deletechecker == 1)
            {
                continue;
            }
            else
            {
                --ListNum;
            }
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