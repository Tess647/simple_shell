#include "shell.h"

/**
  *_getenv - gets the value of an environment variable
  *@name: name of the environment variable
  *
  *Return: value of the variable if it exists
  *NULL if the value does exist
  */
char *_getenv(const char *name)
{
	char **env, *value;

	/*Iterate through the environment variable*/
	for (env = environ; *env != NULL; env++)
	{
		if (*env != NULL && strncmp(name, *env, strlen(name)) == 0)
		{
			/*find the value part*/
			value = strchr(*env, '=') + 1;
			return (value);
		}
	}
	return (NULL);
}
