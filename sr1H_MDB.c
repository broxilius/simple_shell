#include "shell.h"

/**
* _strcat - Concatenates.
* @dest: Destina.
* @src: Source.
* Return: Pointer to the.
*/

char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
* *_strcpy - Copies a.
* @dest: Destinat
* @src:Source st
* Return: Pointer to the
*/

char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
* _strcmp -  Compares two.
* @s1: First str.
* @s2: Second stri.
* Return: 0 if strings if s1 > s2, negative if s1 < s2.
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
* _strchr - Locates in a string.
* @s: Input stri.
* @c: Character to lo.
* Return: Pointer to the first character in the string.
*/
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
* _strspn - Gets the length of.
* @s: Input stri.
* @accept: String containing.
* Return: Number of segment of s, consisting
* entirely of characters.
*/
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
