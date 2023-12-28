/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:45 by nsidqi            #+#    #+#             */
/*   Updated: 2023/12/01 09:30:15 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	if (s == NULL)
		return (0);
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *r, char *tmp)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (r == NULL && tmp == NULL)
		return (NULL);
	res = malloc((ft_strlen(r) + ft_strlen(tmp) + 1) * sizeof(char));
	if (res == NULL)
		return (free(r), NULL);
	if (r != NULL)
	{
		while (r[i] != '\0')
			res[j++] = r[i++];
		free(r);
	}
	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i] != '\0')
			res[j++] = tmp[i++];
	}
	res[j] = '\0';
	return (res);
}
