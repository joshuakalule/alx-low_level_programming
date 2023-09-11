#include <stdlib.h>
#include "dog.h"

/**
 * free_dog- free the dog structure
 * @d: pointer to the dog type variable
 */
void free_dog(dog_t *d)
{
	if (!d)
		return;
	free(d->name);
	free(d->owner);
	free(d);
}
