SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = cc
PRINTF = ft_printf

all:
	@make -s -C $(PRINTF) 
	@$(CC) server.c $(CFLAGS) -I$(PRINTF) -L$(PRINTF) -lftprintf  -o $(SERVER)
	@$(CC) client.c $(CFLAGS) -I$(PRINTF) -L$(PRINTF) -lftprintf  -o $(CLIENT)

clean:
	@make clean -s -C $(PRINTF) 

fclean: clean
	@make fclean -s -C $(PRINTF) 
	@rm -f $(SERVER) $(CLIENT) 

re: fclean all

.PHONY: all clean fclean re