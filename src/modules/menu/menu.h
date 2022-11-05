/* Header untuk file Utility */

#ifndef UTIL_H
#define UTIL_H

#include "../word-machine/wordmachine.h"
#include "../string/string.h"
#include "../simulator/simulator.h"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"

boolean isExit(String s);

boolean isStart(String s);

boolean isMoveEast(String s);

boolean isMoveWest(String s);

boolean isMoveNorth(String s);

boolean isMoveSouth(String s);

void Splash(String name);

void Initiate(Simulator *s, Peta *p, ListStatik *catalog);

void inputCommand(String *cmd);

#endif