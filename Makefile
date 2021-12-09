# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 15:00:41 by smagdela          #+#    #+#              #
#    Updated: 2021/12/09 15:22:34 by smagdela         ###   ########.fr        #
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
SRCS	=	
BONUS 	=	
OBJS	:=	${addprefix ${OBJD},${SRCS:.c=.o}}
SRCS	:=	${addprefix ${SRCD},${SRCS}}
BONUSO	:=	${addprefix ${BONUSOD},${BONUS:.c=.o}}
BONUS	:=	${addprefix ${BONUSSD},${BONUS}}

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror
MLXFLAGS	=	-lX11 -lXext
LIBSMK	=	make -C

##################
#	FANCY STUFF	 #
##################

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
	${CC} ${CFLAGS} -c -o $@ -I${INCD} -I${LIBFTD} -I${MLXD} $<

${LIBS}:
	${LIBSMK} ${LIBFTD} bonus
	${LIBSMK} ${MLXD} all

bonus: ${LIBS} ${OBJS} ${BONUSO}
	${CC} ${CFLAGS} ${OBJS} ${MLXFLAGS} ${LIBS} -o ${NAME}_bonus
	@echo ${WHALE}

${BONUSOD}%.o:	${BONUSSD}%.c
	mkdir -p ${BONUSOD}
	${CC} ${CFLAGS} -c -o $@ -I${INCD} -I${LIBFTD} -I${MLXD} $<

clean:
	-rm -rf ${OBJD} ${BONUSOD}
	${LIBSMK} ${LIBFTD} clean
	${LIBSMK} ${MLXD} clean

fclean:	clean
	-rm ${NAME} ${NAME}_bonus
	${LIBSMK} ${LIBFTD} fclean
	${LIBSMK} ${MLXD} clean
	@echo ${NUKE}

re:		fclean all

.PHONY : re all bonus clean fclean
