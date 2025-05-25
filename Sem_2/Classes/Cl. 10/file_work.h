#pragma once
#include "Time.h"

int make_file(const char* f_name);
int print_file(const char* f_name);
int del_equal(const char* f_name, Time key);
int update_equal(const char* f_name, Time key);
int add_after(const char* f_name, int pos, Time* times, int k);
