NAME        	=   philo

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \

OBJ_DIR			=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# library -----------------------------------------------------------

SRC			= 	ft_atoi.c \
				print_error.c \
				eating.c \
				sleeping.c \
				thinking.c \
				check_args_error.c \
				is_number.c \
				struct_init.c \
				free_struct.c \
				ft_strlen.c \
				ft_strncmp.c \
				get_current_time.c \
				write_status.c \
				philo.c \
				check_end.c \
				ft_usleep.c \

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror -pthread -g3 -fsanitize=address

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

# main part ---------------------------------------------------------

all:
	@echo "\n___$(NAME) Setting___\n"
	@make  $(NAME)

bonus: fclean
	@echo "\n___$(NAME) Setting___\n"
	@make $(NAME_BONUS)

show:
	@echo "SRC :\n$(SRC)"
	@echo "OBJ :\n$(OBJ)"
	@echo "CFLAGS :\n$(CFLAGS)"
	@echo "IFLAGS :\n$(IFLAGS)"
	@echo "\n-----\n"
	@echo "Compiling : \n$(CC) $(CFLAGS) $(OBJ) -o $(NAME)"

$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $@ ... \c"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "DONE\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $@ ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "DONE"

re:	fclean all

clean:
	@echo "Deleting Objects Directory $(OBJ_DIR) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "DONE\n-----"

fclean:	clean
	@echo "Deleting Binary File $(NAME) ... \c"
	@rm -f $(NAME)
	@echo "DONE\n-----"

.PHONY: all bonus show re clean flcean