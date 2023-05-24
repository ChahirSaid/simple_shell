#include "shell.h"

/**
 * my_cd - changes the current working directory
 * @args: arguments
 */

void directory(char **args)
{
	char **directories = NULL, *oldpwd = NULL, *home = NULL;

	if (args[1] == NULL)
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			write(STDERR_FILENO, "cd: HOME not set\n", 17);
			return;
		}
		directories = malloc(sizeof(char *) * 2);
		if (directories == NULL)
			return;
		directories[0] = home;
		directories[1] = NULL;
	}
	else if (_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = _getenv("OLDPWD");
		if (oldpwd == NULL)
		{
			write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
			return;
		}
		directories = malloc(sizeof(char *) * 2);
		if (directories == NULL)
			return;
		directories[0] = oldpwd;
		directories[1] = NULL;
	}
	else
	{
		directories = malloc(sizeof(char *) * 2);
		if (directories == NULL)
			return;
		directories[0] = args[1];
		directories[1] = NULL;
	}
	change_directory(directories, args[0]);
	free(directories);
}

/**
 * change_directory - changes the current working directory
 * @directories: directories to change to
 * @command_name: name of the command
 */

void change_directory(char **directories, char *command_name)
{
	char *oldpwd = _getenv("PWD");
	char *pwd = getcwd(NULL, 0);

	if (chdir(directories[0]) == -1)
	{
		print_error(command_name, 0, directories[0], "can't cd to ");
		return;
	}
	else
	{
		_setenv("OLDPWD", oldpwd, 1);
		_setenv("PWD", pwd, 1);
		free(pwd);
	}
}

