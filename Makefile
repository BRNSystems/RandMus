.DEFAULT_GOAL := all

clean:
	rm -f randMus

compile: clean
	gcc -o randMus -ggdb randMus.c

run: compile
	./randMus | aplay

record: compile
	rm -f out.ogg
	./randMus|ffmpeg -f u16le -ar 8000 -ac 1 -i - out.ogg

all: compile run