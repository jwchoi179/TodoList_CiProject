#define _CRT_SECURE_NO_WARNINGS

#include "BasicInfo.h"
#include "EditDate.h"
#include "EditImportance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowModifyMenu()
{
    printf("\n");
    printf("--------Menu--------\n");
    printf("1. 제목 수정\n");
    printf("2. 날짜 수정\n");
    printf("3. 중요도 수정\n");
    printf("0. 수정메뉴 종료\n");
    printf("\n");

    return;
}

void EditTitle(int LastListIdx)
{
    int selectIdx;
    selectIdx = Select_IDX_In_List(LastListIdx);

    char* input_title = (char*)malloc(SIZE * sizeof(char));

    printf("\n");
    printf("수정하고 싶은 제목을 입력하세요\n");
    printf("입력 : ");
    getchar();
    scanf("%[^\n]", input_title);

    strcpy(myList[selectIdx].Title, input_title);

    free(input_title);
}

void EditTodoList(int LastListIdx)
{
    int choice;
    int answer;

    enum
    {
        TITLE = 1,
        DATE,
        IMPORTANCE,
        COLOR,
        TERMINATE = 0
    };

    printf("\n-------현재 저장되어 있는 항목입니다--------\n");
    ShowMyList(LastListIdx);

    while (1)
    {
        if (LastListIdx == 0)
        {
            printf("저장되어 있는 할 일이 없습니다\n");
            CheckConfimed();
            return;
        }

        ShowModifyMenu();

        printf("선택 : ");
        getchar();
        scanf("%d", &choice);

        switch (choice)
        {
        case TITLE:
            EditTitle(LastListIdx);
            break;

        case DATE:
            EditDate(LastListIdx);
            break;

        case IMPORTANCE:
            EditImportance(LastListIdx);
            break;

        case TERMINATE:
            printf("수정을 완료하시겠습니다?\n");
            printf("확인 : 1, 취소 : 0\n");
            scanf("%d", &answer);

            if (answer == 1)
            {
                return;
            }
            else
            {
                continue;
            }

        default:
            printf("잘못 선택하셨습니다\n");
            printf("다시 선택하십시오\n");
        }
        printf("\n-------수정 처리된 할 일 내역 입니다-------\n");
        ShowMyList(LastListIdx);
    }
}