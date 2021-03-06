/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_ceil_floor_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:24:14 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	get_len_ceil(float angle, t_cub *cub)
{
	return ((cub->map->blk_z - cub->cam->z) / fabsf(tanf(angle)));
}

float	get_len_flor(float angle, t_cub *cub)
{
	return ((cub->cam->z) / -tanf(angle));
}
