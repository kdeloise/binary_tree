/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 04:51:57 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/12 01:45:50 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_signs(t_signs *fl, t_trpointers	*tp, char *s)
{
	int i;

	i = 1;
	while(s[i])
	{
		if (s[i] == 't')
		{
			fl->t = 1;
			tp->l = 1;
		}
		else if (s[i] == 'l')
		{
			fl->l = 1;
			tp->l = 1;
		}
		else if (s[i] == 'r')
			fl->r = 1;
		else if (s[i] == 'R')
			fl->rec = 1;
		else if (s[i] == 'a')
			fl->a = 1;
		else if (s[i] == 'A')
			fl->abig = 1;
		else
		{
			ft_printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", s[i]);
				exit(-1);
		}
		i++;
	}
	return (0);
}

void	ft_ls(char *name, t_signs *fl, t_trpointers *tp)
{
    struct stat stbuf;

    if (lstat(name, &stbuf) == -1)
    {
    	fl->terd = 1;
        ft_err(tp, name, strerror(errno), fl);
        return ;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    {
    	tp->i++;
    	if (!tp->dirs)
    	{
            tp->dirs = (t_dirs *)malloc(sizeof(t_dirs));
			tp->dirs->name = ft_strdup(name);
			tp->first = tp->dirs;
			tp->dirs->next = NULL;
			tp->firstforfree = tp->dirs;
        }
    	else
        {
			tp->dirs->next = (t_dirs *)malloc(sizeof(t_dirs));
			tp->dirs = tp->dirs->next;
    	    tp->dirs->name = ft_strdup(name);
    	    tp->dirs->next = NULL;
        }
        return ;
    }
    else
	{
		tp->ifile++;
		if (fl->r)
		{
			if (fl->t)
				ft_filesrt(tp, name, fl);
			else
				ft_filesr(tp, name, fl);
		}
		else if (fl->t)
		{
			if (fl->r)
				ft_filesrt(tp, name, fl);
			else
				ft_filest(tp, name, fl);
		}
		else
			ft_files(tp, name, fl);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_signs	fl;
	t_trpointers	tp;
	t_ree_dir		*t;

	i = 1;
	tp.i = 0;
	tp.ifile = 0;
	ft_fillfl(&fl, &tp);
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		if (ft_signs(&fl, &tp, argv[i]) == -1)
			return (0);
		i++;
	}
	fl.ac = argc - (i - 1);
	if (argc - i == 0)
	{
		t = ft_treedirs(".", &fl, &tp);
		if (fl.rec && fl.tdr)
		{
			ft_r(t, &fl, &tp);
			freememdir(t, &fl, &tp);
		}
		else
			freememdir(t, &fl, &tp);
		return (0);
	}
	tp.dirs = NULL;
    while (argv[i])
    {
        ft_ls(argv[i], &fl, &tp);
        i++;
    }
    if (tp.dirs)
	{
    	if (!fl.r)
    		ft_lstsort(tp.first);
    	else
			ft_lstsortr(tp.first);
	}
    if (fl.ter)
    	errprint(tp.teroot);
    if (fl.tfr)
		filesprint(tp.tfroot, &fl, &tp);
    if (tp.dirs)
	{
		while (tp.first)
		{
			t = ft_treedirs(tp.first->name, &fl, &tp);
			if (fl.rec && fl.tdr)
			{
					ft_r(t, &fl, &tp);
					freememdir(t, &fl, &tp);
			}
			else
				freememdir(t, &fl, &tp);
			tp.first = tp.first->next;
			if (!tp.first)
				break;
			fl.tdr = 0;
			fl.tds = 0;
			fl.fir = 0;
			fl.reci = 0;
		}
	}
	if (fl.tdr)
		freedirs(tp.firstforfree);
	if (fl.ter)
		freememerr(tp.teroot, &fl);
	if (fl.tfr)
		freememfiles(tp.tfroot, &fl);
	return (0);
}
