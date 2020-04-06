#ifndef LOGGER_H
#define LOGGER_H

#include <chrono>
#include <iostream>
#include <ratio>

#if __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdio.h>


#define LOGGER 1
#if LOGGER
#define LOGGER_GEN 1
#define LOGGER_UI 1
#define LOGGER_CNN 1
#define LOG(LEVEL, ...) logger(LEVEL, __FILE__, __LINE__, __VA_ARGS__);
#else
#define LOG(LEVEL, ...)
#endif 

// define constant color hex
extern const char RED[];
extern const char GREEN[];
extern const char YELLOW[];
extern const char BLUE[];
extern const char MAGENTA[];
extern const char CYAN[];
extern const char GREY[];
extern const char LIGHT_GREY[];
extern const char LIGHT_RED[];
extern const char LIGHT_GREEN[];
extern const char LIGHT_YELLOW[];
extern const char LIGHT_BLUE[];
extern const char LIGHT_MAGENTA[];
extern const char LIGHT_CYAN[];
extern const char WHITE[];
extern const char RESET[];

// define level's name
extern const char *levels_name[];

// define level's color
extern const char *levels_color[];

typedef enum level { TRACE, DEBUG, INFO, WARN, ERROR, FATAL } level_t;

/*
 */
extern void logger(level_t level, const char *file, int line, const char *fmt,
                   ...);

#if __cplusplus
}
#endif

class TimeMeter {
public:
  explicit TimeMeter() {}
  inline void start();
  inline void stop();
  void getPartialElapsed();
  void getTotalElapsed();
  ~TimeMeter();

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_stop;
  std::chrono::duration<double, std::micro> m_partial_elapsed;
  std::chrono::duration<double, std::micro> m_total_elapsed;
};

class StopWatch {
 public:
  explicit StopWatch();
  ~StopWatch();

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_stop;
};

#endif // LOGGER_H
