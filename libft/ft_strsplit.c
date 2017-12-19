/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:23:45 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/12/01 09:49:49 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrdcnt(const char *s, char c)
{
	int		cnt;
	int		substr;

	substr = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (substr == 1 && *s == c)
			substr = 0;
		if (substr == 0 && *s != c)
		{
			substr = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	wrdlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		wrds;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s || !c)
		return (NULL);
	wrds = wrdcnt((const char *)s, c);
	if (!(array = (char **)malloc(sizeof(char*) * (wrds + 1))))
		return (NULL);
	while (wrds--)
	{
		while (*s == c && *s != '\0')
			s++;
		len = wrdlen((const char *)s, c);
		array[i] = ft_strsub((const char *)s, 0, len);
		s = s + wrdlen(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
