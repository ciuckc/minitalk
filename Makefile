NAME_PRINTF = libftprintf.a

NAME_SRV = server

DIR_PRINTF = ft_printf_bonus

DIR_SRV_SRC = srv_src

SRV_SRC = $(DIR_SRV_SRC)/server.c

SRV_OBJ = $(SRV_SRC:.c=.o)

SRV_DIR = 

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME_PRINTF) $(NAME_SRV)

$(NAME_PRINTF):
	$(MAKE) -C $(DIR_PRINTF)

$(NAME_SRV): $(SRV_OBJ)
	

$(SRV_OBJ):
	$(CC) $(FLAGS) -c $(SRV_SRC)
