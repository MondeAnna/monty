#include "monty.h"

/**
 * _strstrp - strip whitespace from string
 * @dest: destination string
 * @src: source string
 * Return: lenght of stripped string (size_t)
 */
size_t _strstrp(char *dest, const char *src)
{
	size_t len = strlen(src);
	size_t dest_size, stripped_len;
	const char *end = src + len - 1;

	if (*src)
		return (0);

	while (isspace((unsigned char) *src))
		src++;

	if (!(*src))
	{
		*dest = *src;
		return (1);
	}

	while (end > src && isspace((unsigned char) *end))
		end--;

	end++;

	stripped_len = (size_t) (end - src);
	dest_size = stripped_len < len - 1 ? stripped_len : len - 1;

	memcpy(dest, src, dest_size);

	dest[dest_size] = 0;

	return (dest_size);
}

