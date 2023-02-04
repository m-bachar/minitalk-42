# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 02:22:09 by mbachar           #+#    #+#              #
#    Updated: 2023/02/04 18:11:02 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 			= server
CLIENT 			= client
SERVER_BONUS 	= server_bonus
CLIENT_BONUS 	= client_bonus
PRINTF 			= ./ft_printf/libftprintf.a
SRC_SERVER 		= ./mandatory/server.c
SRC_CLIENT 		= ./mandatory/client.c
SRC_SERVER_B	= ./bonus/server_bonus.c
SRC_CLIENT_B	= ./bonus/client_bonus.c
INCLUDE			= ./mandatory/minitalk.h
INCLUDE_BONUS	= ./bonus/minitalk_bonus.h
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror

all 			: $(SERVER) $(CLIENT)
bonus 			: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER)		: $(INCLUDE)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(SERVER) $(PRINTF)

$(CLIENT)		: $(INCLUDE)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(CLIENT) $(PRINTF)

$(SERVER_BONUS)	: $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) $(SRC_SERVER_B) -o $(SERVER_BONUS) $(PRINTF)

$(CLIENT_BONUS)	: $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) $(SRC_CLIENT_B) -o $(CLIENT_BONUS) $(PRINTF)

fclean			:
	rm -fr $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re				: fclean all

.PHONY			: re fclean