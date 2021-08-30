#include "BasicInfo.h"
#include "EditDate.h"
#include "EditImportance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowModifyMenu()
{
    // printf("\n");
    printf("-------------------Menu-------------------\n");
    printf("1. ���� ����\n");
    printf("2. ��¥ ����\n");
    printf("3. �߿䵵 ����\n");
    printf("0. �����޴� ����\n");
    printf("\n");

    return;
}

int ShowChooseMenu(int ListNum)
{
    int choice;

    while (1)
    {
        system("clear");
        printf("1. �׸� ��ȣ �����ϱ�\n");
        printf("2. ���� ��� ����\n");
        printf("���� : ");

        getchar();

        scanf("%d", &choice);

        if (choice == 1)
        {
            Select_IDX_In_List(ListNum);
            return 0;
        }
        else if (choice == 2)
        {
            return 1;
        }
        else
        {
            printf("\n");
            printf("�߸������ϼ̽��ϴ�\n");
            CheckConfimed();
        }
    }
}

void EditTitle(int LastListIdx)
{
    int selectIdx;
    selectIdx = myList->TemporaryIdx;
    // (8 29 �߰�) strcpy�� ������ ����Ʈ ��ȣ�� Select �Լ��� ����پ� -> Select �Լ����� ������ ����ü ������ ����پ�

    char *input_title = (char *)malloc(SIZE * sizeof(char));

    printf("\n");
    printf("�����ϰ� ���� ������ �Է��ϼ���\n");
    printf("�Է� : ");
    getchar();
    scanf("%[^\n]", input_title);

    strcpy(myList[selectIdx].Title, input_title);

    free(input_title);
}

void EditTodoList(int LastListIdx)
{
    int choice;
    int answer;
    int result;
    int temp;

    enum
    {
        TITLE = 1,
        DATE,
        IMPORTANCE,
        COLOR,
        TERMINATE = 0
    };

    system("clear");

    if (LastListIdx != 0)
    {
        printf("\n-------���� ����Ǿ� �ִ� �׸��Դϴ�--------\n");
    }

    // (8 29 �߰�) showmyList �Լ� ����(2�� �߿� 1������ ����)
    while (1)
    {
        if (LastListIdx == 0)
        {
            printf("����Ǿ� �ִ� �� ���� �����ϴ�\n");
            printf("\n");
            CheckConfimed();
            return;
        }
        // (8 29 �߰�) Select �Լ� �߰�, ������ Edit~ �Լ� �ȿ� �ִ� ���� �� ��)
        result = ShowChooseMenu(LastListIdx);

        if (result == 1)
        {
            return;
        }

        system("clear");

        while (1)
        {
            system("clear");

            ShowTodoList(myList->TemporaryIdx);

            ShowModifyMenu();

            printf("���� : ");
            getchar();
            scanf("%d", &choice);

            if (choice == TITLE)
            {
                EditTitle(LastListIdx);
            }
            else if (choice == DATE)
            {
                EditDate(LastListIdx);
            }
            else if (choice == IMPORTANCE)
            {
                EditImportance(LastListIdx);
            }
            else if (choice == TERMINATE)
            {
                printf("\n");
                printf("������ �Ϸ��Ͻðڽ��ϴ�?\n");
                printf("Ȯ�� : 1, ��� : 0\n");
                scanf("%d", &answer);

                if (answer == 1)
                {
                    break;
                }
                else
                    continue;
            }
            else
            {
                printf("�߸� �����ϼ̽��ϴ�\n");
                printf("�ٽ� �����Ͻʽÿ�\n");
            }
        }

        printf("\n-------���� ó���� �� �� ���� �Դϴ�-------\n");
        ShowTodoList(myList->TemporaryIdx);
        CheckConfimed();
    }
}