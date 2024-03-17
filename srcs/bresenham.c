/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:37:00 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 16:37:07 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/draw.h"

static void	pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->line_len + x * (data->bits / 8));
		*(unsigned int *)dst = color;
	}
}

static int	gradient(int color[2], float t)
{
	t_gradient	util;
	int			new_color;

	util.r0 = (color[0] >> 16) & 0xFF;
	util.g0 = (color[0] >> 8) & 0xFF;
	util.b0 = color[0] & 0xFF;
	util.r1 = (color[1] >> 16) & 0xFF;
	util.g1 = (color[1] >> 8) & 0xFF;
	util.b1 = color[1] & 0xFF;
	util.r = (int)((1 - t) * util.r0 + t * util.r1);
	util.g = (int)((1 - t) * util.g0 + t * util.g1);
	util.b = (int)((1 - t) * util.b0 + t * util.b1);
	new_color = (util.r << 16) | (util.g << 8) | util.b;
	return (new_color);
}

static void	get_args(t_draw *draw, int x0_y0[2], int x1_y1[2])
{
	draw->x0 = x0_y0[0];
	draw->y0 = x0_y0[1];
	draw->x1 = x1_y1[0];
	draw->y1 = x1_y1[1];
	draw->dx = abs(draw->x1 - draw->x0);
	draw->dy = abs(draw->y1 - draw->y0);
	if (draw->x0 < draw->x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (draw->y0 < draw->y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	draw->err = draw->dx - draw->dy;
}

void	draw_line(t_mlx *data, int x0_y0[2], int x1_y1[2], int color[2])
{
	t_draw	draw;

	get_args(&draw, x0_y0, x1_y1);
	draw.length = sqrt(draw.dx * draw.dx + draw.dy * draw.dy);
	draw.step = 1.0 / draw.length;
	draw.t = 0;
	while (draw.x0 != draw.x1 || draw.y0 != draw.y1)
	{
		if (color[0] != color[1])
			pixel_put(data, draw.x0, draw.y0, gradient(color, draw.t));
		else
			pixel_put(data, draw.x0, draw.y0, color[0]);
		draw.err2 = draw.err * 2;
		if (draw.err2 > -(draw.dy))
		{
			draw.err -= draw.dy;
			draw.x0 += draw.sx;
		}
		if (draw.err2 < draw.dx)
		{
			draw.err += draw.dx;
			draw.y0 += draw.sy;
		}
		draw.t += draw.step;
	}
}
