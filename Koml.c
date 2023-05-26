#include "mnh.h"
/**
* main - int 9wada
*
* Return: 0 null
*/
int main(void)
{
	char *pthflYsf = NULL, *copy = NULL, *buffer = NULL;
	char *PATH = NULL;
	char **av;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenvSYF("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		prmtD();
		buffer = _rdYsf();
		if (*buffer != '\0')
		{
			av = tokenYSF(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			pthflYsf = _fullYSF(av, PATH, copy);
			if (checkbuilYSF(av, buffer, exitstatus) == 1)
				continue;
			exitstatus = _forkproYSF(av, buffer, pthflYsf);
		}
		else
			free(buffer);
	}
	return (0);
}
