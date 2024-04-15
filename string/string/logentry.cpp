//
//
// File:        logentry.cpp
//  ...
// Version:     1.0
// Date:
// Author:
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.h"
#include <iostream>
#include <vector>


//See the supplied source code and data files in the shared folder in svn. logentry.cpp defines an ADT for logEntry. You will need to add functionality to this class (mainly constructors) to solve the problem. logview.cpp is the main and compiles and runs as is. You can modify this if needed.
//For each line in the log file split the line on blanks. This should result in 10 strings.
//If the entry is invalid (not 10 strings), store a blank logEntry.
//For all valid entries you will need to do further processing and properly construct the logEntry data structure. See logentry.hpp

//EXAMPLE OF LOG
//131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625

// REQUIRES: SPLIT
// ENSURES: Logentrys are split by spaces


LogEntry::LogEntry(const String& line) {
    // Split the line by spaces
    std::vector<String> logEntryParts = line.split(' ');
    host = logEntryParts[0];
    date = logEntryParts[2];
    
}

// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;

    return result;
}

// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>&) {
    
}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>&) {

}

// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>&) {
    
    return 0;
}

