CC = gcc
CFLAGS = -Wall -Wextra -Iinc
LDFLAGS = -pthread

SRC = src
INC = inc
BUILD = build

TARGET = c-hot-reloader

SRCS = $(shell find $(SRC) -name '*.c')
OBJS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)
