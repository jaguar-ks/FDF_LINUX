# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:17:31 by deman_wolf        #+#    #+#              #
#    Updated: 2023/01/18 17:40:32 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MD_S = 	parcing.c\
	 	draw_line.c\
	 	draw_map.c\
		main.c\

T_S = checks.c\
		error.c\
		hex_to_dec.c\
		init_drawing_unit.c\
		init_point.c\
		matrix_len.c\
		next_point.c\
		take_dm.c\
		take_z_scale.c\

O_DIR = obj

T_DIR = tools

S_DIR = src

O_S = $(addprefix $(O_DIR)/,$(MD_S:.c=.o))

O_T = $(addprefix $(O_DIR)/,$(T_S:.c=.o))

S_F = $(addprefix $(S_DIR)/,$(MD_S))

T_F = $(addprefix $(T_DIR)/,$(T_S))

FLAGS = -Wall -Wextra -Werror

INC = inc/fdf.h

RM = rm -rf

NAME = fifo

all: $(O_DIR) $(NAME)

$(NAME): $(O_S) $(O_T)
	make -C libtool
	cc $(FLAGS) $^ libtool/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $@ #[LINUX]#
	#cc $(FLAGS) $^ libtool/libft.a -lmlx -framework OpenGL -framework AppKit -o $@

$(O_DIR)/%.o: $(S_DIR)/%.c $(INC) 
	@cc $(FLAGS) -I/usr/include -Imlx -O3 -c $< -o $@ #[LINUX]#
	@#cc $(FLAGS) -c $< -o $@

$(O_DIR)/%.o: $(T_DIR)/%.c $(INC) 
	@cc $(FLAGS) -I/usr/include -Imlx -O3 -c $< -o $@ #[LINUX]#
	@#cc $(FLAGS) -c $< -o $@

$(O_DIR):
	mkdir $@

clean:
	make -C libtool clean
	$(RM) $(O_DIR)

fclean: clean
	make -C libtool fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean re

.SILENT: $(NAME) clean fclean re all $(O_DIR)
