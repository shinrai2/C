#include <stdio.h>
#include <stdlib.h>

#include "q2exit.h"

int main (void)
{
	char c[20];
	while (!isExit())
	{
		gets (c);
		printf ("$ %s $\n",c);
	}
	printf ("Exit.\n");
	return EXIT_SUCCESS;
}