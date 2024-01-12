#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;
void execution(char **mystore);
void wrfunction(char *stringpst);
#endif
