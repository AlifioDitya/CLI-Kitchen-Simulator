/* Header untuk file Utility */

#ifndef UTIL_H
#define UTIL_H

#include "../word-machine/wordmachine.h"
#include "../string/string.h"
#include "../simulator/simulator.h"
#include "../peta/peta.h"
#include "../liststatik/liststatik.h"
#include "../makanan/makanan.h"

boolean isExit(Word w);
/* Mengecek apakah w berisi kata EXIT */

boolean isStart(Word w);
/* Mengecek apakah w berisi kata START */

boolean isBuy(Word w);
/* Mengecek apakah w berisi kata BUY */

boolean isChop(Word w);
/* Mengecek apakah w berisi kata CHOP */

boolean isFry(Word w);
/* Mengecek apakah w berisi kata FRY */

boolean isBoil(Word w);
/* Mengecek apakah w berisi kata BOIL */

boolean isMix(Word w);
/* Mengecek apakah w berisi kata MIX */

void Splash(String name);

void Initiate(Simulator *s, Peta *p, ListStatik *catalog);

void inputCommand(Word *cmd);

#endif