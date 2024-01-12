#include "shell.h"
/**
 * execution - execute child process
 * @mystore: array of commands passed
 */

void execution(char **mystore)
{
	int status = 0;
	pid_t childprocess;

	childprocess = fork();
	if (childprocess == -1)
	{
		perror("fork error");
	}
	else if (childprocess == 0)
	{
		if (execve(mystore[0], mystore, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
