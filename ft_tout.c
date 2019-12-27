/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 02:17:05 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/28 01:57:00 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	treeprint(t_ree_dir *td, t_signs *fl, t_trpointers *tp)
{
	if (td != NULL)
	{
		treeprint (td->left, fl, tp);
		if (td->s != NULL)
		{
			ft_printf("ls: %s: %s\n", td->dname, td->s);
		}
		else if (td->dname != NULL && !fl->l)
			ft_printf("%s\n", td->dname);
		else if (td->dname != NULL && fl->l && td->gg)
		{
			ft_printf("%s  ", td->rwx);
			ft_printf("%*d ",tp->lenc.c2, td->nl);
			ft_printf("%-*s  ", (int)tp->lenc.c3, td->uid);
			ft_printf("%-*s  ", (int)tp->lenc.c4, td->gid);
			if (td->rwx[0] == 'c' || td->rwx[0] == 'b')
			{
				ft_printf(" %*d, ", tp->lenc.cmajor, td->major);
				ft_printf("%*d ", tp->lenc.cminor, td->minor);
			}
			else
			{
				if ((tp->lenc.cmajor > 0 || tp->lenc.cminor > 0) && (tp->lenc.cmajor + tp->lenc.cminor + 2) > tp->lenc.c5)
					ft_printf(" %*lld ", (tp->lenc.cmajor + tp->lenc.cminor + 2), td->size);
				else
					ft_printf("%*lld ", (int)tp->lenc.c5, td->size);
			}
			ft_printf("%s ", td->time);
			if (td->rwx[0] == 'l')
				ft_printf("%s -> %s\n", td->dname, td->buff);
			else
				ft_printf("%s\n", td->dname);
		}
		treeprint(td->right, fl, tp);
	}
}
