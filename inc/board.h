/* Header file for board.c */
#pragma once

#include <stdint.h>

#include <error.h>

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
	GOTE_FU,
	GOTE_KYOU,
	GOTE_KEI,
	GOTE_GIN,
	GOTE_KIN,
	GOTE_KAKU,
	GOTE_HISHA,

	/* Gote promoted pieces + king. */
	GOTE_TO,
	GOTE_NARIKYOU,
	GOTE_NARIKEI,
	GOTE_NARIGIN,
	GOTE_GYOKU,
	GOTE_UMA,
	GOTE_RYUU
};

/* Abstraction for a board. */
struct board {
	uint8_t teban;
	uint8_t board[81];
	uint8_t sente_mochigoma[7];
	uint8_t gote_mochigoma[7];
};

/* Abstraction for a move. prom indicates promotion. */
struct move {
	uint8_t src_tile, dest_tile, piece, prom;
};

enum errs enumerate_moves(struct board *b, struct move **rv);

