#include "our_header.h"

/**
 * sytx_man_p2 - syntax manager part 2 xd
 * @fd: file descriptor
 * @o_en: our global env var
 * @cmd_split: cdm_split
 * @cmmd: command
 * -------------------------------------
*/
void sytx_man_p2(int fd, char ***o_en, char ***cmd_split, char **cmmd)
{
	if (fd == -1)
		counter_plus_plus(o_en);
	free_split(*cmd_split);
	free(*cmmd);
}

/**
 * sytx_man_p3 - syntax manager part 3 xd
 * @fd: file descriptor
 * @o_en: our global env var
 * -----------------------------------------
*/
void sytx_man_p3(int fd, char ***o_en)
{
	if (fd != -1)
		counter_plus_plus(o_en);
}
