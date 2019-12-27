/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 05:25:33 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/03 17:59:22 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ree_dir	*fillemp(t_ree_dir *td)
{
	td = (t_ree_dir *)malloc(sizeof(t_ree_dir));
	td->path = NULL;
	td->dname = NULL;
	td->s = NULL;
	td->fft = 0;
	td->right = NULL;
	td->left = NULL;
	return (td);
}

t_ree_dir	*filltd(t_ree_dir *td, char *name, char *p, t_trpointers *tp)
{
	struct stat		stbuf;

	if (!(td = (t_ree_dir *)malloc(sizeof(t_ree_dir))))
		exit(-1);
	td->path = ft_strdup(p);
	td->dname = ft_strdup(name);
	if (tp->t || tp->l)
	{
		name = ft_strjoinp(td->path, td->dname);
		if (lstat(name, &stbuf) != -1)
		{
			td->gg = 1;
			tp->lenc = total(name, tp->lenc, tp);
			td->time = ctime(&stbuf.st_ctime);
			td->sec = stbuf.st_ctime;
			chtime(td->time);
			td->time = ft_strdup(td->time);
			if (tp->l)
			{
				td->rwx = drwx(stbuf.st_mode);
				td->nl = stbuf.st_nlink;
				td->uid = ft_strdup(getpwuid(stbuf.st_uid)->pw_name);
				td->gid = ft_strdup(getgrgid(stbuf.st_gid)->gr_name);
				td->major = major(stbuf.st_rdev);
				td->minor = minor(stbuf.st_rdev);
				td->size = stbuf.st_size;
				td->buff = NULL;
				if (td->rwx[0] == 'l')
				{
					td->buff = ft_strnew(1025);
					readlink(name, td->buff, 1024);
					td->buff[ft_strlen(td->buff)] = '\0';
				}
			}
		}
		else
			td->gg = 0;
	}
	td->fft = 0;
	td->s = NULL;
	td->right = NULL;
	td->left = NULL;
	if (tp->t || tp->l)
		free(name);
	return (td);
}

t_ree_errors	*fillte(t_ree_errors *te, char *name, char *s)
{
	te = (t_ree_errors *)malloc(sizeof(t_ree_errors));
	te->name = ft_strdup(name);
	te->s = ft_strdup(s);
	te->right = NULL;
	te->left = NULL;
	return (te);
}

t_ree_files		*filltf(t_ree_files *tf, char *name, t_signs *fl, t_trpointers *tp)
{
	struct stat stbuf;

	tf = (t_ree_files *)malloc(sizeof(t_ree_files));
	tf->fname = ft_strdup(name);
	if (fl->t || fl->l)
	{
		if (lstat(name, &stbuf) != -1)
		{
			tp->lenc = total(name, tp->lenc, tp);
			tf->time = ctime(&stbuf.st_ctime);
			tf->sec = stbuf.st_ctime;
			chtime(tf->time);
			tf->time = ft_strdup(tf->time);
			if (fl->l)
			{
				tf->rwx = drwx(stbuf.st_mode);
				tf->nl = stbuf.st_nlink;
				tf->uid = ft_strdup(getpwuid(stbuf.st_uid)->pw_name);
				tf->gid = ft_strdup(getgrgid(stbuf.st_gid)->gr_name);
				tf->major = major(stbuf.st_rdev);
				tf->minor = minor(stbuf.st_rdev);
				tf->size = stbuf.st_size;
				tf->buff = NULL;
				if (tf->rwx[0] == 'l')
				{
					tf->buff = ft_strnew(1025);
					readlink(tf->fname, tf->buff, 1024);
					tf->buff[ft_strlen(tf->buff)] = '\0';
				}
			}
		}
	}
	tf->right = NULL;
	tf->left = NULL;
	return (tf);
}
