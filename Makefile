NAME = fractol

CFLAGS	= -Wall -Werror -Wextra
CFLAGS += -O3 -g3 -fsanitize=address
CC	= cc

SRCS    = sources/main.c 


OBJ 	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

run: re
	./$(NAME)
