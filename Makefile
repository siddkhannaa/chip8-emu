# build the main
main: time
	emojicodec main.🍇 -o ./build/main

time: timeemo timecc
	ar q ./packages/time/libtime.a ./packages/time/times.o

timeemo:
	emojicodec -p time ./packages/time/main.🍇

timecc:
	g++ -c ./packages/time/times.cc -o ./packages/time/times.o
	

# a fake target
.PHONY: clean

# run this command to clean up before clean build
clean:
	rm ./packages/time/*.o ./packages/time/libtime.a ./packages/time/🏛
	rm ./build/*