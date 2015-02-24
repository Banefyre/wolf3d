/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <msagodir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:25:57 by msagodir          #+#    #+#             */
/*   Updated: 2015/02/24 16:26:15 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmps1;
	char	*tmps2;
	int		i;

	i = 0;
	tmps1 = (char*)s1;
	tmps2 = (char*)s2;
	while (tmps1[i] == tmps2[i] && --n)
	{
		i++;
	}
	return (tmps1[i] - tmps2[i]);
}
