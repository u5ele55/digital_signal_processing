CC = g++ -Wall
EXECUTABLE = run.exe

SOURCES = main.cpp   \
		  signal_generator\simple_signal_generator.cpp \
		  signal_generator\normal_noise_signal_generator.cpp \
		  filtering\signal_filter.cpp \
		  filtering\windowing_signal_filter.cpp \
		  autocorrelation\standart_autocorrelation_function.cpp \
		  utilities\math_utilities.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(SFML_FLAGS)

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	del $(OBJECTS)