#include "get_next_line_bonus.h"

/* 
** not_eol finds the end of a line thanks to the first occurrence 
** of a certain char.  
** Paremeters
** char **fdline. The direction to the line that has to be read.
** char c. The char that marks the EOL.
** 
** Return codes:
** 1 - if the line is empty or we have reached the end of it without 
** findig the char.
** 0 - if the char is finded.
*/

int	not_eol(char **fdline, char c)
{
	char	*s;

	s = *fdline;
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (1);
}

/* 
** next_line finds the carry return in fdline and replaces it by a /0
** as result we get line, wich is fdline modified.
** Parameters
** char **fdline. The direction of the line that has to be read. 
*/
char	*next_line(char **fdline)
{
	char	*line;
	int		i;
	char	*s;
	int		len;

	s = *fdline;
	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = ft_strndup(s, i);
	if (!s[i])
	{
		free(s);
		*fdline = 0;
		return (line);
	}
	len = ft_strlen(*fdline) - i;
	*fdline = ft_strndup(s + i + 1, len);
	free(s);
	return (line);
}

/*
** get_next_line read the text available on a file descriptor (fd),
** one line at a time, without the newline.
** Calling get_next_line in a loop read one line the text available on a 
** file descriptor  at a time until the EOF.
**
** Parameters
** int fd. file descriptor for reading
** char **line. The value of what has been read
**
** Return codes:
**
** 1  : A line has been read
** 0  : EOF has been reached
** -1 : An error happened

 ** The static variable remembers the previous call.
 ** if BUFFER_SIZE < 0 || fd < 0 (error) || **line null 
 ** return error.
 ** The function read() returns the number of bytes read.
 */

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*fdline[MAX_FD];
	int			ret;
	char		*tmp_fdline;

	ret = 1;
	if (!line || fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (-1);
	while (not_eol(&fdline[fd], '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp_fdline = fdline[fd];
		fdline[fd] = ft_strjoin(tmp_fdline, buf);
		free(tmp_fdline);
	}
	*line = next_line(&fdline[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
