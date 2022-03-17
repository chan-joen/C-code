#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <Windows.h>

#define one 49
#define two 50


int a[6];
int NUM[6] = { 0,0,0,0,0,0 };
int Now_Money = 0;
char S;
int g = 0;
int C = 0;
int i, k = 0, j, l;
char W;

void Random(void); ///time 함수를 입력하여 매번 다른 값이 나오게 설정함
void RandomNum(void); //int a에 무작위 값을 안 겹치게 넣어줌
void Chogihwa(void); //int a의 값과 int NUM의 값을 초기화 시켜줌
void Gameplay(void); //로또의 기본

int main()
{

	FILE* file = fopen("NowMoney.dat", "rt"); // NowMoney.dat파일을 연결 
	if (file == 0) { Now_Money = 2000; } //파일이 없으면 걍 있는 돈에 2000을 넣음 
	else {
		fscanf(file, "%d", &Now_Money); // 파일이 열리면 있던 돈을 불러옴 
		fclose(file); //파일 닫음 
	}
	system("title 로또");
	system("color FC");
	for (;;)
	{
		system("CLS"); //화면이 더러워지는것을 방지하기위해 한바퀴 돌고 돌아오자마자 화면을 초기화함 
		printf("    보유금액:%d\n", Now_Money);
		if (Now_Money <= 0) //보유금액이 0원이거나 그 이하면 끝남
		{
			printf("탕진하였습니다~!\n");
			printf("대출을 받겠습니까?(1:Yes/2:No):");
			fflush(stdin);
			scanf("%c", &W);
			if (W == one)
			{
				Now_Money = Now_Money - 5000;
				for (l = 4; l >= 0; l--)
				{
					system("CLS");
					printf("    보유금액:%d\n", Now_Money);
					if (Now_Money > 0)
					{
						printf("돈을 갚았습니다. 계속 하시겠습니까?(1:Yes/2:No):");
						rewind(stdin);
						scanf("%c", &W);
						if (W == one)
						{
							break;
						}
						else if (W == two)
						{
							printf("그만두었습니다. \n");
							return 0;
						}
					}
					printf("%d번동안 돈을 갚아야합니다. 어쩔수 없이 계속 시작하게됩니다.\n", l + 1);
					Gameplay();
				}
				if (l <= 0)
				{
					system("CLS");
					printf("    보유금액:%d\n", Now_Money);
					printf("돈을 갚지 못하였습니다~!\n파산하였습니다~!\n");
					printf("끝내기(엔터):");
					rewind(stdin); //scanf때 입력한 Enter때문에 넘어가는 것을 방지함
					scanf("%c", &S); //아무거나 입력했을때 돌아감
				}
				if (l > 0)
				{
					continue;
				}
			}
			else if (W == two)
			{
				printf("대출을 받지 않았습니다~!\n탕진하였습니다~!\n");
			}
			break;
		}
		printf("패가망신 로또(1:로또/2:보유 돈 저장 및 그만):");
		rewind(stdin);
		scanf("%c", &W); //계속할것인가 그만할것인가 선택함
		if (W == one)
		{
			Gameplay();
		}
		else if (W == two)
		{
			break;
		}
	}
	if (Now_Money >= 0) { //보유 돈이 0보다 많을 시
		FILE* file = fopen("NowMoney.dat", "wt"); //NowMoney.dat에 돈 저장                

		if (file == 0) { //파일 에러메세지  
			printf("FILE ERROR: SYSTEM CANNOT WRITE Money ON \"NowMoney.DAT\"");
		}
		else {
			fprintf(file, "%d", Now_Money);
			fclose(file);
		}
	}
	else if (Now_Money < 0) {
		FILE* file = fopen("NowMoney.dat", "wt");
		if (file == 0) { //파일 에러메세지  
			printf("FILE ERROR: SYSTEM CANNOT WRITE Money ON \"NowMoney.DAT\"");
		}
		else {
			Now_Money = 2000;
			fprintf(file, "%d", Now_Money);
			fclose(file);
		}
	}
	return 0;
}

void Random(void)
{
	srand((int)time(NULL)); //time 함수를 입력하여 매번 다른 값이 나오게 설정함
}

void RandomNum(void)
{
	int i, j;
	int k = 0;
	int C = 0;
	for (i = 0; i < 6; i++)
	{
		C = 0;
		k = 0;
		a[i] = rand() % 45 + 1; //a에 랜덤값을 적용함
		k = a[i];
		for (j = 0; j < 6; j++) //a값중 겹치는게 있는지 확인함
		{
			if (k == a[j])
				C++;
		}
		if (C >= 2) //겹치는게 있을경우 다시 값을 받음
		{
			i--;
			continue;
		}
	}
}

void Chogihwa(void)
{
	int i;
	for (i = 0; i <= 5; i++) //a와 NUM의 값을 0으로 초기화함
	{
		a[i] = 0;
		NUM[i] = 0;
	}
}
void Gameplay()
{
	Chogihwa();
	Random();
	RandomNum();
	Now_Money = Now_Money - 1000;
	printf("6개의 수를 입력하세요(1~45)\n");
	for (i = 0; i <= 5; i++) //int NUM에 자신이 원하는 숫자를 넣어줌
	{
		k = 0;
		printf("%d번 : ", i + 1);
		scanf("%d", &NUM[i]);
		if (NUM[i] > 45 || NUM[i] <1)
		{
			printf("45를 넘어가거나 1보다 작은 수는 입력할수 없습니다.\n다시 입력하세요.\n");
			i--;
			continue;
		}
		for (j = 0; j <= 5; j++) //입력한 숫자가 겹치는지 확인함
		{
			if (NUM[j] == NUM[i])
			{
				k++;
			}
		}
		if (k >= 2) //겹칠때 다시 입력하게함
		{
			printf("한숫자를 두번 입력할순 없습니다.\n다시 입력하세요.\n");
			i--;
			continue;
		}
	}
	printf("당첨번호 :");
	for (i = 0; i <= 5; i++)
	{
		printf("%d ", a[i]);
		for (k = 0; k <= 5; k++)
		{
			if (a[i] == NUM[k]) //a의 i번이 NUM중에 있는지 확인함
			{
				C++; //있을경우 C를 증가함
			}
		}
	}
	printf("\n당첨결과 : %d개\n", C);
	switch (C) //C의 값으로 당첨 갯수를 확인과 동시에 돈을 얼마나 줄지 여부를 확인함
	{
	case 0:printf("당첨되지 않았습니다. ㅅㄱㅂ\n");
		break;
	case 1:printf("6등입니다. \n");
		Now_Money = Now_Money + 1000;
		break;
	case 2:printf("5등입니다.\n");
		Now_Money = Now_Money + 3000;
		break;
	case 3:printf("4등입니다.\n");
		Now_Money = Now_Money + 20000;
		break;
	case 4:printf("3등입니다.\n");
		Now_Money = Now_Money + 50000;
		break;
	case 5:printf("2등입니다.\n");
		Now_Money = Now_Money + 200000;
		break;
	case 6:printf("1등입니다.\n");
		Now_Money = Now_Money + 100000000;
		break;
	}
	C = 0;
	printf("다음(엔터):");
	rewind(stdin); //scanf때 입력한 Enter때문에 넘어가는 것을 방지함
	scanf("%c", &S); //아무거나 입력했을때 돌아감
}
