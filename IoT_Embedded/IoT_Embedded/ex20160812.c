#if 0
#include <stdio.h>
int main()
{
	double num = 25;
	int* ptr = &num;
}
#endif

//////////////// ������� ������ ȣ���

#if 0
#include <stdio.h>
/*
���⼭�� ���: char* str�� char str[]�� �Ѵ� �����ϴ�.
���⼭ �Ѵ� �����ϴٴ� �ٰŴ�... char str[]�� �迭�� ���ǿ� ���ؼ� str�� �������̰�
char* str�� str�� �����ͷ� �̸� �������ذ��̹Ƿ� "���Ǽ�"�� ���ؼ� �Ѵ� �����ϴٰ� ���°��̴�.
������ str[]������ str�� ����� �ƴϴ�. (�迭�� ũ�Ⱑ ���������� �������� �ٰŷ� ��������)
-> Ʋ��... ũ�⸦ ������ �Ǵ���...

���: �ܼ��� ���Ǽ��� ���ؼ� �׷��� �����س��ٰ� �������� ���ҰŰ���. -_-; (*str = str[])
C������ �����Ҷ��� ����İ� �Լ��� �Է��������μ��� ������� �ٸ������� �����ȴ�.
(�װ͵� ����� ���� ��쿡...)
*/
//void print(char* str)
//void print(char str[16])
void print(char str[])
{
	printf("str: %s\n", str);
	(*str)++;
}

int main()
{
	char amessage[] = "now is the time";
	char *pmessage = "now is the time";

	amessage[1] = 'k';
//	pmessage[1] = 'k';
//	amessage++;
//	pmessage++;
	print(amessage);
	print(pmessage); // ����~
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int k = 3;
	int *pa = &a[0]; // int *pa = &a;
	int i;

	printf("k = %d\n", k);
	a[-3] = 20;
	printf("k = %d\n", k);

	printf("\n");

	for (i = 0; i < 5; i++)
		printf("*(pa + %d) = %d\n", i, *(pa + i));
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("a[%d] = %d\n", i, a[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("*(a + %d) = %d\n", i, *(a + i));
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("*((char*)pa + %d) = %d\n", i, *((char*)pa + i));
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int *pa = a;
	int(*ppa)[4] = a;

	for (int i = 1; i < 13; i++)
	{
		printf("%d: %d\n", i-1, pa[i-1]);
		if (!(i % 4))
			printf("\n");
	}

	for (int i=0; i<3; i++)
		for (int j = 0; j < 4; j++)
		{
			printf("ppa[%d][%d] = %d\t", i, j, ppa[i][j]);
		}
	printf("\n");
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 5;
	int *p = &i;
	int *q;

	p = (int*)malloc(sizeof(int));
	*p = 5;
	q = p;
	*q = 10;
	printf("*p = %d\n", *p);
	*q = 20;
	printf("*p = %d\n", *p);

	free(p);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
void Init(int **, int num);
int main()
{
	int *p;
	int i;
	Init(&p, 5);

	for (i=0; i<5; ++i)
		printf("*(p + %d) = %d\n", i, *(p+i));

	free(p);
}

void Init(int *(*pp), int num)
{
	int i;

	*pp = (int*)malloc(sizeof(int) * num);
	//**pp = 7

	for (i = 0; i < num; ++i)
		(*pp)[i] = i + 1;
}
#endif


#if 0
#include <stdio.h>
#include <stdlib.h>
void Init(int ***, int);
int main()
{
	int i, j;
	int **p;
	Init(&p, 5);

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
			//printf("*(p+%d)+%d = %d\t", i, j, *(*(p + i) + j));
		printf("\n");
	}

	for (i=0; i<5; ++i)
		free(p[i]);
	free(p);
}

void Init(int ***ptr, int num) 
// ���: &p�� Ÿ���� (int*)�̴�. �׸��� 2�����迭�̹Ƿ� [][]�ε�... **�� (���ǻ�)��ü����
// �׷��Ƿ� int* + [][] (**) = int* ** = int*** (������ ���ع���̹Ƿ� ���ǿ��)
{
	int i, j, count = 0;

	*ptr = (int**)malloc(sizeof(int*)*num); 
	// (int**)���·� (int*)�������� num����ŭ �޸����

	for (i = 0; i < num; i++)
		*(*(ptr)+i) = (int*)malloc(sizeof(int)*num); 
	// (int*)���·� (int)�������� num����ŭ �޸����
	// *(*(ptr)+i) = *(ptr)[i] = (*ptr)[i] <= ����� (*ptr)[i]�� ���� ���غ���

	for (i=0; i<num; i++)
		for (j = 0; j < num; j++)
			(*ptr)[i][j] = count++;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 10;
	int* p;
	(int*)p = &i;
	p = (int*)&i;
	p = &i;

	printf("%d, %d\n", *p, i);
	printf("%p, %p\n", p, &i);
}
#endif // &i�� Ÿ���� �˾ƺ������� ����

#if 0
#include <stdio.h>
#include <stdlib.h>

void goo();
int foo(int, int);

int main()
{
	int a = 10;
	int b;
	b = foo(2, 7);
}

void goo()
{
	printf("Goooooooooo.....\n");
	exit(0);
}
int foo(int a, int b)
{
	int x = 10;
	int y[2] = { 1, 2 };
	printf("62%d1284\n", x*y[1]*y[0]*(x+2));
	y[7] = (int)goo; // ���� ��巹���� �޸��ּҸ� � �����س��� ���� �־����...-_-;
	return 0;
}
#endif

#if 0
#include <stdio.h>
#define MAX 3

void input(int*, int*, int*);
void calc(int*, int*, int*, int*, float*);
void ranking(int*, int*, int*, int*);
void display(int*, int*, int*, int*, float*, int*, int*, int*);

int main()
{
	int kor[MAX], eng[MAX], math[MAX], max, min;
	int total[MAX] = { 0, }, rank[MAX] = { 0, };
	float aver[MAX];

	input(kor, eng, math);
	calc(kor, eng, math, total, aver);
	ranking(total, rank, &min, &max);
	display(kor, eng, math, total, aver, rank, &max, &min);
	return 0;
}

void input(int *kor, int *eng, int *math)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		printf("%d�� �л� ����: ", i + 1);
		scanf_s("%d %d %d", kor + i, eng + i, math + i);
	}
}
void calc(int *kor, int *eng, int *math, int *total, float *aver)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		total[i] = kor[i] + eng[i] + math[i];
		aver[i] = (float)total[i] / MAX;
	}
}
void ranking(int *total, int *rank, int *min, int *max)
{
	int i, j;

	*max = *min = total[0];
	for (i = 0; i < MAX; i++)
	{
		if (*max < total[i])
			*max = total[i];
		if (*min > total[i])
			*min = total[i];
		for (j = 0; j < MAX; j++)
			if (total[i] <= total[j])
				rank[i]++;
	}
}
void display(int* kor, int* eng, int* math, int* total, float* aver, int* rank, int* max, int* min)
{
	int i;

	printf("����\t����\t����\t����\t���\t����\n");
	printf("=============================================\n");

	for (i = 0; i < MAX; i++)
		printf("%5d\t%5d\t%5d\t%5d\t%5.2f\t%5d\n",
			kor[i], eng[i], math[i], total[i], aver[i], rank[i]);
	printf("max: %5d, min: %5d\n", *max, *min);
}
#endif

#if 0
#include <stdio.h>
#define MAX 3

typedef struct
{
	int kor;
	int eng;
	int math;
	int total;
	float aver;
	int rank;
}ST;

void input(ST*);
void calc(ST*);
void ranking(ST*, int*, int*);
void display(ST*, int*, int*);

int main()
{
	int max, min;
	ST s[MAX] = { 0, };
	input(s);
	calc(s);
	ranking(s, *min, *max);
	display(s, *max, *min);
}

void input(ST* student)
{

}
void calc(ST* student)
{

}
void ranking(ST* student, int* min, int* max)
{

}
void display(ST* student, int* max, int* min)
{

}
#endif

#if 0
#include <stdio.h>
typedef struct
{
	int a;
	int b;
	char c;
	char d;
}AAA;

int main()
{
//	struct AAA a;
	//struct AAA {
	//	int a;
	//	int b;
	//	char c;
	//	char d;
	//}a; // ���� ������ ������ �Ѵ�. �ٸ� ���¸� �ٸ���
	AAA a;

	a.a = 10;
	a.b = 20;
	a.c = 'c';
	a.d = 'd';

	printf("a.a: %d\n", a.a);
	printf("a.b: %d\n", a.b);
	printf("a.c: %c\n", a.c);
	printf("a.d: %c\n", a.d);
	printf("sizeof(a): %d\n", sizeof(a));
}
#endif

#if 0
#include <stdio.h>
typedef struct
{
	int x;
	int y;
}POINT;

int main()
{
	POINT start = { 10, 10 };

	printf("start.x = %d\n", start.x);
	printf("start.y = %d\n", start.y);

	for (int i = 0; i < start.y; i++)
		printf("\n");
	for (int i = 0; i < start.x; i++)
		printf(" ");
	printf("*\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
typedef struct
{
	int x1;
	int y1;
	int x2;
	int y2;
}RECT;

int main()
{
	int i, j;
	RECT start = { 3, 3, 40, 10 };

	for (i = 0; i < start.y1; i++)
		printf("\n");
	for (i = 0; i < start.y2 - start.y1; i++)
	{
		for (j = 0; j < start.x1; j++)
			printf(" ");
		for (j = 0; j < start.x2 - start.x1; j++)
			printf("*");
		printf("\n");
	}
	printf("\n");
}
#endif

#if 0
#include <stdio.h>
typedef struct
{
	int x;
	int y;
}POINT;

typedef struct
{
	POINT p1; // ����ü ���� ����ü�� ������
	POINT p2;
}RECT;

int main()
{
	int i, j;
	RECT start = { {3,3}, {40,10} }; // { 3, 3, 40, 10 }���� �ص� �����ϰ� ����.

	printf("start.p1.x = %d\n", start.p1.x);
}
#endif

#if 0
#include <stdio.h>
typedef struct
{
	int x;
	int y;
}POINT;

typedef struct
{
	POINT p[2]; // ����ü ���� ����ü�� ������
}RECT;

int main()
{
	int i, j;
	RECT start = { { { 3,3 },{ 40,10 } } }; 
	// ���������� { 3, 3, 40, 10 }���� �ص� �����ϰ� ����. 

	printf("start.p[0].x = %d\n", start.p[0].x);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char *name;
	int age;
}PERSON;

int main()
{
	PERSON p, q;
	char buffer[256] = { 0, };
	
	printf("�̸�: ");
	gets_s(buffer, sizeof(buffer));
	p.name = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(p.name, strlen(buffer)+1, buffer); // �������, ����, �������

	printf("����: ");
	scanf_s("%d", &p.age);

	printf("�̸�: [%s]\n", p.name);
	printf("����: [%d]\n", p.age);

//	q = p;
	q.age = p.age;
	q.name = (char*)malloc(strlen(p.name)+1);
	strcpy_s(q.name, strlen(p.name), p.name);

	printf("�̸�: [%s]\n", q.name);
	printf("����: [%d]\n", q.age);

	strcpy_s(q.name, strlen("���"), "���");
	printf("�̸�: [%s]\n", p.name);

	free(p.name);
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char *name;
	int age;
}PERSON;

int main()
{
	PERSON p, q;
	PERSON* pp;
	pp = &p;
	char buffer[256] = { 0, };

	printf("�̸�: ");
	gets_s(buffer, sizeof(buffer));
	p.name = (char*)malloc(strlen(buffer) + 1);
	strcpy_s(p.name, strlen(buffer) + 1, buffer); // �������, ����, �������

	printf("����: ");
	scanf_s("%d", &p.age);

	printf("�̸�: [%s]\n", p.name);
	printf("����: [%d]\n", p.age);

	printf("�̸� -> [%s]\n", pp->name);
	printf("���� -> [%d]\n", pp->age);

	free(pp->name);
}

#endif

#if 0
#include <stdio.h>
typedef struct
{
	signed char i : 2, // ó�� �κ�Ʈ�� i�� ����Ѵ�.
		j : 3, // �״��� �� bit�� j�� ����Ѵ�.
		k : 2, // �״��� �� bit�� k�� ����Ѵ�.
		l : 1; // ������ �� bit�� l�� ����Ѵ�.
}BIT;

int main()
{
	BIT b;
	b.i = 3;
	b.j = 7;
	b.k = 3;
	b.l = 0;

	printf("sizeof(BIT) => %d\n", sizeof(BIT));

	printf("b.i => %d\n", b.i);
	printf("b.j => %d\n", b.j);
	printf("b.k => %d\n", b.k);
	printf("b.l => %d\n", b.l);
}
#endif

#if 1
#include <stdio.h>
typedef union // ����ü�� ���� ����� ū�� �ϳ��� ������. (���⼱ int�� ���� ũ�ϱ�? 4����Ʈ)
{
	int i;
	short s[2];
	char c[4];
}U;

int main()
{
	U u;
	u.i = 0x12345678;
	printf("sizeof(U) => %d\n", sizeof(U));

	printf("u.i: %X\n", u.i);
	printf("u.s[0]: %X\n", u.s[0]);
	printf("u.s[1]: %X\n", u.s[1]);
	printf("u.c[0]: %X\n", u.c[0]);
	printf("u.c[1]: %X\n", u.c[1]);
	printf("u.c[2]: %X\n", u.c[2]);
	printf("u.c[3]: %X\n", u.c[3]);
}
#endif