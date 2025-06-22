# Makefile by RushiTori - June 20th 2025
# ====== Everything Makefile internal related ======

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
MAKEFLAGS+=--no-print-directory
RM+=-r
DEBUG:=0
RELEASE:=0

# ========= Everything project related =========

NAME:=mandelbrot_viewer

ifdef OS
	NAME:=$(NAME).exe
endif

CC:=nasm
LD:=gcc
SRC_EXT:=asm
HDS_EXT:=inc
OBJ_EXT:=obj
DEP_EXT:=dep

# ========== Everything files related ==========

INST_DIR:=/usr/local/bin

HDS_DIR:=include
SRC_DIR:=src
OBJ_DIR:=objs

HDS_FILES:=$(call rwildcard,$(HDS_DIR),*.$(HDS_EXT))
SRC_FILES:=$(call rwildcard,$(SRC_DIR),*.$(SRC_EXT))
OBJ_FILES:=$(SRC_FILES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.$(OBJ_EXT))
DEP_FILES:=$(SRC_FILES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.$(DEP_EXT))

# ========== Everything flags related ==========

HDS_PATHS:=$(sort $(dir $(HDS_FILES)))
LIB_PATHS:=

ifdef OS
	HDS_PATHS+=C:/CustomLibs/include
	LIB_PATHS+=C:/CustomLibs/lib
endif

HDS_PATHS:=$(addprefix -I,$(HDS_PATHS))
LIB_PATHS:=$(addprefix -L,$(LIB_PATHS))

LIB_FLAGS:=-lraylib
ifdef OS
	LIB_FLAGS+=-lopengl32 -lgdi32 -lwinmm
else ifeq ($(shell uname), Linux)
	LIB_FLAGS+=-lGL -lm -lpthread -ldl -lrt -lX11
endif

OBJ_FMT:=-felf64
ifeq ($(DEBUG), 1)
	OBJ_FMT+=-gdwarf
else
	ifeq ($(RELEASE), 1)
		OBJ_FMT+=-Ox
	endif
endif

CCFLAGS:=$(OBJ_FMT) $(HDS_PATHS)

EXEFLAGS:=-no-pie -nostartfiles -z noexecstack
LDFLAGS:=$(EXEFLAGS) $(LIB_PATHS) $(LIB_FLAGS)

# =========== Every usable functions ===========

$(NAME): $(OBJ_FILES)
	@echo Linking $@
	@$(LD) $^ -o $@ $(LDFLAGS)

build: $(NAME)

run: $(NAME)
	@./$(NAME)

debug:
	@$(MAKE) DEBUG=1

release:
	@$(MAKE) RELEASE=1

-include $(DEP_FILES)
$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@echo Compiling $< into $@
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAGS) $< -o $@ -MD $(@:.obj=.dep)

install: release
ifeq ($(shell uname), Linux)
	@cp -u -v $(NAME) $(INST_DIR)/$(NAME)
else
	@echo Cannot auto-install binaries on your system, sorry !
endif

uninstall:
ifeq ($(shell uname), Linux)
	@rm -v $(INST_DIR)/$(NAME)
else
	@echo Cannot auto-uninstall binaries on your system, sorry !
endif

clean:
	@echo Deleting $(OBJ_DIR) folder
	@$(RM) $(OBJ_DIR)

wipe: clean
	@echo Deleting $(NAME)
	@$(RM) $(NAME)

rebuild: wipe build

redebug: wipe debug 

rerelease: wipe release

rerun: build run

.PHONY: build rebuild
.PHONY: debug redebug
.PHONY: release rerelease
.PHONY: run rerun
.PHONY: install uninstall
.PHONY: clean wipe
