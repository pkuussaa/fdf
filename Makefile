# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 14:02:48 by pkuussaa          #+#    #+#              #
#    Updated: 2020/02/05 17:10:54 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = fdf

SRC = srcs/draw.c srcs/colors.c srcs/map_coordinates.c srcs/initialize_list.c srcs/controls.c srcs/change_type.c srcs/fdf.c srcs/move_map.c srcs/get_nbr_count.c Libft/libft.a get_next_line/get_next_line.c

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INCLUDE = -I ./includes/fdf.h

.PHONY: all clean fclean re

all: $(FILE)

$(FILE):
	@echo "Compiling Libft."
	@cd Libft && make re
	@echo "Compiling fdf..."
	@gcc $(FLAGS) $(INCLUDE) -o $(FILE) $(SRC)
	@echo "DONE."

clean:
	@echo "Cleaning libraries."
	@cd Libft && make clean

fclean: clean
	@echo "Clearing executables..."
	@rm -f $(FILE)
	@cd Libft && make fclean

re: fclean all
