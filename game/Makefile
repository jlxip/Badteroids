RESULT := badteroids

SRCPATH := src
OBJPATH := obj

CXX := g++
INCLUDES := -Isrc

CXXFLAGS_BASE := -std=c++11 -O2
CXXFLAGS_WARN := -Wall -Wextra -Werror

ifdef DEBUG
CXXFLAGS_BASE += -g
endif

CXXFLAGS := $(INCLUDES) $(CXXFLAGS_BASE) $(CXXFLAGS_WARN)

LINKER := $(CXX)
EXTRA_LINKER := -lglfw -lGL
LINKER_FLAGS := $(CXXFLAGS) $(EXTRA_LINKER)

OBJS := $(shell cd src && find . -type f -iname '*.cpp' | sed 's/\.\///g' | sed 's/\.cpp/\.o/g' | xargs -I {} echo "$(OBJPATH)/"{})

.PHONY: all run clean
all: $(RESULT)

run: all
	./$(RESULT)

$(RESULT): $(OBJS)
	@echo "Linking..."
	@$(LINKER) $(LINKER_FLAGS) $(OBJS) -o $@
	@if [[ ! -v DEBUG ]]; then \
		echo "Stripping..."; \
		strip $(RESULT); \
	fi

-include $(OBJS:.o=.o.d)

$(OBJS): | $(OBJPATH)

$(OBJS): $(OBJPATH)/%.o: $(SRCPATH)/%.cpp
	@echo "===> $<"
	@$(CXX) -c -o $@ $< $(CXXFLAGS)
	@$(CXX) -MM $< -o $@.d.tmp $(CXXFLAGS)
	@sed -e 's|.*:|$@:|' < $@.d.tmp > $@.d
	@rm -f $@.d.tmp

$(OBJPATH):
	@echo "Creating $(OBJPATH)/ hierarchy..."
	@cd src && find . -type d -exec mkdir -p ../$(OBJPATH)/{} \;

clean:
	rm -rf $(RESULT) $(OBJPATH)/
