#include "sshell.h"

/**
 * get_environment_variable_value - return value of env variable
 *
 * @variable: variable name
 * @index: index after = character
 *
 * Return: variable value or NULL
*/

char *get_environment_variable_value(char *variable, int index)
{
	if (variable)
	{
		while (index + 1)
		{
			variable++;
			index--;
		}
		return (variable);
	}
	return (NULL);
}


/**
 * get_environment_variable - return an environment variable
 *
 * @variableName: env variable name
 * Return:
 *  - value of variable string
 *  - NULL: if not exist.
 */

char *get_environment_variable(char *variableName)
{
	int index = 0, charIndex = 0;

	if (*variableName)
	{
		while (__environ[index])
		{
			while (charIndex < _strlen(variableName))
			{
				if (*(variableName + charIndex) == *(__environ[index] + charIndex))
					charIndex++;
				else
				{
					charIndex = 0;
					index++;
				}
			}
			if (charIndex == _strlen(variableName))
				return (get_environment_variable_value(__environ[index], charIndex));
			charIndex = 0;
			index++;
		}
	}
	return (NULL);
}
