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

void Random(void); ///time �Լ��� �Է��Ͽ� �Ź� �ٸ� ���� ������ ������
void RandomNum(void); //int a�� ������ ���� �� ��ġ�� �־���
void Chogihwa(void); //int a�� ���� int NUM�� ���� �ʱ�ȭ ������
void Gameplay(void); //�ζ��� �⺻

int main()
{

	FILE* file = fopen("NowMoney.dat", "rt"); // NowMoney.dat������ ���� 
	if (file == 0) { Now_Money = 2000; } //������ ������ �� �ִ� ���� 2000�� ���� 
	else {
		fscanf(file, "%d", &Now_Money); // ������ ������ �ִ� ���� �ҷ��� 
		fclose(file); //���� ���� 
	}
	system("title �ζ�");
	system("color FC");
	for (;;)
	{
		system("CLS"); //ȭ���� ���������°��� �����ϱ����� �ѹ��� ���� ���ƿ��ڸ��� ȭ���� �ʱ�ȭ�� 
		printf("    �����ݾ�:%d\n", Now_Money);
		if (Now_Money <= 0) //�����ݾ��� 0���̰ų� �� ���ϸ� ����
		{
			printf("�����Ͽ����ϴ�~!\n");
			printf("������ �ްڽ��ϱ�?(1:Yes/2:No):");
			fflush(stdin);
			scanf("%c", &W);
			if (W == one)
			{
				Now_Money = Now_Money - 5000;
				for (l = 4; l >= 0; l--)
				{
					system("CLS");
					printf("    �����ݾ�:%d\n", Now_Money);
					if (Now_Money > 0)
					{
						printf("���� ���ҽ��ϴ�. ��� �Ͻðڽ��ϱ�?(1:Yes/2:No):");
						rewind(stdin);
						scanf("%c", &W);
						if (W == one)
						{
							break;
						}
						else if (W == two)
						{
							printf("�׸��ξ����ϴ�. \n");
							return 0;
						}
					}
					printf("%d������ ���� ���ƾ��մϴ�. ��¿�� ���� ��� �����ϰԵ˴ϴ�.\n", l + 1);
					Gameplay();
				}
				if (l <= 0)
				{
					system("CLS");
					printf("    �����ݾ�:%d\n", Now_Money);
					printf("���� ���� ���Ͽ����ϴ�~!\n�Ļ��Ͽ����ϴ�~!\n");
					printf("������(����):");
					rewind(stdin); //scanf�� �Է��� Enter������ �Ѿ�� ���� ������
					scanf("%c", &S); //�ƹ��ų� �Է������� ���ư�
				}
				if (l > 0)
				{
					continue;
				}
			}
			else if (W == two)
			{
				printf("������ ���� �ʾҽ��ϴ�~!\n�����Ͽ����ϴ�~!\n");
			}
			break;
		}
		printf("�а����� �ζ�(1:�ζ�/2:���� �� ���� �� �׸�):");
		rewind(stdin);
		scanf("%c", &W); //����Ұ��ΰ� �׸��Ұ��ΰ� ������
		if (W == one)
		{
			Gameplay();
		}
		else if (W == two)
		{
			break;
		}
	}
	if (Now_Money >= 0) { //���� ���� 0���� ���� ��
		FILE* file = fopen("NowMoney.dat", "wt"); //NowMoney.dat�� �� ����                

		if (file == 0) { //���� �����޼���  
			printf("FILE ERROR: SYSTEM CANNOT WRITE Money ON \"NowMoney.DAT\"");
		}
		else {
			fprintf(file, "%d", Now_Money);
			fclose(file);
		}
	}
	else if (Now_Money < 0) {
		FILE* file = fopen("NowMoney.dat", "wt");
		if (file == 0) { //���� �����޼���  
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
	srand((int)time(NULL)); //time �Լ��� �Է��Ͽ� �Ź� �ٸ� ���� ������ ������
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
		a[i] = rand() % 45 + 1; //a�� �������� ������
		k = a[i];
		for (j = 0; j < 6; j++) //a���� ��ġ�°� �ִ��� Ȯ����
		{
			if (k == a[j])
				C++;
		}
		if (C >= 2) //��ġ�°� ������� �ٽ� ���� ����
		{
			i--;
			continue;
		}
	}
}

void Chogihwa(void)
{
	int i;
	for (i = 0; i <= 5; i++) //a�� NUM�� ���� 0���� �ʱ�ȭ��
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
	printf("6���� ���� �Է��ϼ���(1~45)\n");
	for (i = 0; i <= 5; i++) //int NUM�� �ڽ��� ���ϴ� ���ڸ� �־���
	{
		k = 0;
		printf("%d�� : ", i + 1);
		scanf("%d", &NUM[i]);
		if (NUM[i] > 45 || NUM[i] <1)
		{
			printf("45�� �Ѿ�ų� 1���� ���� ���� �Է��Ҽ� �����ϴ�.\n�ٽ� �Է��ϼ���.\n");
			i--;
			continue;
		}
		for (j = 0; j <= 5; j++) //�Է��� ���ڰ� ��ġ���� Ȯ����
		{
			if (NUM[j] == NUM[i])
			{
				k++;
			}
		}
		if (k >= 2) //��ĥ�� �ٽ� �Է��ϰ���
		{
			printf("�Ѽ��ڸ� �ι� �Է��Ҽ� �����ϴ�.\n�ٽ� �Է��ϼ���.\n");
			i--;
			continue;
		}
	}
	printf("��÷��ȣ :");
	for (i = 0; i <= 5; i++)
	{
		printf("%d ", a[i]);
		for (k = 0; k <= 5; k++)
		{
			if (a[i] == NUM[k]) //a�� i���� NUM�߿� �ִ��� Ȯ����
			{
				C++; //������� C�� ������
			}
		}
	}
	printf("\n��÷��� : %d��\n", C);
	switch (C) //C�� ������ ��÷ ������ Ȯ�ΰ� ���ÿ� ���� �󸶳� ���� ���θ� Ȯ����
	{
	case 0:printf("��÷���� �ʾҽ��ϴ�. ������\n");
		break;
	case 1:printf("6���Դϴ�. \n");
		Now_Money = Now_Money + 1000;
		break;
	case 2:printf("5���Դϴ�.\n");
		Now_Money = Now_Money + 3000;
		break;
	case 3:printf("4���Դϴ�.\n");
		Now_Money = Now_Money + 20000;
		break;
	case 4:printf("3���Դϴ�.\n");
		Now_Money = Now_Money + 50000;
		break;
	case 5:printf("2���Դϴ�.\n");
		Now_Money = Now_Money + 200000;
		break;
	case 6:printf("1���Դϴ�.\n");
		Now_Money = Now_Money + 100000000;
		break;
	}
	C = 0;
	printf("����(����):");
	rewind(stdin); //scanf�� �Է��� Enter������ �Ѿ�� ���� ������
	scanf("%c", &S); //�ƹ��ų� �Է������� ���ư�
}