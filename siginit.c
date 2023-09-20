#include "shell.h"

/**
 * sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
