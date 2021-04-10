#include "our_header.h"

/**
 * comms_pross - (Cut off..) activate boolean when
 *                found first comma and detects when it closes
 * @s: the string given in check_split_line
 * @bool: given bool commas in check_split_line
 * @i: index given in check_split_line
 * @nxComms: when finding the first, this bool will active
 *              indicating that the program should find the close
 *              comma.
 * @tComms: type of commas
 *
*/
void comms_pross(char *s, int *bool, int *i, int *nxComms, int *tComms)
{
	int j;

	if ((*bool) == -1)
	{
		for (j = 1; s[*i + j] != '\0'; j++)
		{
			if (s[*i + j] == s[*i])
			{
				*nxComms = 1;
				break;
			}
		}
		if (*nxComms && *tComms == 0)
		{
			*bool = *bool * -1;
			*tComms = s[*i];
		}
	}
	else
	{
		if (*tComms == s[*i])
		{
			*bool = *bool * -1;
			*tComms = 0;
		}
	}
}
