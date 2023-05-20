/* Header file for hash-related utilities. */
#pragma once

/* Tuple of two bitstrings for hash table operations. */
struct bs_pair{
	uint_64t h1, h2;
};

/* Bitstrings for use in Zobrist hashes. */
struct bs_pair sente_zbs;
struct bs_pair board_zbs[2268];
struct bs_pair sente_mochigoma_zbs[126];
struct bs_pair gote_mochigoma_zbs[126];

struct two_hash zobrist_hash(struct board *b);

