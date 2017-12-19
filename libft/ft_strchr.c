/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:16:22 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/11/28 12:02:17 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;
	char			*s_hold;

	s_hold = (char*)s;
	u_c = c;
	while (*s_hold)
	{
		if (*s_hold == u_c)
			return (s_hold);
		if (*++s_hold == u_c && u_c == '\0')
			return (s_hold);
	}
	return (NULL);
}
