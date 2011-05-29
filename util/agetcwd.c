/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../util.h"

char *
agetcwd(void)
{
	char *buf;
	size_t size;

	if((size = pathconf(".", _PC_PATH_MAX)) < 0)
		size = BUFSIZ;
	if(!(buf = malloc(size)))
		eprintf("malloc:");
	if(!getcwd(buf, size))
		eprintf("getcwd:");
	return buf;
}