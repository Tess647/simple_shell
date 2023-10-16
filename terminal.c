#include "shell.h"

/**
 * signal_handler - checks if Ctrl C is pressed
 * @signal_num: int
 */
void signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
  * _isatty - verify if terminal
  */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @cmdline: buffer
 */
void _EOF(int len, char *cmdline)
{
	(void)cmdline;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(cmdline);
		}
		exit(0);
	}
}
