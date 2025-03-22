# Binary Files!
NAME_1 = server
NAME_2 = client
NAME_3 = server_bonus
NAME_4 = client_bonus

# Compiler stuff
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# MANDATORY / BONUS
MANDATORY = mandatory/
BONUS = bonus/

# Header File!
HEADER_FILE = $(MANDATORY)minitalk.h
HEADER_FILE_BONUS = $(BONUS)minitalk_bonus.h

# Sauce Files
SRC = $(MANDATORY)src/
INCLUDES = includes/

# ----------------- libraries ------------------ #
# ft_printf
FT_PRINTF_PATH = $(INCLUDES)ft_printf/
FT_PRINTF_SRC = $(FT_PRINTF_PATH)$(FT_PRINTF)
FT_PRINTF = libftprintf.a

# libft
LIBFT_PATH = $(INCLUDES)libft/
LIBFT_SRC = $(LIBFT_PATH)$(LIBFT)
LIBFT = libft.a

# ---------------------------------------------- #

# ------------------ MANDATORY ----------------- #
# Directories for Server & Client!
CLIENT_SRC = $(SRC)client/
SERVER_SRC = $(SRC)server/



# Source files for Server & Client!
SRC_FILES = $(addprefix $(SRC), pingPong.c utils.c)
FILES_SERVER = $(SERVER_SRC)/server.c
FILES_CLIENT = $(CLIENT_SRC)/client.c

# Objects files for Server & Client!
OBJ_SRC = $(SRC_FILES:.c=.o)
OBJ_SERVER = $(FILES_SERVER:.c=.o)
OBJ_CLIENT = $(FILES_CLIENT:.c=.o)

# ------------------ FOR BONUS ----------------- #

# Sauce Files
SRC_BONUS = $(BONUS)src/
INCLUDES_BONUS = $(BONUS)includes/

# Directories for Server & Client!
CLIENT_SRC_BONUS = $(SRC_BONUS)client/
SERVER_SRC_BONUS = $(SRC_BONUS)server/

# Source files for Server & Client!
SRC_FILES_BONUS = $(addprefix $(SRC_BONUS), pingPong_bonus.c utils_bonus.c)
FILES_SERVER_BONUS = $(SERVER_SRC_BONUS)/server_bonus.c
FILES_CLIENT_BONUS = $(CLIENT_SRC_BONUS)/client_bonus.c

# Objects files for Server & Client!
OBJ_SRC_BONUS = $(SRC_FILES_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(FILES_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(FILES_CLIENT_BONUS:.c=.o)

# -------------------------------------------- #

%.o: %.c $(HEADER_FILE) $(HEADER_FILE_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling “$(notdir $<)” ────୨ৎ──── “$(notdir $@)” ✅"

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_SRC) $(OBJ_SERVER) $(FT_PRINTF_SRC) $(LIBFT_SRC)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "🗎 Your “$@” ready to use!"

$(NAME_2): $(OBJ_SRC) $(OBJ_CLIENT) $(FT_PRINTF_SRC) $(LIBFT_SRC)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "🗎 Your “$@” ready to use!"

# -------------- BONUS COMPILATION -------------- #
bonus: $(NAME_3) $(NAME_4)

$(NAME_3): $(OBJ_SRC_BONUS) $(OBJ_SERVER_BONUS) $(FT_PRINTF_SRC) $(LIBFT_SRC)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "🗎 Your “$@” ready to use!"


$(NAME_4): $(OBJ_SRC_BONUS) $(OBJ_CLIENT_BONUS) $(FT_PRINTF_SRC) $(LIBFT_SRC)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "🗎 Your “$@” ready to use!"

# ------------------------------------ #
$(FT_PRINTF_SRC):
	@$(MAKE) --no-print-directory -C $(FT_PRINTF_PATH)
	@echo "“$(notdir $@)” library 📚 is ready!"

$(LIBFT_SRC):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@echo "“$(notdir $@)” library 📚 is ready!"

clean:
	@rm -f $(OBJ_SRC) $(OBJ_SERVER) $(OBJ_CLIENT)
	@rm -f $(OBJ_SRC_BONUS) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	@$(MAKE) clean --no-print-directory -C $(FT_PRINTF_PATH)
	@$(MAKE) clean --no-print-directory -C $(LIBFT_PATH)
	@echo "🧼 All object files has been deleted! 🧼"

fclean: clean
	@rm -f $(NAME_1) $(NAME_2)
	@rm -f $(NAME_3) $(NAME_4)
	@$(MAKE) fclean --no-print-directory -C $(FT_PRINTF_PATH)
	@$(MAKE) fclean --no-print-directory -C $(LIBFT_PATH)
	@echo "✨ All binary files has been deleted! ✨"

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SRC) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(OBJ_SRC_BONUS)
