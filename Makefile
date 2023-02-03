# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 02:22:09 by mbachar           #+#    #+#              #
#    Updated: 2023/02/03 16:32:53 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clean:
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME) 

re: fclean SERVER_NAME 

.PHONY: clean fclean re