CC=clang
CFLAGS=-Wall -Wextra

vector: vector.c
	$(CC) $(CFLAGS) -o vector vector.c

vector-sanitize-asan: vector_asan.c
	$(CC) -g -fsanitize=address -o vector-sanitize-asan vector_asan.c

vector-sanitize-leak: vector_leak.c
	$(CC) -g -fsanitize=leak -o vector-sanitize-leak vector_leak.c

vector-sanitize-undefined: vector_ubsan.c
	$(CC) -g -fsanitize=undefined -o vector-sanitize-undefined vector_ubsan.c

vector-sanitize-memory: vector_msan.c
	$(CC) -g -fsanitize=memory -o vector-sanitize-memory vector_msan.c

vector-sanitize: vector.c
	$(CC) -g -fsanitize=address,leak,undefined -o vector-sanitize vector.c

analyze:
	scan-build make

format:
	clang-format -i *.c