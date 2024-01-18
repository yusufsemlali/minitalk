CC = cc
FLAGS = -Wall -Wextra -Werror
SRV = server
CLI = client
SERVER_SRC = server.c
CLIENT_SRC = client.c

all: $(SRV) $(CLI)

$(SRV):
	@$(CC) $(FLAGS) $(SERVER_SRC) -o $(SRV)

$(CLI):
	@$(CC) $(FLAGS) $(CLIENT_SRC) -o $(CLI)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(SRV) $(CLI)

re: fclean all

.PHONY: all clean fclean re