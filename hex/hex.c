#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef FALSE
	#define FALSE 0
#endif
#ifndef TRUE
	#define TRUE 1
#endif

int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		fprintf(stdout, "%s [file] [write?]\n", argv[1]);
		exit(0);
	}
	FILE *fp;
	char c;
	int i = 0, per_line = 16,  split_when = per_line;
	fp = fopen(argv[1], "r");
	
	/*
	If you access a file which requires elevated perms then this part will also send file not found.
	You may use `geteuid()` function to check does it have elevated perms or not. (root = 0) elsse non-zero
	*/
	if (fp == NULL)
	{
		fprintf(stderr, "Error: file not found.\n");
		exit(0);
	}

	// int buf = malloc(1024 * 4);

	while ((c = fgetc(fp)) != EOF)
	{
		if (split_when >= per_line)
		{
			fprintf(stdout, "\n[0x%08x] ", i);
			split_when = 0;
		}
		fprintf(stdout, "%02x ", c);
		split_when++;
		i++;
	}
	fprintf(stdout, "\n");
	fclose(fp);
	exit(0);
}
