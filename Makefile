default: build

build: main.c
	gcc `pkg-config --cflags gtk+-3.0` -o calculator main.c basics.c logs_exp.c inverse_trig.c trig.c `pkg-config --libs gtk+-3.0`
run: build
	./calculator
	
clean:
	rm -f calculator
