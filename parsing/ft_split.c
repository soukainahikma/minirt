/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:51:25 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 09:51:27 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			is_compere(int c, int o)
{
	return (c == o || c == '\0');
}

static int			y_tab_len(const char *str, int c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (!is_compere(str[i], c) && is_compere(str[i + 1], c))
			len++;
		i++;
	}
	return (len);
}

static int			x_tab_len(const char *str, int c)
{
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (!is_compere(str[i++], c))
		len++;
	return (len);
}

static void			*fill(const char *str, char **tab, int len_y, int c)
{
	int len_x;
	int x;
	int y;

	y = 0;
	while (y < len_y)
	{
		while (is_compere(*str, c))
			str++;
		len_x = x_tab_len(str, c);
		x = 0;
		tab[y] = malloc(sizeof(char) * (len_x + 1));
		if (tab[y] == NULL)
			return (NULL);
		while (x < len_x)
		{
			tab[y][x++] = *str;
			str++;
		}
		tab[y][x] = '\0';
		y++;
	}
	return ((void*)1);
}

char				**ft_split(char const *s, char c)
{
	int		len_y;
	char	**tab;
	void	*check;

	if (!s)
		return (0);
	len_y = 0;
	len_y = y_tab_len(s, c);
	tab = malloc(sizeof(char*) * (len_y + 1));
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	tab[len_y] = 0;
	check = fill(s, tab, len_y, c);
	if (check == NULL)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
