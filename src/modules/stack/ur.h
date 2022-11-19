/* Deklarasi Fungsi Undo Redo */

#ifndef UR_H
#define UR_H

#include "../stack/stack.h"

void InitiateURStacks(Stack *U, Stack *R);
// Membuat 2 Stack untuk Undo dan Redo

infotypeStack CreateSave(Simulator S, PrioQueueMakanan PQ, TIME CT);
// Membuat sebuah save kondisi program disuatu waktu

void outputNotification(Inventory OldInv, Inventory NewInv, PrioQueueMakanan OldPQ, PrioQueueMakanan NewPQ);
// Mengeluarkan Notifikasi setelah Undo/Redo

void LoadSave(infotypeStack Saved, Simulator *S, PrioQueueMakanan *PQ, TIME *CT);
// Menload Save yang tersimpan

#endif