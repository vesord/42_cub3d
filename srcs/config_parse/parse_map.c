/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:42:06 by matrus            #+#    #+#             */
/*   Updated: 2020/07/16 22:42:06 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_line_to_map(char *line, t_cub *cub)
{
	int i;

	i = 0;
	while ((cub->map->field)[i])
		i++;
	if (!(cub->map->field = (char**)ft_realloc_tab((void**)cub->map->field,
		i + 1, i + 2))
		|| !((cub->map->field)[i] = ft_strdup(line)))
	{
		free(line);
		cub_destroy(cub, ERR_NO_MEMORY);
	}
	(cub->map->field)[i + 1] = NULL;
}

int		check_map(t_cub *cub)
{
	if (cub)
	{}
	return (PARSE_OK_MAP);
}

void	**ft_realloc_tab(void **tab, int prev_size, int need_size)	// TODO: add this to libft
{
	void	**new_ptr;

	if (!(new_ptr = (void**)malloc(sizeof(void*) * need_size))) // TODO: check sizeof(void*/char*/int*)
		return (NULL);
	while (need_size > prev_size)
	{
		new_ptr[need_size - 1] = NULL;
		need_size--;
	}
	while (prev_size > 0)
	{
		new_ptr[prev_size - 1] = tab[prev_size - 1];
		prev_size--;
	}
	free_tab(tab);
	return (new_ptr);
}

void	free_tab(void **tab)	// TODO: test this function // TODO: add this to libft
{
	void	**ptr;

	ptr = tab;
	while (*ptr)
	{
		free(*ptr);
		ptr += sizeof(void*);
	}
	free(tab);
}