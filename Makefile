CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c
SRCS_PRINTF = ft_printf/ft_printf.c ft_printf/ft_printf_utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client
LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^
	
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_PRINTF)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
