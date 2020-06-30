#include "sh21.h"
#include "help_lib.h"

char	*ft_strdup(const char *s1)
{
	int		le;
	char	*temp;

	if (!s1)
		return ((char*)s1);
	le = ft_strlen(s1);
	temp = (char*)ft_xmalloc((le + 1) * sizeof(*s1));
	while (*s1 != '\0')
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	return (temp -= le);
}
