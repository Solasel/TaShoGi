/* Contains utilities for error handling. */

#include <stdio.h>

#include <error.h>

void err_msg(enum errs code)
{
	switch(code) {

	case SUCCESS:
		printf("Error handler invoked with no errors.\n");
		break;
	case NOT_YET_IMP:
		printf("Not yet implemented.\n");
		break;
	case BAD_ARGS:
		printf("Bad arguments.\n");
		break;
	case RAND_FAILURE:
		printf("Failed to get random data from the kernel.\n");
		break;
	case FOPEN_FAILURE:
		printf("Failed to open a file.\n");
		break;
	case MALLOC_FAILURE:
		printf("Failed to allocate required memory.\n");
		break;
	}
}

