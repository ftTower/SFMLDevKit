#pragma once

// Couleurs de texte
#define ANSI_RESET   "\033[0m"
#define ANSI_RED     "\033[31m"
#define ANSI_GREEN   "\033[32m"
#define ANSI_YELLOW  "\033[33m"
#define ANSI_BLUE    "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN    "\033[36m"
#define ANSI_WHITE   "\033[37m"

// Couleurs de fond
#define ANSI_BG_RED     "\033[41m"
#define ANSI_BG_GREEN   "\033[42m"
#define ANSI_BG_YELLOW  "\033[43m"
#define ANSI_BG_BLUE    "\033[44m"
#define ANSI_BG_MAGENTA "\033[45m"
#define ANSI_BG_CYAN    "\033[46m"
#define ANSI_BG_WHITE   "\033[47m"

// Effets de texte
#define ANSI_BOLD      "\033[1m"
#define ANSI_UNDERLINE "\033[4m"
#define ANSI_REVERSED  "\033[7m"

// Positionnement du curseur
#define ANSI_CURSOR_UP(n)    "\033[" #n "A"
#define ANSI_CURSOR_DOWN(n)  "\033[" #n "B"
#define ANSI_CURSOR_RIGHT(n) "\033[" #n "C"
#define ANSI_CURSOR_LEFT(n)  "\033[" #n "D"