# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:17:31 by deman_wolf        #+#    #+#              #
#    Updated: 2023/01/10 20:26:44 by deman_wolf       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MD_S = tools/error.c\
		tools/hex_to_dec.c\
		tools/take_dm.c\
		src/parcing.c\
		src/main.c\

MD_O = $(MD_S:.c=.o)

FLAGS = -Wall -Wextra

INC = inc/fdf.h

RM = rm -rf

NAME = fifo

all: $(NAME)

$(NAME): $(MD_O)
	make -C libtool
	cc $(FLAGS) $^ libtool/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $@

%.o: %.c $(INC)
	cc $(FLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	make -C libtool clean
	$(RM) src/*.o tools/*.o *.o

fclean: clean
	make -C libtool fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean re
