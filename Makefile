
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c
CLIENT_SRC = client.c

LIBFTPRINTF_SRC = ft_printf.c ft_libft.c ft_number.c
LIBFTPRINTF_OBJ = $(LIBFTPRINTF_SRC:.c=.o)
LIBFTPRINTF = libftprintf.a

SERVER_TARGET = server
CLIENT_TARGET = client

.PHONY:	all clean fclean re

all: $(SERVER_TARGET)  $(CLIENT_TARGET)

$(SERVER_TARGET): $(SERVER_SRC) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -Ift_printf/headers -L. -lftprintf $< -o $@

$(CLIENT_TARGET): $(CLIENT_SRC) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -Ift_printf/headers -L. -lftprintf $< -o $@


$(LIBFTPRINTF): $(LIBFTPRINTF_OBJ)
	ar rcs $@ $^
	@echo ""
	@echo "El servido y el cliente están listos!"
	@echo ""

clean:
	@echo ""
	rm -f $(LIBFTPRINTF_OBJ)
	@echo "Se han limpiado correctamente los archivos .o"
	@echo ""

fclean: clean
	@echo ""
	rm -f $(LIBFTPRINTF) $(SERVER_TARGET) $(CLIENT_TARGET)
	@echo "El servidor y el cliente se han limpiado correctamente"
	@echo ""

re: fclean all
