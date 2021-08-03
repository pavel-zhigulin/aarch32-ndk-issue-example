all:
	"$(CLANG)" --target=armv7a-linux-androideabi23 -c -fPIC -std=c99 -Wall -Wextra -Wno-unused-label -fPIC -fvisibility=hidden -O3 -Werror -g -DNDEBUG -mfpu=neon -mfloat-abi=hard ./test.c -o ./test.o