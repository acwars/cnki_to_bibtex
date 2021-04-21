CC			:= -gcc
CFLAGS		:= -g3 -Wall -pedantic
LDFLAGS 	:=
BUILD_DIR 	:= build
OBJ_DIR  	:= $(BUILD_DIR)/objects
BIN_DIR  	:= $(BUILD_DIR)/bin
PREFIX    	:= /usr/local
BIN_PREFIX 	:= $(PREFIX)/bin
TARGET   	:= krios
INCLUDE  	:= -Iinclude/
SRC      	:=                      \
   $(wildcard src/box/*.c) 			\
   $(wildcard src/iff/*.c) 			\
   $(wildcard src/path/*.c) 	 	\
   $(wildcard src/common/*.c) 	 	\
   $(wildcard src/*.c)         	 	\

OBJECTS  := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

all: build $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

install:
	@cp $(BIN_DIR)/$(TARGET) $(BIN_PREFIX)

uninstall:
	-@rm -f "$(DESTDIR)$(BINPREFIX)"/$(TARGET)

.PHONY: all build install uninstall clean debug release info

build:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CFLAGS += -DDEBUG -g
debug: all

release: CFLAGS += -O2
release: all

clean:
	-@rm -rf $(BUILD_DIR)

info:
	@echo "[*] Application dir: ${BIN_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
