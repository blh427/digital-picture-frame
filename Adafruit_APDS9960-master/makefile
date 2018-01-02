# all is the default target.
.DEFAULT_GOAL := color_sensor
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

gesture_sensor: $(OBJECTS)
	$(CC) gesture_sensor.o Adafruit_APDS9960.o  -g -o gesture_sensor -lwiringPi

color_sensor: $(OBJECTS)
	$(CC) color_sensor.o Adafruit_APDS9960.o -g -o color_sensor -lwiringPi

proximity_sensor: $(OBJECTS)
	$(CC) proximity_sensor.o Adafruit_APDS9960.o -g -o proximity_sensor -lwiringPi

 
# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

all: gesture_sensor color_sensor proximity_sensor


