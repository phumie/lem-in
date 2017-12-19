/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:17:49 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/11/28 12:22:58 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen((char*)src);
	if (len <= 0)
		return (dst);
	while (index < len)
	{
		if (index < src_len)
		{
			dst[index] = src[index];
			index++;
			continue;
		}
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
