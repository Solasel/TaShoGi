/* Contains the overall logic and I/O for the engine. */

#include <stdbool.h>
#include <stdio.h>

#include <error.h>
#include <hash.h>
#include <board.h>

int main(int argc, char *argv[])
{
	enum errs errno;
	if ((errno = populate_zbs())) {
		printf("Failed to initialize bitstrings for Zobrist hashing.\n");
		err_msg(errno);
	}

	return 0;
}

