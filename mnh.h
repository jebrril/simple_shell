#ifndef MNH_H
#define MNH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int prmtD(void);
char *_rdYsf(void);
char *_fullYSF(char **av, char *PATH, char *copy);
int checkbuilYSF(char **av, char *buffer, int exitstatus);
int _forkproYSF(char **av, char *buffer, char *pthflYsf);


char *_strYsfup(char *YsfnStr);
int _splitstringYSF(char *YsfnStr);
int _strYSF(const char *YsfSt1, const char *YsfSt2);
char *_strcatFSY(char *dest, char *src);
int _strLenYsf(char *s);

char **tokenYSF(char *buffer);
int _splitYSF(char *YsfnStr);
int _PATHstrYSF(const char *YsfSt1, const char *YsfSt2);
char *_CONYSF(char *tmp, char **av, char *tok);

char *_getenvSYF(const char *name);
int _YSFENV(void);
void _putsYSF(char *YsfnStr);
int _YSFptch(char c);
char *_memsetYSF(char *s, char b, unsigned int n);

#endif
