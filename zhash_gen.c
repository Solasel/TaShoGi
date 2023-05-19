/* Generates a header file containing bitstrings
   for use in Zobrist hashing. */

#include <error.h>
#include <stdio.h>

#define DEF_FILE ("zhash_bms.h")

enum errs gen_bitstrings(const char *dst);

/* Parses user input, and then generates bitstrings,
   either in the user-provided file, or the default
   file, if no arguments are provided. */
int main(int argc, char *argv[])
{
	enum errs failure;
	char *dst_file = DEF_FILE;
	
	if (argc > 2) {
		printf("ERROR: The generator should take one argument max.\n\n"
			"Sample usage:\n"
			"./{exec} [src file]\n");
		failure = BAD_ARGS;
		goto end;
	}
	if (argc == 2)
		dst_file = argv[1];

	failure = gen_bitstrings(dst_file);

end:
	/* Reports to the user how the program fared. */
	printf("\n###################################################\n\n");

	if (failure)
		printf("Zobrist bitstring generation failed!\n"
			"Target file '%s' has not been changed.\n\n",
				dst_file);
	else
		printf("Zobrist bitstring generation successful!\n"
			"Target file '%s' now contains C - readable Zobrist bitstrings.\n\n",
				dst_file);
	return failure;
}

/* Generates bitstrings and writes them to the destination file. */
enum errs gen_bitstrings(const char *dst)
{
	return NOT_YET_IMP;
}

