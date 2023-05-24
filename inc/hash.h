/* Header file for hash-related utilities. */
#pragma once

#include <board.h>
#include <error.h>

#include <stdint.h>

/* Tuple of two bitstrings for hash table operations. */
struct bs_pair{
	uint64_t h1, h2;
};

/* Bitstrings for use in Zobrist hashes. */
extern struct bs_pair sente_zbs;
extern struct bs_pair board_zbs[2268];
extern struct bs_pair sente_mochigoma_zbs[126];
extern struct bs_pair gote_mochigoma_zbs[126];

enum errs populate_zbs(void);
struct bs_pair zobrist_hash(struct board *b);

