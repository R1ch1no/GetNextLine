/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:01:45 by rkurnava          #+#    #+#             */
/*   Updated: 2022/12/04 18:05:56 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*jstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 && str2)
		jstr = (char *)malloc(sizeof(char) * ft_strlen(str2) + 1);
	if (str1 && str2)
		jstr = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2))
				+ 1);
	if (!jstr || !str2)
		return (NULL);
	if (str1)
	{
		i = -1;
		while (str1[++i])
			jstr[i] = str1[i];
	}
	while (str2[j])
		jstr[i++] = str2[j++];
	jstr[i] = '\0';
	free(str1);
	return (jstr);
}

char	*ft_strtrim(char *str, char rem)
{
	char	*res;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!str || !str[0] || str == NULL)
	{
		return (NULL);
	}
	while (str[i] != rem && str[i] != '\0')
		i++;
	if (str[i] == rem)
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		res[j++] = str[i++];
	if (str[i] == rem)
		res[j++] = '\n';
	res[j] = '\0';
	return (res);
}

char	*ft_strtrim_hold(char *str, char rem)
{
	char	*res;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!str || !str[0] || str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i] != rem && str[i] != '\0')
		i++;
	if (str[i] == rem)
		i++;
	res = NULL;
	res = malloc((ft_strlen(str) - i) + 1);
	if (!res)
		return (NULL);
	while (str[i] != '\0' && i < ft_strlen(str))
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}
