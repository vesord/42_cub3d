/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:45:23 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/bmp_bonus.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		cube_start(argv[1]);
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		save_frame(argv[1]);
	else
		ft_exit(ERR_WRONG_ARGUMENTS);
	return (0);
}

void	cube_start(char *path_to_conf)
{
	t_cub *cub;

	if (!(cub = (t_cub*)malloc(sizeof(t_cub))))
		ft_exit(ERR_NO_MEMORY);
	cub_init(cub);
	if (!(cub->win->mlx_ptr = mlx_init()))
		cub_destroy(cub, ERR_NO_MEMORY);
	cub->config_path = path_to_conf;
	config_parse(path_to_conf, cub);
	player_init(cub);
	window_setup(cub);
	hook_initialize(cub);
}

void	ft_exit(char *msg)
{
	if (msg && !ft_strncmp(msg, ERR_NO_ERR, 20))
		exit(0);
	ft_putendl_fd("Error.", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(0);
}

void	save_frame(char *path_to_conf)
{
	t_cub *cub;

	if (!(cub = (t_cub*)malloc(sizeof(t_cub))))
		ft_exit(ERR_NO_MEMORY);
	cub_init(cub);
	if (!(cub->win->mlx_ptr = mlx_init()))
		cub_destroy(cub, ERR_NO_MEMORY);
	config_parse(path_to_conf, cub);
	player_init(cub);
	window_setup_save(cub);
	if (!cub->frm_0 && !(cub->frm_0 = frame_init(cub->win->mlx_ptr,
		cub->win->x, cub->win->y)))
		cub_destroy(cub, ERR_NO_MEMORY);
	make_frame(cub);
	if (!create_bmp_img(cub->frm_0))
		cub_destroy(cub, NULL);
	cub_destroy(cub, ERR_NO_ERR);
}
