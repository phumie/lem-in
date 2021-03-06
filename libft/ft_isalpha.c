/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:07:58 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/08/17 11:27:04 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int al)
{
	if ((al >= 'a' && al <= 'z') || (al >= 'A' && al <= 'Z'))
		return (1);
	return (0);
}
