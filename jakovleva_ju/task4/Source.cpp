#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, i, m, t = 0, obshsale = 0, sum = 0;
	int sh[5] = { 2468, 1357, 5629, 4798, 7398 }; // ���������
	char tov[5][19] = { {"������ �����������"}, {"����� �������"}, {"�����"}, {"����� ������"}, {"����"} };
	int price[5] = { 1200, 400, 550, 2000, 200 }; // ���� �� ������� ��������
	int cake[5] = { 0 };
	int new_price[5] = { 0 };//���� �� �������
	int sale[5] = { 0 }; //������ ��� ������
	for (i = 0; i < 5; i++)
	{
		printf("%d ", sh[i]);
		puts(tov[i]);
	}
	printf("\n������� ������ �����-���: ");
	scanf_s("%d", &n);
	for (i = 0; i < 5; i++)
		sale[i] = 5 * (rand() % 9 + 1) + 5;
	while (n != 0)
	{
		for (i = 0; i < 5; i++)
		{
			if (n == 0)
				break;
			else
				if (n == sh[i])
				{
					printf("��� �����: ");
					puts(tov[i]);
					new_price[i] = price[i] * (100 - sale[i]) / 100;
					printf("���� %d ���.\n������ �� ����� %d ����.\n���� �� ����� � ������ ������ %d ���.\n", price[i], sale[i], new_price[i]);
					printf("������� ���������� ����������� ������: ");
					scanf_s("%d", &m);
					cake[i] += m;
					printf("\n������� �������� ���������� ������ ��� ���� �� ������ ��������� ,�� ������� 0: ");
					scanf_s("%d", &n);
					break;
				}
		}
	}
	for (i = 0; i < 5; i++)
	{
		new_price[i] = cake[i] * (price[i] * (100 - sale[i]) / 100);
		t = t + (cake[i] * price[i]);//��������� ��������� ������� ��� ������
		sum = sum + new_price[i];//��������� ������� �� �������
	}
	obshsale = t - sum;
	//��������� ���
	printf("\n\n");
	printf("�������� ���\n");
	for (i = 0; i < 5; i++)
	{
		if (cake[i] != 0)
		{
			puts(tov[i]);
			printf_s("���������� %d �� , ���� � ������ ���������� � ������ %d \n", cake[i], new_price[i]);
		}
	}
	printf("���� ������ ��������� : %d  ������ \n", obshsale);
	printf("����� : %d ������\n", sum);
	printf("������� �� �������!\n");
	system("pause");
}
