#include <stdio.h>


int pack4Chars2Int(char c1, char c2, char c3, char c4);
int checkEvenParity(short input);
void main()
{
	short input = -55;
	char c1 = 'a';
	char c2 = 'b';
	char c3 = 'c';
	char c4 = 'd';
	
	printf("%d", checkEvenParity(input));
}

int pack4Chars2Int(char c1, char c2, char c3, char c4)
{
	int temp=0x4;	
	char tempChar[4] = {c1,c2,c3,c4};
	for (int i = 0; i < 4;i++)
	{
		temp <<= 8;
		temp = temp | tempChar[i];
	}
	return temp;
}
int checkEvenParity(short input)
{
	char mask = 0b1;
	int count = 0;
	if (input<0)
	{
		input = ~input;
	}
	while (input != 0)
	{
		if (mask & input)
		{
			count++;
		}
		input >>= 1;
	}
	if (count % 2)
	{
		return 0;
	}
	return 1;
}