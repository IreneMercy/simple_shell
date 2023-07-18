#include "shell.h"

/*
 * strdup_custom - Duplicates a string
 * @source: The source string to duplicate
 *
 * Returns: A pointer to the duplicated string, or NULL on failure
 */
char *strdup_custom(const char *source)
{
	size_t length = _strlen(source);
	char *duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	_strcpy(duplicate, source);

	return (duplicate);
}

/*
 * strncpy_custom - Copies a string with a specified length
 * @destination: The destination buffer to copy to
 * @source: The source string to copy
 * @num: The maximum number of characters to copy
 *
 * Returns: A pointer to the destination buffer
 */
char *strncpy_custom(char *destination, const char *source, size_t num)
{
	char *dest = destination;

	while (*source && num > 0)
	{
		*dest++ = *source++;
		num--;
	}

	while (num > 0)
	{
		*dest++ = '\0';
		num--;
	}

	return (destination);
}

/*
 * _strlen - Calculates the length of a string
 * @s: The input string
 *
 * Returns: The length of the string
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/*
 * _strcpy - Copies a string from source to destination
 * @dest: The destination buffer
 * @src: The source string
 *
 * Returns: A pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/*
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Returns: A pointer to the destination string
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}
