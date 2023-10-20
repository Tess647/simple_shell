#include "shell.h"

/**
* check_custom_build - checks if the command is a buildin
* @argv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*check_custom_build(char **argv))(char **argv)
{
	int i, j;
	custom_build S[] = {
		{"exit", my_exit},
		{"env", env},
		{NULL, NULL}
	};

	for (i = 0; S[i].code_name; i++)
	{
		j = 0;
		if (S[i].code_name[j] == argv[0][j])
		{
			int k;
			for (k = 0; argv[0][k]; k++)
			{
				if (S[i].code_name[j + k] != argv[0][k])
					break;
			}
			if (!argv[0][k])
				return (S[i].func);
		}
	}
	return (0);
}
