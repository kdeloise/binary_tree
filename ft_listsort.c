#include "ft_ls.h"

t_dirs *ft_lstsortr(t_dirs *dirs)
{
	int l;
	int i;
	int ii;
	t_dirs *forsort2;
	t_dirs *nul;

	nul = dirs;
	i = 0;
	l = ft_lenlst(nul);
	while (i++ < l && !(ii = 0))
	{
		dirs = nul;
		while (ii++ < (l - 1))
		{
			forsort2 = dirs->next;
			if (ft_strcmp(forsort2->name, dirs->name) > 0)
			{
				ft_swap(&(forsort2->name), &(dirs->name));
			}
			dirs = dirs->next;
		}
	}
	return (dirs);
}

t_dirs *ft_lstsort(t_dirs *dirs)
{
    int l;
    int i;
    int ii;
    t_dirs *forsort2;
    t_dirs *nul;

    nul = dirs;
    i = 0;
    l = ft_lenlst(nul);
    while (i++ < l && !(ii = 0))
    {
        dirs = nul;
        while (ii++ < (l - 1))
        {
            forsort2 = dirs->next;
            if (ft_strcmp(forsort2->name, dirs->name) < 0)
            {
                ft_swap(&(forsort2->name), &(dirs->name));
            }
            dirs = dirs->next;
        }
    }
    return (dirs);
}