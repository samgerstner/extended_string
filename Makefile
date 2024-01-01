ifeq ($(OSTYPE),cygwin)
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
else ifeq ($(OS),Windows_NT)
	CLEANUP=del /F /Q
	MKDIR=mkdir
	TARGET_EXTENSION=exe
else
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
endif

.PHONY: clean
.PHONY: test

UNITY_PATH = inc/unity/
SRC_PATH = src/
TEST_PATH = test/
BUILD_PATH = build/
DEPENDS_PATH = build/depends/
OBJ_PATH = build/objs/
RESULTS_PATH = build/results/
BUILD_PATHS = $(BUILD_PATH) $(DEPENDS_PATH) $(OBJ_PATH) $(RESULTS_PATH)
SRCT = $(wildcard $(TEST_PATH)*.c)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(UNITY_PATH) -I$(SRC_PATH) -DTEST

RESULTS = $(patsubst $(TEST_PATH)test_%.c,$(RESULTS_PATH)test_%.txt,$(SRCT) )
PASSED = `grep -s PASS $(RESULTS_PATH)*.txt`
FAIL = `grep -s FAIL $(RESULTS_PATH)*.txt`
IGNORE = `grep -s IGNORE $(RESULTS_PATH)*.txt`

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

$(RESULTS_PATH)%.txt: $(BUILD_PATH)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(BUILD_PATH)test_%.$(TARGET_EXTENSION): $(OBJ_PATH)test_%.o $(OBJ_PATH)%.o $(OBJ_PATH)unity.o
	$(LINK) -o $@ $^

$(OBJ_PATH)%.o:: $(TEST_PATH)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(OBJ_PATH)%.o:: $(SRC_PATH)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(OBJ_PATH)%.o:: $(UNITY_PATH)%.c $(UNITY_PATH)%.h
	$(COMPILE) $(CFLAGS) $< -o $@

$(DEPENDS_PATH)%.d:: $(TEST_PATH)%.c
	$(DEPEND) $@ $<

$(BUILD_PATH):
	$(MKDIR) $(BUILD_PATH)

$(DEPENDS_PATH):
	$(MKDIR) $(DEPENDS_PATH)

$(OBJ_PATH):
	$(MKDIR) $(OBJ_PATH)

$(RESULTS_PATH):
	$(MKDIR) $(RESULTS_PATH)

clean:
	$(CLEANUP) $(OBJ_PATH)*.o
	$(CLEANUP) $(BUILD_PATH)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(RESULTS_PATH)*.txt

.PRECIOUS: $(BUILD_PATH)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(DEPENDS_PATH)%.d
.PRECIOUS: $(OBJ_PATH)%.o
.PRECIOUS: $(RESULTS_PATH)%.txt