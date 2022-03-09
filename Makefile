# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 13:51:00 by mac               #+#    #+#              #
#    Updated: 2022/03/08 17:57:00 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	*.c

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address

NAME			= philo
				
all:			$(NAME)

$(NAME):		$(SRCS)
				gcc  $(FLAGS) $(SRCS) -o $(NAME)
				
clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)