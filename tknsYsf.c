#include "mnh.h"
/**
* tokenYSF - char myta
* @buffer: paro dyali
*
* Return: paro dyali
*/
char **tokenYSF(char *buffer)
{
	char *token;
	int i = 0, wordcount = 0;
	char *delimiter = " \n";
	char **av;

	wordcount = _splitstringYSF(buffer);
	if (!wordcount)
		return (NULL);
	av = malloc((wordcount + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _strYsfup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}
/**
* _splitYSF - int dyal lah
* @YsfnStr: paro dyali
*
* Return: dire nub
*/
int _splitYSF(char *YsfnStr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; YsfnStr[i]; i++)
	{
		if (YsfnStr[i] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (YsfnStr[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (wordcount);
}
/**
* _PATHstrYSF - int m9aweda
* @YsfSt1: paro dyali
* @YsfSt2: paro dyali
*
* Return: 0 null
*/
int _PATHstrYSF(const char *YsfSt1, const char *YsfSt2)
{
	int i;

	for (i = 0; YsfSt2[i] != '='; i++)
	{
		if (YsfSt1[i] != YsfSt2[i])
			return (-1);
	}
	return (0);
}
/**
* _CONYSF - char mchat
* @tmp: paro dyali
* @av: paro domere
* @tok: paro farecha
*
* Return: 0 null
*/
char *_CONYSF(char *tmp, char **av, char *tok)
{
	int len = 0;

	_memsetYSF(tmp, 0, 256);
	len = _strLenYsf(tok) + _strLenYsf(av[0]) + 2;
	_strcatFSY(tmp, tok);
	_strcatFSY(tmp, "/");
	_strcatFSY(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
