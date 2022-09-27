/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:31:35 by hdurand           #+#    #+#             */
/*   Updated: 2020/02/04 14:13:57 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2, int s2size)
{
	int		slen1;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	slen1 = 0;
	if (s1 != NULL)
		slen1 = ft_strlen(s1);
	if (!(str = malloc(sizeof(char *) * (slen1 + s2size) + 1)))
		return (0);
	while (j < slen1)
		str[i++] = s1[j++];
	j = 0;
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	while (j < s2size)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

void	ft_cleanbuf(char *buf)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
}

int		ft_whileloop(int retval, char **line, char **tmp, int fd)
{
	char buf[BUFFER_SIZE + 1];

	if ((ft_reader(&retval, buf, fd)) == -1)
		return (-1);
	while (retval != 0)
	{
		if (ft_is_endofline(buf) == -1)
		{
			if (!(*line = ft_strjoin2(*line, buf, retval)))
				return (-1);
			if ((ft_reader(&retval, buf, fd)) == -1)
				return (-1);
		}
		else
		{
			if ((ft_tmpsaver(tmp, buf, retval)) == -1)
				return (-1);
			if (!(*line = ft_strjoin2(*line, buf, ft_is_endofline(buf))))
				return (-1);
			return (1);
		}
	}
	return (-2);
}

int		get_next_line(int fd, char **line)
{
	static char *tmp = NULL;
	int			retval;

	retval = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	if (tmp != NULL)
		if ((retval = ft_tmptoline(&tmp, line)) != 0)
			return (retval);
	retval = ft_whileloop(retval, line, &tmp, fd);
	if (retval != -2)
		return (retval);
	else if (*line == NULL)
	{
		if (!(*line = malloc(sizeof(char*) * 1)))
			return (-1);
		(*line)[0] = 0;
	}
	return (0);
}
