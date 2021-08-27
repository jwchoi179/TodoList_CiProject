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

    printf("�߰��ϰ��� �ϴ� ��¥�� ��(Month)�� �Է� : ");

    getchar();

    scanf("%d", &month);

    printf("�߰��ϰ��� �ϴ� ��¥�� ��(Day)�� �Է� : ");

    getchar();

    scanf("%d", &day);

    myList[selectIdx].Date.date.month = month;
    myList[selectIdx].Date.date.day = day;

    myList[selectIdx].Date.DateChecker = 1;

    printf("�߰��� ��¥�� %d�� %d�� �Դϴ�\n",
           myList[selectIdx].Date.date.month, myList[selectIdx].Date.date.day);
}

void ModifyDate(int selectIdx)
{
    int choice;
    int month;
    int day;

    printf("���� ����� ��¥�� �ֽ��ϴ�.");
    printf("���� ����� ��¥�� %d�� %d�� �Դϴ�\n",
           myList[selectIdx].Date.date.month, myList[selectIdx].Date.date.day);

    printf("1. ���� ����� ��¥�� ����\n");
    printf("2. ���� ����� ��¥�� ����\n");
    printf("���� (1 or 2) : ");

    getchar();

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("���� ����� ��¥�� �����մϴ�\n");
        printf("�����ϰ� ���� ��¥ �Է�\n");
        printf("��(Month) : ");

        getchar();

        scanf("%d", &month);

        printf("��(Day) : ");

        getchar();

        scanf("%d", &day);

        myList[selectIdx].Date.date.month = month;
        myList[selectIdx].Date.date.day = day;
    }
    else if (choice == 2)
    {
        printf("���� ����� ��¥�� �����մϴ�\n");
        myList[selectIdx].Date.DateChecker = 0;
    }
}

void EditDate(int LastListIdx)
{
    int selectIdx;
    selectIdx = Select_IDX_In_List(LastListIdx);

    if (myList[selectIdx].Date.DateChecker == 0) // ������ ��¥�� ���� ���
    {
        char make_choice;

        while (1)
        {
            printf("���� ����� ��¥�� �����ϴ�\n");
            printf("��¥�� ���� ����ðڽ��ϱ�? (y/n)\n");
            printf("���� : ");

            getchar();

            scanf("%c", &make_choice);

            if (make_choice == 'y')
            {
                MakeNewDate(selectIdx);
                return;
            }
            else if (make_choice == 'n')
            {
                printf("��¥�� �������� �ʾҽ��ϴ�\n");
                printf("���� ���� ȭ������ ���ư��ϴ�\n");
                return;
            }
            else
            {
                printf("�߸��Է��ϼ̽��ϴ�\n");
                printf("�ٽ� �����մϴ�\n");
            }
        }
    }
    else if (myList[selectIdx].Date.DateChecker == 1) // ��¥�� �����ϴ� ���
    {
        char modify_choice;
        while (1)
        {
            printf("���� ����� ��¥�� �ֽ��ϴ�\n");
            printf("��¥�� �����Ͻðڽ��ϱ�? (y/n)\n");
            printf("���� : ");

            getchar();

            scanf("%c", &modify_choice);

            if (modify_choice == 'y')
            {
                ModifyDate(selectIdx);
                return;
            }
            else if (modify_choice == 'n')
            {
                printf("��¥�� �������� �ʾҽ��ϴ�\n");
                printf("���� ���� ȭ������ ���ư��ϴ�");
                return;
            }
            else
            {
                printf("�߸��Է��ϼ̽��ϴ�\n");
                printf("�ٽ� �����մϴ�\n");
            }
        }
    }
}