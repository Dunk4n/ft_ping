# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niduches <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 14:57:17 by niduches          #+#    #+#              #
#    Updated: 2022/06/23 10:19:52 by niduches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

SRC_DIRECTORY	=	./src/
INC_DIRECTORY	=	./include/
LIB_DIRECTORY	=	./libft/

BUILD_DIRECTORY	=	build

SRC_FILE_NAME	=	main.c			\
					packet.c		\
					signal.c		\
					ping_data.c		\
					argument.c		\

SRC			=	$(addprefix $(SRC_DIRECTORY),$(SRC_FILE_NAME))

NAME		=	ft_ping

OBJ			=	$(SRC:%.c=$(BUILD_DIRECTORY)/%.o)

CFLAGS		=	-I$(INC_DIRECTORY) -Wall -Wextra -Werror

CDEBUG_FLAGS	=	-I$(INC_DIRECTORY) -Wall -Wextra -g -no-pie
CDEBUG_FLAGS_FSANITIZE	=	-g -fsanitize=address -fsanitize=leak -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=undefined

LDFLAGS		=	-L$(LIB_DIRECTORY) -lft -lm

all:	$(NAME)

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIRECTORY)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_DIRECTORY) clean --no-print-directory
	@echo "  RM       $(BUILD_DIRECTORY)"
	@rm -rf $(BUILD_DIRECTORY)

fclean: clean
	@$(MAKE) -C $(LIB_DIRECTORY) fclean --no-print-directory
	@echo "  RM       $(NAME)"
	@rm -f $(NAME)

$(NAME): options $(OBJ)
	@$(MAKE) -C $(LIB_DIRECTORY) --no-print-directory
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

re:	fclean	all

debug:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) "CFLAGS=$(CDEBUG_FLAGS)" --no-print-directory

.PHONY: all options clean fclean re debug
