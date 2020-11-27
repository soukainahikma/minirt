/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:20:07 by shikma            #+#    #+#             */
/*   Updated: 2020/11/27 09:20:57 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		my_checker_free(char *str, int error, int i)
{
	free(str);
	str = NULL;
	return (my_file(error, i));
}

int		my_free(char *str)
{
	free(str);
	str = NULL;
	return (0);
}

void	free_c_liste(t_cam_elm *c_liste)
{
	t_cam_elm *ptr1;
	t_cam_elm *ptr2;

	ptr1 = c_liste;
	while (ptr1)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		free(ptr2);
		ptr2 = NULL;
	}
}

void	free_liste(t_element *liste)
{
	t_element *ptr1;
	t_element *ptr2;

	ptr1 = liste;
	while (ptr1)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		free(ptr2);
		ptr2 = NULL;
	}
}

int		free_my_list(t_cam_elm *c_liste, t_element *liste)
{
	free_c_liste(c_liste);
	free_liste(liste);
	return (0);
}
