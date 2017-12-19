/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:11:21 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/11/28 12:13:11 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int length;

	length = ft_strlen(s1);
	index = 0;
	while (s2[index] != '\0')
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}
