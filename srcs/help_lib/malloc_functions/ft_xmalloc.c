#include "sh21.h"
#include "help_lib.h"

void		*ft_xmalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
	{
		write(2, "No space left\n", 15);
		exit(ERR_MALLOC);
	}
	ft_bzero(ptr, size);
	return (ptr);
}
