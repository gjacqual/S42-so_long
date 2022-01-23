# Program conf
NAME		:=	so_long

# Compilation Parameters
CC 			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -MMD -g -O2
RM			=	rm -f

# Libraries
LIBFT_DIR	:=	libft
LIBFT_LIB	:=	${LIBFT_DIR}/libft.a

# MLX lib
MLX_DIR		:=	mlx-linux
MLX_LIB		:=	${MLX_DIR}/libmlx.a
MLXFLAGS 	:=	-I ${MLX_DIR} -L ${MLX_DIR} -Lmlx -lmlx -lXext -lX11

# Includes
INC_DIR 	:= includes
INC			:= includes/so_long.h
INC_B_DIR 	:= includes_bonus
INC_B		:= includes_bonus/so_long_bonus.h

#Get next line
GNL_INC		:= ./srcs/get_next_line/get_next_line.h
GNL_B_INC	:= ./srcs_bonus/get_next_line_bonus/get_next_line.h

LIBFT_INC	:= .${LIBFT_DIR}

# Sources
SRCS_DIRS	=	./srcs/\
				./srcs/get_next_line/
SRCS_B_DIRS	=	./srcs_bonus/\
				./srcs_bonus/get_next_line_bonus/

# Search for src in catalogs
vpath %.c ${if ${BONUS_MODE}, ${SRCS_B_DIRS}, ${SRCS_DIRS}}


SRCS	=	./srcs/so_long.c\
			./srcs/errors.c\
			./srcs/check_map.c\
			./srcs/check_file.c\
			./srcs/check_wall.c\
			./srcs/load_images.c\
			./srcs/find_map_size.c\
			./srcs/read_map.c\
			./srcs/hooks.c\
			./srcs/steps.c\
			./srcs/draw_picture.c\
			./srcs/init.c\
			./srcs/close_window.c\
			./srcs/get_next_line/get_next_line.c\
			./srcs/get_next_line/get_next_line_utils.c

SRCS_B	=	./srcs_bonus/so_long.c\
			./srcs_bonus/errors.c\
			./srcs_bonus/check_map.c\
			./srcs_bonus/check_file.c\
			./srcs_bonus/check_wall.c\
			./srcs_bonus/load_images.c\
			./srcs_bonus/find_map_size.c\
			./srcs_bonus/read_map.c\
			./srcs_bonus/hooks.c\
			./srcs_bonus/steps.c\
			./srcs_bonus/draw_picture.c\
			./srcs_bonus/init.c\
			./srcs_bonus/close_window.c\
			./srcs_bonus/get_next_line_bonus/get_next_line.c\
			./srcs_bonus/get_next_line_bonus/get_next_line_utils.c

# Object files
OBJS_DIR 	:=	./objs
OBJS_B_DIR 	:=	./objs_bonus

OBJS		:=  ${addprefix ${OBJS_DIR}/, ${notdir ${SRCS:.c=.o}}}


OBJS_B 		:=  ${addprefix ${OBJS_B_DIR}/, ${notdir ${SRCS_B:.c=.o}}}

# Dependencies
DEP			=  ${OBJ:%.o=%.d}
DEP_B		=  ${OBJ_B:%.o=%.d}

# Targets
all bonus	:	 
				${MAKE} ${NAME}

bonus		: export BONUS_MODE := 1

${LIBFT_LIB}: FORCE
			@make -C ./${LIBFT_DIR}
${MLX_LIB}	:
			@make -C ./${MLX_DIR}

FORCE:;

${NAME}	:	${if ${BONUS_MODE}, ${OBJS_B}, ${OBJS}} ${LIBFT_LIB} ${MLX_LIB}
			${CC} ${CFLAGS} ${MLXFLAGS} ${if ${BONUS_MODE}, ${OBJS_B}, ${OBJS}} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}
			@echo "\033[1;32mSo_Long App is ready\033[0m"	

${OBJS_DIR}: 
			@mkdir -p ${OBJS_DIR}
${OBJS_B_DIR}:
			@mkdir -p ${OBJS_B_DIR}

# Include all .d files
-include ${DEP}
${OBJS_DIR}/%.o : %.c ${INC} ${GNL_INC} Makefile | ${OBJS_DIR}  
			${CC} ${CFLAGS} $(INC_DIR:%=-I %) -c $< -o $@
			@echo "The object BONUS file is ready in OBJS_DIR"

${OBJS_B_DIR}/%.o : %.c ${INC_B} ${GNL_B_INC} Makefile | ${OBJS_B_DIR} 
			${CC} ${CFLAGS} $(INC_B_DIR:%=-I %) -c $< -o $@
			@echo "The object BONUS file is ready in OBJS_B_DIR"

 
 
#Utils
clean:
			${MAKE} -C ${LIBFT_DIR} clean
			${MAKE} -C ${MLX_DIR} clean
			@rm -rf ${OBJS_DIR} ${OBJS_B_DIR}
			@echo "So_Long is Cleaned"	

fclean: clean
			@${RM} ${NAME} ${LIBFT_LIB} ${MLX_LIB}
			@echo "So_Long is Full Cleaned"	

re			:	fclean all

re_bonus	:	fclean bonus

# Leak Search
seleak	:
			@valgrind --leak-check=full --track-origins=yes ./so_long maps/map_3x9.ber

seleakf	:
			@valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=med --track-origins=yes ./so_long maps/map_3x9.ber

norma	:
			norminette ./libft ./srcs ./includes ./srcs_bonus ./includes_bonus


.PHONY	: 	all libft clean fclean re norma seleak bonus