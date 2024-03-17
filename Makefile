SRCS_LIST		=	bresenham.c \
					check_valid.c \
					draw_landscape.c \
					init_matrix.c \
					main.c \
					utils.c \
					key_controls.c

SRCS 			= $(addprefix srcs/, $(SRCS_LIST))

MLX_DIR			= minilibx/

LIBFT_DIR		= libft/libft.a

MLX_LINK		= -Lminilibx -lmlx -lXext -lX11

MATH_FLAGS 		= -lm

OBJS			= ${SRCS:.c=.o}

NAME			= fdf

RM				= rm -f

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -Iincludes

all:		${NAME}

${NAME}:	${OBJS}
		make -C $(MLX_DIR)
		make -sC libft
		${CC} ${CFLAGS} $(MATH_FLAGS) ${OBJS} $(MLX_LINK) $(LIBFT_DIR) -o ${NAME}

bonus:		all

clean:
		make clean -sC libft
		${RM} ${OBJS}

fclean:		clean
		make clean -C $(MLX_DIR)
		make fclean -sC libft
		${RM} ${NAME}

re:		fclean all

.PHONY:		all fclean clean re bonus
