/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:02:00 by rkurnava          #+#    #+#             */
/*   Updated: 2022/12/04 18:06:03 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(const char *str);
char	*ft_strtrim(char *str, char rem);
char	*ft_strtrim_hold(char *str, char rem);
char	*get_next_line(int fd);
int		ft_newline(char *str);

#endif
