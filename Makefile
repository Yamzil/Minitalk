# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 23:03:02 by yamzil            #+#    #+#              #
#    Updated: 2022/01/17 20:00:04 by yamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

server = server.c

serve = server_bonus.c

clent = client_bonus.c

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

bonus : $(serve) $(clent)
	@$(CC) $(CFLAGS) $(SRC) $(serve) -o server -I $(INC)
	@$(CC) $(CFLAGS) $(SRC) $(clent) -o client -I $(INC)
	@echo Done Well Bonus Part
	
fclean : clean
	@echo Done !
	@rm -f $(NAME) $(bonus) server client

re : fclean all
