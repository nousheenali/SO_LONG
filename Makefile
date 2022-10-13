# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nali <nali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 16:57:25 by nali              #+#    #+#              #
#    Updated: 2022/03/20 16:06:26 by nali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	= so_long.c ft_map_functions.c ft_check_file_ext.c ft_so_long_utils.c \
		get_next_line.c get_next_line_utils.c ft_map_checks.c ft_initialize_game.c \
		ft_convert_xpm.c ft_animate.c ft_move_player.c ft_convert_xpm_2.c\
		ft_put_enemy.c ft_move_enemy.c 
				
LIBFT 	= libft

MLX_DIR = mlx
		
OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra 

IFLAGS = -I. -I./libft -I./mlx

LIBS = libft.a libmlx.a

RM		= rm -f

all:	${NAME}

${NAME}:	
			make -C ${LIBFT}
			make -C ${MLX_DIR}
			cp libft/libft.a .
			cp mlx/libmlx.a .
			$(CC) ${CFLAGS} ${IFLAGS} ${SRCS} -L. ${LIBS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:		
			make -C ${LIBFT}
			make -C ${MLX_DIR}
			cp libft/libft.a .
			cp mlx/libmlx.a .
			$(CC) ${CFLAGS} ${IFLAGS}  -D BONUS=1 ${SRCS} -L. ${LIBS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)		

clean:		
			${RM} ${OBJS}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a
			${RM} libft.a
			${RM} libmlx.a

re:			fclean all

.PHONY:		all clean fclean re .c.o