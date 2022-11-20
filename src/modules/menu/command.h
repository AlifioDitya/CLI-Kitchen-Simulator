#include "../string/string.h"
#include "../boolean.h"

#ifndef COMMAND_H
#define COMMAND_H

void inputCommand(String *cmd);
// I.S String command sembarang
// F.S String command terisi

boolean isExit(String s);
// Mengembalikan true apabila string adalah "EXIT"

boolean isStart(String s);
// Mengembalikan true apabila string adalah "START"

boolean isMoveEast(String s);
// Mengembalikan true apabila string adalah "MOVE EAST"

boolean isMoveWest(String s);
// Mengembalikan true apabila string adalah "MOVE WEST"

boolean isMoveNorth(String s);
// Mengembalikan true apabila string adalah "MOVE NORTH"

boolean isMoveSouth(String s);
// Mengembalikan true apabila string adalah "MOVE SOUTH"

boolean isCommandInteger(String cmd);
// Mengembalikan true apabila string adalah integer

int parseToInteger(String s);
// Mengembalikan hasil integer dari string

boolean isWait(String s);
// Mengembalikan true apabila string adalah "WAIT"

boolean isCatalog(String s);
// Mengembalikan true apabila string adalah "CATALOG"

boolean isDisplayInventory(String s);
// Mengembalikan true apabila string adalah "INVENTORY"

boolean isDisplayDelivery(String s);
// Mengembalikan true apabila string adalah "DELIVERY"

boolean isBuy(String s);
// Mengembalikan true apabila string adalah "BUY"

boolean isChop(String s);
// Mengembalikan true apabila string adalah "CHOP"

boolean isFry(String s);
// Mengembalikan true apabila string adalah "FRY"

boolean isBoil(String s);
// Mengembalikan true apabila string adalah "BOIL"

boolean isMix(String s);
// Mengembalikan true apabila string adalah "MIX"

boolean isCookBook(String s);
// Mengembalikan true apabila string adalah "COOKBOOK"

boolean isUndo(String s);
// Mengembalikan true apabila string adalah "UNDO"

boolean isRedo(String s);
// Mengembalikan true apabila string adalah "REDO"

#endif