/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:12:23 by rakpinar          #+#    #+#             */
/*   Updated: 2023/08/25 15:12:28 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_get_read(int fd, char *str);

char	*ft_get_line(char *str);
char	*ft_get_new_str(char *str);

/*
int		ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
*/
#endif
