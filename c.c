#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t trimwhitespace(char *out, size_t len, const char *str)
{
	const char *end;
	size_t out_size, trimmed_len;

	if(len == 0)
		return 0;


	while (isspace((unsigned char) *str))
		str++;

	if (!(*str))
	{
		*out = *str;
		return (1);
	}

	end = str + strlen(str) - 1;

	while (end > str && isspace((unsigned char) *end))
		end--;

	end++;

	trimmed_len = (size_t) (end - str);
	out_size = trimmed_len < len-1 ? trimmed_len : len-1;

	memcpy(out, str, out_size);

	out[out_size] = 0;

	return (out_size);
}

int main(void)
{
	FILE *file = fopen("../bytecodes/05.m", "r");

	char trimmed[1024];
	char *line;
	size_t size;

	while (getline(&line, &size, file) != EOF)
	{
		trimwhitespace(trimmed, size, line);

		puts(line);
		puts(trimmed);

	}

	free(line);
	fclose(file);

	return (0);
}
