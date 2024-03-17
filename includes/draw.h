/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:36:43 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 16:36:47 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_draw
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	float	length;
	float	step;
	float	t;
}		t_draw;

typedef struct s_gradient
{
	int	r0;
	int	g0;
	int	b0;
	int	r1;
	int	g1;
	int	b1;
	int	r;
	int	g;
	int	b;
}		t_gradient;

#endif
