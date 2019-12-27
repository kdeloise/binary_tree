/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:58:26 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/18 07:28:39 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	freememfiles(t_ree_files *tf, t_signs *fl)
{
	if (tf == NULL)
		return ;
	freememfiles(tf->left, fl);
	freememfiles(tf->right, fl);
	if (tf->fname)
	{
		free(tf->fname);
		tf->fname = NULL;
	}
	if (fl->l || fl->t)
	{
		free(tf->time);
		if (fl->l)
		{
			free(tf->uid);
			free(tf->gid);
			free(tf->rwx);
			if (tf->buff)
				free(tf->buff);
		}
	}
	free(tf);
}

void	filesprint(t_ree_files *tf, t_signs *fl, t_trpointers *tp)
{
	if (tf != NULL)
	{
		filesprint(tf->left, fl, tp);
		if (!fl->l)
			ft_printf("%s\n", tf->fname);
		else if (fl->l)
		{
			ft_printf("%s  ", tf->rwx);
			ft_printf("%*d ",tp->lenc.c2, tf->nl);
			ft_printf("%-*s  ", (int)tp->lenc.c3, tf->uid);
			ft_printf("%-*s  ", (int)tp->lenc.c4, tf->gid);
			if (tf->rwx[0] == 'c' || tf->rwx[0] == 'b')
			{
				ft_printf(" %*d, ", tp->lenc.cmajor, tf->major);
				ft_printf("%*d ", tp->lenc.cminor, tf->minor);
			}
			else
			{
				if ((tp->lenc.cmajor > 0 || tp->lenc.cminor > 0) && (tp->lenc.cmajor + tp->lenc.cminor + 2) > tp->lenc.c5)
					ft_printf(" %*lld", (tp->lenc.cmajor + tp->lenc.cminor + 2), tf->size);
				else
					ft_printf("%*lld ", (int)tp->lenc.c5, tf->size);
			}
			ft_printf("%s ", tf->time);
			if(tf->rwx[0] == 'l')
				ft_printf("%s -> %s\n", tf->fname, tf->buff);
			else
				ft_printf("%s\n", tf->fname);
		}
		filesprint(tf->right, fl, tp);
	}
}

void	ft_filesr(t_trpointers *tp, char *name, t_signs *fl)
{
	if (!fl->tfr)
	{
		tp->lenc = zerostruct(tp->lenc);
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name, fl, tp);
		tp->tf = tp->tfroot;
		return ;
	}
	tp->tf = tp->tfroot;
	while (1)
	{
		if (ft_strcmp(tp->tf->fname, name) < 0)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (ft_strcmp(tp->tf->fname, name) >= 0)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}

void	ft_files(t_trpointers *tp, char *name, t_signs *fl)
{
	if (!fl->tfr)
	{
		tp->lenc = zerostruct(tp->lenc);
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name, fl, tp);
		tp->tf = tp->tfroot;
		return ;
	}
	tp->tf = tp->tfroot;
	while (1)
	{
		if (ft_strcmp(tp->tf->fname, name) >= 0)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
					break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (ft_strcmp(tp->tf->fname, name) < 0)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name, fl, tp);
					break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}

void	ft_filesrt(t_trpointers *tp, char *name, t_signs *fl)
{
	struct stat				stbuf;

	if (!fl->tfr)
	{
		tp->lenc = zerostruct(tp->lenc);
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name, fl, tp);
		tp->tf = tp->tfroot;
		return ;
	}
	tp->tf = tp->tfroot;
	while (1)
	{
		if (lstat(name, &stbuf) != -1)
			tp->tsec = stbuf.st_ctime;
		if (tp->tf->sec >= tp->tsec)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (tp->tf->sec < tp->tsec)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}

void	ft_filest(t_trpointers *tp, char *name, t_signs *fl)
{
	struct stat stbuf;

	if (!fl->tfr)
	{
		tp->lenc = zerostruct(tp->lenc);
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name, fl, tp);
		tp->tf = tp->tfroot;
		return ;
	}
	tp->tf = tp->tfroot;
	while (1)
	{
		if (lstat(name, &stbuf) != -1)
			tp->tsec = stbuf.st_ctime;
		if (tp->tf->sec < tp->tsec)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (tp->tf->sec >= tp->tsec)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}
