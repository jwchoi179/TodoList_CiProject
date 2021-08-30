#include "BasicInfo.h"
#include "InputTodoList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Input_Title(int LastListIdx)
{
	char Title[100] = {'\0'};
	printf("������ �Է����ּ���.\n");
	getchar();
	scanf("%[^\n]", Title); // ��������, ���� ��ü

	strcpy(myList[LastListIdx].Title, Title);
}

void Input_Date(int LastListIdx)
{
	char dateset;
	int check;
	int month, day;
	while (1)
	{

		printf("\n");
		printf("��¥�� �����Ͻðڽ��ϱ�? [y / n]\n");
		getchar();
		scanf("%c", &dateset);

		if (dateset == 'y')
		{
			while (1)
			{
				printf("\n");
				printf("��¥�� �Է����ּ���. [ex) 3 29]\n");

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

			myList[LastListIdx].Date.date.month = month;
			myList[LastListIdx].Date.date.day = day;

			myList[LastListIdx].Date.DateChecker = 1;
			break;
		}
		else if (dateset == 'n')
		{
			myList[LastListIdx].Date.DateChecker = 0;
			break;
		}
		else
		{
			printf("\n");
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			printf("�ٽ� �������ּ���.\n");
			while (getchar() != '\n')
				;
			printf("�ƹ�Ű�� �Է� �� ���͸� �����ּ���.\n");
			getchar();
		}
	}
}

void Set_Importance(int LastListIdx)
{
	char importanceset;
	int importance;
	while (1)
	{
		printf("\n");
		printf("�߿䵵�� �����Ͻðڽ��ϱ�? [y / n]\n");

		getchar();

		scanf("%c", &importanceset);
		if (importanceset == 'y')
		{
			while (1)
			{
				printf("\n");
				printf("�߿䵵�� ���Դϱ�? [1 / 2 / 3]\n");
				getchar();

				scanf("%d", &importance);

				if (!importance)
				{
					printf("\n");
					printf("�߸��� �����Դϴ�.\n");
					printf("�ٽ��Է����ּ���.\n");
					while (getchar() != '\n')
						;
				}
				else
				{
					if (importance == 1 || importance == 2 || importance == 3)
					{
						myList[LastListIdx].Importance.importance = importance;
						myList[LastListIdx].Importance.ImportanceChecker = 1;
						break;
					}
					else
					{
						printf("\n");
						printf("��ȿ���� ���� �����Դϴ�.\n");
						printf("�ٽ� �������ּ���.\n");
					}
				}
			}
			return;
		}
		else if (importanceset == 'n')
		{
			myList[LastListIdx].Importance.ImportanceChecker = 0;
			return;
		}
		else
		{
			printf("\n");
			printf("��ȿ���� ���� �����Դϴ�.\n");
			printf("�ٽ� �������ּ���.\n");
			while (getchar() != '\n')
				;
			printf("�ƹ�Ű�� �Է� �� ���͸� �����ּ���.\n");
			getchar();
		}
	}
}

void INPUT_Function(int ListNum)
{
	system("cls");
	Input_Title(ListNum);
	Input_Date(ListNum);
	Set_Importance(ListNum);
}