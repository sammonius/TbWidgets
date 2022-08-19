#include "tbwidgets.H"
#include "frame.H"

extern unsigned int frameCount;
extern Frame *frames;

Tb_t *getWindowTb(enum TbWindowType winType, void *win, bool empty);

TbSpacer_t *newTbSpacer(Tb_t *parent);
TbSeparator_t *newTbSeparator(Tb_t *parent);
TbLabel_t *newTbLabel(Tb_t *parent);
TbIcon_t *newTbIcon(Tb_t *parent);
TbButton_t *newTbButton(Tb_t *parent);
TbIconButton_t *newTbIconButton(Tb_t *parent);
TbCheckBox_t *newTbCheckBox(Tb_t *parent);
TbTextInput_t *newTbTextInput(Tb_t *parent);
TbSlider_t *newTbSlider(Tb_t *parent);
TbComboBox_t *newTbComboBox(Tb_t *parent);
TbListView_t *newTbListView(Tb_t *parent);
TbButtonGroup_t *newTbButtonGroup(Tb_t *parent);
TbMenu_t *newTbMenu(Tb_t *parent);

void addTbSpacer(TbSpacer_t *spacer, Tb_t *parent);
void addTbSeparator(TbSeparator_t *separator, Tb_t *parent);
void addTbLabel(TbLabel_t *label, Tb_t *parent);
void addTbIcon(TbIcon_t *icon, Tb_t *parent);
void addTbButton(TbButton_t *button, Tb_t *parent);
void addTbIconButton(TbIcon_t *iconBtn, Tb_t *parent);
void addTbCheckBox(TbCheckBox_t *checkbox, Tb_t *parent);
void addTbTextInput(TbTextInput_t *input, Tb_t *parent);
void addTbSlider(TbSlider_t *slider, Tb_t *parent);
void addTbComboBox(TbComboBox_t *cb, Tb_t *parent);
void addTbListView(TbListView_t *listView, Tb_t *parent);
void addTbButtonGroup(TbButtonGroup_t *btnGroup, Tb_t *parent);
void addTbMenu(TbMenu_t *menu, Tb_t *parent);

void TbWidget_setWidth(TbWidget_t *widget, unsigned int width);
unsigned int TbWidget_minWidth(TbWidget_t *widget);

void TbSeparator_setFull(TbSeparator_t *separator, bool full);
void TbSeparator_setDashed(TbSeparator_t *separator, bool dashed);

void TbLabel_setText(TbLabel_t *label, char *text);
void TbLabel_setItalic(TbLabel_t *label, bool italic);
void TbLabel_setBold(TbLabel_t *label, bool bold);
void TbLabel_setUnderlined(TbLabel_t *label, bool underlined);
void TbLabel_setStrikeThrough(TbLabel_t *label, bool strikeThrough);

void TbIcon_load(TbIcon_t *icon);

void TbButton_setLabel(TbButton_t *btn, TbLabel_t *label);
void TbButton_setIcon(TbButton_t *btn, TbIcon_t *icon);
void TbButton_setDisabled(TbButton_t *btn, bool disabled);
void TbButton_setLink(TbButton_t *btn, bool link);
void TbButton_setToggle(TbButton_t *btn, bool toggle);
void TbButton_setToggled(TbButton_t *btn, bool toggled);
void TbButton_setIconOnTheRight(TbButton_t *btn, bool iconOnTheRight);

void TbIconButton_setIcon(TbButton_t *btn, TbIcon_t *icon);
void TbIconButton_setToggle(TbButton_t *btn, bool toggle);
void TbIconButton_setToggled(TbButton_t *btn, bool toggled);

void TbCheckBox_setLabel(TbButton_t *btn, TbLabel_t *label);
void TbCheckBox_setDisabled(TbButton_t *btn, bool disabled);
void TbCheckBox_setChecked(TbButton_t *btn, bool checked);

void TbTextInput_setText(TbTextInput_t *input, char *text);
void TbTextInput_setWarning(TbTextInput_t *input, char *warning);
void TbTextInput_setDisabled(TbTextInput_t *input, bool disabled);
void TbTextInput_setPassword(TbTextInput_t *input, bool password);
void TbTextInput_setLocked(TbTextInput_t *input, bool locked);
void TbTextInput_setResizable(TbTextInput_t *input, bool resizable);

void TbSlider_setVal(TbSlider_t *slider, double val);
void TbSlider_setMin(TbSlider_t *slider, double min);
void TbSlider_setMax(TbSlider_t *slider, double max);
void TbSlider_setStops(TbSlider_t *slider, unsigned int stops);
void TbSlider_setDisabled(TbSlider_t *slider, bool disabled);

void TbComboBox_addItem(TbComboBox_t *cb, TbButton_t *button);
void TbComboBox_removeItem(TbComboBox_t *cb, TbButton_t *button);
void TbComboBox_addItemAtLocation(TbComboBox_t *cb, TbButton_t *button, unsigned int spot);
void TbComboBox_removeItemAtLocation(TbComboBox_t *cb, unsigned int spot);
void TbComboBox_setDisabled(TbComboBox_t *cb, bool disabled);

void TbListView_addItem(TbListView_t *listView, TbButton_t *button);
void TbListView_removeItem(TbListView_t *listView, TbButton_t *button);
void TbListView_addItemAtLocation(TbListView_t *listView, TbButton_t *button, unsigned int spot);
void TbListView_removeItemAtLocation(TbListView_t *listView, unsigned int spot);

void TbButtonGroup_addItem(TbButtonGroup_t *btnGroup, TbButton_t *button);
void TbButtonGroup_removeItem(TbButtonGroup_t *btnGroup, TbButton_t *button);
void TbButtonGroup_addItemAtLocation(TbButtonGroup_t *btnGroup, TbButton_t *button, unsigned int spot);
void TbButtonGroup_removeItemAtLocation(TbButtonGroup_t *btnGroup, unsigned int spot);

void TbMenu_addItem(TbMenu_t *menu, TbButton_t *button);
void TbMenu_removeItem(TbMenu_t *menu, TbButton_t *button);
void TbMenu_addItemAtLocation(TbMenu_t *menu, TbButton_t *button, unsigned int spot);
void TbMenu_removeItemAtLocation(TbMenu_t *menu, unsigned int spot);
