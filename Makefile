# build the main
main:
	emojicodec main.🍇 -o ./build/main

# a fake target
.PHONY: clean

# run this command to clean up before clean build
clean:
	rm ./build/*