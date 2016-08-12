#if 0
#include <stdio.h>
int main()
{
	int i = 1, j = 2;
	int a[5] = { 1,2,3,4,5 };
	printf("i=%d, j=%d\n", i, j);
	a[7] = 10;
	a[10] = 20;
	printf("i=%d, j=%d\n", i, j);
	return 0;
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 0;
	int a[5] = { 1,2,3,4,5 };

	4[a] = 10;

	for (i = 0; i < 5; i++)
		printf("%#p, %#p, %#p\n", a + i, &a[i], &*(a + i));

	for (i = 0; i < 5; i++)
		printf("%d, %d, %d\n", *(a + i), a[i], i[a]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i, j, num;

	printf("숫자 입력: ");
	scanf_s("%d", &num);

	for (i = 2; i <= num; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break;
		}
		if (i == j)
			printf("%5d", i);
		else
			printf("%5c", 'X');

		if ((i - 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i, j, num, a[100] = { -1, -1, };

	printf("숫자입력(최대: 100): ");
	scanf_s("%d", &num);

	for (i = 2; i <= num; i++)
		a[i] = i;
	for (i = 0; i <= num; i++)
	{
		if (a[i] == -1)
			continue;
		for (j = i + 1; j <= num; j++)
		{
			if (a[j] == -1)
				continue;
			if (j%i == 0)
				a[j] = -1;
		}
	}
	for (i = 0; i <= num; i++)
	{
		if (a[i] != -1)
			printf("%3d", a[i]);
		else
			printf("%3c", 'X');

		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int main() // 동적할당을 이용한 배열입니다.
{
	int i, j, num;
	int* a;

	printf("숫자입력(최대 5자리수): ");
	scanf_s("%d", &num);

	a = (int*)malloc(sizeof(int)*(num+1));
	*(a+0) = *(a+1) = -1;

	for (i = 2; i <= num; i++)
		a[i] = i;
	for (i = 0; i <= num; i++)
	{
		if (a[i] == -1)
			continue;
		for (j = i + 1; j <= num; j++)
		{
			if (a[j] == -1)
				continue;
			if (j%i == 0)
				a[j] = -1;
		}
	}
	for (i = 0; i <= num; i++)
	{
		if (a[i] != -1)
			printf("%6d", a[i]);
		else
			printf("%6c", 'X');

		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	free(a);
	return 0;
}
#endif

#if 0
/*
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
#include <stdio.h>
#define NUM 5
int main()
{
	int i, j;
	int arr[NUM][NUM] = { 0 };

	for (i = 0; i < NUM; ++i)
	{
		for (j = 0; j < NUM; ++j)
		{
			arr[i][j] = i*NUM+(j+1);
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}
#endif

#if 0
/*
1
2  3
4  5  6
7  8  9  10
11 12 13 14 15 
*/
#include <stdio.h>
#define NUM 5
int add_sum(int);

int main()
{
	int i, j;
	int arr[NUM][NUM] = { 0 };

	for (i = 0; i < NUM; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			arr[i][j] = add_sum(i) + j + 1;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}

int add_sum(int num)
{
	if (num == 0)
		return 0;
	else
		return num + add_sum(num - 1);
}
#endif

#if 0
/*
1  2  3  4  5
6  7  8  9
10 11 12
13 14
15
*/
#include <stdio.h>
#define NUM 5
int add_sum(int);

int main()
{
	int i, j, cnt = 1;
	int arr[NUM][NUM] = { 0 };

	for (i = 0; i < NUM; ++i)
	{
		for (j = 0; j < NUM-i; ++j)
		{
			arr[i][j] = cnt++;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}

int add_sum(int num)
{
	if (num == 0)
		return 0;
	else
		return num + add_sum(num - 1);
}
#endif

#if 0
/*
             1
          2  3
       4  5  6
    7  8  9 10
11 12 13 14 15
*/
#include <stdio.h>
#define NUM 5
int add_sum(int);

int main()
{
	int i, j, cnt = 1;
	int arr[NUM][NUM] = { 0 };

	for (i = 0; i < NUM; ++i)
	{
		for (j = 0; j < NUM; ++j)
		{
			if (j+1 < NUM-i)
				printf("     ");
			else
			{
				arr[i][j] = cnt++;
				printf("%5d", arr[i][j]);
			}
		}
		printf("\n");
	}
}

int add_sum(int num)
{
	if (num == 0)
		return 0;
	else
		return num + add_sum(num - 1);
}

#endif

#if 0
/*
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
#include <stdio.h>
#define NUM 5
int add_sum(int);

int main()
{
	int i, j, count = NUM, num = 0, row=0, col = -1, inc = 1;
	int a[100][100] = { 0 };

	while (1)
	{
		for (i = 0; i < count; i++)
			a[row][col += inc] = ++num;

		if (--count == 0)
			break;
		for (i = 0; i < count; i++)
			a[row += inc][col] = ++num;
		inc = -inc;
	}

	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			if (a[i][j])
				printf("%3d", a[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}
}

#endif

#if 0
/*
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
#include <stdio.h>
//#define NUM 5
int add_sum(int);

int main()
{
	int i, j, count, input, num = 0, row = 0, col = -1, inc = 1;
	int a[100][100] = { 0 };

	printf("숫자 입력: ");
	scanf_s("%d", &input);

	count = input;

	while (1)
	{
		for (i = 0; i < count; i++)
			a[row][col += inc] = ++num;

		if (--count == 0)
			break;
		for (i = 0; i < count; i++)
			a[row += inc][col] = ++num;
		inc = -inc;
	}

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			if (a[i][j])
				printf("%4d", a[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}
}

#endif