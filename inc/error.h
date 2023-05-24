/* Header file for error-handling utilities. */
#pragma once

/* Error codes. */
enum errs {
	SUCCESS,
	NOT_YET_IMP,
	BAD_ARGS,
	RAND_FAILURE,
	FOPEN_FAILURE,
	MALLOC_FAILURE
};

/* Prints out a relevant error message given
   an error code. */
void err_msg(enum errs code);

