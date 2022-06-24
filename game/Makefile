RESULT := badteroids
ZIPRESULT := release.zip

SRCPATH := src
OBJPATH := obj

CXX := g++
INCLUDES := -Isrc

ifeq ($(shell uname -s),Darwin)
	INCLUDES += -I/opt/homebrew/include
endif

CXXFLAGS_BASE := -std=c++11 -O2
CXXFLAGS_WARN := -Wall -Wextra -Werror
CXXFLAGS_OPTS := -fno-exceptions
ifeq ($(DEBUG),1)
	CXXFLAGS_OPTS += -g
endif

ifeq ($(shell uname -s),Darwin)
	CXXFLAGS_WARN := -Wno-deprecated-declarations
endif

CXXFLAGS := $(INCLUDES) $(CXXFLAGS_BASE) $(CXXFLAGS_WARN) $(CXXFLAGS_OPTS)

LINKER := $(CXX)
ifeq ($(shell uname -s),Darwin)
	LINKER += -L/opt/homebrew/lib
	EXTRA_LINKER += -framework OpenGL
else
	EXTRA_LINKER += -lGL -lGLU
endif
EXTRA_LINKER += -lglfw -lGLEW
ifeq ($(DEBUG),1)
	EXTRA_LINKER += -g
endif
LINKER_FLAGS := $(CXXFLAGS) $(EXTRA_LINKER)

STRIP := strip
ifeq ($(DEBUG),1)
	STRIP := ls
endif

OBJS := $(shell cd src && find . -type f -iname '*.cpp' | sed 's/\.\///g' | sed 's/\.cpp/\.o/g' | xargs -I {} echo "$(OBJPATH)/"{})

.PHONY: all run clean zip
all: $(RESULT)

run: all
	./$(RESULT)

zip: $(ZIPRESULT)
$(ZIPRESULT): $(RESULT)
	zip -r $@ $< assets/

$(RESULT): $(OBJS)
	@echo "Linking..."
	@$(LINKER) $(LINKER_FLAGS) $(OBJS) -o $@
	@$(STRIP) $@

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
