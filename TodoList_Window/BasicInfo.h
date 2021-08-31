#ifndef __BASICINFO_H__
#define __BASICINFO_H__

#define SIZE 100

typedef struct _detailDate
{
    int month;
    int day;
} DetailDate;

typedef struct _date
{
    DetailDate date;
    int DateChecker;
} Date;

typedef struct _importance
{
    int importance;
    int ImportanceChecker;
} Importance;

typedef struct _todolist
{
    Date Date;
    Importance Importance;
    int TemporaryIdx;
    char Title[SIZE];
} List;

List myCompList[SIZE];
List myList[SIZE];

void DataInit();
void ShowMenu();
void ShowTodoList(int idx);
int ShowMyList(int ListNum);
void Select_IDX_In_List(int LastListIdx);
void ShowRestWork(int ListNum);
void CheckConfimed();
int ShowChooseMenu(int ListNum);

#endif