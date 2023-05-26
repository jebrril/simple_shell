#include "mnh.h"
/**
* _getenvSYF -  function is slution.
* @name: paro extra.
*
* Return: i++NULL
*/
char *_getenvSYF(const char *name)
{
int i, result;

for (i = 0; environ[i]; i++)
{
	result = _PATHstrYSF(name, environ[i]);
	if (result == 0)
	{
		return (environ[i]);
	}
}
return (NULL);
}
/**
* _YSFENV - imprim environment.
*
* Return: rien des tou 0.
*/
int _YSFENV(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_putsYSF(environ[i]);
	return (0);
}
/**
* _putsYSF - prints void.
* @YsfnStr: str in the impraision.
*/
void _putsYSF(char *YsfnStr)
{
	int c;

	for (c = 0; YsfnStr[c] != '\0'; c++)
		_YSFptch(YsfnStr[c]);
	_YSFptch('\n');
}
/**
* _YSFptch - prints  pro.
* @c: character  pro.
*
* Return: return the value  pro.
*/
int _YSFptch(char c)
{
	return (write(1, &c, 1));
}
/**
* _memsetYSF - dyalena.
* @s: paro.
* @b: paro.
* @n: paro.
* Return: dyl.
*/
char *_memsetYSF(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
