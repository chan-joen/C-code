#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define SWAP(a, b, tmp){(tmp) = (a); (a) = (b); (b) = (tmp);}
void StudentNumSort(int* list1,int* list2, int n)
{
	int min, temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list1[j] < list1[min])
			{
				min = j;
			}
		}
		if (list1[i] != list1[min]) {
			SWAP(list1[i], list1[min],temp);
			SWAP(list2[i], list2[min], temp);
		}
	}
}
void ScoreSort(int* list1,int* list2, int n)
{
	int max, temp;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list1[j] > list1[max])
			{
				max = j;
			}
		}
		if (list1[i] != list1[max]) {
			SWAP(list1[max], list1[i], temp);
			SWAP(list2[max], list2[i], temp);
		}
	}
}
int main()
{
	int* student;
	int* score;
	int* arr;
	int Num1=0,Num2=0;
	int i;
	printf("학생의 수를 입력해 주세요: ");
	scanf("%d", &Num1);
	student = (int*)malloc(sizeof(int) * Num1);
	score = (int*)malloc(sizeof(int) * Num1);
	arr = (int*)malloc(sizeof(int) * Num1);
	for (i = 0; i < Num1; i++)
	{
		printf("학생의 학번과 점수를 입력해 주세요: ");
		scanf("%d %d", &student[i], &score[i]);
		arr[i] = i;
	}
	printf("1.학번으로 정리하기 2.점수 순으로 정리하기:");
	scanf("%d", &Num2);
	if (Num2 == 1)
	{
		StudentNumSort(student, arr, Num1);
		for (i = 0; i < Num1; i++)
		{
			printf("%d %d \n", student[i], score[arr[i]]);
		}

	}
	else if (Num2 == 2)
	{
		ScoreSort(score, arr, Num1);
		for (i = 0; i < Num1; i++)
		{
			printf("%d %d \n", student[arr[i]], score[i]);
		}
	}
	else
	return 0;
}
