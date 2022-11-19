#include "../string/string.h"
#include "../boolean.h"

#ifndef COMMAND_H
#define COMMAND_H

void inputCommand(String *cmd);

boolean isExit(String s);

boolean isStart(String s);

boolean isMoveEast(String s);

boolean isMoveWest(String s);

boolean isMoveNorth(String s);

boolean isMoveSouth(String s);

boolean isCommandInteger(String cmd);

int parseToInteger(String s);

boolean isWait(String s);

boolean isCatalog(String s);

boolean isDisplayInventory(String s);

boolean isDisplayDelivery(String s);

boolean isBuy(String s);

boolean isChop(String s);

boolean isFry(String s);

boolean isBoil(String s);

boolean isMix(String s);

boolean isUndo(String s);

boolean isRedo(String s);

#endif