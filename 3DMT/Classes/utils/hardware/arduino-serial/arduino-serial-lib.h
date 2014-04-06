//
// arduino-serial-lib -- simple library for reading/writing serial ports
//
// 2006-2013, Tod E. Kurt, http://todbot.com/blog/
//


#ifndef __ARDUINO_SERIAL_LIB_H__
#define __ARDUINO_SERIAL_LIB_H__

#include <stdint.h>   // Standard types 
#include "termiosC.h"  // POSIX terminal control definitions 
#include "../../SpecialKeys.h"

int serialport_init(const char* serialport, int baud);
int serialport_close(int fd);
int serialport_writebyte( int fd, uint8_t b);
int serialport_write(int fd, const string &str);
int serialport_read_until(int fd, string &buf, char until, int buf_max,int timeout);
int serialport_flush(int fd);

#if defined(__APPLE__) && defined(__MACH__)
#   include "arduino-serial-lib.c"
#endif

#endif

