CC=g++
CFLAGS=-Wall
CREQS=-lsfml-system -lsfml-window -framework GLUT -framework OpenGL
SRCROOT=src
BUILDROOT=build
TARGET=$(BUILDROOT)/FlightGame

all: FlightGame

r:
	$(TARGET)

cr: FlightGame r
	

FlightGame:
	$(CC) $(CFLAGS) $(CREQS) $(SRCROOT)/*.cpp -o $(TARGET)
