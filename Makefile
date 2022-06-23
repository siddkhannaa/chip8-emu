# build the main
main: time keyboard
	emojicodec main.🍇 -o ./build/main

# thicc but keyboard
keyboard: keyboardemo keyboards.o
	ar q ./packages/keyboard/libkeyboard.a ./packages/keyboard/keyboards.o
	ar q ./packages/keyboard/libkeyboard.a $(shell find ./packages/keyboard/tinfo -type f)
	ar q ./packages/keyboard/libkeyboard.a $(shell find ./packages/keyboard/ncurses -type f)


# /usr/lib/x86_64-linux-gnu/libncurses.a
# /usr/lib/x86_64-linux-gnu/libtinfo.a

keyboardemo:
	emojicodec -p keyboard ./packages/keyboard/main.🍇

keyboards.o:
	g++ -c ./packages/keyboard/keyboards.cc -o ./packages/keyboard/keyboards.o


time: timeemo times.o
	ar q ./packages/time/libtime.a ./packages/time/times.o

timeemo:
	emojicodec -p time ./packages/time/main.🍇

times.o:
	g++ -c ./packages/time/times.cc -o ./packages/time/times.o
	


# a fake target
.PHONY: clean

# run this command to clean up before clean build
clean:
	rm ./packages/time/*.o ./packages/time/libtime.a ./packages/time/🏛
	rm ./packages/keyboard/*.o ./packages/keyboard/libkeyboard.a ./packages/keyboard/🏛
	rm ./build/*
