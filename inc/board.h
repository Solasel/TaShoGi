/* Header file for board.c */
#pragma once

#include <stdint.h>
#include <stdbool.h>

#define SENTEBAN (0U)
#define GOTEBAN (1U)

/* Abstraction for pieces. */
enum pieces {
	NONE,

	/* Sente standard pieces. */
	SENTE_FU,
	SENTE_KYOU,
	SENTE_KEI,
	SENTE_GIN,
	SENTE_KIN,
	SENTE_KAKU,
	SENTE_HISHA,

	/* Sente promoted pieces + king. */
	SENTE_TO,
	SENTE_NARIKYOU,
	SENTE_NARIKEI,
	SENTE_NARIGIN,
	SENTE_GYOKU,
	SENTE_UMA,
	SENTE_RYUU,

	/* Gote standard pieces. */
	SENTE_FU,
	SENTE_KYOU,
	SENTE_KEI,
	SENTE_GIN,
	SENTE_KIN,
	SENTE_KAKU,
	SENTE_HISHA,

	/* Gote promoted pieces + king. */
	SENTE_TO,
	SENTE_NARIKYOU,
	SENTE_NARIKEI,
	SENTE_NARIGIN,
	SENTE_GYOKU,
	SENTE_UMA,
	SENTE_RYUU
};

/* Abstraction for a board. */
struct board {
	uint8_t teban;
	uint8_t[81] board;
	uint8_t[7] sente_mochigoma;
	uint8_t[7] gote_mochigoma;
};

/* Abstraction for a move. prom indicates promotion. */
struct move {
	uint8_t src_tile, dest_tile, piece, prom;
};

int enumerate_moves(struct board *b, struct move **rv);

