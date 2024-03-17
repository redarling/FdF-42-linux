SRCS            =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_strchr.c ft_strdup.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_substr.c ft_tolower.c ft_toupper.c \
			ft_strmapi.c ft_strrchr.c ft_strtrim.c \
			ft_split.c ft_strjoin_free.c ft_strcpy.c \
			get_next_line.c ft_isxdigit.c ft_strtol.c

BONUS_SRCS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstiter.c \
			ft_lstdelone.c \
			ft_lstclear.c 

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${BONUS_SRCS:.c=.o}

NAME		= libft.a

AR		= ar rcs

RM		= rm -f

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c -I.  $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

all:		${NAME}

bonus:		${NAME} ${OBJS_BONUS}
		${AR} ${NAME} ${OBJS_BONUS}

so: $(OBJS)
	gcc --shared -o libft.so $(OBJS) $(OBJS_BONUS)

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME} ${bonus} 

re:		fclean all

.PHONY:		all bonus fclean clean re
