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
1. C ���α׷��� ����
2. ��������
3. ����� �Լ�
4. ������
5. ���
6. �Լ�
7. ������ �޸���
8. �迭
9. ������
10. ����ü�� ����ü
11. ���� �����
*/

/*
1. C ���α׷��� �⺻����
����					���

��ó���� ����		#include, #define,
���� ����			�Լ��� �������� ����
Main()				���α׷��� ���ۺκ�
��������� �Լ�		���α׷����� ����� �Լ� ����
*/

#if 0
// C ���α׷� ����			//���� �ּ���
#include <stdio.h>			//��ó�� ����

int main()					//Main �Լ� ����� ���ÿ� ����
{							//�߰�ȣ�� �Լ� �Ǵ� ���� ����
	printf("Hello World!!\n"); // ������ ��Ÿ���� ';'�� ���� ��
	return 0;
}							//�߰�ȣ�� ���� ����(main �Լ��� ���� ��ź����.)

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
2, ����Լ�
printf("��� ����������", ��º�����);
��� ������ ����: ��ȯ����(%)�� �����(\)
1) ��ȯ����

����		���
%d		��ȣ�ִ� 10���� ���
%u		��ȣ���� 10���� ���
%s		16������ ��� (hexa)
%c		�ƽ�Ű ���ڷ� ��� (character)
%f		�ε� �Ҽ����� ��� (float)
%e		���� �������� ��� (exponent)
%g		%e, %f �߿� �� ª�� ���·� ���
%%		%��ü�� ���

����						���			���
printf("%d", 234);			234			3������ ������ ���
printf("%5d", 234);			--234		5������ ������ ���
printf("%05d", 234);		00234		���� 5, ���� ������ 0
printf("%-5d", 234);		234--		���� 5, ��������
printf("%5.1f", 234.56);	234.6		���� 5, �Ҽ��� ���� 1�ڸ�
printf("%06.1f", 234.56);	0234.6		���� ������ 0
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
2) ���� ����: '\' �̽�������(escape)

�����			���
\n			Ŀ���� �������� ���η� �̵� (new line)
\t			Ŀ���� �� ���ݸ�ŭ �̵� (tab)
\b			Ŀ���� �� ĭ ������ �̵� (back space)
\r			Ŀ���� ���� ���� ���η� �̵�(carriage return)
\f			������ �� �� �ѱ�(form feed)
\a			���Ҹ��� ��(alarm)
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
�Է��Լ�
scanf()�Լ��� ����Ͽ� Ű����� ���� ��ġ�� ���ڵ��� �Է¹޴´�.
scanf("�Էº�ȯ����", ����);

����(�Էº�ȯ����)		���
%d				��ȣ�ִ� 10������ �Է�
%u				��ȣ���� 10������ �Է�
%f				�ε� �Ҽ��������� �Է�
%s				���ڿ��� �Է�
%c				1 ���� �Է�
*/
#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	char ch;
	int i;

	printf("���� �� ���� �Է�: ");
	scanf("%d %c", &i, &ch);

	printf("i: %d, ch: %c\n", i, ch);
	return 0;
}
#endif