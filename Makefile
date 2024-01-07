CC = cc
FLAGS = -Wall -Wextra -Werror
SRV = server
CLI = client
SERVER_SRC = server.c
CLIENT_SRC = client.c
FTPF_SRC = ft_printf/ft_printf.c ft_printf/ft_utils.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putptr.c ft_printf/ft_puthex.c ft_printf/ft_puthexup.c ft_printf/ft_putuns.c ft_printf/ft_atoi.c
FTPF_OBJ = $(FTPF_SRC:.c=.o)
FTPF_NAME = libftprintf.a
LIBS = -L. -lftprintf

all: $(FTPF_NAME) $(SRV) $(CLI)

$(FTPF_NAME): $(FTPF_OBJ)
	@ar rc $(FTPF_NAME) $(FTPF_OBJ) 

$(CLI): $(FTPF_NAME)
	@$(CC) $(FLAGS) $(CLIENT_SRC) $(LIBS) -o $(CLI)

$(SRV): $(FTPF_NAME)
	@$(CC) $(FLAGS) $(SERVER_SRC) $(LIBS) -o $(SRV)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(FTPF_OBJ) $(SRV) $(CLI)

fclean: clean
	@rm -f $(FTPF_NAME)

re: fclean all

.PHONY: clean fclean re all