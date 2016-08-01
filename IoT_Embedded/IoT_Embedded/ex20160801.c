#if 0
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int *p[] = { &a, &b, &c, &d };

	*p[1] = 100;


}

#endif

/*
1. C 프로그램의 구조
2. 데이터형
3. 입출력 함수
4. 연산자
5. 제어문
6. 함수
7. 변수의 메모리형
8. 배열
9. 포인터
10. 구조체와 공용체
11. 파일 입출력
*/

/*
1. C 프로그램의 기본구조
구조					기능

전처리기 영역		#include, #define,
선언 영역			함수와 전역변수 선언
Main()				프로그램의 시작부분
사용자정의 함수		프로그램에서 사용할 함수 정의
*/

#if 0
// C 프로그램 예제			//한줄 주석문
#include <stdio.h>			//전처리 영역

int main()					//Main 함수 선언과 동시에 정의
{							//중괄호는 함수 또는 블럭의 시작
	printf("Hello World!!\n"); // 문장을 나타내며 ';'은 문장 끝
	return 0;
}							//중괄호에 대한 닫음(main 함수의 끝을 나탄낸다.)

#endif


#if 0
#include <stdio.h>

int add();
int i = 3, j = 7;
int main()
{
	int a = add();
	printf("%d + %d = %d\n", i, j, a);
	return 0;
}
int add()
{
	int sum = i + j;
	return sum;
}
#endif

#if 0
/*
2, 출력함수
printf("출력 데이터형태", 출력변수들);
출력 데이터 형태: 변환문자(%)와 제어문자(\)
1) 변환문자

문자		기능
%d		부호있는 10진수 출력
%u		부호없는 10진수 출력
%s		16진수로 출력 (hexa)
%c		아스키 문자로 출력 (character)
%f		부동 소수점형 출력 (float)
%e		지수 형식으로 출력 (exponent)
%g		%e, %f 중에 더 짧은 형태로 출력
%%		%자체를 출력

형식						출력			기능
printf("%d", 234);			234			3글자의 폭으로 출력
printf("%5d", 234);			--234		5글자의 폭으로 출력
printf("%05d", 234);		00234		폭은 5, 앞의 공란은 0
printf("%-5d", 234);		234--		폭은 5, 왼쪽정렬
printf("%5.1f", 234.56);	234.6		폭은 5, 소수점 이하 1자리
printf("%06.1f", 234.56);	0234.6		앞의 공란은 0
*/

#include <stdio.h>

int main()
{
	printf("%d\n", 234);
	printf("%5d\n", 234);
	printf("%05d\n", 234);
	printf("%-5d\n", 234);
	printf("%5.1f\n", 234.56);
	printf("%06.1f\n", 234.56);
}
#endif

#if 0
/*
2) 제어 문자: '\' 이스케이프(escape)

제어문자			기능
\n			커서를 다음행의 선두로 이동 (new line)
\t			커서를 탭 간격만큼 이동 (tab)
\b			커서를 한 칸 앞으로 이동 (back space)
\r			커서를 같은 행의 선두로 이동(carriage return)
\f			용지를 한 장 넘김(form feed)
\a			벨소리를 냄(alarm)
*/
#include <stdio.h>
int main()
{
	printf("Hello, World!!");
	printf("\n\a");
	printf("Hello\nWorld!!\n");
	printf("\tHello, World!!\n");
	return 0;
}
#endif

#if 1
/*
입력함수
scanf()함수를 사용하여 키보드로 부터 수치나 문자등을 입력받는다.
scanf("입력변환문자", 인자);

문자(입력변환문자)		기능
%d				부호있는 10진수로 입력
%u				부호없는 10진수로 입력
%f				부동 소수점형으로 입력
%s				문자열을 입력
%c				1 문자 입력
*/
#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	char ch;
	int i;

	printf("정수 및 문자 입력: ");
	scanf("%d %c", &i, &ch);

	printf("i: %d, ch: %c\n", i, ch);
	return 0;
}
#endif