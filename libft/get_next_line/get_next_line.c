/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:15:23 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 15:55:32 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	char		*next_line;
	static char	stash[BUFFER_SIZE + 1] = "";

	ret = 1;
	next_line = ft_strjoin2(NULL, stash);
	if (BUFFER_SIZE <= 0 || next_line == NULL)
		return (NULL);
	if (stash[0] == -1)
		return (free(next_line), NULL);
	while (pos_end_line(next_line) == -1 && ret != 0)
	{
		ret = read (fd, buf, BUFFER_SIZE);
		if (ret == -1 || (ret == 0 && next_line[0] == '\0'))
			return (free(next_line), NULL);
		buf[ret] = '\0';
		next_line = ft_strjoin2(next_line, buf);
	}
	get_end(next_line, stash, pos_end_line(next_line));
	next_line = get_begin(next_line, pos_end_line(next_line));
	if (ret == 0)
		stash[0] = -1;
	return (next_line);
}

/*int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	main(void)
{
	int		fd;
	char	*s;

	s = "";
	fd = 0;
	fd = open("./Makefile", O_RDONLY);
	if (fd == -1)
		return (ft_putstr("open fail"), 1);
	int i = 0;
	while (s != 0)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return (ft_putstr("\nERROR\n"), 0);
		ft_putstr(s);
		free(s);
		i++;
	}

	if (close(fd) == -1)
		return (ft_putstr("close fail"), 1);
	return (0);
}*/
