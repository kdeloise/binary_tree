/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:27:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/07 02:14:33 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	freememerr(t_ree_errors	*te, t_signs *fl)
{
	if (te == NULL)
		return ;
	freememerr(te->left, fl);
	freememerr(te->right, fl);
	if (te->name)
	{
		free(te->name);
		te->name = NULL;
	}
	if (te->s)
	{
		free(te->s);
		te->s = NULL;
	}
	free(te);
}

void	errprint(t_ree_errors *te)
{
    if (te != NULL)
    {
        errprint (te->left);
        ft_printf("ls: %s: %s\n", te->name, te->s);
        errprint(te->right);
    }
}

void	ft_err(t_trpointers *tp, char *name, char *s, t_signs *fl)
{
	if (!fl->ter)
	{
		fl->ter = 1;
		tp->teroot = fillte(tp->teroot, name, s);
		tp->te = tp->teroot;
		return ;
	}
	tp->te = tp->teroot;
	while (1)
	{
		if (ft_strcmp(tp->te->name, name) >= 0)
		{
			if (tp->te->left == NULL)
			{
				tp->te->left = fillte(tp->te, name, s);
					break ;
			}
			else
				tp->te = tp->te->left;
		}
		if (ft_strcmp(tp->te->name, name) < 0)
		{
			if (tp->te->right == NULL)
			{
				tp->te->right = fillte(tp->te, name, s);
					break ;
			}
			else
				tp->te = tp->te->right;
		}
	}
}

t_ree_dir *ft_errd(t_ree_dir *td, char *s, char *name, t_signs *fl)
{
	td = (t_ree_dir *)malloc(sizeof(t_ree_dir));
	td->path = ft_strdup(name);
	td->dname = ft_name(name);
	td->s = ft_strdup(s);
	td->right = NULL;
	td->left = NULL;
	return (td);
}
