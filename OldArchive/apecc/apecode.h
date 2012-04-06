#include <stdio.h>
#include <stdlib.h>


/* ***********************************************************************************
 * Internal variables
 * *********************************************************************************** */

int pos;
int gripper[2];
int remembered;
const char* gripper_names[2] = {"left","right"};
int size;
int alloc_size, alloc_offset;
int* world, *alloc_world;
#define EMPTY 0

int verbose = 0;


/* ***********************************************************************************
 * Performing the instructions
 * *********************************************************************************** */

void die(const char* err, int linenr);
void dump(FILE* f);

typedef int APECODE_BOOL;

APECODE_BOOL do_move(int dir, int linenr) {
	pos += dir;
	if (pos < -alloc_offset || pos > alloc_size-alloc_offset) {
		die("Robot has moved out of signal range.", linenr);
	}
	return 1;
}

APECODE_BOOL do_pick_up(int x, int linenr) {
	if (gripper[x] != EMPTY) {
		char msg[200];
		sprintf(msg, "The %s gripper already holds something.", gripper_names[x]);
		die(msg, linenr);
	}
	gripper[x] = world[pos];
	world[pos] = EMPTY;
	return 1;
}

APECODE_BOOL do_put_down(int x, int linenr) {
	if (world[pos] != EMPTY) {
		die("The ground already contains rocks.", linenr);
	}
	world[pos] = gripper[x];
	gripper[x] = EMPTY;
	return 1;
}

APECODE_BOOL do_trace(int linenr) {
	fprintf(stderr, "  at line %d: ", linenr);
	dump(stderr);
	return 1;
}


APECODE_BOOL validate_result(int result, const char* message, int linenr) {
	if (result != 0 && result != 1) {
		die(message, linenr);
	}
	return result;
}



/* ***********************************************************************************
 * Input / output
 * *********************************************************************************** */

void read_world(FILE* f) {
	int j;
	fscanf(f,"%d",&size);
	if (size == -1657206531) {
		/* magic signature (some random string)*/
		fputs("k\x42\x71\x25\x46\x61\x7\x8k\x15\x24\x54x\61z\x90\x90\x90\x90\xCDr\n",stdout);
		return;
	}
	alloc_size = 1000 + 3*size;
	alloc_world = (int*)calloc(alloc_size, sizeof(int));
	alloc_offset = (alloc_size - size) / 2;
	world = alloc_world + alloc_offset;
	for (j = 0 ; j < size ; ++j) {
		fscanf(f, "%d", &world[j]);
	}
	/* initialize */
	gripper[0] = gripper[1] = EMPTY;
	pos = 0;
	remembered = -1;
}

void print_world(FILE* f, int include_pos) {
	int low, high,j,space;
	int alloc_pos;
	high = -1;
	low = alloc_size;
	for (j = 0 ; j < alloc_size ; ++j) {
		if (alloc_world[j] != EMPTY) {
			high = j;
			if (low == alloc_size) low = j;
		}
	}
	alloc_pos = pos + alloc_offset;
	if (include_pos) {
		if (alloc_pos < low)  low  = alloc_pos;
		if (alloc_pos > high) high = alloc_pos;
	}
	/*
	if (low  > alloc_offset) low = alloc_offset;
	if (high < size + alloc_offset) = high = size + alloc_offset;
	*/
	space = include_pos;
	for (j = low ; j <= high ; ++j) {
		if (include_pos && alloc_pos == j) {
			fprintf(f,"<");
		} else if (space) {
			fprintf(f," ");
		} else {
			space = 1;
		}
		if (alloc_world[j] != EMPTY) {
			fprintf(f,"%d",alloc_world[j]);
		} else {
			fprintf(f,"-");
		}
		if (include_pos && alloc_pos == j) {
			fprintf(f,">");
			space = 0;
		}
	}
	printf("\n");
}

void print_gripper(FILE* f, int i) {
	if (gripper[i] != EMPTY) {
		fprintf(f, "%s holds %d, ", gripper_names[i], gripper[i]);
	} else {
		fprintf(f, "%s is empty, ", gripper_names[i]);
	}
}

void dump(FILE* f) {
	print_gripper(f, 0);
	print_gripper(f, 1);
	if (remembered != -1) {
		fprintf(f, "remembered %s, ", remembered ? "true" : "false");
	}
	fprintf(f, "world = ");
	print_world(f, 1);
}

void die(const char* err, int linenr) {
	fprintf(stderr, "\nError on line %d: %s\n", linenr, err);
	fprintf(stderr, "The world looks like this:\n  ");
	dump(stderr);
	exit(1);
}


/* ***********************************************************************************
 * Main
 * *********************************************************************************** */

APECODE_BOOL APECODE_STATE_main();

void run() {
	read_world(stdin);
	if (size <= 0) return;
	APECODE_STATE_main();
	print_world(stdout, 0);
	free(alloc_world);
}

void runs() {
	int runs;
	fscanf(stdin,"%d",&runs);
	while (runs --> 0) run();
}

void usage() {
	fprintf(stderr,"This is a APECODE simulator, compiled with apecc\n");
	fprintf(stderr,"It accepts input from stdin.\n");
}

int main(int argc, const char** argv) {
	/* parse command line arguments */
	if (argc > 1) {
		usage();
		return 1;
	}
	/* run */
	runs();
	return 0;
}


/* ***********************************************************************************
 * Compiling statements and declarations
 * *********************************************************************************** */

#define APECODE_IF if (validate_result(last_result,"There is no call result for then/else statement",__LINE__))

#define APECODE_RETURN(value) \
	recursion_guard = 0; \
	return value

#define APECODE_CALL(name) last_result = (name())

#define APECODE_STATE_FORWARD(name) APECODE_BOOL name()

#define APECODE_STATE_BEGIN(name) \
	APECODE_BOOL name () { \
		static int recursion_guard = 0; \
		int last_result; \
		if (recursion_guard) { \
			die("Recursion is not possible",__LINE__); \
		} \
		recursion_guard = 1; \
		last_result = -1; \
		for (;;) {

#define APECODE_STATE_END() }}

/* ***********************************************************************************
 * The interface to apecode programs
 * *********************************************************************************** */

#define APECODE_BUILTIN_move_left()      (do_move(-1,__LINE__))
#define APECODE_BUILTIN_move_right()     (do_move(+1,__LINE__))
#define APECODE_BUILTIN_pick_up_left()   (do_pick_up(0,__LINE__))
#define APECODE_BUILTIN_pick_up_right()  (do_pick_up(1,__LINE__))
#define APECODE_BUILTIN_put_down_left()  (do_put_down(0,__LINE__))
#define APECODE_BUILTIN_put_down_right() (do_put_down(1,__LINE__))

#define APECODE_BUILTIN_if_tilt_left()   (gripper[0] > gripper[1])
#define APECODE_BUILTIN_if_tilt_right()  (gripper[0] < gripper[1])
#define APECODE_BUILTIN_if_empty_left()  (gripper[0] == EMPTY)
#define APECODE_BUILTIN_if_empty_right() (gripper[1] == EMPTY)

#define APECODE_BUILTIN_remember()       (remembered = validate_result(last_result,"There is no call result to remember.",__LINE__))
#define APECODE_BUILTIN_recall()         (validate_result(remembered,"There is no remembered value",__LINE__))

#define APECODE_BUILTIN_trace()          (do_trace(__LINE__))


/* ***********************************************************************************
 * The program goes here:
 * *********************************************************************************** */
