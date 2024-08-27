# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:43:07 by pleander          #+#    #+#              #
#    Updated: 2024/08/26 09:45:10 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
CFILES := ft_atoi.c \
	ft_abs.c \
	ft_atoi_base.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_ft.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJECTS := $(CFILES:.c=.o)

PRINTF := ft_printf/libft_printf.o
PRINTF_CFILES := ft_printf/ft_printf.c \
	ft_printf/ft_utoa_base.c \
	ft_printf/conversions.c \
	ft_printf/conversions2.c \
	ft_printf/parse_conversion.c \
	ft_printf/precision.c \
	ft_printf/printers.c \
	ft_printf/utils.c \
	ft_printf/plus.c \
	ft_printf/poundsign.c \
	ft_printf/field_width.c \
	ft_printf/space.c \
	ft_printf/process_spec.c
PRINTF_OBJECTS := $(PRINTF_CFILES:.c=.o)

GNL := get_next_line/libft_get_next_line.o
GNL_CFILES:= get_next_line/get_next_line.c
GNL_OBJECTS := $(GNL_CFILES:.c=.o)

MEMLIST_CFILES := memlist/memlist_add.c \
	memlist/memlist.c \
	memlist/release.c \
	memlist/reserve.c

MEMLIST_OBJECTS := $(MEMLIST_CFILES:.c=.o)

INCLUDE := include

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS) $(PRINTF) $(GNL) $(MEMLIST_OBJECTS)
	ar rcs $(NAME) $?

$(PRINTF): $(PRINTF_OBJECTS)
	ld -r $(PRINTF_OBJECTS) -o $(PRINTF)

$(GNL): $(GNL_OBJECTS)
	ld -r $(GNL_OBJECTS) -o $(GNL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE) 

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(PRINTF_OBJECTS) $(PRINTF) $(GNL_OBJECTS) $(GNL)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
