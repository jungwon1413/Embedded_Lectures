#if 0
#include <stdio.h>
int main()
{
	unsigned char a = 0xFF;
	int b = 0xFFFFFFFF;
	b = a;

	printf("%08X\n", b);
	return 0;
}

#endif

#if 0
#include <stdio.h>
int main()
{
	char a = 10;
	int *b;
	b = &a;
	*b = 10;
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a[2] = { 1, 2 };
	int *p = a;

	printf("p: %p\n", p);
	p[1] = 10;

	p++;
	printf("p: %p\n", p);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	/*int ip = 0x12345678;
	char *p = (char*)&ip;

	int i;
	for (i = 0; i < 4; i++)
		printf("%X\n", p[i]);*/

	int i = 0x12345678;
	char *p = i;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a[4] = { 1,2,3,4 };
	int *p = a;
	char *ch = a;

	printf("sizeof(p): %d\n", sizeof(p));
	printf("sizeof(int*): %d\n", sizeof(int*));
	printf("sizeof(char*): %d\n", sizeof(char*));
	printf("sizeof(*): %d\n", sizeof(*ch));
	printf("sizeof(a): %d\n", sizeof(a));
	printf("sizeof(&): %d\n", sizeof(&a));
	printf("sizeof(int[4]): %d\n", sizeof(int[4]));
	return 0;
}
#endif

#if 0
#include <stdio.h>
typedef int (*FF)[2];
int main()
{
	int a[2][2] = { 1, 2, 3, 4 };
	int *p = a;

	((FF)(p))[1][1] = 10;
	printf("a[1][1] = %d\n", a[1][1]);

	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a[2][2] = { 1, 2, 3, 4 };
	int (*p)[2] = a;

	p[1][1] = 10;
	printf("a[1][1] = %d\n", a[1][1]);

	return 0;
}
#endif

#if 0
//함수인자로 배열 넘기기
#include <stdio.h>
void init(int p[2]) // 또는 int p[]
{
	int i;
	for (i = 0; i < 4; ++i)
		p[i] = i + 1;
}

int main()
{
	int a[4];
	int i;
	init(a);
	for (i=0; i<4; ++i)
		printf("a[%d] = %d\n", i, a[i]);
}
#endif

#if 0
//함수인자로 배열 넘기기
#include <stdio.h>
void init(int (*p)[2])
{
	int i, j;
	int cnt = 1;
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 2; ++j)
			p[i][j] = cnt++;
}

int main()
{
	int a[2][2];
	int i, j;
	init(a);
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 2; ++j)
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
}
#endif

#if 0
#include <stdio.h>
int (*foo(void))[2]
{
	static int a[2][2] = { 1,2,3,4 };
	return a;
}

int main()
{
	int (*v)[2];
	v = foo();
	foo()[1][1] = 30;
	printf("*v: %d\n", foo()[1][1]);
//	printf("foo(): %p\n", &foo()); // 오류의 원인은?
}
#endif

#if 0
#include <stdio.h>
void foo(void)
{
	printf("foo is called\n");
}

int main()
{
	foo();
}
#endif

#if 0
#include <stdio.h>
void foo(void)
{
	printf("foo is called\n");
}

int main()
{
	void (*p)(void) = foo;
	p();
}
#endif

#if 0
#include <stdio.h>
int foo(int a, int b)
{
	printf("foo is called\n");
	printf("a: %d, b: %d\n", a, b);
	return a + b;
}

int main()
{
	int(*fp)(int, int) = foo;

	printf("fp(5, 6): %d\n", fp(5, 6));
	
	fp(5, 6);
}
#endif

#if 0
#include <stdio.h>
void foo(void)
{
	printf("foo is called\n");
}
void bar(void (*fp)(void))
{
	fp();
	printf("bar is called\n");
}

int main()
{
	bar(foo);
	return 0;
}
#endif

#if 0
#include <stdio.h>
void ccc(void)
{
	printf("cccc is called\n");
}

void (* foo(void))(void)
{
	printf("foo is called\n");
	return ccc;
}

//int bar()
//void* bar(void)
//void(*bar(void))(void)
void (*(*bar(void))(void))(void)
{
	printf("bar is called\n");
	return foo;
}

int main()
{
	//  int(*fp)(foo) = bar();
	//	void(*fp)(void) = bar();
	//  fp();
	bar()()(); // bar를 호출하고 bar의 리턴값이 foo이니까... bar() = foo라고 인식! 그러므로 bar를 실행후 foo()를 실행한것과 동일한것이다.

	return 0;
}
#endif