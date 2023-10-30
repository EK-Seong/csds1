TARGET=KMEANS
OBJECTS=main.o data.o data_handler.o kmeans.o 

CXX=g++
CPPFLAGS := -std=c++11  
SLURM_FLAGS = --partition=class4 --nodes=1 --ntasks-per-node=1 --time=5 --cpus-per-task=1 --mem=1G



all: $(TARGET)



$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)

clean:
	rm -rf $(TARGET) $(OBJECTS)



test: $(TARGET)
	# ./$(TARGET)
	salloc $(SLURM_FLAGS) ./$(TARGET)