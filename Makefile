# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 23:03:02 by yamzil            #+#    #+#              #
#    Updated: 2022/01/08 18:48:54 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

server = server.c

client = client.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all :$(NAME) 

OBJ = $(SRC:.c=.o)

$(NAME) : $(server) $(client)
	ar rc $(NAME) $(server) $(client)
	$(CC) $(CFLAGS) $(server) -o server
	$(CC) $(CFLAGS) $(client) -o client
	@echo Everything is up ! 
	
clean :
	@rm -f $(OBJ)
	
fclean : clean
	@echo Done !
	@rm -f $(NAME) server client

re : fclean all