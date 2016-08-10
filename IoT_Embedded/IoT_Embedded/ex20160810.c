#if 0
#include <stdio.h>

int main()
{
	int a = 100, b = 30, flag = 2;
	int con1 = 1, con2 = 2;
	char *ptr = "hello";

	/*printf("a + b = %4d\n", a + b);
	printf("a - b = %4d\n", a - b);
	printf("a * b = %4d\n", a * b);
	printf("a / b = %4d\n", a / b);
	printf("a %% b = %4d\n", a % b);*/

	/*
	1. ������ ���� (Compile error)
	if (flag = 1	// ')'�� �����������ν� ��ǻ�Ͱ� �˾Ƶ������Ѵ�...
		printf("true\n");
	else

	2. ��Ÿ�� ���� (Run-time error)
	++*ptr // ��������� �ִ� value�� �����Ϸ��� �ϴ� �ൿ���� ���� ����(read-only������ write�ൿ)

	3. ��ŷ ���� (Linking error)
	aaa(); // ���ǵ��� ���� �Լ����� ����

	4. �� ���� (Logic error)
	if (con1 & con2) // 0001 & 0010 -> 0000 (������ ����)
		printf("true\n");
	*/
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int item = 3;
	int t = item ^ 4;

	while (getch() != EOF)
	{
		printf("Item: %d\n", item);
		item = item ^ t;
	}
}
#endif

#if 0
/*
Į
����
����
����

KAL		1 => 0001
BANG	2 => 0010
YACK	4 => 0100
RING	8 => 1000
*/
#include <stdio.h>
#define KAL		1
#define BANG	2
#define YACK	4
#define RING	8
int main()
{
	int item = 0;

	item = item | KAL;
	item = item | RING;
	item = item | YACK;

	printf("###������ ���â###\n");
	if (item & KAL)
		printf("Į ȹ��!\n");
	if (item & BANG)
		printf("���� ȹ��!\n");
	if (item & YACK)
		printf("���� ȹ��!\n");
	if (item & RING)
		printf("���� ȹ��!\n");
	printf("-------------------\n");
	item = item & ~YACK;

	printf("###������ ���â###\n");
	if (item & KAL)
		printf("Į ȹ��!\n");
	if (item & BANG)
		printf("���� ȹ��!\n");
	if (item & YACK)
		printf("���� ȹ��!\n");
	if (item & RING)
		printf("���� ȹ��!\n");

	return 0;

	// | <- ����ִ�.. , & <- Ȯ������ , ~ <- ����
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a = -100 - , b = 2, c = 3;

	printf("%d\n", (a > 100) ? 100 : ((a < 0) ? 0 : a));
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int a = 3, b = 4, c = 5, d = 6, e = 7, f;
	f = (++a - b--)*(c--) + ++d - e--;

	printf("a: %d, b: %d, c: %d, d: %d, e: %d, f: %d\n", a, b, c, d, e, f);
	return 0;
}
#endif

#if 0
#include <stdio.h> 
void main(void) 
{ 
	int i = 10, j = 2; 
	i += j++; 
	printf("i = %d, j = %d\n",i,j); 
	{ 
		int i = 2; 
		i += j; 
		j -= i; 
		printf("i = %d, j = %d\n",i,j);   
		{ 
			int j = 5; 
			j *= i + 1; 
			++i; 
			printf("i = %d, j = %d\n",i,j);  
		} 
		printf("i = %d, j = %d\n",i,j);  
	} 
	printf("i = %d, j = %d\n",i,j);  
}
#endif

#if 0
#include <stdio.h>
int main()
{
	for (int i = 0, j = 0; i < 5; i++)
	{
		j++;
	}

	i = 7; // ������ ������������ ��������.
	printf("i: %d\n", i);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int age;
	printf("Enter the age: ");
	scanf_s("%d", &age);
	
	switch (age)
	{
	case 79: case 78: case 77: case 76: case 75: case 74: case 73: case 72: case 71: case 70:
	case 69: case 68: case 67: case 66: case 65: case 64: case 63: case 62: case 61: case 60:
		printf("60�� �̻�\n");
		break;
	case 59: case 58: case 57: case 56: case 55: case 54: case 53: case 52: case 51: case 50:
		printf("50�� �̻�\n");
		break;
	case 49: case 48: case 47: case 46: case 45: case 44: case 43: case 42: case 41: case 40:
		printf("40�� �̻�\n");
		break;
	case 39: case 38: case 37: case 36: case 35: case 34: case 33: case 32: case 31: case 30:
		printf("30�� �̻�\n");
		break;
	case 29: case 28: case 27: case 26: case 25: case 24: case 23: case 22: case 21: case 20:
		printf("20�� �̻�\n");
		break;
	case 19: case 18: case 17: case 16: case 15: case 14: case 13: case 12: case 11: case 10:
		printf("10�� �̻�\n");
		break;
	case 9: case 8: case 7: case 6: case 5: case 4: case 3: case 2: case 1:
		printf("���ҳ�\n");
		break;
	default:
		printf("�ش���� �����ϴ�.\n");
	}
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int a;
	printf("Menu: (");
	printf("1: open,");
	printf("2: save,");
	printf("3: close");
	printf("):\n");

	scanf("%d", &a);

	switch (a)
	{
	case 1:
		printf("open\n");
		break;
	case 2:
		printf("save\n");
		break;
	case 3:
		printf("close\n");
		break;
	default:
		printf("�߸� ���� �ϼ̽��ϴ�.\n");
		break;
	}

	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 0;
	while (i < 128)
	{
		printf("%3d: %c\n", i, i);
		i++;
	}

	return 0;
}
#endif

#if 0
// �������� ����! ������ ��� ���α׷�...(���� 1���� �Է¹޽��ϴ�.)
#include <stdio.h>
int main()
{
	int num;
	int multi;
	printf("���ڸ� �Է��ϼ���: ");
	scanf_s("%d", &num);

	for (multi = 1; multi <= 9; ++multi)
		printf("%d x %d = %d\n", num, multi, num*multi);

	return 0;
}
#endif

////////////////// �������� �ñ���
#if 0
#include <stdio.h>
enum _boolean false_bool;
enum _boolean true_bool;

int main()
{
	printf("%d %d\n", false_bool, true_bool); // �Ѵ� 0���� ��µȴ�.
}
#endif

///////////////////

// ###### �Ʒ��� ���´� ������ �Ը��� �°� ������ �ڵ��̹Ƿ� �����ð��� ���� �����ڵ带 ��������ø� �ٸ� �л��� �ڵ带 �����Ͻñ� �ٶ��ϴ�. ######
#if 0
/*
����� ���� ����:
*****
*****
*****
*****
*****
*/
#include <stdio.h>
int main()
{
	int i=0, j=0, num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	/*for (i = 0; i < num; ++i)
	{
		for (j = 0; j < num; ++j)
			printf("*");
		printf("\n");
	}*/

	while (i < num)
	{
		while (j < num)
		{
			printf("*");
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return 0;
}
#endif

#if 0
/*
����� ���� ����:
*
**
***
****
*****
*/
#include <stdio.h>
int main()
{
	int i=0, j=0, num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	while (i < num)
	{
		while (j <= i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return 0;
}
#endif

#if 0
/*
����� ���� ����:
    *
   **
  ***
 ****
*****
*/
#include <stdio.h>
int main()
{
	int i = 0, j = 0, num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	while (i < num)
	{
		while (j < num)
		{
			if ((num-i -1) > j)
				printf(" ");
			else
				printf("*");
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return 0;
}
#endif

#if 0
/*
����� ���� ����:
    *
   ***
  *****
 *******
*********
*/
#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	while (i < num)
	{
		while (j < num)
		{
			if ((num - i - 1) > j)
				printf(" ");
			else if ((num - i - 1) == j)
				printf("*");
			else
				printf("**");
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}
#endif

#if 0
/*
����� ���� ����:
    *		(line 1, space 4)
   ***		(line 2, space 3)
  *****		(line 3, space 2)
 *******	(line 4, space 1)
*********	(line 5, space 0)
 *******	(line 6, space 1)
  *****		(line 7, space 2)
   ***		(line 8, space 3)
    *		(line 9, space 4)
*/

#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	while (i < num*2 -1)
	{
		if (i < num)
		{
			while (j < num)
			{
				if ((num - i - 1) > j)
					printf(" ");
				else if ((num - i - 1) == j)
					printf("*");
				else
					printf("**");
				j++;
			}
		}
		else
			while (j < num)
			{
				if (i-j+1 > num)
					printf(" ");
				else if (i-j+1 == num)
					printf("*");
				else
					printf("**");
				j++;
			}
		printf("\n");
		j = 0;
		
		i++;
	}
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 0, j = 0, num, inc = 0, sign = 1;
	printf("���� �Է�:");
	scanf_s("%d", &num);
	//getchar();
	while (i < num * 2 - 1)
	{
		j = 0;
		/*while (j++ < space)
			printf(" ");
		j = 0;*/
		while (j < inc + 1)
		{
			printf("*");
			j++;
		}
		j = 0;
		while (j < (num - inc - 1) * 2 - 1)
		{
			printf(" ");
			j++;
		}
		j = 0;
		while (j < inc + 1 && j != num - 1)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;

		if (i == num)
			sign = -sign;
		inc += sign;
	}	
}
#endif

#if 0
/*
*   	*
** 	   **
***   ***
**** ****
*********
**** ****
***   ***
** 	   **
*   	*
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main(void)
{
	int i = 0, j = 0, num, inc = 0, sign = 1, enter = 5, space = 20, choice;
	printf("���� �Է�:");
	scanf("%d", &num);
	getchar();
	while (1)
	{
		i = 0;
		j = 0;
		inc = 0;
		sign = 1;
		while (j++ < enter)
			printf("\n");
		while (i < num * 2 - 1)
		{
			j = 0;
			while (j++ < space)
				printf(" ");
			j = 0;
			while (j < inc + 1)
			{
				printf("*");
				j++;
			}
			j = 0;
			while (j < (num - inc - 1) * 2 - 1)
			{
				printf(" ");
				j++;
			}
			j = 0;
			while (j < inc + 1 && j != num - 1)
			{
				printf("*");
				j++;
			}
			printf("\n");
			i++;

			if (i == num)
				sign = -sign;
			inc += sign;
		}
		while ((choice = getch()) != 224);
		choice = getch();
		switch (choice)
		{
		case 75: space = (space == 0) ? 0 : space - 1;  break;
		case 77: space = (space + num * 2 - 1 == 70) ? space : space + 1;  break;
		case 72: enter = (enter == 0) ? 0 : enter - 1;  break;
		case 80: enter = (enter + num * 2 - 1 == 30) ? enter : enter + 1;  break;
		}
		system("cls");
	}
	return 0;
}
#endif


///////////////////////// �������� Ž�������Դϴ�.
#if 0
#include <stdio.h>
int main()
{
	int i=10, j=5, count1 = 0, count2 = 0;

	while (count1 < i)
	{
		while (count2 < j)
			count2++;
		count1++;
	}

	count1 = count2 = 0;

	while (count1 != i)
	{
		while (count2 != j)
			count2++;
		count1++;
	}
}
#endif

#if 1
#include <stdio.h>
int main()
{
	char run = 0;

	while (run != 0)
	{
		for (int i = 0; i != 100; ++i);
		++run;
	}


	while (run != 1)
	{
		for (int i = 100; i != 0; --i);
		--run;
	}
}
#endif