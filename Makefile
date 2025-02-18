CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/server.c src/client.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): src/server.o ft_printf/ft_printf.o ft_printf/ft_printf_utils.o
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): src/client.o ft_printf/ft_printf.o ft_printf/ft_printf_utils.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

