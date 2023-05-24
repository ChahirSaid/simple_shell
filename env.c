#include "shell.h"

/**
 * _getenv - gets the environment variable
 * @key: key to get the value of
 * Return: value of the environment variable
 */

char *_getenv(char *key)
{
	unsigned int i = 0;
	char *path;
	char **env;
	int count = 0, j = 0;

	while (environ[count])
		count++;

	env = malloc(sizeof(char *) * (count + 1));

	for (j = 0; j < count; j++)
		env[j] = _strdup(environ[j]);

	env[count] = NULL;

	while (env[i])
	{
		path = strtok(env[i], "=");
		if (_strcmp(key, env[i]) == 0)
		{
			path = _strtok(NULL, "\n");
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * len_env - gets the length of the environment
 * @env: environment
 * Return: length of the environment
 */

int len_env(char **env)
{
	int i = 0;

	while (env[i])
		i++;
	return (i);
}

/**
 * _setenv - sets an environment variable
 * @key: name of the variable
 * @value: value of the variable
 * @overwrite: overwrite flag
 * Return: 0 on success, -1 on failure
 */

int _setenv(char *key, char *value, int overwrite)
{
	int i = 0, j = 0, len_key = 0, len_value = 0;
	char **env = NULL;

	env = environ;
	if (key == NULL || value == NULL)
		return (-1);
	len_key = _strlen(key);
	len_value = _strlen(value);
	while (env[i] != NULL)
	{
		while (env[i][j] != '=')
			j++;
		if (_strncmp(env[i], (char *)key, j) == 0)
		{
			if (overwrite == 1)
			{
				env[i] = malloc(sizeof(char) * (len_key + len_value + 2));
				_strcpy(env[i], key);
				_strcat(env[i], "=");
				_strcat(env[i], value);
				return (0);
			}
			return (0);
		}
		i++;
		j = 0;
	}
	env[i] = malloc(sizeof(char) * (len_key + len_value + 2));
	_strcpy(env[i], key);
	_strcat(env[i], "=");
	_strcat(env[i], value);
	env[i + 1] = NULL;
	return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @key: name of the variable
 * Return: 0 on success, -1 on failure
 */

int _unsetenv(char *key)
{
	int i = 0, j = 0, k = 0;
	char **env = NULL;

	env = environ;
	while (env[i] != NULL)
	{
		while (env[i][j] != '=')
			j++;
		if (_strncmp(env[i], (char *)key, j) == 0)
		{
			for (k = i; env[k] != NULL; k++)
				env[k] = env[k + 1];
			return (0);
		}
		i++;
		j = 0;
	}
	return (-1);
}
