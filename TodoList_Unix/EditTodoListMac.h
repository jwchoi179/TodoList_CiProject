#ifndef __EDITTODOLISTMAC_H__
#define __EDITTODOLISTMAC_H__

#include "EditTodoListMac.h"

void ShowModifyMenu();
void EditTitle(int LastListIdx);
void MakeNewDate(int selectIdx);
void ModifyDate(int selectIdx);
void EditDate(int LastListIdx);
void ChooseImportanceMenu(int selectIdx);
void EditImportance(int LastListIdx);
void EditTodoList(int LastListIdx);

#endif