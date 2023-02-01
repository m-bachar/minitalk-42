# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 02:22:09 by mbachar           #+#    #+#              #
#    Updated: 2023/02/01 11:56:47 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = ./ft_printf/libftprintf.a
SERVER_NAME = server
CLIENT_NAME = client
SERVER_SRC = server.c \
			 mandatory_utils.c
CLIENT_SRC = client.c \
			 mandatory_utils.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(SERVER_NAME) $(CLIENT_NAME)

SERVER_NAME: $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_NAME) $(PRINTF)

CLIENT_NAME: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME) $(PRINTF)

clean:
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME) 

re: fclean SERVER_NAME 

.PHONY: clean fclean re