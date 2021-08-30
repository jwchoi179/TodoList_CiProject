#include "BasicInfo.h"
#include "EditDate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MakeNewDate(int selectIdx)
{
    int month;
    int day;
    while (1)
    {
        printf("\n");
        printf("�߰��ϰ��� �ϴ� ��¥�� �Է����ּ���. [ex) 3 29]\n");

        getchar();

        scanf("%d %d", &month, &day);

        if (!month || !day)
        {
            printf("\n");
            printf("�߸��� �����Դϴ�.\n");
            printf("�ٽ��Է����ּ���.\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }

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

    printf("\n");
    printf("���� ����� ��¥�� �ֽ��ϴ�.\n");
    printf("���� ����� ��¥�� %d�� %d�� �Դϴ�\n",
           myList[selectIdx].Date.date.month, myList[selectIdx].Date.date.day);

    printf("\n");
    printf("1. ���� ����� ��¥�� ����\n");
    printf("2. ���� ����� ��¥�� ����\n");
    printf("���� (1 or 2) : ");

    getchar();

    scanf("%d", &choice);

    if (choice == 1)
    {
        while (1)
        {
            printf("\n");
            printf("���� ����� ��¥�� �����մϴ�\n");
            printf("�����ϰ� ���� ��¥�� �Է��ϼ���. [ex) 03 30]\n");

            getchar();

            scanf("%d %d", &month, &day);

            if (!month || !day)
            {
                printf("\n");
                printf("�߸��� �����Դϴ�.\n");
                printf("�ٽ��Է����ּ���.\n");
                while (getchar() != '\n')
                    ;
            }
            else
            {
                break;
            }
        }

        myList[selectIdx].Date.date.month = month;
        myList[selectIdx].Date.date.day = day;
    }
    else if (choice == 2)
    {
        printf("\n");
        printf("���� ����� ��¥�� �����մϴ�\n");
        myList[selectIdx].Date.DateChecker = 0;
    }
}

void EditDate(int LastListIdx)
{
    int selectIdx;
    selectIdx = myList->TemporaryIdx;

    if (myList[selectIdx].Date.DateChecker == 0) // ������ ��¥�� ���� ���
    {
        char make_choice;

        while (1)
        {
            printf("\n");
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
                printf("�߸� �Է��ϼ̽��ϴ�\n");
                printf("�ٽ� �����մϴ�\n");
                while (getchar() != '\n')
                    ;
                printf("�ƹ�Ű�� �Է� �� ���͸� �����ּ���.\n");
                getchar();
            }
        }
    }
    else if (myList[selectIdx].Date.DateChecker == 1) // ��¥�� �����ϴ� ���
    {
        char modify_choice;
        while (1)
        {
            printf("\n");
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