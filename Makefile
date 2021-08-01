NAME=libasm.a

TESTE=test

OBJS=ft_read.o ft_strcpy.o ft_strlen.o ft_strcmp.o ft_strdup.o ft_write.o


# Compilation Flags
ASM			=	nasm
ASM_FLAGS	=	-f elf64

CC			=	clang
CC_FLAGS	=	-Wall -Wextra -Werror
LD_FLAGS	=	-L. -lasm

# Linking Flags
AR			=	ar
AR_FLAGS	=	rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) $@ $^

%.o: %.s
	$(ASM) $< $(ASM_FLAGS)

main.o: main.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(TESTE): main.o $(NAME)
	$(CC) $< $(LD_FLAGS) -o $@
	./$@

clean:
	rm -rf $(OBJS) main.o

fclean: clean
	rm -rf $(NAME) $(TESTE)

re: fclean all

.PHONY: test