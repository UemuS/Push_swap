#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	return (ft_memset(str, 0, count * size));
}
