#if 0
#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	char name1[30], name2[30];
	char *s = "Hello World!!!";
	char str[] = "hello";
	str[5] = 'k';
//	s[1] = 'a';
//	printf("�̸��� �Է��ϼ���! "); scanf("%s", name1);
//	printf("�̸��� �Է��ϼ���! "); scanf("%s", name2);
//	printf("���� �̸��� %s �Դϴ�.\n", name1);
//	printf("���� �̸��� %s �Դϴ�.\n", name2);
	printf("s: %s\n", s);
	printf("str: %s\n", str);
	return 0;
}

#endif

#if 0
#include <stdio.h>
int main()
{
	/*
	scanf...
	%s
	%d
	%o
	%x
	*/
	char c1, c2, c3;
	printf("Input three lowercase characters: ");
	c1 = getchar();
	c2 = getchar();
	c3 = getchar();

	printf("Converted: ");
	putchar(c1 - 32);
	putchar(c2 - 32);
	putchar(c3 - 32);
	putchar('\n');
}

#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int i = 0, j = 0, k = 0;
	printf("input 3 integer ");
	scanf("%d %d %d", &i, &j); // k�� ������ ���� ���ϸ� �׸��̴�! �׷���... �Է����ڰ� 3���϶� �۵�����?! << �Ҵ���� �������� ������ �ϴ� ������ �Ѵ�...
	printf("i = %d, j = %d, k = %d\n", i, j, k);
	return 0;
}
#endif

/*
	������
	- ���� ������, ���� ������, ���� ������

	1. ��� ������
		��ȣ			���Ǽ�			��ġ			�ǹ�
		 +			����				��ġ			���� ��ȣ(default)
		 -			����				��ġ			���� ��ȣ
		 +			����(��2��)		��ġ			����
		 -			����				��ġ			����
		 *			����				��ġ			����
		 /			����				��ġ			������
		 %			����				��ġ			������
		 ++			����				��ġ,��ġ	1����
		 --			����				��ġ,��ġ	1����
*/

#if 0
#include <stdio.h>
int main()
{
	int i = 5, j = 5;
	printf("i = %d, j = %d\n", i, j);
	printf("++i = %d, j++ = %d\n", ++i, j++);
	printf("i = %d, j = %d\n", i, j);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 5, j = 5;
	int k;
	k = ++i;
	k = j++;
}
#endif

#if 0
#include <stdio.h>
int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int k;
	k = sum(5, 6);
	printf("k: %d\n", k);
	k = sum(5, 3 + 6);
	printf("k: %d\n", k);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 5, j = 7;
	int k;

	k = i++ + ++j + ++i + j++ + ++i + ++j;
	printf("i: %d, j: %d, k: %d, i++: %d\n", i++, j, k, i); // printf�� ó������: ������->���� (i, k, j, i++) << ������ ����� �� �س��� ��ġ++������ �ӽð��� �����°����� ����Ѵ�.
	printf("i: %d, j: %d, k: %d, i++: %d\n", i, j, k, i++); // printf�� ó������: ������->���� (++i, k, j, i)
}
#endif

/*
	3. ���迬����
	��ȣ		���Ǽ�		��ġ		�ǹ�
	 <		 ����		��ġ		�۴�
	<=		 ����		��ġ		�۰ų� ����
	 >		 ����		��ġ		ũ��
	>=		 ����		��ġ		ũ�ų� ����
	==		 ����		��ġ		����
	!=		 ����		��ġ		���� �ʴ�.
*/

#if 0
#include <stdio.h>
int main()
{
	int i = 1, j = 2, k = -5;
	int val;
	val = (-i - 5 * j >= k + 1);
	printf("val: %d\n", val);
}
#endif

/*
	4. ��������
	��ȣ		���Ǽ�		��ġ		�ǹ�
	&&		����			��ġ		AND
	||		����			��ġ		OR
	!		����			��ġ		NOT

P	Q
0	0
0	1
1	0
1	1

*/

#if 0
#include <stdio.h>
int main()
{
	char c = 'B';
	int i = 3, j = 3, k = 3;
	double x = 0.0, y = 2.3;

	i && j && k; // 1 && 1 && 1
	!i - j; // !1 -> 0 - 3 = -3
	i * !x; // 3 * !0 -> 3 * 1 = 3
	i<j || x>y; // 0 || 0 = 0

	printf("1: %d\n", (i && j && k));
	printf("2: %d\n", (!i - j));
	printf("3: %d\n", (i * !x));
	printf("4: %d\n", (i<j || x>y));
}
#endif


/*
5. ���
	1. If���� ��
	2. while, do while
	3. for
	4. switch, break
	5. exit, continue, goto
*/

/*
if

if(���ǽ�)
	���� 1;
[else
	���� 2; ] -> �־���� ������ ����~

*/

#if 0
#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int su;
	scanf("%d", &su);
	if (su <= 10)
		printf("10 ������ ��\n");
	else
		printf("10���� ū ��\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int i;
	printf("Input an integer: ");
	scanf("%d", &i);

	if (i >= 0) {
		if (i % 2)
			printf("Odd number\n");
		else
			printf("Even number\n");
	}
	else
		printf("Negative number\n");
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int kor, eng, mat, avg;

	printf("3���� ������ �Է��ϼ���...\n");
	scanf("%d %d %d", &kor, &eng, &mat);
	avg = (kor + eng + mat) / 3;

	if (avg < 70)
		printf("���հ�\n");
	else if (kor < 60)
		printf("���հ�\n");
	else if (eng < 60)
		printf("���հ�\n");
	else if (mat < 60)
		printf("���հ�\n");
	else
		printf("�հ�!! \n");
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = 0;
	
	while (i < 10)
	{
		printf("i: %d\n", i);
		i++;
	}
}

#endif

#if 0
#include <stdio.h>
int main()
{
	char ch;
	while ((ch = getch()) != 0x1b)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
			putch(ch);
		}
	}
	printf("\n");
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int count_line = 0;
	int count_char = 0;
	char ch;
	while ((ch=getchar()) != EOF)
	{
		if (ch != '\n')
			++count_char;
		if (ch == '\n')
			++count_line;
		putch(ch);
	}
	printf("���ڼ��� %d �Դϴ�.\n", count_char);
	printf("���� Ƚ���� %d�Դϴ�.\n", count_line);
} // ������������ ���ư����� ���α����� �����쿡���� ���ư��� �ʴ� �����̴�...?

#endif // ����: �� ���ư����� ���ĺ��ô� ^��^;;;;;;


#if 0
#include <stdio.h>
int main()
{
	int res = 0;
	char c;
	while ((c = getchar()) == '0' || c == '1')
		res = res * 2 + c - '0';
	printf("Dec = %d, Oct = %o, Hex = %x\n", res, res, res);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i, sum;
	//for (sum = 0, i = 1; i <= 100; sum += i++); // 1~100���� ���ϴ� �������̴�.
	for (sum = 0, i = 1; i <= 100; sum = sum + i, i = i + 1); // 1~100���� ���ϴ� �������̴�.
	printf("sum = %d\n", sum);
}
#endif

#if 0
#include <stdio.h>
#pragma warning (disable:4996)
int main()
{
	int i, j;
	printf("Input number-> ");
	scanf("%d", &j);
	printf("Dec(%d)->Hex = %x, Oct = %o, Bin = ", j, j, j);
	for (i = 15; i >= 0; --i)
		printf("%d", (j >> i) & 0x01);
	printf("\n");
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (i == 3)
			exit(0);
		printf("i: %d\n", i);
	}
	printf("return\n");
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <Windows.h>
int main()
{
	int i;
	
	for (i = 0; i < 5; i++)
	{
		putchar('.');
		Sleep(1000);
		if (i == 4)
		{
			putchar('&');
			i = 0;
			continue;
		}
		putch('x');
	}
}
#endif

#if 0
#include <stdio.h>
#include <Windows.h>
int main()
{
	int i;
	int k = 0;

back:

	if (k == 2)
		goto end;
	for (i = 0; i < 5; i++)
	{
		putchar('.');
		Sleep(1000);
		if (i == 3)
		{
			putchar('\n');
			k++;
			goto back;
		}
	}
	printf("for�� �ܺ�\n");
	
end:
	printf("end \n");
	return 0;
}
#endif


#if 0
#include <stdio.h>
int sum(int a, int b)
{
	int result;
	result = a + b;
	return result;
}

int main()
{
	int i = 10, j = 20, k;
	k = sum(i, j);
	printf("%d\n", k);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i = -8;
	printf("%d\n", i);
	return 0;
}

#endif