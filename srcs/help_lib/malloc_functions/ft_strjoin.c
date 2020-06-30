#include "sh21.h"
#include "help_lib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char*)ft_xmalloc(len1 + len2 + 1);
	ft_strcpy(str, s1);
	ft_memcpy(str + len1, s2, len2);
	return (str);
}
