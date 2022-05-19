NAME = libftprintf.a

SRC = ft_printf.c \
ft_parse.c \
ft_character_conversion.c \
ft_decimal_conversion.c \
ft_hex_conversion.c \
ft_put_w_p.c \
ft_utils.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar

AR_FLAGS = rcs

ARCHIVE = $(AR) $(AR_FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $(OBJ)

$(OBJ):
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE)

.PHONY: all re fclean clean
