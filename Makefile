CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc
LDFLAGS = -pthread

SRC = src
INC = inc
BUILD = build

TARGET = c-hot-reloader

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)


