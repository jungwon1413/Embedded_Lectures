/*
1. 부등호를 쓴 경우

while (count1 < i)
	00F90F9A  mov         eax, dword ptr[count1]
	00F90F9D  cmp         eax, dword ptr[i]
	00F90FA0  jge         main + 60h(0F90FC0h)
{
	while (count2 < j)
		00F90FA2  mov         eax, dword ptr[count2]
		00F90FA5  cmp         eax, dword ptr[j]
		00F90FA8  jge         main + 55h(0F90FB5h)
		count2++;
			00F90FAA  mov         eax, dword ptr[count2]
			00F90FAD  add         eax, 1
			00F90FB0  mov         dword ptr[count2], eax
			00F90FB3  jmp         main + 42h(0F90FA2h)
	count1++;
		00F90FB5  mov         eax, dword ptr[count1]
		00F90FB8  add         eax, 1
		00F90FBB  mov         dword ptr[count1], eax
}
00F90FBE  jmp         main + 3Ah(0F90F9Ah)


2. NOT을 쓴 경우

while (count1 != i)
	001016FD  mov         eax,dword ptr [count1]
	00101700  cmp         eax,dword ptr [i]
	00101703  je          main+93h (0101723h)
{
	while (count2 != j)
		00101705  mov         eax,dword ptr [count2]
{
	while (count2 != j)
		00101708  cmp         eax,dword ptr [j]
		0010170B  je          main+88h (0101718h)
		count2++;
			0010170D  mov         eax,dword ptr [count2]
			00101710  add         eax,1
			00101713  mov         dword ptr [count2],eax
			00101716  jmp         main+75h (0101705h)
	count1++;
		00101718  mov         eax,dword ptr [count1]
		0010171B  add         eax,1
		0010171E  mov         dword ptr [count1],eax
}
00101721  jmp         main+6Dh (01016FDh)
*/

/*
비교 연산자와 관련된 루머...?

1) 루프문에서는 0과 비교하는것이 더 빠르다?


while (run != 0)
	008D3CD2  movsx       eax, byte ptr[run]
	008D3CD6  test        eax, eax
	008D3CD8  je          main + 4Eh(08D3CFEh)
{
	for (int i = 0; i != 100; ++i);
		008D3CDA  mov         dword ptr[ebp - 14h], 0
		008D3CE1  jmp         main + 3Ch(08D3CECh)
		008D3CE3  mov         eax, dword ptr[ebp - 14h]
		008D3CE6  add         eax, 1
		008D3CE9  mov         dword ptr[ebp - 14h], eax
		008D3CEC  cmp         dword ptr[ebp - 14h], 64h
		008D3CF0  je          main + 44h(08D3CF4h)
		008D3CF2  jmp         main + 33h(08D3CE3h)
	++run;
		008D3CF4  mov         al, byte ptr[run]
		008D3CF7  add         al, 1
		008D3CF9  mov         byte ptr[run], al
}
008D3CFC  jmp         main + 22h(08D3CD2h)


while (run != 1)
	008D3CFE  movsx       eax, byte ptr[run]
	008D3D02  cmp         eax, 1
	008D3D05  je          main + 7Bh(08D3D2Bh)
{
	for (int i = 100; i != 0; --i);
		008D3D07  mov         dword ptr[ebp - 20h], 64h
		008D3D0E  jmp         main + 69h(08D3D19h)
{
	for (int i = 100; i != 0; --i);
		008D3D10  mov         eax, dword ptr[ebp - 20h]
		008D3D13  sub         eax, 1
		008D3D16  mov         dword ptr[ebp - 20h], eax
		008D3D19  cmp         dword ptr[ebp - 20h], 0
		008D3D1D  je          main + 71h(08D3D21h)
		008D3D1F  jmp         main + 60h(08D3D10h)
	--run;
		008D3D21  mov         al, byte ptr[run]
		008D3D24  sub         al, 1
		008D3D26  mov         byte ptr[run], al
}
	008D3D29  jmp         main + 4Eh(08D3CFEh)
}

*/