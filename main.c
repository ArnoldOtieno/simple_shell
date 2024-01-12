#include "shell.h"
/**
 * main - my entry function
 * @argc: argument count
 * @argv: array of arguments
 * Return: return zero for success
 */
int main(int argc, char *argv[])
{
	ssize_t gtread = 0;
	size_t gtcnt = 0;
	char *gtcontent = NULL;
	int interact = 1;
	char **mystore = NULL;
	char *token = NULL;
	int i = 0;

	while(1)
	{
		interact = isatty(STDIN_FILENO);
		if (interact == 1)
		{	
			wrfunction("$ ");
		}

		gtread = getline(&gtcontent, &gtcnt, stdin);
		if (gtread == -1)
		{
			wrfunction("\n");
			break;
		}
		mystore = malloc(10 * sizeof(char *));
		token = strtok(gtcontent, " \n\r\t");
		while(token != NULL)
		{
			mystore[i] = malloc(sizeof(char) * strlen(token) + 1);
			strcpy(mystore[i], token);
			i++;
			token = strtok(NULL, " \n\r\t");
		}
		mystore[i] = NULL;

		if (strcmp(mystore[0], "exit") == 0)
		{
			break;
		}
		if (access(mystore[0], F_OK | X_OK | R_OK | W_OK) != 0)
		{
			perror("File not found");
		}

		execution(mystore);
		if (mystore != NULL)
                                free(mystore);
                        if (gtcontent != NULL)
                                free(gtcontent);
	}
	return (0);
}
