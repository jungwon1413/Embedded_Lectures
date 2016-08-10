#if 0
#include <stdio.h>
int aaa(int a)
{
	a += 10;
	return a;
}
int ccc(int c)
{
	c -= 10;
	return c;
}
int (*bbb(int a, int (*p)(int)))(int)
{
	a += 10;
	a = p(a);
	return aaa;
}
int main()
{
	int(*(*p)(int a, int(*)(int)))(int) = bbb;
//	??? p = bbb;
	int (*rp)(int) = ccc;
//	??? rp = ccc;
	rp = p(10, aaa);
	printf("rp: %d\n", rp(20));

	printf("p(10, aaa)(40): %d\n", p(10, aaa)(40));
	return 0;
}
#endif

#if 0
#include <stdio.h>
typedef unsigned char uchar;

int main()
{
	uchar ch = 255;
	//unsigned char ch = 255;�� �����ϰ� �ν��Ѵ�.
	printf("ch: %d\n", ch);
}
#endif

#if 0
#include <stdio.h>
typedef int(*FP1)(int);
typedef FP1(*FP2)(int , FP1);

int aaa(int a)
{
	a += 10;
	return a;
}
int ccc(int c)
{
	c -= 10;
	return c;
}
//int(*bbb(int a, int(*p)(int)))(int)
//int(*bbb(int a, FP1 p))(int)
FP1 bbb(int a, FP1 p)
{
	a += 10;
	a = p(a);
	return aaa;
}
int main()
{
	//int(*(*p)(int a, int(*)(int)))(int) = bbb;
	FP1(*p)(int, FP1) = bbb;
	//FP2 p = bbb; // typedef FP2������ ����
	//	??? p = bbb;

	int(*rp)(int) = ccc;
	//	??? rp = ccc;
	rp = p(10, aaa);
	printf("rp: %d\n", rp(20));

	printf("p(10, aaa)(40): %d\n", p(10, aaa)(40));
	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int multi(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}

int main()
{
	int a, b;
	int result;
	char op;
	printf("���� �Է�: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("������ �Է�: ");
	scanf("%c", &op);

	switch (op)
	{
	case '+':
		result = add(a, b);
		printf("%d + %d = %d\n", a, b, result);
		break;
	case '-':
		result = sub(a, b);
		printf("%d - %d = %d\n", a, b, result);
		break;
	case '*':
		result = multi(a, b);
		printf("%d * %d = %d\n", a, b, result);
		break;
	case '/':
		result = div(a, b);
		printf("%d / %d = %d\n", a, b, result);
		break;
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
double multi(double a, double b) // ��°��� ���������ϴ�.
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}

int main()
{
	int a, b;
	int result;
	char op;
	int(*fp_arr[])(int, int) = { add, sub, multi, div };

	printf("���� �Է�: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("������ �Է�: ");
	scanf("%c", &op);

	switch (op)
	{
	case '+':
		result = fp_arr[0](a, b);
		printf("%d + %d = %d\n", a, b, result);
		break;
	case '-':
		result = fp_arr[1](a, b);
		printf("%d - %d = %d\n", a, b, result);
		break;
	case '*':
		result = fp_arr[2](a, b);
		printf("%d * %d = %d\n", a, b, result);
		break;
	case '/':
		result = fp_arr[3](a, b);
		printf("%d / %d = %d\n", a, b, result);
		break;
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
double multi(double a, double b) // ��°��� ���������ϴ�.
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}

struct op_func
{
	int(*st_add)(int, int);
	int(*st_sub)(int, int);
	double(*st_multi)(double, double);
	int(*st_div)(int, int);
};

int main()
{
	int a, b;
	int result;
	char op;
	//int(*fp_arr[])(int, int) = { add, sub, multi, div };
	struct op_func oper = { add, sub, multi, div };

	printf("���� �Է�: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("������ �Է�: ");
	scanf("%c", &op);

	switch (op)
	{
	case '+':
		result = oper.st_add(a, b);
		printf("%d + %d = %d\n", a, b, result);
		break;
	case '-':
		result = oper.st_sub(a, b);
		printf("%d - %d = %d\n", a, b, result);
		break;
	case '*':
		result = oper.st_multi(a, b);
		printf("%d * %d = %d\n", a, b, result);
		break;
	case '/':
		result = oper.st_div(a, b);
		printf("%d / %d = %d\n", a, b, result);
		break;
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
/* �� ���α׷��� �μ� ó�� ���α׷� */
int main(int argc, char *argv[], char *envp[]) // ���α׷��� ���۵Ǵ� ����Ʈ (�ü���� �����ͷ� �����ϰ��ִ� ���� �Լ���ġ�� �ٷ� main�̴�.), 'envp' is not specified by POSIX, but widely supported.
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf(" %s\n", argv[i]);
	}

	printf("hello world!!\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a = 1234;
	float f = 3.14f;
	char buf[] = "hello";
	char c = 'a' - 32;
	float f1 = 0.1f;

	printf("[%d]\n", a); // a���� ���
	printf("[%10d]\n", a); // 10ĭ�� Ȯ���ϰ� �׾ȿ��� a���� ���
	printf("[%-10d]\n", a); // 10ĭ�� Ȯ���ϰ� �׾ȿ��� a������ ���������ؼ� ���
	printf("[%010d]\n", a); // 10ĭ�� Ȯ���ϰ� �׾ȿ��� a������ ���, ��ĭ�� 0���� ä���.
	printf("[%+010d]\n", a); // 10ĭ�� Ȯ���ϰ� �׾ȿ��� a������ ���, ��ĭ�� 0���� ä��� �� ���ʿ� +��ȣ�� �ִ´�.
	printf("[%x]\n", a); // 16������ ǥ���Ѵ�.(���ĺ��� �ҹ��ڷ� ǥ��)
	printf("[%X]\n", a); // 16������ ǥ���Ѵ�.(���ĺ��� �빮�ڷ� ǥ��)
	printf("[0x%X]\n", a); // 0x ����� ���� ���� (�빮�� ǥ��)
	printf("[%#X]\n", a); // 0X%X�� �����ϴ�.
	printf("[%#o]\n", a); // 0%o�� �����ϴ�.

	printf("[%f]\n", f); // float�������� ����Ѵ�.
	printf("[%10.2f]\n", f); // 10ĭ�� Ȯ���� �Ҽ������� 2������ ���ڸ��� ����Ѵ�.
	
	printf("[%s]\n", buf); // ���ڿ��� ����Ѵ�.
	printf("[%10s]\n", buf); // 10ĭ�� Ȯ���ϰ� �׾ȿ��� ���ڿ��� ����Ѵ�.

	printf("[%e]\n", f1); // exponential ǥ������� ���ڸ� ����Ѵ�.
	printf("[%g]\n", f1); // %f�� %e�� �� ª������ �����Ͽ� ����Ѵ�.

	putchar('B'); // B �ѹ��ڸ� ���
	putchar('I'); // I ���
	putchar('T'); // T ���
	putchar('\n'); // ���� ��� (���͸� ġ�°Ͱ� ���� �ǹ�)

	puts("I like C."); // ���ٿ� I like C. �� ǥ���ϰ� ���� �ѱ��.
	puts("I like Program."); // ���ٿ� I like Program. �� ǥ���ϰ� ���� �ѱ��.

	fputs("I like C.\n", stdout); // stdout(���⼭�� ������ڰ� ����͹ۿ� �����Ƿ� ����͸� �ش�ȴ�.)�� I like C.�� ����Ѵ�.
	fputs("I like Program.\n", stdout); // stdout�� I like Program.�� ����Ѵ�.
	fputs("I like C Program.\n", stdout); // stdout�� I like C Program.�� ����Ѵ�.
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	printf("sizeof(long): %d\n", sizeof(long));
	printf("sizeof(int): %d\n", sizeof(int));
	printf("sizeof(long long): %d\n", sizeof(long long));
	unsigned long long nc = 0xFFFFFFFF;
	nc = nc + 1;
	printf("%I64u\n", nc);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	printf("<\"That's great! You scored 99%%\">\n");
}

#endif

#if 0
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	/*char ch1, ch2;
	ch1 = getchar();
	ch2 = getchar();
	putchar(ch2);
	putchar(ch1);*/

	char buf[6];
	int i;
	
	for (i = 5; i >= 0; --i)
	{
		if (i != 5)
			buf[i] = getchar();
		else
			buf[i] = 0;
	}
	printf("%s\n", buf);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main()
{
	int age;
	char* buffer = (char*) malloc (sizeof(char) * 200);
	sscanf("19 cool kid", "%d %[^\t\n]", &age, buffer);

	printf("%s is %d years old\n", buffer, age);
	free(buffer);
	return 0;
}
#endif