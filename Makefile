# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 15:00:41 by smagdela          #+#    #+#              #
#    Updated: 2022/01/03 11:54:26 by smagdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
#	VARIABLES	#
#################

NAME	=	fractol

LIBSD	=	libs/
LIBFTD	=	${addprefix ${LIBSD},libft/}
MLXD	=	${addprefix ${LIBSD},mlx_linux/}
INCD	=	includes/
SRCD	=	sources/
OBJD	=	objects/
BONUSD	=	bonus/
BONUSSD	=	${BONUSD}sources/
BONUSOD	=	${BONUSD}objects/

LIBFT	:=	${addprefix ${LIBFTD},libft.a}
MLX		:=	${addprefix ${MLXD},libmlx_Linux.a}
LIBS	:=	${LIBFT} ${MLX}
SRCS	=	fractol.c parsing.c ft_utils.c ft_data.c ft_draw.c ft_draw_2.c ft_colouring.c ft_colouring_2.c ft_events.c ft_events_2.c mandelbrot.c julia.c zooms.c
BONUS 	=	fractol_bonus.c parsing_bonus.c ft_utils_bonus.c ft_data_bonus.c ft_draw_bonus.c ft_draw_2_bonus.c ft_colouring_bonus.c ft_colouring_2_bonus.c ft_events_bonus.c ft_events_2_bonus.c mandelbrot_bonus.c julia_bonus.c burning_ship_bonus.c multicorn_bonus.c cam_moves_bonus.c zooms_bonus.c
OBJS	:=	${addprefix ${OBJD},${SRCS:.c=.o}}
DEPS	:=	${addprefix ${OBJD},${SRCS:.c=.d}}
SRCS	:=	${addprefix ${SRCD},${SRCS}}
BONUSO	:=	${addprefix ${BONUSOD},${BONUS:.c=.o}}
BONUS	:=	${addprefix ${BONUSSD},${BONUS}}

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror
MLXFLAGS	=	-lX11 -lXext -lm -lz
LIBSMK	=	make -C

###################
#	FANCY STUFF   #
###################

GREEN	=	\033[0;32m
RED		=	\033[1;31m
NC		=	\033[0m

WHALE	=	"\n${GREEN}       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!	${NC}\n"
NUKE	=	"\n${RED}     _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____${NC}\n\n"

#############
#	RULES	#
#############

all:	${NAME}

${NAME}:	${LIBS} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} ${LIBS} -o ${NAME}
	@echo ${WHALE}

${OBJD}%.o:	${SRCD}%.c
	mkdir -p ${OBJD}
	${CC} ${CFLAGS} -c -o $@ -I${INCD} -I${LIBFTD} -I${MLXD} -MMD $<

${LIBS}:
	${LIBSMK} ${LIBFTD} bonus
	${LIBSMK} ${MLXD} all

bonus:	${NAME}_bonus

${NAME}_bonus : ${LIBS} ${BONUSO}
	${CC} ${CFLAGS} ${BONUSO} ${MLXFLAGS} ${LIBS} -o ${NAME}_bonus
	@echo ${WHALE}

${BONUSOD}%.o:	${BONUSSD}%.c
	mkdir -p ${BONUSOD}
	${CC} ${CFLAGS} -c -o $@ -I${INCD} -I${LIBFTD} -I${MLXD} -MMD $<

clean:
	-rm -rf ${OBJD} ${BONUSOD} ${DEPD}
	${LIBSMK} ${LIBFTD} clean
	${LIBSMK} ${MLXD} clean

fclean:	clean
	-rm ${NAME} ${NAME}_bonus
	${LIBSMK} ${LIBFTD} fclean
	${LIBSMK} ${MLXD} clean
	@echo ${NUKE}

re:		fclean all

norm:
	norminette ${SRCS} ${BONUS} ${INCD}*.h ${LIBFTD}*.c ${LIBFTD}*.h

.PHONY : re all bonus clean fclean norm

-include ${DEPS}
