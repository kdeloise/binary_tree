/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 22:02:09 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/24 16:09:41 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_lenlst(t_dirs *forlen)
{
	int len;

	if (!forlen)
		return (0);
	len = 1;
	while (forlen->next)
	{
		forlen = forlen->next;
		len++;
	}
	return (len);
}
