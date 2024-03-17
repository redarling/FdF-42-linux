/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:37:16 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 16:37:18 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	destroy_and_put(t_mlx *i)
{
	char	menu[44];

	ft_strcpy(menu, "W-A-S-D - to move | P/M - zoom in/zoom out");
	mlx_destroy_image(i->mlx_ptr, i->img);
	i->img = mlx_new_image(i->mlx_ptr, i->width, i->height);
	i->addr = mlx_get_data_addr(i->img, &i->bits, &i->line_len, &i->endian);
	draw_landscape(i);
	mlx_put_image_to_window(i->mlx_ptr, i->win_ptr, i->img, 0, 0);
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 10, 0xFFFFFF, menu);
}

static void	wasd(int keycode, t_mlx **img)
{
	if (keycode == W)
		(*img)->up_down--;
	if (keycode == A)
		(*img)->left_right--;
	if (keycode == S)
		(*img)->up_down++;
	if (keycode == D)
		(*img)->left_right++;
	destroy_and_put(*img);
}

void	control_moves(int keycode, t_mlx **img)
{
	if (keycode == P || keycode == M)
	{
		if (keycode == P)
		{
			(*img)->scale_x += 0.1;
			(*img)->scale_y += 0.1;
		}
		else
		{
			(*img)->scale_x -= 0.1;
			(*img)->scale_y -= 0.1;
		}
		destroy_and_put(*img);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		wasd(keycode, img);
}
