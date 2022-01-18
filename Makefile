NAME		:=	so_long

CC :=  clang
CFLAGS	:= -Wall -Wextra -Werror
RM	= rm -f

LIBFT_DIR	:= libft
LIBFT_LIB	:= ${LIBFT_DIR}/libft.a

MLX_DIR		:= mlx-linux
MLX_LIB		:= ${MLX_DIR}/libmlx.a
MLXFLAGS 	:= -I ${MLX_DIR} -L ${MLX_DIR} -Lmlx -lmlx -lXext -lX11
 
SRCS_DIRS	=	./srcs/

vpath %.c ${SRCS_DIRS}

INC_DIR := ./includes
INC		:= includes/so_long.h

SRCS	=	./srcs/so_long.c\
			./srcs/errors.c\
			./srcs/checkers.c\
			./srcs/init.c
			

OBJS_DIR 	=	./objs
OBJS 	=  ${addprefix ${OBJS_DIR}/, ${notdir ${SRCS:.c=.o}}}

all:	${NAME}

${LIBFT_LIB}: 
	@make -C ./${LIBFT_DIR}
${MLX_LIB}: 
	@make -C ./${MLX_DIR}

${NAME}: ${OBJS} ${LIBFT_LIB} ${MLX_LIB} ${INC} Makefile
	@ ${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -I ${INC_DIR}
	@echo "So_Long App is ready"	

${OBJS_DIR}:
	@mkdir -p ${OBJS_DIR}

${OBJS_DIR}/%.o : %.c | ${OBJS_DIR}
	@${CC} ${CFLAGS} -o $@ -I${INC_DIR} -c $^


clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean
	@rm -rf ${OBJS_DIR}
	@echo "So_Long is Cleaned"	

fclean: clean
	@${RM} ${NAME} ${LIBFT_LIB} ${MLX_LIB}
	@echo "So_Long is Full Cleaned"	

re:		fclean all

.PHONY: all libft clean fclean re