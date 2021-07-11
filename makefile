export EXECUTABLE := dec
#default: $(EXECUTABLE)
export SHELL := /bin/bash
export SOURCE_FILES := $(wildcard *.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export DEP_FILES := $(patsubst %.cpp, %.dep, $(SOURCE_FILES))
export Temp :=$(DEP_FILES) $(OBJ_FILES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJ_FILES)
	@g++ $^ -o $@

%.o :
	@g++ -c $< -o $@

%.dep : %.cpp
	@g++ -MM $< -o $@


.PHONY: clean
clean:
	@echo "All cleaned"
	@rm -r $(Temp) > /dev/null 2> /dev/null

.PHONY: test
test:
	@./$(EXECUTABLE)

.PHONY: debug
debug:
	@$(MAKE) 
	@gdb ./$(EXECUTABLE)

.PHONY: release
release:
	@$(MAKE) 
.PHONY: profile
profile: 
	@echo "profile proces"
	@$(MAKE) 
	@./$(EXECUTABLE)
	@gprof ./$(EXECUTABLE)
	

-include $(DEP_FILES)
