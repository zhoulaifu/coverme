#ifndef __dbg_h__
#define __dbg_h__
 
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//char format[90];
//strcpy (format,"DEBUG %s:%d");
   char src[40];
   char dest[100];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strcpy(dest, src);

#ifdef DEBUG
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
////#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: %s \n",  __FILE__, __LINE__, M,  ##__VA_ARGS__)
//#define debug(M, ...) std::cerr<< ANSI_COLOR_CYAN<< "[DEBUG]" <<ANSI_COLOR_RESET<<  __FILE__<<":"<< __LINE__":"<< __FUNCTION__<<" "<< M <<std::endl;
#else
#define debug(M, ...)
#endif


#define clean_errno() (errno == 0 ? "None" : strerror(errno))
 
#define log_err(M, ...) fprintf(stderr, ANSI_COLOR_RED "[ERROR]" ANSI_COLOR_RESET " (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
 
#define log_warn(M, ...) fprintf(stderr, ANSI_COLOR_YELLOW "[WARN]" ANSI_COLOR_RESET " (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
 
#define log_info(M, ...) fprintf(stderr, ANSI_COLOR_GREEN "[INFO]" ANSI_COLOR_RESET " (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
 
#define check(A, M, ...) if (!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
 
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
 
#define check_mem(A) check((A), "Out of memory.")
 
#define check_debug(A, M, ...) if (!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }
 
#endif
