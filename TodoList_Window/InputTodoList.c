#define _CRT_SECURE_NO_WARNINGS

#include "BasicInfo.h"
#include "InputTodoList.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

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
	int month = 1;
	int day = 1;
	while (1)
	{
		printf("��¥�� �����Ͻðڽ��ϱ�? [y / n]\n");
		getchar();
		scanf("%c", &dateset);
		if (dateset == 'y')
		{
			printf("��¥�� �Է����ּ���. [ex) 3 29]\n");

			getchar();

			scanf("%d %d", &month, &day);
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
			printf("��ȿ���� ���� �����Դϴ�.\n");
	}
}

void Set_Importance(int LastListIdx)
{
	char importanceset;
	int importance = 1;
	while (1)
	{
		printf("�߿䵵�� �����Ͻðڽ��ϱ�? [y / n]\n");
		getchar();
		scanf("%c", &importanceset);
		if (importanceset == 'y')
		{
			printf("�߿䵵�� ���Դϱ�? [1 / 2 / 3]\n");

			getchar();

			scanf("%d", &importance);
			myList[LastListIdx].Importance.importance = importance;
			myList[LastListIdx].Importance.ImportanceChecker = 1;
			break;
		}
		else if (importanceset == 'n')
		{
			myList[LastListIdx].Importance.ImportanceChecker = 0;
			break;
		}
		else
			printf("��ȿ���� ���� �����Դϴ�.\n");
	}
}

void INPUT_Function(int ListNum)
{
	Input_Title(ListNum);
	Input_Date(ListNum);
	Set_Importance(ListNum);
}