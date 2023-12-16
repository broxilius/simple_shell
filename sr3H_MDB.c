#include "shell.h"

/**
* rev_string - Reverses a.
* @s: String to be .
* Return: void
*/
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;
/* Calculate the tring*/
	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;
/* Reverse the string using a hm*/
	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
