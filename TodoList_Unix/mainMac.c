#include <stdio.h>
#include <stdlib.h>
#include "BasicInfoMac.h"
#include "InputTodoListMac.h"
#include "CompleteCheckMac.h"
#include "EditTodoListMac.h"
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

int ListNum = 0, CompNum = 0; // 완료처리한 항목들을 저장하는 배열의 인덱스

int main()
{
    int choice;

    DataInit();

    while (1)
    {
        ShowMenu();
        printf("선택 : ");
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
            printf("잘못 선택하셨습니다.\n");
            printf("다시 선택하십시오\n");
        }
    }
}