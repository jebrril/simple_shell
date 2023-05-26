#include "mnh.h"
/**
* _strYsfup - int CHE HAJA
* @YsfnStr: MY PROJECT
*
* Return: REPOSERETY FIHA
*/
char *_strYsfup(char *YsfnStr)
{
	int i;
	char *dest_str;

	if (YsfnStr == NULL)
		return (NULL);
	for (i = 0; YsfnStr[i] != '\0'; i++)
		;
	dest_str = malloc(sizeof(char) * (i + 1));
	if (dest_str == NULL)
		return (NULL);
	for (i = 0; YsfnStr[i] != '\0'; i++)
	{
		dest_str[i] = YsfnStr[i];
	}
	dest_str[i] = '\0';
	return (dest_str);
}
/**
* _splitstringYSF - KAMELINE MAIN
* @YsfnStr: RAH MRIDE HADECHI
*
* Return: BERAM CHI CODE
*/
int _splitstringYSF(char *YsfnStr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; YsfnStr[i]; i++)
	{
		if (YsfnStr[i] != ' ' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (YsfnStr[i + 1] == ' ')
			searchflag = 1;
	}
	return (wordcount);
}
/**
* _strYSF - int KAMELINE MAIN
* @YsfSt1:  MAIN parametre 
* @YsfSt2:  parametre 
* Return: int chi HAJA
*/
int _strYSF(const char *YsfSt1, const char *YsfSt2)
{
	while ((*YsfSt1 != '\0' && *YsfSt2 != '\0') && *YsfSt1 == *YsfSt2)
	{
		YsfSt1++;
		YsfSt2++;
	}
	if (*YsfSt1 == *YsfSt2)
		return (0);
	else
		return (*YsfSt1 - *YsfSt2);
}
/**
* _strcatFSY - char func awdi ach ghadi
* @dest: 3WAJE parametre LICAYENE
* @src: 3AWAJE parametre dyalna
* i - param parametre FACILEMENT
* j - RAYAREHA
* Return: HEROUFA NADEYINE
*/
char *_strcatFSY(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
/**
* _strLenYsf - int I
* @s: parO ca marche
* i - 3awaje parametre dyalena
* Return: int hiya likayena
*/
int _strLenYsf(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
