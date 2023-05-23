#include "shell.h"

/**
 * handle_ctrl - Function to handle the Ctrl-C signal
 * @signal: Signal number
 * Return: Void
 */
void handle_ctrl(int signal)
{
	(void)signal;
	write(1, "\n$ ", 4);
}
