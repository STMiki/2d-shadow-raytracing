##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Simple description
##

DIR			=	src

SRCDIRS		=	$(shell find $(DIR) -name '*.cpp' -exec dirname {} \; | uniq)

CC			=	g++

OBJDIR		=	obj

CFLAGS		+=	-Wall -Wextra -Werror -g
CFLAGS		+=	-Iheader

LDFLAGS		+=	-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

FILE 	  	=   $(shell find $(DIR) -name '*.cpp')

OBJ			=	$(patsubst %.cpp,$(OBJDIR)/%.o,$(FILE))

APPNAME		=	raytracing_test

TEST_TERM	=	$(shell [ -t 1 ] && echo 1 || echo 0)

COLORGOOD	=	$(if $(TEST_TERM),\033[1;32m,)

COLORINFO	=	$(if $(TEST_TERM),\033[0;36m,)

COLORWARN	=	$(if $(TEST_TERM),\033[1;33m,)

COLORERROR	=	$(if $(TEST_TERM),\033[0;31m,)

COLORRESET	=	$(if $(TEST_TERM),\033[0m,)

all: buildrepo compiling build
	@echo "$(COLORINFO)Done !$(COLORRESET)"

$(APPNAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o ./$@

$(OBJDIR)/%.o: %.cpp
	@echo -n "    $(COLORWARN)[    ]$(COLORRESET) - $(COLORGOOD)`echo $< | rev | cut -d/ -f1 | rev`$(COLORRESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\r    $(COLORGOOD)[ OK ]$(COLORRESET) - $(COLORGOOD)`echo $< | rev | cut -d/ -f1 | rev` from$(COLORRESET)"

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(APPNAME) | source-highlight -s asm -f esc256 | less -eRiMX

clean:
	@echo "$(COLORWARN)Removing object file...$(COLORRESET)"
	@rm -f $(OBJ)
	@rm -frd $(OBJDIR)

fclean:	clean
	@echo "$(COLORWARN)Removing executable file...$(COLORRESET)"
	@rm -f ./$(APPNAME)

re:	fclean	all

compiling:
	@echo "$(COLORINFO)Compiling CLI...$(COLORRESET)"

build: $(APPNAME)

norm:
	@norminette -nutAi 4 src header

buildrepo:
	@$(call make-repo)

define make-repo
	mkdir -p $(OBJDIR);				\
	for dir in $(SRCDIRS);			\
	do								\
		mkdir -p $(OBJDIR)/$$dir;	\
	done
endef

.PHONY: disassemble clean fclean re compiling build buildrepo norm all
