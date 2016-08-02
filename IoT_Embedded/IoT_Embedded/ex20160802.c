#if 0
#include <stdio.h>

int swap(int *a, int *b)
{
	int temp;
	printf("(sw)a: %d, b: %d\n", *a, *b);
	temp = *a;
	*a = *b;
	*b = temp;
	printf("(sw)a: %d, b: %d\n", *a, *b);
}

int main()
{
	int i = 10;
	int j = 20;
	printf("(ma)i: %d, j: %d\n", i, j);
	swap(&i, &j);
	printf("(ma)i: %d, j: %d\n", i, j);
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	int i = 7;
	int k;
	k = i++;
} // ����� �ؼ�, ����ȭ ����

#endif

/*
2. ������ ��
	1) ������
	2) ������
	3) ���� ��������
	4) �Ǽ���
	5) �����
	6) ������ ����
*/

/*
�����Ϸ��� �⺻������ �����ϴ� �⺻�� �����͵��̸�
�޸𸮿� ����Ǵ� ���¿� ���� ũ�� �������迭 �����Ϳ� �Ǽ��� �迭 �����ͷ� ����.
������ �迭 ������: ������, ������, ������ ������
�Ǽ��� �迭 ������: �Ǽ��� ������(float, double)
*/

#if 0
#include <stdio.h>

int main()
{
	float f = 10.625f;
	
	return 0;
}
#endif

/*
1. ������
char(signed char)	1byte		-128 ~ 127
unsigned char		1byte		0 ~ 255
*/

#if 0
#include <stdio.h>
int main()
{
	char ch1 = -1;
	unsigned char ch2 = -1;
	printf("ch1 = %d\n", ch1);
	printf("ch2 = %d\n", ch2);
	return 0;
}

#endif

/*
2. ������
short int (short, signed short int)		2byte		-32,768 ~ 32,767
unsigned short int(unsigned short)		2byte		0 ~ 65,535
int (signed, signed int)				4byte		-2,147,483,648 ~ 2,147,483,647
unsigned int							4byte		0 ~ 4,294,967,295
*/

#if 0
#include <stdio.h>
int main()
{
	int int_max = 2147483647;
	printf("int�� ������ �ִ밪 = %d\n", int_max);
	printf("int�� ������ �ִ밪+1 = %d\n", int_max+1);
	return 0;
}

#endif

/*
3. ������ ��������
	1) enum �������������� {����1, ����2, ..., ����n} [����1, ..., ����n];
	2) enum �������������� ����1, ..., ����n;

enum weekend {Saturday, Sunday} d1, d2;
enum weekend newday;
*/

#if 0
#include <stdio.h>
enum su {zero, one, two, three, four, five, six = 20, seven, eight, nine, ten}; // Ÿ�Լ���, su = Ÿ������, 0~10����
int main()
{
	enum su a; // a�� �������ִ°��� zero ~ ten�����̴�.
	a = two + six;
	//a = 13;
	printf("two + six = %d\n", a);
	printf("sizeof(a): %d\n", sizeof(a));
	return 0;
}

#endif

/*
4, �Ǽ���
	ũ��
float:	4byte
double: 8byte

float: -10e(-38) ~ 10e(+38)
double: -10e(-308) ~ 10e(+308)
*/

#if 0
#include <stdio.h>
int main()
{
	float su = 12.3456;
	printf("su = %f\n", su);
	printf("su = %e\n", su);
	return 0;
}
#endif


#if 0
#include <stdio.h>
int main()
{
	float f;
	double d;
	f = 123456750.12;
	d = 123456750.12;
	printf("Float type result = %f\n", f);
	printf("Double type result = %lf\n", d);
	return 0;
}

#endif

/*
5. ���
����� ���α׷� ��ü�� ���� �� �ǹ̰� ������ �ʴ� ���� ���Ѵ�.
1) ������ ���
	'A', '0', 'a', '*'
2) '\' Escape Sequence
	 Escape Sequence	�ش� ASCII ����			�̸�
			\0				NULL			NULL
			\a				BEL
			\b				BS				Backspace
			\f				FF				Form Feed
			\n				LF
			\r				CR
			\t				HT
			\v				VT
			\\				\
			\'				'
*/

#if 0
#include <stdio.h>
int main()
{
	printf("���� %c�� ASCII�ڵ� ���� %d �̴�.\n", 'a', 'a');
	printf("ASCII �ڵ� ���� %d�� ���� %c�̴�.\n", 98, 98);
}
#endif

/*
3) ������ ���
10����
8����
16����
*/

#if 0
#include <stdio.h>
int main()
{
	printf("10����: %d\n", 123);
	printf("8����: %d(10) %o(8)\n", 0677, 0677); // 0������ �ٷ� ���ڸ� �Է��ϸ� 8������ �Է��ϰڴٴ� �̾߱�
	printf("16����: %d(10) %x(16)\n", 0xa29, 0xa29); // 0x�� ���� ���ڸ� �Է��ϸ� 16������ �Է��ϰڴٴ� �̾߱�
}

#endif

/*
4) ���ڿ� ���
���ڿ��� �������� ���ڵ��� �ǹ��Ѵ�.
C������ �̸� �⺻ ������������ �������� �ʰ� �ִ�.
"test", "This is string", "123", "computer"
printf(" Warning !!\a\n");
*/

#if 0
#include <stdio.h>
int main()
{
	char* s = "Hello World";
	int i;
	for (i = 0; "Hello World"[i]; i++)
		//putchar("Hello World"[i]);
		printf("%c", "Hello World"[i]);
	printf("\n");
	return 0;
}

#endif

/*
������ ����
1) ��� ��Ī�� ������ �ҹ��ڿ� �빮��, ���� �׸��� ���ٹ���("_")�� ����Ͽ� �����.
2) ��Ī�� ���ڷ� �����ؼ��� �ȵȴ�.
3) ������ ��Ī���� ����� �� ����.

�ڷ��� ������;
������ ������ = �ʱⰪ;
*/

#if 0
#include <stdio.h>
int main()
{
	int ��� = 3;
	printf("%d\n", ���); // ��??? �������ϴ�. �����ڵ带 �����Ѵٴ� �����Ͽ�...
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 10;
	int *p = &i;
	int **pp = &p;
	int ***ppp = &pp;

	return 0;
}
#endif

/*
����� �Լ�
	1. �Է��Լ�
	2. ����Լ�

	1. �Է��Լ�
	scanf("���� ���� ���� ���ڿ�", �μ�1, �μ�2, ...);
	scanf("���� ��Ʈ��", &����);
*/

#if 0
#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	char c1, c2, c3;
	printf("Input first character: ");
	scanf("%c", &c1);
	c3 = getchar(); // Ű���忡�� ĳ���� �ϳ� �������� ��ɾ�
	//fflush(stdin);
	//scanf("%c", &c3);
	printf("Input second character: ");
	scanf("%c", &c2);
	//scanf("%c", &c3);

	printf("%d %d\n", c1, c2);
}

#endif

#if 1
#include <stdio.h>

int main(void)
{
	int num = 0x00FF00FF;
	unsigned char* p = (unsigned char*)&num; // ������ ���� �޸𸮸� �����ϴ°����� ���̳� �����δ� OS�� �޸𸮸� �������ִ°��̴�. ������ �Ӻ���带 �Ҷ� �ȵǴ� �۾�...

	//printf("%02X %02X %02X %02X\n", p[0], p[1], p[2], p[3]);
	printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3)); //�ּ��ڸ��� FF���� �����. little endian ���
	// (*(p+1)�� *p+1�� ȥ������ �ʵ�������. *p+1�� *p���� ����1�� ���Ѱ����� ��µ�.)

	return 0;
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int ch;
	printf("������ ���ڸ� �Է��ϼ���...\n");
	ch = getchar();
	printf("�Էµ� ���ڴ� %c�Դϴ�.\n", ch+('A'-'a'));
	return 0;
}
#endif
