#include <iostream>

//C++ uses streams as an interface between the program and input/output devices
//they are abstracted and independent of the actual device
//device can be keyboard, web service, sensor.. whatever..
//stream is a sequence of bytes
//input --> stream into the program
//output --> stream out of the program

//MAIN HEADERS
//iostream: formated input output from/to streams
//fstream: formated input utput from to file streams
//iomanip: manipulators for formating streams

//MAIN CLASSES:
//ios: base class for most other classes, formatted and unformatted io operations
//ifstream: input to a file
//ofstream: output to a file
//fstream: both input and output to a file (derived from ifstream, ofstream)
//stringstream operations on memory based strings (derived from istringstream, ostringstream)

//cin: instance of istream. by default connected to keyboard (buffered --> the input will not be automatic until te user presses Enter)
//cout: instance of ostream. by default connected to console (buffered --> the outup will happen only when the buffer ends up, or we provide std::endline, or flush the stream)
//cerr: error stream, instance of ostream. by default connected to console
//clog: log stream, instance of ostream. by default connected to console

//cin and cout are buffered --> the output will not be automatic until te user presses Enter
