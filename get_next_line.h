/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:33:26 by hdurand           #+#    #+#             */
/*   Updated: 2020/02/04 14:04:16 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_tmpcleaner(char *tmp, int retval);
int		ft_tmptoline(char **tmp, char **line);
void	ft_cleanbuf(char *buf);
int		ft_reader(int *retval, char *buf, int fd);
int		ft_tmpsaver(char **str, char *buf, int limit);
int		ft_is_endofline(char *str);
char	*ft_strjoin2(char *s1, char *s2, int s2size);
int		ft_strlen(char *str);
int		get_next_line(int fd, char **line);
int		ft_whileloop(int retval, char **line, char **tmp, int fd);

#endif
