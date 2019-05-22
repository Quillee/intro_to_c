// A header file that sets up some external varaiables and some functions

#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE available outside of this file
extern int THE_SIZE;

// gets and sets an internal static variable in ex22.c
int get_age();
void set_age(int age);

// updates a static var that's inside update_ratio
double update_ratio(double ratio);

void print_size();
#endif
