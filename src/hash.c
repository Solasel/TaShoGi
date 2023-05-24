/* Contains an implementation for a hash table and
   various related helper functions. */
#include <sys/random.h>
#include <stdio.h>

#include <hash.h>
#include <error.h>

/* Bitstrings for use in Zobrist hashes. */
struct bs_pair sente_zbs;
struct bs_pair board_zbs[2268];
struct bs_pair sente_mochigoma_zbs[126];
struct bs_pair gote_mochigoma_zbs[126];

/* Populates the bitstring tables used for Zobrist hashing. */
enum errs populate_zbs(void)
{
	int rand_rv, written, goal;

	/* First, write the senteban bitstring.
	   Note that reads of up to 256 bytes are
	   guaranteed to not be interrupted. */
	rand_rv = getrandom(((char *)(&sente_zbs)), sizeof(struct bs_pair), 0);
	if (rand_rv != sizeof(struct bs_pair)) {
		printf("%d: Failed to generate random bitstrings for Zobrist hashes.\n",
				__LINE__);
		return RAND_FAILURE;
	}

	/* Then, the board bitstrings.
	   Since these are larger than 256 bytes, we have to loop
	   until we've filled them completely. */
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
	struct bs_pair rv;
	/* TODO */
	rv.h1 = 0U;
	rv.h2 = 0U;
	return rv;
}

