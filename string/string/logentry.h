//
//  logentry.h
//  string
//
//  Created by Anthony Cruz on 4/1/24.
//

#ifndef logentry_h
#define logentry_h
//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

//
class Date {
public:
            Date() {};
private:
    String  day, month, year;
};

//
class Time {
  public:
            Time() {};
  private:
    String  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
            LogEntry() {};
            LogEntry(const String&);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);

#endif


#endif /* logentry_h */
