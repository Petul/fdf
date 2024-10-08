# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 13:34:34 by pleander          #+#    #+#              #
#    Updated: 2024/08/29 16:13:12 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CC := cc
CFLAGS := -Wall -Wextra -Werror -O2
CFILES :=	fdf.c \
			thickness.c \
			translation.c \
			clip_line.c \
			clip_line2.c \
			color.c \
			draw_line.c \
			draw_map.c \
			draw_menu.c \
			error.c \
			handle_keypress.c \
			handle_keypress2.c \
			handle_keypress3.c \
			handlers.c \
			main.c \
			map.c \
			matrix.c \
			menu.c \
			parse_token.c \
			projection.c \
			read_file.c \
			read_map.c \
			text.c \
			utils.c

LIBFT := libft/libft.a
LIBMLX42 := mlx42/build/libmlx42.a

OBJECTS := $(CFILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(LIBMLX42) $(LIBFT) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) $(LIBMLX42) -lm -lglfw -o $(NAME)


$(LIBFT):
	make -C libft

$(LIBMLX42):
	cmake mlx42 -B mlx42/build
	make -C mlx42/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: bonus
bonus: $(NAME)
	
.PHONY: clean
clean:
	rm -f $(OBJECTS)
	rm -rf mlx42/build
	make clean -C libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

.PHONY: re
re: fclean all
