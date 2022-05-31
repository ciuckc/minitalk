NAME_SRV = server

NAME_CLT = client

DIR_PRINTF = ft_printf_bonus

NAME_PRINTF = $(addprefix $(DIR_PRINTF)/, libftprintf.a)

DIR_LIBFT = libft

NAME_LIBFT = $(addprefix $(DIR_LIBFT)/, libft.a)

LIBS = $(NAME_PRINTF) $(NAME_LIBFT)

DIR_SRV_SRC = srv_src

DIR_CLT_SRC = clt_src

DIR_OBJ = obj

SRV_SRC = $(addprefix $(DIR_SRV_SRC)/, server.c)

CLT_SRC = $(addprefix $(DIR_CLT_SRC)/, client.c)

SRV_OBJ = $(subst $(DIR_SRV_SRC),$(DIR_OBJ),$(SRV_SRC:.c=.o))

CLT_OBJ = $(subst $(DIR_CLT_SRC),$(DIR_OBJ),$(CLT_SRC:.c=.o))

CC = gcc

INC = include

FLAGS = -Wall -Wextra -Werror

all: $(LIBS) $(NAME_SRV) $(NAME_CLT)

$(NAME_CLT): $(CLT_OBJ)
	$(CC) $(FLAGS) -I$(INC) $(LIBS) $(CLT_OBJ) -o $(NAME_CLT)

$(CLT_OBJ): $(CLT_SRC)
	$(CC) $(FLAGS) -I$(INC) -c $(CLT_SRC) -o $(CLT_OBJ)

$(NAME_SRV): $(SRV_OBJ)
	$(CC) $(FLAGS) -I$(INC) $(LIBS) $(SRV_OBJ) -o $(NAME_SRV)

$(SRV_OBJ): $(SRV_SRC)
	$(CC) $(FLAGS) -I$(INC) -c $(SRV_SRC) -o $(SRV_OBJ)

$(NAME_PRINTF):
	$(MAKE) -C $(DIR_PRINTF)

$(NAME_LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

clean:
	$(MAKE) clean -C $(DIR_PRINTF)
	$(MAKE) clean -C $(DIR_LIBFT)
	$(RM) $(SRV_OBJ) $(CLT_OBJ)

fclean: clean
	$(RM) -r $(LIBS)
	$(RM) -r $(NAME_SRV) $(NAME_CLT)

re: fclean
	$(MAKE)