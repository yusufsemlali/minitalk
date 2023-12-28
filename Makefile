CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = ./libftprintf.a ./libft.a
SERVER_NAME = server
CLIENT_NAME = client
SERVER_SRC = server.c
CLIENT_SRC = client.c

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBS) -o $(SERVER_NAME)

$(CLIENT_NAME):
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBS) -o $(CLIENT_NAME)

clean:
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
fclean: clean

re: clean all