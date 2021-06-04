#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*sc;

	if (!s)
		return (0);
	sc = s;
	while (*sc)
		++sc;
	return ((unsigned int)(sc - s));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!s && !d)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*s;

	if (!s1 && !s2)
		return (0);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	s = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!s)
		return (0);
	ft_memcpy(s, s1, l1);
	ft_memcpy(s + l1, s2, l2);
	s[l1 + l2] = '\0';
	return (s);
}

char	*ft_strndup(const char *s, size_t	len)
{
	char	*d;

	if (len < 0)
		return (0);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (!d)
		return (0);
	ft_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}
