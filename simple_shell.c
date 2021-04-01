#include "our_header.h"

/**
*main - coso
*
Return: int
*/
int main()
{
	char prompt[] = "#cisfun$ ";

	while (1)
	{
		/* Print prompt */
		write(1, &prompt, sizeof(prompt) / sizeof(char));

		_getline();
	}
	return (0);
}
