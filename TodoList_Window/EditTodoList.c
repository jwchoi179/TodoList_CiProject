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
    printf("1. ���� ����\n");
    printf("2. ��¥ ����\n");
    printf("3. �߿䵵 ����\n");
    printf("0. �����޴� ����\n");
    printf("\n");

    return;
}

void EditTitle(int LastListIdx)
{
    int selectIdx;
    selectIdx = Select_IDX_In_List(LastListIdx);

    char* input_title = (char*)malloc(SIZE * sizeof(char));

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

    enum
    {
        TITLE = 1,
        DATE,
        IMPORTANCE,
        COLOR,
        TERMINATE = 0
    };

    printf("\n-------���� ����Ǿ� �ִ� �׸��Դϴ�--------\n");
    ShowMyList(LastListIdx);

    while (1)
    {
        if (LastListIdx == 0)
        {
            printf("����Ǿ� �ִ� �� ���� �����ϴ�\n");
            CheckConfimed();
            return;
        }

        ShowModifyMenu();

        printf("���� : ");
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
            printf("������ �Ϸ��Ͻðڽ��ϴ�?\n");
            printf("Ȯ�� : 1, ��� : 0\n");
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
            printf("�߸� �����ϼ̽��ϴ�\n");
            printf("�ٽ� �����Ͻʽÿ�\n");
        }
        printf("\n-------���� ó���� �� �� ���� �Դϴ�-------\n");
        ShowMyList(LastListIdx);
    }
}