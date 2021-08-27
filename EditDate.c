#define _CRT_SECURE_NO_WARNINGS

#include "BasicInfo.h"
#include "EditDate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MakeNewDate(int selectIdx)
{
    int month;
    int day;

    printf("추가하고자 하는 날짜의 달(Month)를 입력 : ");

    getchar();

    scanf("%d", &month);

    printf("추가하고자 하는 날짜의 일(Day)를 입력 : ");

    getchar();

    scanf("%d", &day);

    myList[selectIdx].Date.date.month = month;
    myList[selectIdx].Date.date.day = day;

    myList[selectIdx].Date.DateChecker = 1;

    printf("추가한 날짜는 %d월 %d일 입니다\n",
           myList[selectIdx].Date.date.month, myList[selectIdx].Date.date.day);
}

void ModifyDate(int selectIdx)
{
    int choice;
    int month;
    int day;

    printf("현재 저장된 날짜가 있습니다.");
    printf("현재 저장된 날짜는 %d월 %d일 입니다\n",
           myList[selectIdx].Date.date.month, myList[selectIdx].Date.date.day);

    printf("1. 현재 저장된 날짜를 수정\n");
    printf("2. 현재 저장된 날짜를 삭제\n");
    printf("선택 (1 or 2) : ");

    getchar();

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("현재 저장된 날짜를 수정합니다\n");
        printf("수정하고 싶은 날짜 입력\n");
        printf("월(Month) : ");

        getchar();

        scanf("%d", &month);

        printf("일(Day) : ");

        getchar();

        scanf("%d", &day);

        myList[selectIdx].Date.date.month = month;
        myList[selectIdx].Date.date.day = day;
    }
    else if (choice == 2)
    {
        printf("현재 저장된 날짜를 삭제합니다\n");
        myList[selectIdx].Date.DateChecker = 0;
    }
}

void EditDate(int LastListIdx)
{
    int selectIdx;
    selectIdx = Select_IDX_In_List(LastListIdx);

    if (myList[selectIdx].Date.DateChecker == 0) // 생성된 날짜가 없는 경우
    {
        char make_choice;

        while (1)
        {
            printf("현재 저장된 날짜가 없습니다\n");
            printf("날짜를 새로 만드시겠습니까? (y/n)\n");
            printf("선택 : ");

            getchar();

            scanf("%c", &make_choice);

            if (make_choice == 'y')
            {
                MakeNewDate(selectIdx);
                return;
            }
            else if (make_choice == 'n')
            {
                printf("날짜를 수정하지 않았습니다\n");
                printf("수정 선택 화면으로 돌아갑니다\n");
                return;
            }
            else
            {
                printf("잘못입력하셨습니다\n");
                printf("다시 선택합니다\n");
            }
        }
    }
    else if (myList[selectIdx].Date.DateChecker == 1) // 날짜가 존재하는 경우
    {
        char modify_choice;
        while (1)
        {
            printf("현재 저장된 날짜가 있습니다\n");
            printf("날짜를 수정하시겠습니까? (y/n)\n");
            printf("선택 : ");

            getchar();

            scanf("%c", &modify_choice);

            if (modify_choice == 'y')
            {
                ModifyDate(selectIdx);
                return;
            }
            else if (modify_choice == 'n')
            {
                printf("날짜를 수정하지 않았습니다\n");
                printf("수정 선택 화면으로 돌아갑니다");
                return;
            }
            else
            {
                printf("잘못입력하셨습니다\n");
                printf("다시 선택합니다\n");
            }
        }
    }
}