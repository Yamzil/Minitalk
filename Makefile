# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 23:03:02 by yamzil            #+#    #+#              #
#    Updated: 2022/01/16 20:04:27 by yamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

server = server.c

client = client.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = minitalk_utils.c

INC = minitalk.h

all :$(NAME) 

OBJ = $(SRC:.c=.o)

$(NAME) : $(server) $(client)
	@$(CC) $(CFLAGS) $(SRC) $(server) -o server -I $(INC)
	@$(CC) $(CFLAGS) $(client) -o client -I $(INC)
	@echo "ⓜⓘⓝⓘⓣⓐⓛⓚ"
	@echo Everything is up ! 
	
clean :
	@rm -f $(OBJ)
	
fclean : clean
	@echo Done !
	@rm -f $(NAME) server client

re : fclean all