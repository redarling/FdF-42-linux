/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:16:41 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 15:03:36 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define ESC 65307
# define P 112
# define M 109
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_mlx
{
	int		**arr;
	long	**color;
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;
	int		up_down;
	int		left_right;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits;
	int		line_len;
	int		endian;
}		t_mlx;

typedef struct s_landscape
{
	double	angle;
	int		pos;
	int		x_y[2];
	int		x1_y1[2];
}		t_landscape;

/******************DRAW FUNCTIONS************************************/
void	draw_line(t_mlx *data, int x0_y0[2], int x1_y1[2], int color[2]);
void	draw_landscape(t_mlx *data);

/******************INITIALIZATION_OF_MATRIX**************************/
void	init_matrix(t_mlx *data, char *file);

/******************CHECK_INPUT_FILE**********************************/
void	ft_check_input(char *file);

/******************HANDLE_ERRORS_AND_FREEING*************************/
void	ft_error_exit(char *msg);
void	ft_free(char **to_free);
void	free_matrix(t_mlx **data);
void	free_color(t_mlx **data);

/******************UTILS*********************************************/
int		get_x(char *line);
void	get_scale(t_mlx *data);

/*******************MLX_HOOK*****************************************/
void	control_moves(int keycode, t_mlx **img);

#endif
