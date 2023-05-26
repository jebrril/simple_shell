#include "mnh.h"
/**
* prmtD - int mchat
*
* Return: 0 null
*/
int prmtD(void)
{
	char *prmtD = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prmtD, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}
/**
* _rdYsf - char 9wada
*
* Return: pointer a
*/
char *_rdYsf(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
/**
* _fullYSF - char mchat
* @av: paro dyali
* @PATH: paro dyali
* @copy: paro dyali
*
* Return: hana 3la pointer
*/
char *_fullYSF(char **av, char *PATH, char *copy)
{
	char *tok, *pthflYsf = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strYsfup(PATH);
	PATHcount = _splitYSF(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _CONYSF(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			pthflYsf = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strLenYsf(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					pthflYsf = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		pthflYsf = av[0];
	free(copy);
	return (pthflYsf);
}
/**
* checkbuilYSF - int nadi
* @av: paro dyali
* @buffer: paro dyali
* @exitstatus: paro dyali
* Return: 1 or 0 hadi mon avi
*/
int checkbuilYSF(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_strYSF(av[0], "env") == 0)
	{
		_YSFENV();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strYSF(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
* _forkproYSF - int 3iche
* @av: paro dyali
* @buffer: paro dyali
* @pthflYsf: paro dyali
*
* Return: 0 null
*/
int _forkproYSF(char **av, char *buffer, char *pthflYsf)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(pthflYsf, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}
