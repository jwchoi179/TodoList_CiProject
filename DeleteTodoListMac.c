#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "BasicInfo.h"
#include "DeleteTodoList.h"

void DeleteTodoList(int ListNum)
{
    if (ListNum == 0)
    {
        printf("\n삭제할 일정이 없습니다. \n");
        return;
    }

    ShowMyList(ListNum);

    int num;
    while (1)
    {
        printf("삭제할 일정의 번호를 입력하세요 : ");
        scanf("%d", &num);

        if (num < 1 || num > ListNum)
        {
            printf("일정을 찾지 못하였습니다. \n");
            printf("다시 선택하세요. \n");
        }
        else
        {
            break;
        }
    }

    num -= 1;

    printf("\n해당 일정을 삭제했습니다.\n");
    ShowTodoList(num);

    for (int i = num; i < ListNum - num; ++i)
    {
        myList[i] = myList[i + 1];
    }
}