/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:54:50 by kshantel          #+#    #+#             */
/*   Updated: 2020/07/23 23:55:16 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_found(char **ptr_n, char **remainder, char **template)
{
	**ptr_n = '\0';
	*template = *remainder;
	*remainder = ft_strdup(++(*ptr_n));
	free(*template);
}

int		ft_checking(int readed, char *ptr_n)
{
	if (readed == -1)
		return (-1);
	if (ptr_n)
		return (1);
	return (0);
}

void	ft_alive(char ***line, char **remainder, char **ptr_n)
{
	char	*template;

	if ((*ptr_n = ft_strchr(*remainder, '\n')))
	{
		**ptr_n = '\0';
		template = **line;
		**line = ft_strjoin(**line, *remainder);
		free(template);
		template = *remainder;
		*remainder = ft_strdup(++*ptr_n);
		free(template);
	}
	else
	{
		template = **line;
		**line = ft_strjoin(**line, *remainder);
		free(template);
		template = *remainder;
		*remainder = NULL;
		free(template);
	}
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			readed;
	char		*ptr_n;
	char		*template;
	static char	*remainder;

	ptr_n = NULL;
	readed = 0;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || !(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	if (remainder)
		ft_alive(&line, &remainder, &ptr_n);
	while (!ptr_n && (readed = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readed] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
			ft_found(&ptr_n, &remainder, &template);
		template = *line;
		*line = ft_strjoin(*line, buf);
		free(template);
	}
	return (ft_checking(readed, ptr_n));
}
