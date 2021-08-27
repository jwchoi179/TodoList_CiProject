#include "BasicInfoMac.h"
#include "InputTodoListMac.h"
#include <stdio.h>
#include <string.h>

void Input_Title(int LastListIdx)
{
	char Title[100] = {'\0'};
	printf("제목을 입력해주세요.\n");
	getchar();
	scanf("%[^\n]", Title); // 공백포함, 문장 전체
	strcpy(myList[LastListIdx].Title, Title);
}

void Input_Date(int LastListIdx)
{
	char dateset;
	int month = 1;
	int day = 1;
	while (1)
	{
		printf("날짜를 지정하시겠습니까? [y / n]\n");
		getchar();
		scanf("%c", &dateset);
		if (dateset == 'y')
		{
			printf("날짜를 입력해주세요. [ex) 3 29]\n");

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
			printf("유효하지 않은 형식입니다.\n");
	}
}

void Set_Importance(int LastListIdx)
{
	char importanceset;
	int importance = 1;
	while (1)
	{
		printf("중요도를 설정하시겠습니까? [y / n]\n");
		getchar();
		scanf("%c", &importanceset);
		if (importanceset == 'y')
		{
			printf("중요도는 얼마입니까? [1 / 2 / 3]\n");

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
			printf("유효하지 않은 형식입니다.\n");
	}
}

void INPUT_Function(int ListNum)
{
	Input_Title(ListNum);
	Input_Date(ListNum);
	Set_Importance(ListNum);
}