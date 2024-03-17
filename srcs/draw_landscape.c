/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:38:02 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 16:38:04 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_scale(t_mlx *data)
{
	data->scale_x = (double)(data->width * 0.4) / (data->x);
	data->scale_y = (double)(data->height * 0.4) / (data->y);
}

static void	draw_lines_right(t_mlx *data, t_landscape util, int i)
{
	int	j;
	int	h[2];
	int	color[2];

	j = 0;
	while (j < data->x)
	{
		h[0] = data->arr[i][j];
		h[1] = data->arr[i][j + 1];
		color[0] = data->color[i][j];
		color[1] = data->color[i][j + 1];
		util.x_y[0] = j - i + util.pos + data->left_right;
		util.x_y[0] = util.x_y[0] * cos(util.angle) * data->scale_x;
		util.x_y[1] = j + i - h[0] + util.pos + data->left_right;
		util.x_y[1] = util.x_y[1] * sin(util.angle) * data->scale_y;
		if (j + 1 < data->x)
		{
			util.x1_y1[0] = j - i + 1 + util.pos + data->left_right;
			util.x1_y1[0] = util.x1_y1[0] * cos(util.angle) * data->scale_x;
			util.x1_y1[1] = j + i + 1 - h[1] + util.pos + data->left_right;
			util.x1_y1[1] = util.x1_y1[1] * sin(util.angle) * data->scale_y;
			draw_line(data, util.x_y, util.x1_y1, color);
		}
		j++;
	}
}

static void	draw_lines_down(t_mlx *data, t_landscape util, int i)
{
	int	j;
	int	h[2];
	int	color[2];

	j = 0;
	while (j < data->x)
	{
		h[0] = data->arr[i + 1][j];
		h[1] = data->arr[i][j];
		color[0] = data->color[i][j];
		color[1] = data->color[i + 1][j];
		util.x_y[0] = j - (i + 1) + util.pos + data->left_right;
		util.x_y[0] = util.x_y[0] * cos(util.angle) * data->scale_x;
		util.x_y[1] = j + (i + 1) - h[0] + util.pos + data->left_right;
		util.x_y[1] = util.x_y[1] * sin(util.angle) * data->scale_y;
		if (i + 1 < data->y)
		{
			util.x1_y1[0] = j - i + util.pos + data->left_right;
			util.x1_y1[0] = util.x1_y1[0] * cos(util.angle) * data->scale_x;
			util.x1_y1[1] = j + i - h[1] + util.pos + data->left_right;
			util.x1_y1[1] = util.x1_y1[1] * sin(util.angle) * data->scale_y;
			draw_line(data, util.x1_y1, util.x_y, color);
		}
		j++;
	}
}

void	draw_landscape(t_mlx *data)
{
	t_landscape	util;
	int			i;

	if (data->x < data->y)
		util.pos = data->y;
	else
		util.pos = data->x;
	util.angle = (25.0 + data->up_down) * M_PI / 180.0;
	i = 0;
	while (i < data->y)
	{
		draw_lines_right(data, util, i);
		if (i + 1 < data->y)
			draw_lines_down(data, util, i);
		i++;
	}
}
