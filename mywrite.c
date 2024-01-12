#include "shell.h"
/**
 * wrfunction - function that writes what is passed to it
 * @stringpst: pointer to character to be printed
 */
void wrfunction(char *stringpst)
{
	write(1, stringpst, strlen(stringpst));
}
