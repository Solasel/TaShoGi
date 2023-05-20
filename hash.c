/* Contains an implementation for a hash table and
   various related helper functions. */
#include <sys/random.h>

#include <hash.h>

/* Populates the bitstring tables used for Zobrist hashing. */
enum errs populate_zbs(void)
{
	/* First, write the senteban bitstring. */
	int rand_rv, written = 0;
	int goal = sizeof(struct bs_pair);
	while (written < goal) {
		rand_rv = getrandom(((char *)(&sente_zbs)) + written, goal - written, 0);
		if (rand_rv == -1) {
			printf("%d: Failed to generate random bitstrings for Zobrist hashes.\n",
					__LINE__);
			return RAND_FAILURE;
		}

		written += rand_rv;
	}

	/* Then, the board bitstrings. */
	written = 0;
	goal = 2268 * sizeof(struct bs_pair);
	while (written < goal) {
		rand_rv = getrandom(((char *)(board_zbs)) + written, goal - written, 0);
		if (rand_rv == -1) {
			printf("%d: Failed to generate random bitstrings for Zobrist hashes.\n",
					__LINE__);
			return RAND_FAILURE;
		}

		written += rand_rv;
	}

	/* Then, the sente mochigoma bitstrings. */
	written = 0;
	goal = 126 * sizeof(struct bs_pair);
	while (written < goal) {
		rand_rv = getrandom(((char *)(sente_mochigoma_zbs)) + written, goal - written, 0);
		if (rand_rv == -1) {
			printf("%d: Failed to generate random bitstrings for Zobrist hashes.\n",
					__LINE__);
			return RAND_FAILURE;
		}

		written += rand_rv;
	}

	/* Finally, the gote mochigoma bitstrings. */
	written = 0;
	goal = 126 * sizeof(struct bs_pair);
	while (written < goal) {
		rand_rv = getrandom(((char *)(gote_mochigoma_zbs)) + written, goal - written, 0);
		if (rand_rv == -1) {
			printf("%d: Failed to generate random bitstrings for Zobrist hashes.\n",
					__LINE__);
			return RAND_FAILURE;
		}

		written += rand_rv;
	}

	return SUCCESS;
}

/* Generates a Zobrist hash pair for a given board state. */
struct bs_pair zobrist_hash(struct board *b)
{
	/* TODO */
	return 0U;
}

