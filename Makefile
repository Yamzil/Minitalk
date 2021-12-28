# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 23:03:02 by yamzil            #+#    #+#              #
#    Updated: 2021/12/28 17:17:14 by yamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

INC = minitalk.h

server = server.c

client = client.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc

# SRC = 	client.c \
# 		server.c \

all :$(NAME) 

OBJ = $(SRC:.c=.o)

$(NAME) : $(server) $(client)
	ar rc $(NAME) $(server) $(client)
	$(CC) $(CFLAGS) $(server) -o server -I $(INC)
	$(CC) $(CFLAGS) $(client) -o client -I $(INC)
	
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME) server client

re : fclean all