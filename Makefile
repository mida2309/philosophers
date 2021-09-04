# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mida <mida@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:04:01 by mida              #+#    #+#              #
#    Updated: 2021/09/03 18:28:03 by mida             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc
CFLAG	= -Wextra -Wall -Werror
RM		= rm -rf
AR		= ar cr

PHILO_SRC 		= check_and_init.c main.c philo.c thread.c time_death.c utils.c
PHILO_SRC_DIR 	= ./src/
PHILO_OBJS 		= $(PHILO_SRC:.c=.o)

INC				= -I./inc/

all : $(NAME)

$(NAME) : $(PHILO_OBJS)
		$(CC) $(CFLAG) -o $(NAME) $(PHILO_OBJS) $(INC) -pthread

%.o: $(PHILO_SRC_DIR)%.c
	$(CC) $(CFLAG) -c $< -o $@ $(INC)

clean		:
				rm -rf $(PHILO_OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all
