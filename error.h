/* Header file for error-handling utilities. */

/* Error codes. */
enum errs {
	SUCCESS,
	NOT_YET_IMP,
	BAD_ARGS,
	FOPEN_FAILURE,
	MALLOC_FAILURE
};

/* Prints out a relevant error message given
   an error code. */
char *err_msg(enum errs code);

