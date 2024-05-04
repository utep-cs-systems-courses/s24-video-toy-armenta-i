# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:wakedemo.elf

#additional rules for files
wakedemo.elf: ${COMMON_OBJECTS} buzzer.o switches.o led.o p1_interrupt_handler.o p2_interrupt_handler.o stateMachine.o main.o happyFace.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

wakedemo-s.elf: ${COMMON_OBJECTS} buzzer.o switches.o led.o p1_interrupt_handler.o p2_interrupt_handler.o stateMachine.o main.o happyFace.o wdt_handler.o clearMain_s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: wakedemo.elf
	msp430loader.sh $^

load-s: wakedemo-s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~
