// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	//  Allocating memory for the new element
	void *new_elem = mmap(NULL, sizeof(struct mem_list), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (new_elem == MAP_FAILED) {
		return NULL;
	}

	//  Adding the element to the heap list
	int ret = mem_list_add(new_elem, size);

	if (ret < 0) {
		errno = -ret;
		return NULL;
	}

	return new_elem;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t calculatedSize = nmemb * size;
	int ret = mem_list_add(mem_list_head.next, calculatedSize);

	if (ret < 0) {
		return NULL;
	}

	return &mem_list_head;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (mem_list_find(ptr) != NULL) {
		mem_list_del(ptr);
	}
	return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	//  Cast the ptr to obtain length
	struct mem_list *cast_ptr = (struct mem_list *)ptr;

	//  Alloc a bigger chunk of memory
	void *new_space = malloc(size);

	if (cast_ptr->len < size) {
		//  Update size
		cast_ptr->len = size;
		//  Copy the old data into the new space
		memcpy(new_space, ptr, size);
	} else {
		memcpy(new_space, ptr, cast_ptr->len);
	}
	free(ptr);

	return new_space;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return realloc(ptr, nmemb * size);
}
