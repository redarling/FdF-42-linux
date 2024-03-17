/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:23:47 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 16:02:50 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	close_window(t_mlx **img)
{
	mlx_destroy_image((*img)->mlx_ptr, (*img)->img);
	mlx_destroy_window((*img)->mlx_ptr, (*img)->win_ptr);
	mlx_destroy_display((*img)->mlx_ptr);
	free_matrix(img);
	free_color(img);
	free((*img)->mlx_ptr);
	exit (0);
}

static int	key_hook(int keycode, t_mlx **img)
{
	if (keycode == ESC)
		close_window(img);
	control_moves(keycode, img);
	return (0);
}

static void	close_program(t_mlx *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free_color(&img);
	free_matrix(&img);
	free(img->mlx_ptr);
	exit (0);
}

static void	fdf(t_mlx *img)
{
	char	menu[44];

	ft_strcpy(menu, "W-A-S-D - to move | P/M - zoom in/zoom out");
	img->up_down = 0;
	img->left_right = 0;
	draw_landscape(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 10, 0xFFFFFF, menu);
	mlx_hook(img->win_ptr, 2, 1L << 0, (void *)key_hook, &img);
	mlx_hook(img->win_ptr, 17, 1L << 17, (void *)close_window, &img);
	mlx_loop(img->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	i;

	if (argc != 2)
		ft_error_exit("./fdf <filename>\n");
	ft_check_input(argv[1]);
	i.mlx_ptr = mlx_init();
	if (!i.mlx_ptr)
		ft_error_exit("MLX connection failed\n");
	mlx_get_screen_size(i.mlx_ptr, &i.width, &i.height);
	i.win_ptr = mlx_new_window(i.mlx_ptr, i.width, i.height, "FdF");
	if (!i.win_ptr)
	{
		free(i.mlx_ptr);
		ft_error_exit("Unable to create a window\n");
	}
	init_matrix(&i, argv[1]);
	get_scale(&i);
	i.img = mlx_new_image(i.mlx_ptr, i.width, i.height);
	i.addr = mlx_get_data_addr(i.img, &i.bits, &i.line_len, &i.endian);
	fdf(&i);
	close_program(&i);
	return (0);
}
