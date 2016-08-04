#if 0
#include <stdio.h>
/*
int big(int x, int y)
{
	if (x > y)
		return x;
	else if (x < y)
		return y;
	else
		return 0;
}
*/
int big(int x, int y)
{
	if (x != y)
		return x > y ? x : y; // x > y�� ���� ���̸� x�� �ѱ�� �ƴϸ� y�� �ѱ��.
	else
		return 0;
}
int main()
{
	int a = 100, b = 200;
	int result = big(a, b);
	printf("ū����: %d\n", result);
	return 0;
}
#endif

/*
	�Լ� ȣ�� �Ծ�(CAlling Convention)
	: ȣ����(caller)�� ��ȣ����(callee)���� �Լ� ȣ��� ���޵Ǵ� ������
	������ ȣ��� �Լ��� ���ϵɶ� ��������� ���� ���
	__cdecl, __stdcall, __fastcall (<< �ٸ��͵� ������ �츮�� ������ �ϴ� 3�����̴�.)
*/

#if 0
/*
__cdecl ���
1. C/C++ �Լ����� �⺻������ ���Ǵ� ȣ�� �Ծ�
2. ȣ���ڰ� ��������
3. ���ڴ� �����ʿ��� �������� ����
4. ȣ���ڰ� ȣ��� ���޵Ǵ� ������ ������ �˰� �ֱ� ������ ���� �μ� �Լ��� ����� �ִ�.
int __cdecl sum(int a, int b)
*/
int __cdecl sum(int a, int b)
{
	return a + b;
}
int main()
{
	sum(5, 4);
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
	printf("k: %d\n", k); // �ñ��ϸ� ����׸�忡�� eax�� �ٲ���� k���� �ٲ���� ���� ������ Ȯ���غ����ִ�!
}
#endif

/*
__stdcall ���
1. Win32 API���� ���
2. ��ȣ���ڰ� ���� ����
3. ���ڴ� �����ʿ��� �������� ����
4. Win32 API������ ���� �μ� �Լ��� ���� ������
	�Ű������� ������ �������̴�.
*/
#if 0
int __stdcall sum(int a, int b)
{
	return a + b;
}

int main()
{
	sum(5, 4);
	return 0;
}
#endif // ARM���� ������ �Ǵ����� ���� Ȯ���� ���غ��� �𸨴ϴ�...

/*
__fastcall
1. �������͸� ���
2. ȣ�� �ӵ��� ������
3. ���� ������ �ʿ����
*/

#if 0
int _fastcall sum(int a, int b)
{
	return a + b;
}

int main()
{
	sum(5, 4);
	return 0;
}
#endif

#if 0
#include <stdio.h>
void aaa()
{
	printf("Aaa\n");
}

void bbb()
{
	aaa();
	printf("Bbb\n");
}

void ccc()
{
	bbb();
	printf("Ccc\n");
}

int main()
{
	ccc();
	printf("main\n");
	return 0;
}
#endif // ���������� ����� �˴ϴ�~

#if 0
#include <stdio.h>
int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	int i;
	i = factorial(5);
	printf("5! = %d\n", i);
	return 0;
}
#endif

/*
static
extern
*/

#if 0
#include <stdio.h>
extern int sum(int, int); // extern = �� �Լ��� �ٱ��� �ִ�. (�� ������ �ƴ� �ٸ� ���Ͽ� �ִ�.)
int main()
{
	int i = 10, j = 20, k;
	k = sum2(i, j);
	printf("k: %d\n", k);
	return 0;
}

#endif

/*
auto, extern, static
*/
#if 0
int main()
{
	auto int i = 7; // static�� extern�߿� �ڵ����� �������ݴϴ�~ (����...)
	int k = 20;
}

#endif

#if 0
#include <stdio.h>
int main()
{
	extern int i;
	int j = 20;
	int k;
	k = i + j;
	printf("k: %d\n", k);
}
#endif // extern������ ��� ���������� �Ǿ���Ѵ�. (�Լ��� �Լ��� ����� ������ ������ �Ǳ⶧���̴�.)

#if 0
#include <stdio.h>
int foo()
{
	static int a = 10; // foo�� access�Ҽ��ִ� ����������� �����ϸ�ɰ�...
	a++;
	return a;
}

int main()
{
	int i;
	i = foo();
	printf("1st i: %d\n", i);
	i = foo();
	printf("2nd i: %d\n", i);
	i = foo();
	printf("3rd i: %d\n", i);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int* foo()
{
	static int a = 10;
	return &a;
}

int* goo()
{
	int b = 20;
	return &b;
}

int main()
{
	int* k;
	int* p;
	k = foo();
	printf("*k: %d, k: %08X\n", *k, k);
	p = goo();
	printf("*p: %d, p: %08X\n", *p, p);
	printf("*k: %d\n", *k);
	printf("*p: %d\n", *p);
}
#endif

#if 0
#include <stdio.h>
int* foo()
{
	static int a = 0;
	printf("a: %d\n", a);
	return &a;
}

int main()
{
/*	int *p;
	p = foo();
	*p = 20;	*/
	*foo() = 20;
	foo();
}
#endif

#if 1
#define MAX 10
int main()
{
	int i;
	for (i = 0; i < MAX; i++)
	{
	}
	return 0;
}
#endif