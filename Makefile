# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 01:28:19 by aasselma          #+#    #+#              #
#    Updated: 2023/02/26 16:10:49 by aasselma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME = client
S_NAME = server

cc = cc

CFLAGS = -Wall -Wextra -Werror

C_SRC = client.c utils.c

S_SRC = server.c utils.c

C_SRC_B = client_bonus.c utils_bonus.c

S_SRC_B = server_bonus.c utils_bonus.c

all: client server

client: $(C_SRC)
	$(CC) $(CFLAGS) $(C_SRC) -o $(C_NAME)

server: $(S_SRC)
	$(CC) $(CFLAGS) $(S_SRC) -o $(S_NAME)

client_bonus: $(C_SRC_B)
	$(CC) $(CFLAGS) $(C_SRC_B) -o $(C_NAME)

server_bonus: $(S_SRC_B)
	$(CC) $(CFLAGS) $(S_SRC_B) -o $(S_NAME)

clean : $(S_SRC) $(C_SRC)
	rm -fr $(S_NAME) $(C_NAME)

fclean : clean
	rm -rf client server

re : fclean all

bonus: server_bonus client_bonus
	