
CFLAGS = -Isrc -Wall -Wextra

all: build/extname.o

build/%.o: src/%.c src/%.h
	@mkdir -p build
	$(CC) -c $< -o $@ $(CFLAGS)

test/%.test: test/%.c build/extname.o
	@$(CC) $^ -o $@ $(CFLAGS)
	@./$@

clean:
	rm -rf build
	rm -f test/*.test

test: test/test.test

.PHONY: test clean
