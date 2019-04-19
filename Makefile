CURR_PATH=$(shell pwd)
SERVER=$(CURR_PATH)/server
CLIENT=$(CURR_PATH)/client
DATA_POOL=$(CURR_PATH)/data_pool
LIB=$(CURR_PATH)/lib
COMM=$(CURR_PATH)/comm
WINDOW=$(CURR_PATH)/window

LD_FLAGS=-lpthread -ljsoncpp

INCLUDE=-I$(DATA_POOL) -I$(LIB)/include -I$(COMM) -I$(WINDOW)
LIB_PATH=-L$(LIB)/lib

cc=g++
ser_bin=chatSystem
cli_bin=chatClient

ser_obj=$(shell ls $(SERVER)/*.cpp $(DATA_POOL)/*.cpp $(COMM)/*.cpp| sed -e 's/\/.*\///' -e 's/\.cpp/\.o/')
cli_obj=$(shell ls $(CLIENT)/*.cpp $(COMM)/*.cpp $(WINDOW)/*.cpp| sed -e 's/\/.*\///' -e 's/\.cpp/\.o/')

.PHONY:all
all:$(ser_bin) $(cli_bin)

$(ser_bin):$(ser_obj)
	$(cc) -o $@ $^ $(LIB_PATH) $(LD_FLAGS)
$(cli_bin):$(cli_obj)
	$(cc) -o $@ $^ $(LIB_PATH) $(LD_FLAGS) -lncurses -static
%.o:$(SERVER)/%.cpp
	$(cc) -c $< $(INCLUDE)
%.o:$(CLIENT)/%.cpp
	$(cc) -c $< $(INCLUDE)
%.o:$(DATA_POOL)/%.cpp
	$(cc) -c $<
%.o:$(COMM)/%.cpp
	$(cc) -c $< $(INCLUDE)
%.o:$(WINDOW)/%.cpp
	$(cc) -c $< $(INCLUDE)


.PHONY:clean
clean:
	rm -rf *.o $(ser_bin) $(cli_bin)

.PHONY:debug
debug:
	@echo $(ser_obj)
	@echo $(cli_obj)















