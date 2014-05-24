OpenFst 1.2.8 for Windows/Visual Studio
Paul Dixon (paul@edobashira.com)

A modified version of OpenFst 1.3.1 for compilation on Windows using Visual Studio

REQUIREMENTS:
  This version is known to work under Windows 7 and compile with Visual Studio 2010 Professional or better.
  	
INSTALLATION:
  the archive, open the solution file in Visual Studio and compile.

TODO:
  Weight class for DLL
  GenericRegister fails outside of the DLL becauase of the way Windows/VS treats static 
  variables in DLLs.
  warning LNK4087: CONSTANT keyword is obsolete; use DATA

07/01/12
Updated to 1.2.8

11/11/11
Updated to 1.2.8
Auto generate the config.h
Changed some conditional compilation macros (OPENFSTDLL)
64bit compilation
Wrote round the ICU requirement


05/04/2011
Updated to 1.2.7
Big change in the linking everything is now in a dll
WARNING it is not currently possible to locally register type, weight etc.
fstest currently does not work (due to the above)
Added auto-linking support for Visual Studio


07/12/2010
Updated to version 1.2.6

Fixed a bug in fstdraw
Added fstsymbols command
Added newer pdt commands

18/09/2010
Updated to version 1.2.3 
Added far 32bit fix

05/09/2010
Version 1.2.2



Acknowledgements
Micheal Riley and the OpenFst developers, Daniel Povey

CHANGES

Changed config.h to Windows suitable defines and to switch off many
compiler warnings

compat.h:47 added the conditional compilation
#ifdef WINDOWS
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#define snprintf _snprintf
#define strtoll _strtoi64
#else
#include <dlfcn.h>
#endif

Added files <tr1/unordered_map> and #include <fst/unordered_map.h>
Changed all occurrences off #include <tr1/unordered_map> to #include
<fst/unordered_map.h>

Changed all occurrences off #include <tr1/unordered_set> to #include
<fst/unordered_set.h>

generic-register.h:77 Added conditional compilation of the dl calls

replace.h:1041 added conditional compilation of correct template
keyword to make VS happy

Added to flags.h:32 
#ifdef WINDOWS
#define strtoll _strtoi64
#endif

far/compile-strings.h:23 Added
#ifndef WINDOWS
#include <libgen.h>
#endif

far.create.h:28 Added
#ifndef WINDOWS
#include <libgen.h>
#endif

far/main.h Added
#ifdef WINDOWS
const char kFileSeperator = '\\';
std::string basename(const std::string &filename);
#endif

far/main.cc:110 Added
#ifdef WINDOWS
std::string basename(const std::string &filename) {
 size_t p = filename.find_last_of(kFileSeperator);
 return p == string::npos ? filename
               : filename.substr(p + 1, filename.size() - p);
}
#endif

far/info.h and compile-strings.cc
Added casts for all the log10 calls e.g. log10((float)info.nstate)
Visual studio was complaining about an ambiguity between float an
double  overloads

To switch the std in/out to binary
flags.cc:25 Added
#ifdef WINDOWS
#include <io.h>
#include <fcntl.h>
#endif

flags.cc:39  Added
#ifdef WINDOWS
_setmode(_fileno(stdin),_O_BINARY);
_setmode(_fileno(stdout),_O_BINARY);
#endif