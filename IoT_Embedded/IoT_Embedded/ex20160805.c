#if 0
#include <stdio.h>
#define MAX 9
int main()
{
	int size;
#if MAX > 10
	size = 100;
#else
	size = 10;
#endif
	printf("size: %d\n", size);
}
#endif

#if 0
#include <stdio.h>
#define GR_MODE
int main()
{
#ifdef GR_MODE
	printf("�׷��� ���[1]...\n");
#else
	printf("�ؽ�Ʈ ���[1]...\n");
#endif

#undef GR_MODE

#ifdef GR_MODE
	printf("�׷��� ���[2]...\n");
#else
	printf("�ؽ�Ʈ ���[2]...\n");
#endif
}
#endif

#if 0
#include <stdio.h>
#define SQ(x) (x*x)

int main()
{
	int x, y, z;
	x = y = z = 3;
	x = SQ(x);
	y = SQ(++y);
	z = SQ(z + z);
	printf("x: %d, y: %d, z: %d\n", x, y, z);
}
#endif


/*
<�迭>
1. ������ �����͵��� ����
2. �ε����� ���� [i]
3. �ε����� 0 ���� ����
4. �迭���� ù��° ������ �ּҸ� ��Ÿ����.

(����): int a[n]
*/

#if 0
#include <stdio.h>
#define SIZE(x) (sizeof(x) / sizeof(x[0]))
int main()
{
	int i, data[] = { 78, 55, 99, 75, 84, 39, 100, 87 };
	int sum = 0;
	float a;
//	for (i = 0; i < sizeof(data) / sizeof(int); i++)
	for (i = 0; i < SIZE(data); i++)
		sum += data[i];
	a = (float)sum / SIZE(data);
	printf("Total: %d, Average: %.2f\n", sum, a);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int arr[3] = { 100, 200, 300 };
	int* p = arr;
	printf("%p, %p\n", &arr, arr); // �迭��ü�� ù��°ĭ�� �ּҴ� �����մϴ�.
	printf("sizeof(&arr): %d\n", sizeof(&arr));
	printf("sizeof(arr): %d\n", sizeof(arr));
	printf("*(p+1): %d, *p+1: %d\n", *(p + 1), *p + 1); // ���ڴ� 2��°����, ���ڴ� ù��°���ҿ� 1���Ѱ�
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int arr[3][3];

	printf("&arr: %p\n", &arr);
	printf("arr: %p\n", arr);
	printf("arr[0]: %p\n", arr[0]);
	printf("&arr[0][0]: %p\n", &arr[0][0]);
}
#endif // ���: �Ϲ� ���������Ϳ� �迭�����ʹ� ���̰� �ִ�. (�����ּҰ��� �ݺ�&������������ ���� vs �ּҰ��� ����&����)

#if 0
#include <stdio.h>
#define MAX 5
int main()
{
	int i = 0;
//	char a[MAX] = { 'a','b','c','d','\0' };
//	char a[MAX] = {"abcd"};
	char a[MAX] = "abcde";

//	for (i = 0; i < MAX; i++)
//		a[i] = i + 1;
//	for (i = 0; i < MAX; i++)
//		printf("a[%d]=%d\n", i, a[i]);

	printf("%s\n", a);
}
#endif

#if 0
#include <stdio.h>
char get_line(char[]);
void reverse(char*, int);
int main()
{
	char line[250];
	char *cp;
	char len;

	while (len = get_line(line))
	{
		reverse(line, len);
		for (cp = line; cp < line + len; cp++)
		{
			putchar(*cp);
		}
	}
	return 0;
}

char get_line(char line[])
{
	int len = 0;
	while ((*line = getchar()) != EOF)
	{
		++len;
		if (*line++ == '\n')
			return len;
	}
	return len;
}

void reverse(char* line, int len)
{
	char* cp = line + len - 2;
	int d;
	while (line < cp)
	{
		d = *line;
		*line++ = *cp;
		*cp-- = d;
	}
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	
	char com[20], name[20], pass[20];
	scanf("%[^,]", com); // %[^,]�� ,���ö������� �Է¹������ �̾߱��̴�. (���й��ڰ� �޸�(,)�ΰ�!)
	getchar();
	scanf("%[^:]", name);
	getchar();
	scanf("%[^\n]s", pass);
	getchar();

	printf("Computer: %s\n", com);
	printf("Name    : %s\n", name);
	printf("Password: %s\n", pass);
	
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
//�ֹι�ȣ ������ �����
int main()
{
	int i;
	char jumin[14] = { 0 };
	char seq[13] = "234567892345";
//	int a, b, c, d, e, f, g, h, i, j, k, l;
	int check_sum = 0;
	
	printf("�ֹι�ȣ �Է�: ");
	scanf("%[^\n]s", jumin);
//	jumin[13] = '\0';

/*	
	a = jumin[0] * seq[0];
	b = jumin[1] * seq[0];
	c = jumin[2] * seq[0];
	d = jumin[3] * seq[0];
	e = jumin[4] * seq[0];
	f = jumin[5] * seq[0];
	g = jumin[6] * seq[0];
	h = jumin[7] * seq[0];
	i = jumin[8] * seq[0];
	j = jumin[9] * seq[0];
	k = jumin[10] * seq[0];
	l = jumin[11] * seq[0];

	check_sum = a + b + c + .... ;
*/

	for (i = 0; i < 12; i++)
		check_sum += (jumin[i] - '0') * (seq[i] - '0');

	check_sum = (11 - check_sum % 11) % 10;

	printf("[%s] �ֹι�ȣ�� ", jumin);
	if (check_sum == jumin[12] - '0')
		printf("�ùٸ� ");
	else
		printf("�߸��� ");

	printf("�ֹι�ȣ �Դϴ�.\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable:4996)

const int month_end[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int month_end_special[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void INPUT_SCREEN(int* year, int* month);
void INTERFACE(int year, int month, int* m_total);
int LEAP(int year);
void CALC_DAY(int* day, int month, int leap_year);
void INIT_CALC(int m_total[]);
int CONTROL(int* year, int* month);

int main()
{
	int i, input;
	int year, month, day = 0;
	int m_total[53] = { 0, };
	int leap_year = 0;

	INPUT_SCREEN(&year, &month);

	do
	{
		INIT_CALC(m_total, &day);

		leap_year = LEAP(year); // ���� �Ǵ�

		for (i = 0; i < year; i++)
			day += 365 + (LEAP(i));

		CALC_DAY(&day, month, leap_year);

		if (leap_year)
		{
			for (i = 0; i < month_end_special[month - 1]; i++)
				m_total[i + day] = i + 1;
		}
		else
		{
			for (i = 0; i < month_end[month - 1]; i++)
				m_total[i + day] = i + 1;
		}

		printf("(���۹�: ������: ��, ������: ��, ������: ��, ������: ��)\n");
		INTERFACE(year, month, m_total);
		printf("\n����� QŰ�� �Է��ϼ���...\n");
		input = CONTROL(&year, &month);

		system("cls");

		
	} while (input != ('Q' | 'q'));

	return 0;
}

void INTERFACE(int year, int month, int* m_total)
{
	int i;

	printf("     %4d��  %2d��\n", year, month);
	printf("%4s%4s%4s%4s%4s%4s%4s\n", "��", "��", "ȭ", "��", "��", "��", "��");

	for (i = 0; i < 53; i++)
	{
		if (m_total[i])
			printf("%4d", m_total[i]);
		else
			printf("    ");

		if ((i + 1) % 7 == 0)
			printf("\n");
	}
}

void INPUT_SCREEN(int* year, int* month)
{
	int y, m;
	printf("����Է�: ");
	scanf("%d %d", &y, &m);

	*year = y;
	*month = m;

	system("cls"); // clear screen ��ɾ�
}

int LEAP(int year)
{
	int leap_year;
	leap_year = (!(year % 4) && (year % 100)) || !(year % 400);
	return leap_year;
}

void CALC_DAY(int* day, int month, int leap_year)
{
	int i;
	for (i = 0; i < month - 1; i++)
	{
		if (leap_year)
			*day += month_end_special[i];
		else
			*day += month_end[i];
	}
	*day %= 7;
}

void INIT_CALC(int m_total[], int* day)
{
	int i;

	for (i = 0; i < 53; i++)
		m_total[i] = 0;

	*day = 0;
}

int CONTROL(int* year, int* month)
{
	int c;
	c = getch();

	if (c == 224)
	{
		c = getch();
		
		switch (c)
		{
			case 72:
				--*year;
				return c;
			case 80:
				++*year;
				return c;
			case 77:
				++*month;
				return c;
			case 75:
				--*month;
				return c;
		}
		
	}
}

#endif



/*
Ű���޴¹�~
*/

#if 0
#include <stdio.h>
int main()
{
	while (1)
	{
		int c;
		c = getch();
		if (c == 224)
		{
			c = getch();
			printf("<%d> ", c);
			continue;
		}
		printf("=%d= ", c);
	}
}
#endif



//////////////////���⼭���ʹ� ���͵�׷� �����Դϴ�.
#if 0
#include <stdio.h>
int reset();
int next(int), last(int), now(int);
int i = 1;

void main()
{
	auto int i, j;

	i = reset();
	for (j = 0; j <= 3; j++)
	{
		printf("i=%d, j=%d\n", i, j);
		printf("next(i)=%d\n", next(i));
		printf("last(i)=%d\n", last(i));
		printf("now(i+j)=%d\n", now(i + j));
	}
}

int reset()
{
	return i;
}

int next(int j)
{
	return (j = i++);
}

int last(int j)
{
	static int i = 10;
	return (j = i--);
}

int now(int i)
{
	auto int j = 10;
	return (i = j += i);
}
#endif

#if 0
#include <stdio.h>
extern int num;
int main()
{
	num = 10;
	printf("%d\n", num);
}

#endif