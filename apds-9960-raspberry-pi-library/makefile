# all is the default target.
# .DEFAULT_GOAL := all
# Declaration of variables
CC = g++
CC_FLAGS = -Wall -g
 
# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARIES = -lwiringPi

# Targets

# Main target
# $(EXEC): $(OBJECTS)
# 	$(CC) $(OBJECTS) -o $(EXEC)

GestureTest: $(OBJECTS)
	$(CC) GestureTest.o APDS9960_RPi.o  -g -o GestureTest -lwiringPi

ColorSensor: $(OBJECTS)
	$(CC) ColorSensor.o APDS9960_RPi.o -g -o ColorSensor -lwiringPi

ProximitySensor: $(OBJECTS)
	$(CC) ProximitySensor.o APDS9960_RPi.o -g -o ProximitySensor -lwiringPi

 
# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

all: GestureTest ColorSensor ProximitySensor


