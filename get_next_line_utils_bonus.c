/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:22:41 by hdurand           #+#    #+#             */
/*   Updated: 2020/02/04 14:13:23 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_is_endofline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

int		ft_reader(int *retval, char *buf, int fd)
{
	ft_cleanbuf(buf);
	if ((*retval = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	buf[*retval] = 0;
	return (0);
}

int		ft_tmpsaver(char **str, char *buf, int limit)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && i < limit)
		i++;
	if (buf[i] == '\n')
	{
		if (!(*str = malloc(sizeof(char *) * limit + 1)))
			return (-1);
		i++;
	}
	else
		return (0);
	while (i < limit && buf[i])
		(*str)[j++] = buf[i++];
	(*str)[j] = 0;
	return (1);
}

char	*ft_tmpcleaner(char *tmp, int retval)
{
	int i;

	i = 0;
	while (tmp[retval])
		tmp[i++] = tmp[retval++];
	while (i < retval)
		tmp[i++] = 0;
	return (tmp);
}

int		ft_tmptoline(char **tmp, char **line)
{
	int		i;

	i = 0;
	while ((*tmp)[i] != '\n' && (*tmp)[i])
		i++;
	if ((*tmp)[i] != '\n')
	{
		if (!(*line = ft_strjoin2(*line, *tmp, ft_strlen(*tmp))))
			return (-1);
		free(*tmp);
		*tmp = NULL;
		return (0);
	}
	else
	{
		if (!(*line = ft_strjoin2(*line, *tmp, i)))
			return (-1);
		*tmp = ft_tmpcleaner(*tmp, i + 1);
		return (1);
	}
}
