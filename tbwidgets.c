#include "tbwidgets.h"
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum tbw_operation {
	newTbSeparator_f = 0,
	newTbLabel_f = 1,
	newTbIcon_f = 2,
	newTbButton_f = 3,
	newTbIconButton_f = 4,
	newTbCheckBox_f = 5,
	newTbTextInput_f = 6,
	newTbSlider_f = 7,
	newTbComboBox_f = 8,
	newTbListView_f = 9,
	newTbButtonGroup_f = 10,
	newTbMenu_f = 11,
	addTbSpacer_f = 12,
	addTbSeparator_f = 13,
	addTbLabel,addTbIcon_f = 14,
	addTbButton_f = 15,
	addTbIconButton_f = 16,
	addTbCheckBox_f = 17,
	addTbTextInput_f = 18,
	addTbSlider_f = 19,
	addTbComboBox_f = 20,
	addTbListView_f = 21,
	addTbButtonGroup_f = 22,
	addTbMenu_f = 23,
	TbWidget_setWidth_f = 24,
	TbWidget_minWidth_f = 25,
	TbSeparator_setFull_f = 26,
	TbLabel_setText_f = 27,
	TbLabel_setItalic_f = 28,
	TbLabel_setBold_f = 29,
	TbLabel_setUnderlined_f = 30,
	TbLabel_setStrikeThrough_f = 31,
	TbIcon_load_f = 32,
	TbButton_setLabel_f = 33,
	TbButton_setIcon_f = 34,
	TbButton_setDisabled_f = 35,
	TbButton_setLink_f = 36,
	TbButton_setToggle_f = 37,
	TbButton_setToggled_f = 38,
	TbButton_setIconOnTheRigh_f = 39,
	TbIconButton_setToggle_f = 40,
	TbIconButton_setToggled_f = 41,
	TbCheckBox_setLabel_f = 42,
	TbCheckBox_setDisabled_f = 43,
	TbCheckBox_setChecked_f = 44,
	TbTextInput_setText_f = 45,
	TbTextInput_setWarning_f = 46,
	TbTextInput_setDisabled_f = 47,
	TbTextInput_setPassword_f = 48,
	TbTextInput_setLocked_f = 49,
	TbTextInput_setResizable_f = 50,
	TbSlider_setVal_f = 51,
	TbSlider_setMin_f = 52,
	TbSlider_setMax_f = 53,
	TbSlider_setStops_f = 54,
	TbSlider_setDisabled_f = 55,
	TbComboBox_setVal_f = 56,
	TbComboBox_addItem_f = 57,
	TbComboBox_removeItem_f = 58,
	TbComboBox_addItemAtLocati_f = 59,
	TbComboBox_removeItemAtLocation_f = 60,
	TbComboBox_setDisabled_f = 61,
	TbListView_setVal_f = 62,
	TbListView_addItem_f = 63,
	TbListView_removeItem_f = 64,
	TbListView_addItemAtLocation_f = 65,
	TbListView_removeItemAtLocation_f = 66,
	TbButtonGroup_addItem_f = 67,
	TbButtonGroup_removeItem_f = 68,
	TbButtonGroup_addItemAtLocation_f = 69,
	TbButtonGroup_removeItemAtLocation_f = 70,
	TbMenu_addItem_f = 71,
	TbMenu_removeItem_f = 72,
	TbMenu_addItemAtLocation_f = 73,
	TbMenu_removeItemAtLocation_f = 74;
};

#define MAX_BACKENDS 999
static int (*backends)(enum tbw_operation o)[MAX_BACKENDS];

bool TbRemoveBackend(int (backend_func*)(enum tbw_operation o)){
	for(int i = 0; backends[i] != NULL && i < 999; i++)
		if(backends[i] == backend_func) //TODO
	return false;
}

bool TbAddBackend(int (backend_func*)(enum tbw_operation o)){

}

int TbCallOperation(enum tbw_operation o, ...){
#if __GNUC__ > 4 // fancy optimization

}