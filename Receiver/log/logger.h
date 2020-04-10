#ifndef LOGGER_H
#define LOGGER_H

#include <array>
#include <iostream>
#include <ostream>
#include <string>
#include <type_traits>

template <typename E>
constexpr auto to_underlying(E e) noexcept {
  return static_cast<std::underlying_type_t<E>>(e);
}

#define LOGGER 0
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

// define level's color
extern const std::array<std::string, 6> levels_color;

enum class LevelAlert : int { I, T, D, W, E, F };

inline std::string get_level(LevelAlert lvl) {
  std::string alert;
  switch (lvl) {
    case LevelAlert::I:
      alert = "I ";
      break;
    case LevelAlert::T:
      alert = "T ";
      break;
    case LevelAlert::D:
      alert = "D ";
      break;
    case LevelAlert::W:
      alert = "W ";
      break;
    case LevelAlert::E:
      alert = "E ";
      break;
    case LevelAlert::F:
      alert = "F ";
      break;
  }
  return alert;
}

inline std::ostream &operator<<(std::ostream &os, LevelAlert lvl) {
  auto alert = get_level(lvl);
  os << alert;
  return os;
}

template <typename... T>
inline void logger(LevelAlert lvl, const char *file, int line, T &&... args) {
  std::cerr << levels_color[to_underlying(lvl)] << lvl << RESET << " " << file
            << " l: " << line << "] ";
  int expander[]{0, (void(std::cerr << std::forward<T>(args) << " "), 0)...};
  static_cast<void>(expander);
  std::cerr << std::endl;
}

#endif  // LOGGER_H
