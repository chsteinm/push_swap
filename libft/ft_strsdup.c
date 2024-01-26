#include "libft.h"

char	**strsdup(char **strs, size_t size)
{
	char	**ret;
	size_t	i;

	ret = malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		ret[i] = ft_strdup(strs[i]);
		if (!ret[i])
			return (ft_free_strings(ret), NULL);
	}
	ret[i] = NULL;
	return (ret);
}