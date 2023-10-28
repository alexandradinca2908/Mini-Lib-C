// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	for (; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	destination[i] = source[i];
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	for (; i < len && source[i] != '\0'; i++) {
		destination[i] = source[i];
	}

	//  In case there is still space left, add padding
	for(; i < len; i++) {
		destination[i] = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	//  Starting from the end of the string.
	char *dest_copy = destination + strlen(destination);
	int i = 0;
	for (; source[i] != '\0'; i++) {
		dest_copy[i] = source[i];
	}
	dest_copy[i] = source[i];
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	//  Starting from the end of the string.
	char *dest_copy = destination + strlen(destination);
	size_t i = 0;
	for (; i < len && source[i] != '\0'; i++) {
		dest_copy[i] = source[i];
	}

	//  Padding the rest of the length.
	for(; i < len; i++) {
		dest_copy[i] = '\0';
	}
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	//  Compare each byte. Stop if a difference is found.
	for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++) {
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
	}
	//  If the strings have different sizes, the longer one is considered greater.
	if (*str1 > *str2) {
		return 1;
	} else if (*str1 < *str2) {
		return -1;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	//  Compare each byte. Stop if a difference is found or NULL is found.
	for (; *str1 != '\0' && *str2 != '\0' && len > 0; str1++, str2++, len--) {
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
	}

	//  If length is not 0, the longer array is considered greater.
	if (len > 0) {
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (; *str != '\0'; str++) {
		if (*str == c) {
			return (char *)str;
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int length = strlen(str);
	
	//  Starting from the end of the string.
	str += length;
	for (; length > 0; length--, str--) {
		if (*str == c) {
			return (char *)str;
		}
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	size_t needle_length = strlen(needle);

	//  Using strcmp to compare every substring.
	for (; strlen(haystack) >= needle_length; haystack++) {
		if (strncmp(haystack, needle, needle_length) == 0) {
			return (char *)haystack;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	size_t needle_length = strlen(needle);
	size_t haystack_length = strlen(haystack);

	// Starting from the last needle_length substring in haysack
	haystack += strlen(haystack) - needle_length;

	for (; strlen(haystack) < haystack_length; haystack--) {
		if (strncmp(haystack, needle, needle_length) == 0) {
			return (char *)haystack;
		}
	}
	// Loop stops before we reach 1st char. One more comparison needed
	if (strncmp(haystack, needle, needle_length) == 0) {
			return (char *)haystack;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	if (destination == NULL || source == NULL) {
		return NULL;
	}

	//  Casting the void parameters to char arrays
	//  Casting is necessary for accessing the data
	char *destination_cast = (char *)destination;
	const char *source_cast = (const char*)source;
	while (num) {
		*destination_cast = *source_cast;
		destination_cast++;
		source_cast++;
		num--;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	if (destination == NULL || source == NULL) {
		return NULL;
	}

	//  Casting the void parameters to char arrays
	//  Casting is necessary for accessing the data
	char *destination_cast = (char *)destination;
	const char *source_cast = (const char*)source;

	//  First we tranfer data to a buffer
	const size_t kBuffer_size = num + 1;
	char buffer[kBuffer_size];

	size_t i = 0;
	for (; i < num; i++) {
		buffer[i] = source_cast[i];
	}
	//  Then we put the bytes in the original destination
	for (i = 0; i < num; i++) {
		destination_cast[i] = buffer[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	//  Cast the void parameters to char arrays
	//  Compare bytes until num bytes have been checked
	const char *str1 = (const char *)ptr1;
	const char *str2 = (const char *)ptr2;
	for (; num > 0; str1++, str2++, num--) {
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *source_cast = (char *)source;
	for (size_t i = 0; i < num; i++) {
		source_cast[i] = (char)value;
	}
	return source;
}
