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
		return x > y ? x : y; // x > y의 값이 참이면 x를 넘기고 아니면 y를 넘긴다.
	else
		return 0;
}
int main()
{
	int a = 100, b = 200;
	int result = big(a, b);
	printf("큰값은: %d\n", result);
	return 0;
}
#endif

/*
	함수 호출 규약(CAlling Convention)
	: 호출자(caller)와 피호출자(callee)간에 함수 호출시 전달되는 인자의
	순서나 호출된 함수가 리턴될때 스택정리등에 대한 약속
	__cdecl, __stdcall, __fastcall (<< 다른것도 많지만 우리가 볼것은 일단 3가지이다.)
*/

#if 0
/*
__cdecl 방식
1. C/C++ 함수에서 기본적으로 사용되는 호출 규약
2. 호출자가 스택정리
3. 인자는 오른쪽에서 왼쪽으로 전달
4. 호출자가 호출시 전달되는 인자의 개수를 알고 있기 떄문에 가변 인수 함수를 만들수 있다.
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
	printf("k: %d\n", k); // 궁금하면 디버그모드에서 eax값 바꿔놓고 k값이 바뀌는지 직접 눈으로 확인해볼수있다!
}
#endif

/*
__stdcall 방식
1. Win32 API에서 사용
2. 피호출자가 스택 정리
3. 인자는 오른쪽에서 왼쪽으로 전달
4. Win32 API에서는 가변 인수 함수가 없기 때문에
	매개변수의 개수가 고정적이다.
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
#endif // ARM에도 적용이 되는지는 아직 확인을 안해봐서 모릅니다...

/*
__fastcall
1. 레지스터를 사용
2. 호출 속도가 빠르다
3. 스택 정리가 필요없다
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
#endif // 스택형으로 출력이 됩니다~

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
extern int sum(int, int); // extern = 이 함수는 바깥에 있다. (이 파일이 아닌 다른 파일에 있다.)
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
	auto int i = 7; // static과 extern중에 자동으로 선택해줍니다~ (편함...)
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
#endif // extern변수는 모두 전역변수로 되어야한다. (함수는 함수의 실행시 변수의 생성이 되기때문이다.)

#if 0
#include <stdio.h>
int foo()
{
	static int a = 10; // foo만 access할수있는 전역변수라고 생각하면될것...
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