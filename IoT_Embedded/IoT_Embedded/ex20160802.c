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
} // 어셈블리 해석, 최적화 가능

#endif

/*
2. 데이터 형
	1) 문자형
	2) 정수형
	3) 열거 데이터형
	4) 실수형
	5) 상수형
	6) 변수의 선언
*/

/*
컴파일러가 기본적으로 제공하는 기본형 데이터들이며
메모리에 저장되는 형태에 따라서 크게 정수형계열 데이터와 실수형 계열 데이터로 구분.
정수형 계열 데이터: 문자형, 정수형, 열거형 데이터
실수형 계열 데이터: 실수형 데이터(float, double)
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
1. 문자형
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
2. 정수형
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
	printf("int형 변수의 최대값 = %d\n", int_max);
	printf("int형 변수의 최대값+1 = %d\n", int_max+1);
	return 0;
}

#endif

/*
3. 열거형 데이터형
	1) enum 열거형데이터형 {원소1, 원소2, ..., 원소n} [변수1, ..., 변수n];
	2) enum 열거형데이터형 변수1, ..., 변수n;

enum weekend {Saturday, Sunday} d1, d2;
enum weekend newday;
*/

#if 0
#include <stdio.h>
enum su {zero, one, two, three, four, five, six = 20, seven, eight, nine, ten}; // 타입선언, su = 타입정의, 0~10까지
int main()
{
	enum su a; // a가 가질수있는값은 zero ~ ten까지이다.
	a = two + six;
	//a = 13;
	printf("two + six = %d\n", a);
	printf("sizeof(a): %d\n", sizeof(a));
	return 0;
}

#endif

/*
4, 실수형
	크기
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
5. 상수
상수는 프로그램 전체에 걸쳐 그 의미가 변하지 않는 값을 말한다.
1) 문자형 상수
	'A', '0', 'a', '*'
2) '\' Escape Sequence
	 Escape Sequence	해당 ASCII 문자			이름
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
	printf("문자 %c의 ASCII코드 값은 %d 이다.\n", 'a', 'a');
	printf("ASCII 코드 값은 %d인 문자 %c이다.\n", 98, 98);
}
#endif

/*
3) 정수형 상수
10진수
8진수
16진수
*/

#if 0
#include <stdio.h>
int main()
{
	printf("10진수: %d\n", 123);
	printf("8진수: %d(10) %o(8)\n", 0677, 0677); // 0을쓰고 바로 숫자를 입력하면 8진수로 입력하겠다는 이야기
	printf("16진수: %d(10) %x(16)\n", 0xa29, 0xa29); // 0x를 쓰고 숫자를 입력하면 16진수로 입력하겠다는 이야기
}

#endif

/*
4) 문자열 상수
문자열은 여러개의 문자들을 의미한다.
C언어에서는 이를 기본 데이터형으로 제공하지 않고 있다.
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
변수의 선언
1) 모든 명칭은 영문자 소문자와 대문자, 숫자 그리고 밑줄문자("_")만 사용하여 만든다.
2) 명칭은 숫자로 시작해서는 안된다.
3) 예약어는 명칭으로 사용할 수 없다.

자료형 변수명;
져료형 변수명 = 초기값;
*/

#if 0
#include <stdio.h>
int main()
{
	int 사과 = 3;
	printf("%d\n", 사과); // 응??? 가능은하다. 유니코드를 지원한다는 조건하에...
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
입출력 함수
	1. 입력함수
	2. 출력함수

	1. 입력함수
	scanf("형식 지정 제어 문자열", 인수1, 인수2, ...);
	scanf("포맷 스트링", &변수);
*/

#if 0
#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	char c1, c2, c3;
	printf("Input first character: ");
	scanf("%c", &c1);
	c3 = getchar(); // 키보드에서 캐릭터 하나 가져오는 명령어
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
	unsigned char* p = (unsigned char*)&num; // 눈에는 직접 메모리를 접촉하는것으로 보이나 실제로는 OS가 메모리를 접속해주는것이다. 실제로 임베디드를 할땐 안되는 작업...

	//printf("%02X %02X %02X %02X\n", p[0], p[1], p[2], p[3]);
	printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3)); //최소자리인 FF부터 저장됨. little endian 방식
	// (*(p+1)과 *p+1을 혼동하지 않도록하자. *p+1은 *p값에 숫자1을 더한값으로 출력됨.)

	return 0;
}

#endif

#if 0
#include <stdio.h>
int main()
{
	int ch;
	printf("임의의 문자를 입력하세요...\n");
	ch = getchar();
	printf("입력된 문자는 %c입니다.\n", ch+('A'-'a'));
	return 0;
}
#endif
