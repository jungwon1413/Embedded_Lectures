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
	//unsigned char ch = 255;와 동일하게 인식한다.
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
	//FP2 p = bbb; // typedef FP2에서의 정의
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
	printf("정수 입력: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("연산자 입력: ");
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
double multi(double a, double b) // 출력계산시 오류가납니다.
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

	printf("정수 입력: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("연산자 입력: ");
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
double multi(double a, double b) // 출력계산시 오류가납니다.
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

	printf("정수 입력: ");
	scanf("%d %d", &a, &b);
	getchar();
	printf("연산자 입력: ");
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
/* 이 프로그램은 인수 처리 프로그램 */
int main(int argc, char *argv[], char *envp[]) // 프로그램이 시작되는 포인트 (운영체제가 포인터로 지정하고있는 시작 함수위치가 바로 main이다.), 'envp' is not specified by POSIX, but widely supported.
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

	printf("[%d]\n", a); // a정수 출력
	printf("[%10d]\n", a); // 10칸을 확보하고 그안에서 a정수 출력
	printf("[%-10d]\n", a); // 10칸을 확보하고 그안에서 a정수를 왼쪽정렬해서 출력
	printf("[%010d]\n", a); // 10칸을 확보하고 그안에서 a정수를 출력, 빈칸은 0으로 채운다.
	printf("[%+010d]\n", a); // 10칸을 확보하고 그안에서 a정수를 출력, 빈칸은 0으로 채우고 맨 왼쪽에 +기호를 넣는다.
	printf("[%x]\n", a); // 16진수로 표기한다.(알파벳은 소문자로 표기)
	printf("[%X]\n", a); // 16진수로 표기한다.(알파벳은 대문자로 표기)
	printf("[0x%X]\n", a); // 0x 출력후 위와 동일 (대문자 표기)
	printf("[%#X]\n", a); // 0X%X와 동일하다.
	printf("[%#o]\n", a); // 0%o와 동일하다.

	printf("[%f]\n", f); // float형식으로 출력한다.
	printf("[%10.2f]\n", f); // 10칸을 확보후 소수점이하 2개만의 숫자만을 출력한다.
	
	printf("[%s]\n", buf); // 문자열을 출력한다.
	printf("[%10s]\n", buf); // 10칸을 확보하고 그안에서 문자열을 출력한다.

	printf("[%e]\n", f1); // exponential 표기법으로 숫자를 출력한다.
	printf("[%g]\n", f1); // %f와 %e중 더 짧은것을 선택하여 출력한다.

	putchar('B'); // B 한문자만 출력
	putchar('I'); // I 출력
	putchar('T'); // T 출력
	putchar('\n'); // 엔터 출력 (엔터를 치는것과 같은 의미)

	puts("I like C."); // 한줄에 I like C. 를 표시하고 줄을 넘긴다.
	puts("I like Program."); // 한줄에 I like Program. 을 표시하고 줄을 넘긴다.

	fputs("I like C.\n", stdout); // stdout(여기서는 출력인자가 모니터밖에 없으므로 모니터만 해당된다.)에 I like C.를 출력한다.
	fputs("I like Program.\n", stdout); // stdout에 I like Program.을 출력한다.
	fputs("I like C Program.\n", stdout); // stdout에 I like C Program.을 출력한다.
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