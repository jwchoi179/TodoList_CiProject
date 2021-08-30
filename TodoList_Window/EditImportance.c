#include "BasicInfo.h"
#include "EditImportance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ChooseImportanceMenu(int selectIdx)
{
    char choice;
    int *importance;

    if (myList[selectIdx].Importance.ImportanceChecker == 0)
    {
        printf("���� ����� �߿䵵�� �����ϴ�.\n");
        printf("\n");
        printf("�߿䵵�� ���� �߰��Ͻðڽ��ϱ�? (y/n)\n");
        printf("���� : ");

        getchar();

        scanf("%c", &choice);

        if (choice == 'y')
        {
            importance = (int *)malloc(sizeof(int));
            while (1)
            {
                printf("\n");
                printf("���ο� �߿䵵�� �ο��Ͻʽÿ�. (1, 2, 3)\n");
                printf("���� : ");

                getchar();

                scanf("%d", importance);
                if (*importance == 1 || *importance == 2 || *importance == 3)
                {
                    myList[selectIdx].Importance.importance = *importance;
                    myList[selectIdx].Importance.ImportanceChecker = 1;
                    break;
                }
                else
                {
                    printf("��ȿ���� ���� �����Դϴ�\n");
                    printf("\n");
                }
            }

            free(importance);
            return;
        }
        else if (choice == 'n')
        {
            printf("�߿䵵�� �������� �ʾҽ��ϴ�\n");
            printf("���� ���� ȭ������ ���ư��ϴ�");
            return;
        }
    }
    else if (myList[selectIdx].Importance.ImportanceChecker == 1)
    {
        while (1)
        {
            printf("���� ����� �߿䵵�� �ֽ��ϴ�.\n");
            printf("���� ����� �߿䵵�� %d�Դϴ�\n", myList[selectIdx].Importance.importance);
            printf("�߿䵵�� �����Ͻðڽ��ϱ�?\n");
            printf("���� (y/n) : ");

            getchar();

            scanf("%c", &choice);

            if (choice == 'y')
            {
                int choice_menu;

                printf("------Menu------\n");
                printf("1. ���� ����� �߿䵵�� ����\n");
                printf("2. ���� ����� �߿䵵�� ����\n");
                printf("���� (1 or 2) : ");

                getchar();

                scanf("%d", &choice_menu);

                if (choice_menu == 1)
                {
                    importance = (int *)malloc(sizeof(int));

                    printf("���� ����� �߿䵵�� �����մϴ�\n");
                    while (1)
                    {
                        printf("���� �ο��� �߿䵵�� �Է��ϼ��� : ");
                        scanf("%d", importance);
                        if (*importance == 1 || *importance == 2 || *importance == 3)
                        {
                            myList[selectIdx].Importance.importance = *importance;
                            break;
                        }
                        else
                            printf("��ȿ���� ���� �����Դϴ�\n");
                    }

                    free(importance);
                    return;
                }
                else if (choice_menu == 2)
                {
                    printf("���� ����� �߿䵵�� �����մϴ�\n");
                    myList[selectIdx].Importance.ImportanceChecker = 0;
                    return;
                }
                else
                {
                    printf("�߸��� �����Դϴ�.\n");
                    printf("�ٽ� �����ϼ���\n");
                }
            }
            else if (choice == 'n')
            {
                printf("�߿䵵�� �������� �ʾҽ��ϴ�\n");
                return;
            }
        }
    }
}

void EditImportance(int LastListIdx)
{
    int selectIdx;
    selectIdx = myList->TemporaryIdx;

    ChooseImportanceMenu(selectIdx);
    return;
}