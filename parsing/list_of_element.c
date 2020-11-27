/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:45:59 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 10:49:49 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cam_elm	*create_c_list(void *c_elt, size_t data_size)
{
	t_cam_elm *stnode;

	stnode = (t_cam_elm *)malloc(sizeof(t_cam_elm));
	if (stnode == NULL)
		return (NULL);
	else
	{
		stnode->cam = malloc(data_size);
		stnode->cam = c_elt;
		stnode->next = NULL;
		stnode->prev = NULL;
		stnode->c_ptr_last = stnode;
	}
	return (stnode);
}

t_element	*create_list(void *elt, int id, size_t data_size)
{
	t_element *stnode;

	stnode = (t_element *)malloc(sizeof(t_element));
	if (stnode == NULL)
		return (NULL);
	else
	{
		stnode->obj = malloc(data_size);
		stnode->obj = elt;
		stnode->id = id;
		stnode->next = NULL;
		stnode->ptr_last = stnode;
	}
	return (stnode);
}

t_cam_elm	*add_c_end(t_cam_elm **liste, void *elt, size_t data_size)
{
	t_cam_elm	*new;
	t_cam_elm	*ptr;
	t_cam_elm	*pv;

	ptr = *liste;
	new = (t_cam_elm *)malloc(sizeof(t_cam_elm));
	if (new == NULL)
		return (NULL);
	else
	{
		new->cam = malloc(data_size);
		new->cam = elt;
		new->next = NULL;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
	(*liste)->c_ptr_last = new;
	return (*liste);
}

t_element	*add_end(t_element **liste, void *elt, int id, size_t data_size)
{
	t_element	*new;
	t_element	*ptr;

	ptr = *liste;
	new = (t_element *)malloc(sizeof(t_element));
	if (new == NULL)
		return (NULL);
	else
	{
		new->obj = malloc(data_size);
		new->obj = elt;
		new->id = id;
		new->next = NULL;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	(*liste)->ptr_last = new;
	return (*liste);
}
