NAME = fractol

SRCS_DIR = srcs/
USER = $(shell whoami)
OS = $(shell uname)

SRCS =	srcs/init.c	\
		srcs/main.c	\

COMPILER = cc
OBJS_DIR = objs/

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
ifeq ($(OS),Linux)
	MLX_FLAGS = MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
else ifeq ($(OS),Darwin)
	MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
	$(error OS is not Linux nor Darwin.)
endif

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@cd main-libs && make --silent
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) ./main-libs/libs.a ./MLX42/build/libmlx42.a $(MLX_FLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

info-m:
	@echo "instructions:"
	@echo "currently offering Mandelbrot and Julia"
	@echo "Mandelbrot default:"
	@echo "use with: ./a.out Mandelbrot || or ./a.out -m"
	@echo ""

clean:
	@cd main-libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -rf MLX42
	@rm -f $(NAME)

mlxclean:
	@rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re