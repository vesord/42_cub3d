/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:06:25 by matrus            #+#    #+#             */
/*   Updated: 2020/07/15 16:06:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init_win(t_cub *cub)
{
	cub->win->mlx_ptr = NULL;
	cub->win->win_ptr = NULL;
	cub->win->x = 0;
	cub->win->y = 0;
}

void	cub_init_ray(t_cub *cub)
{
	cub->ray->angle = 0;
	cub->ray->x = 0;
	cub->ray->y = 0;
}

void	cub_init_textures(t_cub *cub)
{
	cub_init_textures_null(cub->tex);
	if (!(cub->tex->ea = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->ea);
	if (!(cub->tex->we = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->we);
	if (!(cub->tex->no = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->no);
	if (!(cub->tex->so = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->so);
	if (!(cub->tex->s0 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->s0);
}

void	cub_init_textures_null(t_textures *tex)
{
	tex->ea = NULL;
	tex->no = NULL;
	tex->we = NULL;
	tex->so = NULL;
	tex->s0 = NULL;
	tex->ceil = 0;
	tex->flor = 0;
}

void	cub_init_img(t_img *img)
{
	img->width = 0;
	img->height = 0;
	img->btp = 0;
	img->sz_ln = 0;
	img->endian = 0;
	img->ptr =NULL;
	img->data = NULL;
}

void	cub_init_map(t_cub *cub)
{
	cub->map->blk_y = 0;
	cub->map->blk_x = 0;
	cub->map->blk_z = 0;
	cub->map->max_x = 0;
	cub->map->max_y = 0;
	if (!(cub->map->field = (char**)malloc(sizeof(char*))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		*(cub->map->field) = NULL;
}

void	cub_init_cam(t_cub *cub)
{
	cub->cam->cam_direction_yaw = 0;
	cub->cam->cam_direction_pitch = 0;
	cub->cam->cam_angle_yaw = 0;
	cub->cam->cam_angle_pitch = 0;
	cub->cam->x = 0;
	cub->cam->y = 0;
	cub->cam->z = 0;
}
