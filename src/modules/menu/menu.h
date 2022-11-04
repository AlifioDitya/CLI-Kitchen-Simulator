/* Header untuk file Utility */

#ifndef UTIL_H
#define UTIL_H

#include "../word-machine/wordmachine.h"
#include "../string/string.h"
#include "../simulator/simulator.h"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"

boolean isExit(Word w);

boolean isStart(Word w);

void Splash(String name);

void Initiate(Simulator *s, Peta *p, ListStatik *catalog);

void inputCommand(Word *cmd);

#endif