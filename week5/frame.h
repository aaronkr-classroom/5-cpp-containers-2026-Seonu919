#pragma once
// frame.h
#ifndef GRARD_frame_h
#define GRARD_frame_h

#include <vector>
#include <string>

using std::vector; using std::string;

string::size_type width(const vector<string>&);
vector<string> frame(const vector<string>&);


#endif
