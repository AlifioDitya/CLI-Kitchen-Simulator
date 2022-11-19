#include <stdio.h>
#include "../string/string.h"
#include "../boolean.h"

void inputCommand(String *cmd) {
    printf("Enter command : ");
    startString();
    assignString(currentString, cmd);
    printf("\n");
}

boolean isExit(String s) {
    String temp;
    createString("EXIT", 4, &temp);
    return (isStringEqual(s, temp));
}

boolean isStart(String s) {
    String temp;
    createString("START", 5, &temp);
    return (isStringEqual(s, temp));
}

boolean isCommandInteger(String cmd) {
    int i;
    for (i=0; i<cmd.Length; i++) {
        if (cmd.str[i] > '9' || cmd.str[i] < '0') {
            return false;
        }
    }
    return true;
}

int parseToInteger(String s) {
    int i;
    int total = 0;
    if (isCommandInteger(s)) {
        for (i=0; i<s.Length; i++) {
            total = total*10 + (s.str[i]-48);
        }
    }
    return total;
}

boolean isMoveEast(String s) {
    int i;
    char* command = "MOVE EAST";
    int len = 9;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMoveWest(String s) {
    int i;
    char* command = "MOVE WEST";
    int len = 9;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMoveNorth(String s) {
    int i;
    char* command = "MOVE NORTH";
    int len = 10;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isMoveSouth(String s) {
    int i;
    char* command = "MOVE SOUTH";
    int len = 10;
    if (len == s.Length) {
        for (i=0; i<s.Length; i++) {
            if (s.str[i] != command[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

boolean isWait(String s) {
    // KAMUS
    String temp;
    int countSpace, i, isLastCharSpace;

    // ALGORITMA
    createString("WAIT", 4, &temp);
    countSpace = 0;

    if (s.Length < 8) {
        return false;
    }

    for (i = 0; i < temp.Length; i++) {
        if (s.str[i] != temp.str[i]) {
            return false;
        }
    }
    
    i = 4;
    isLastCharSpace = false;

    while (i < s.Length) {
        if (s.str[i] == ' ') {
            if (isLastCharSpace) {
                return false;
            } else {
                countSpace++;
                isLastCharSpace = true;
            }
        } else if (s.str[i] < '0' || s.str[i] > '9') {
            return false;
        } else {
            isLastCharSpace = false;
        }
        i++;
    }

    return (countSpace == 2 && !isLastCharSpace);
}

boolean isCatalog(String s) {
    String temp;
    createString("CATALOG", 7, &temp);
    return (isStringEqual(s, temp));
}

boolean isDisplayInventory(String s) {
    String temp;
    createString("INVENTORY", 9, &temp);
    return (isStringEqual(s, temp));
}

boolean isDisplayDelivery(String s) {
    String temp;
    createString("DELIVERY", 8, &temp);
    return (isStringEqual(s, temp));
}

boolean isBuy(String s) {
    String temp;
    createString("BUY", 3, &temp);
    return (isStringEqual(s, temp));
}
boolean isChop(String s) {
    String temp;
    createString("CHOP", 4, &temp);
    return (isStringEqual(s, temp));
}
boolean isFry(String s) {
    String temp;
    createString("FRY", 3, &temp);
    return (isStringEqual(s, temp));
}
boolean isBoil(String s) {
    String temp;
    createString("BOIL", 4, &temp);
    return (isStringEqual(s, temp));
}
boolean isMix(String s) {
    String temp;
    createString("MIX", 3, &temp);
    return (isStringEqual(s, temp));
}
boolean isCookBook(String s) {
    String temp;
    createString("COOKBOOK", 8, &temp);
    return (isStringEqual(s, temp));
}