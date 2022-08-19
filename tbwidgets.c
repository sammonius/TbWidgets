#define TBWIDGETS_NO_FUNC_DECLS
#include "tbwidgets.h"
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef void(*TbFunc_t)();

TbFunc_t getWindowTb,
newTbSpacer,
newTbSeparator,
newTbLabel,
newTbIcon,
newTbButton,
newTbIconButton,
newTbCheckBox,
newTbTextInput,
newTbSlider,
newTbComboBox,
newTbListView,
newTbButtonGroup,
newTbMenu,
addTbSpacer,
addTbSeparator,
addTbLabel,addTbIcon,
addTbButton,
addTbIconButton,
addTbCheckBox,
addTbTextInput,
addTbSlider,
addTbComboBox,
addTbListView,
addTbButtonGroup,
addTbMenu,
TbWidget_setWidth,
TbWidget_minWidth,
TbSeparator_setFull,
TbSeparator_setFull,
TbLabel_setText,
TbLabel_setItalic,
TbLabel_setBold,
TbLabel_setUnderlined,
TbLabel_setStrikeThrough,
TbIcon_load,
TbButton_setLabel,
TbButton_setIcon,
TbButton_setDisabled,
TbButton_setLink,
TbButton_setToggle,
TbButton_setToggled,
TbButton_setIconOnTheRight,
TbIconButton_setToggle,
TbIconButton_setToggled,
TbCheckBox_setLabel,
TbCheckBox_setDisabled,
TbCheckBox_setChecked,
TbTextInput_setText,
TbTextInput_setWarning,
TbTextInput_setDisabled,
TbTextInput_setPassword,
TbTextInput_setLocked,
TbTextInput_setResizable,
TbSlider_setVal,
TbSlider_setMin,TbSlider_setMax,
TbSlider_setStops,
TbSlider_setDisabled,
TbComboBox_setVal,
TbComboBox_addItem,
TbComboBox_removeItem,
TbComboBox_addItemAtLocation,
TbComboBox_removeItemAtLocation,
TbComboBox_setDisabled,
TbListView_setVal,
TbListView_addItem,
TbListView_removeItem,
TbListView_addItemAtLocation,
TbListView_removeItemAtLocation,
TbButtonGroup_addItem,
TbButtonGroup_removeItem,
TbButtonGroup_addItemAtLocation,
TbButtonGroup_removeItemAtLocation,
TbMenu_addItem,
TbMenu_removeItem,
TbMenu_addItemAtLocation,
TbMenu_removeItemAtLocation;

void *backendLib;

static char backendLibName[99];

void getTbBackendLib(char *dest){
	strcpy(dest, backendLibName);
}

int setTbBackendLib(char *newLibPath){
	if(newLibPath == NULL || newLibPath[0] == '\0') return false;
	// RTLD_NOW is faster since practically all functions in the library will be used.
	if(!(backendLib = dlopen(newLibPath, RTLD_NOW))) return false; 
	
	/* Checks if the requested backend has function NAME.
	 * If it doesn't, revert to previous backend. */
	#define LOAD_BACKEND_FUNC(NAME) if((NAME = dlsym(backendLib, #NAME)) == NULL){return setTbBackendLib(backendLibName);}
	
	LOAD_BACKEND_FUNC(getWindowTb)
	LOAD_BACKEND_FUNC(newTbSpacer)
	LOAD_BACKEND_FUNC(newTbSeparator)
	LOAD_BACKEND_FUNC(newTbLabel)
	LOAD_BACKEND_FUNC(newTbIcon)
	LOAD_BACKEND_FUNC(newTbButton)
	LOAD_BACKEND_FUNC(newTbIconButton)
	LOAD_BACKEND_FUNC(newTbCheckBox)
	LOAD_BACKEND_FUNC(newTbTextInput)
	LOAD_BACKEND_FUNC(newTbSlider)
	LOAD_BACKEND_FUNC(newTbComboBox)
	LOAD_BACKEND_FUNC(newTbListView)
	LOAD_BACKEND_FUNC(newTbButtonGroup)
	LOAD_BACKEND_FUNC(newTbMenu)
	LOAD_BACKEND_FUNC(addTbSpacer)
	LOAD_BACKEND_FUNC(addTbSeparator)
	LOAD_BACKEND_FUNC(addTbLabel)
	LOAD_BACKEND_FUNC(addTbIcon)
	LOAD_BACKEND_FUNC(addTbButton)
	LOAD_BACKEND_FUNC(addTbIconButton)
	LOAD_BACKEND_FUNC(addTbCheckBox)
	LOAD_BACKEND_FUNC(addTbTextInput)
	LOAD_BACKEND_FUNC(addTbSlider)
	LOAD_BACKEND_FUNC(addTbComboBox)
	LOAD_BACKEND_FUNC(addTbListView)
	LOAD_BACKEND_FUNC(addTbButtonGroup)
	LOAD_BACKEND_FUNC(addTbMenu)
	LOAD_BACKEND_FUNC(TbWidget_setWidth)
	LOAD_BACKEND_FUNC(TbWidget_minWidth)
	LOAD_BACKEND_FUNC(TbSeparator_setFull)
	LOAD_BACKEND_FUNC(TbSeparator_setFull)
	LOAD_BACKEND_FUNC(TbLabel_setText)
	LOAD_BACKEND_FUNC(TbLabel_setItalic)
	LOAD_BACKEND_FUNC(TbLabel_setBold)
	LOAD_BACKEND_FUNC(TbLabel_setUnderlined)
	LOAD_BACKEND_FUNC(TbLabel_setStrikeThrough)
	LOAD_BACKEND_FUNC(TbIcon_load)
	LOAD_BACKEND_FUNC(TbButton_setLabel)
	LOAD_BACKEND_FUNC(TbButton_setIcon)
	LOAD_BACKEND_FUNC(TbButton_setDisabled)
	LOAD_BACKEND_FUNC(TbButton_setLink)
	LOAD_BACKEND_FUNC(TbButton_setToggle)
	LOAD_BACKEND_FUNC(TbButton_setToggled)
	LOAD_BACKEND_FUNC(TbButton_setIconOnTheRight)
	LOAD_BACKEND_FUNC(TbIconButton_setToggle)
	LOAD_BACKEND_FUNC(TbIconButton_setToggled)
	LOAD_BACKEND_FUNC(TbCheckBox_setLabel)
	LOAD_BACKEND_FUNC(TbCheckBox_setDisabled)
	LOAD_BACKEND_FUNC(TbCheckBox_setChecked)
	LOAD_BACKEND_FUNC(TbTextInput_setText)
	LOAD_BACKEND_FUNC(TbTextInput_setWarning)
	LOAD_BACKEND_FUNC(TbTextInput_setDisabled)
	LOAD_BACKEND_FUNC(TbTextInput_setPassword)
	LOAD_BACKEND_FUNC(TbTextInput_setLocked)
	LOAD_BACKEND_FUNC(TbTextInput_setResizable)
	LOAD_BACKEND_FUNC(TbSlider_setVal)
	LOAD_BACKEND_FUNC(TbSlider_setMin)
	LOAD_BACKEND_FUNC(TbSlider_setMax)
	LOAD_BACKEND_FUNC(TbSlider_setStops)
	LOAD_BACKEND_FUNC(TbSlider_setDisabled)
	LOAD_BACKEND_FUNC(TbComboBox_addItem)
	LOAD_BACKEND_FUNC(TbComboBox_removeItem)
	LOAD_BACKEND_FUNC(TbComboBox_addItemAtLocation)
	LOAD_BACKEND_FUNC(TbComboBox_removeItemAtLocation)
	LOAD_BACKEND_FUNC(TbComboBox_setDisabled)
	LOAD_BACKEND_FUNC(TbListView_addItem)
	LOAD_BACKEND_FUNC(TbListView_removeItem)
	LOAD_BACKEND_FUNC(TbListView_addItemAtLocation)
	LOAD_BACKEND_FUNC(TbListView_removeItemAtLocation)
	LOAD_BACKEND_FUNC(TbButtonGroup_addItem)
	LOAD_BACKEND_FUNC(TbButtonGroup_removeItem)
	LOAD_BACKEND_FUNC(TbButtonGroup_addItemAtLocation)
	LOAD_BACKEND_FUNC(TbButtonGroup_removeItemAtLocation)
	LOAD_BACKEND_FUNC(TbMenu_addItem)
	LOAD_BACKEND_FUNC(TbMenu_removeItem)
	LOAD_BACKEND_FUNC(TbMenu_addItemAtLocation)
	LOAD_BACKEND_FUNC(TbMenu_removeItemAtLocation)
	
	strcpy(backendLibName, newLibPath);
	return true;
}
