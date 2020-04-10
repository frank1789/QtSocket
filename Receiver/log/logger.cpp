#include "logger.h"

// define constant color hex
const char RED[] = "\x1b[0;31m";
const char GREEN[] = "\x1b[0;32m";
const char YELLOW[] = "\x1b[0;33m";
const char BLUE[] = "\x1b[0;34m";
const char MAGENTA[] = "\x1b[0;35m";
const char CYAN[] = "\x1b[0;36m";
const char GREY[] = "\x1b[0;36m";
const char LIGHT_GREY[] = "\x1b[0;37m";
const char LIGHT_RED[] = "\x1b[0;91m";
const char LIGHT_GREEN[] = "\x1b[0;92m";
const char LIGHT_YELLOW[] = "\x1b[0;93m";
const char LIGHT_BLUE[] = "\x1b[0;94m";
const char LIGHT_MAGENTA[] = "\x1b[0;95m";
const char LIGHT_CYAN[] = "\x1b[0;96m";
const char WHITE[] = "\x1b[0;97m";
const char RESET[] = "\x1b[0m";

// initialize level's color
extern const std::array<std::string, 6> levels_color{YELLOW, CYAN, GREEN, LIGHT_RED, RED, MAGENTA};
