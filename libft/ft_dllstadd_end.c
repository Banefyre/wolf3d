/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:54:14 by msagodir          #+#    #+#             */
/*   Updated: 2015/02/24 16:29:18 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dllstadd_end(t_dllist **alst, t_dllist *new)
{
	t_dllist	*root;

	root = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	new->prev = (*alst);
	(*alst)->next = new;
	*alst = root;
}
