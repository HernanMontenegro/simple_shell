#include "our_header.h"

/**
*main - coso
*
Return: int
*/
int main()
{
	char prompt[] = "#cisfun$ ";
	char *input;
	int bytes_used_read = 0;
	int bytes_read = 0;

	while (1)
	{
		bytes_read = 0;
		bytes_used_read = 0;
		input = NULL;
		/* Print prompt */
		write(1, &prompt, sizeof(prompt) / sizeof(char));

		bytes_read = _getline(input, &bytes_used_read, 1);
		if (bytes_read == -1)
		{
			return (1);
		}


	}
	return (0);
}
