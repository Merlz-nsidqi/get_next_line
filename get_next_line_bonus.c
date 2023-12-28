/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:41 by nsidqi            #+#    #+#             */
/*   Updated: 2023/12/28 10:20:57 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line(char *s, char *str)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_next(char *s)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1));
	if (str == NULL)
		return (free(s), NULL);
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

static char	*ft_read(int fd, char *r)
{
	char	*tmp;
	int		t;

	tmp = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (free(r), NULL);
	while (!ft_strchr(r, '\n'))
	{
		t = read(fd, tmp, BUFFER_SIZE);
		if (t == -1)
		{
			free(tmp);
			free(r);
			return (NULL);
		}
		else if (t == 0)
			break ;
		tmp[t] = '\0';
		r = ft_strjoin(r, tmp);
	}
	free(tmp);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*r[OPEN_MAX];
	char		*t;

	t = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	r[fd] = ft_read(fd, r[fd]);
	if (r[fd] == NULL)
		return (NULL);
	t = ft_line(r[fd], t);
	r[fd] = ft_next(r[fd]);
	if (!t)
	{
		free(r[fd]);
		r[fd] = NULL;
	}
	return (t);
}
