# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborione <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 10:18:41 by dborione          #+#    #+#              #
#    Updated: 2022/11/03 10:18:57 by dborione         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#	Sources
FILES = main	\
		parsing	\
		parsing_utils	\
		moves_utils	\
		moves	\
		ft_split 	\
		ft_atoi \
		sort_small 	\
		sort_big	\
		sort_utils 	\


SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))

#	Objects
OBJS = $(SRCS:.c=.o)

#	Others
NAME = push_swap
RM = rm -f

#	Colours
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
DEFAULT = \033[0m

#	Targets
all :	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[Done!]$(DEFAULT)"

#	Cleaning
clean:
	@echo "$(YELLOW)[Cleaning...]$(DEFAULT)"
	$(RM) $(OBJS)
	@echo "$(RED)[Objects Cleaned!]$(DEAFULT)"


fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)[Executable File Cleaned!]$(DEFAULT)"

re: fclean all

.PHONY:	clean fclean re all
