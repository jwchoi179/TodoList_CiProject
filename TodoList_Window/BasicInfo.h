#ifndef __BASICINFO_H__
#define __BASICINFO_H__

#define SIZE 100

typedef struct _detailDate
{
    int month; // ��¥�� ��(Month)
    int day;   // ��¥�� ��(Day)
} DetailDate;

typedef struct _date
{
    DetailDate date; // ���� ��¥ �� �ؾ��ϴ� ��¥
    int DateChecker;
} Date;

typedef struct _importance
{
    int importance;
    int ImportanceChecker;
} Importance;

typedef struct _todolist
{
    Date Date; // �� ���� ��¥
    Importance Importance;
    // �߿䵵�� 1, 2, 3���� �켱������ �ο��մϴ�
    int TemporaryIdx; // ����ü ���� �߰�
    char Title[SIZE]; // �� ���� ����
} List;

List myCompList[SIZE]; // �Ϸ�ó���� �� �׸���� ������ �迭
List myList[SIZE];     // �� �ϵ��� ������ �迭

void DataInit();
void ShowMenu();
void ShowTodoList(int idx);
int ShowMyList(int ListNum);
void Select_IDX_In_List(int LastListIdx);
void ShowRestWork(int ListNum);
void CheckConfimed();

#endif