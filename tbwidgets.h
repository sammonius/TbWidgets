#ifndef TBWIDGETS_H
#define TBWIDGETS_H

#include <stdbool.h>

#define TB_WIDGET_PROPERTIES enum TbWidget widgetType; unsigned int width; void *raw;

enum TbWidget {
	Tb,
	TbSpacer,
	TbSeparator,
	TbLabel,
	TbIcon,
	TbButton,
	TbIconButton,
	TbCheckBox,
	TbTextInput,
	TbSlider,
	TbComboBox,
	TbListView,
	TbButtonGroup,
	TbMenu
};


typedef struct TbSpacer {
	TB_WIDGET_PROPERTIES
} TbSpacer_t;

typedef struct TbSeparator {
	TB_WIDGET_PROPERTIES
	bool full, dashed;
} TbSeparator_t;

typedef struct TbLabel {
	TB_WIDGET_PROPERTIES
	char *text;
	bool italic, bold, underlined, strikethrough;
} TbLabel_t;

enum TbIconSource { TbXdgIconSource, TbUrlIconSource, TbCharIconSource};

typedef struct TbIcon {
	TB_WIDGET_PROPERTIES
	char *path;
	enum TbIconSource source;
} TbIcon_t;

typedef struct TbButton {
	TB_WIDGET_PROPERTIES
	TbLabel_t *label;
	TbIcon_t *icon;
	bool disabled, link, toggle, toggled, iconOnTheRignt;
	void(*onClick)();
} TbButton_t;

typedef struct TbIconButton {
	TB_WIDGET_PROPERTIES
	TbIcon_t *icon;
	bool disabled, toggle, toggled;
	void(*onClick)();
} TbIconButton_t;

typedef struct TbCheckBox {
	TB_WIDGET_PROPERTIES
	TbLabel_t *label;
	bool disabled, checked;
	void(*onClick)();
} TbCheckBox_t;

typedef struct TbTextInput {
	TB_WIDGET_PROPERTIES
	char *text, *warning;
	bool disabled, password, locked, resizable;
	void(*textChanged)();
} TbTextInput_t;

typedef struct TbSlider {
	TB_WIDGET_PROPERTIES
	double val, min, max;
	unsigned int stops;
	bool disabled;
	void(*onValChanged)();
} TbSlider_t;

typedef struct TbComboBox {
	TB_WIDGET_PROPERTIES
	TbButton_t *items;
	unsigned int itemCount, val;
	bool disabled;
	void(*onValChanged)();
} TbComboBox_t;

typedef struct TbListView {
	TB_WIDGET_PROPERTIES
	TbButton_t *items;
	unsigned int itemCount, val;
	void(*onValChanged)();
} TbListView_t;

typedef struct TbButtonGroup {
	TB_WIDGET_PROPERTIES
	TbButton_t *items;
	unsigned int itemCount;
} TbButtonGroup_t;

typedef struct TbMenu {
	TB_WIDGET_PROPERTIES
	TbButton_t *items;
	unsigned int itemCount;
	bool disabled;
} TbMenu_t;

typedef union TbWidgetAbstraction TbWidget_t;

typedef struct Tb {
	TB_WIDGET_PROPERTIES
	TbWidget_t *items;
	unsigned int itemCount;
	void(*onResize)();
} Tb_t;

union TbWidgetAbstraction {
	struct {TB_WIDGET_PROPERTIES};
	Tb_t tb;
	TbSpacer_t spacer;
	TbSeparator_t separator;
	TbLabel_t label;
	TbIcon_t icon;
	TbButton_t button;
	TbIconButton_t iconButton;
	TbCheckBox_t checkBox;
	TbTextInput_t textInput;
	TbSlider_t slider;
	TbComboBox_t comboBox;
	TbListView_t listView;
	TbButtonGroup_t buttonGroup;
	TbMenu_t menu;
};

enum TbWindowType {TbXLibWindow, TbXCBWindow, TbWlSurfaceWindow};

#ifdef __cplusplus
extern "C" {
#endif

/* This macro prevents the "redeclared as different kind of symbol" error
 * when compiling [tbwidgets.c] since it is defined in that file. */
#ifndef TBWIDGETS_NO_FUNC_DECLS

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

void TbComboBox_setVal(TbComboBox_t *cb, unsigned int val);
void TbComboBox_addItem(TbComboBox_t *cb, TbButton_t *button);
void TbComboBox_removeItem(TbComboBox_t *cb, TbButton_t *button);
void TbComboBox_addItemAtLocation(TbComboBox_t *cb, TbButton_t *button, unsigned int spot);
void TbComboBox_removeItemAtLocation(TbComboBox_t *cb, unsigned int spot);
void TbComboBox_setDisabled(TbComboBox_t *cb, bool disabled);

void TbListView_setVal(TbListView_t *listView, unsigned int val);
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

#endif /* TBWIDGETS_NO_FUNC_DECLS */

void getTbBackendLib(char *dest);
int setTbBackendLib(char *newLibPath);


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* TBWIDGETS_H */















/*
     __________________________________________________
  
	]]]]]]
	]     ]   ]]]]   ]    ]   ]   ]   ]]]]   ]]]]]]  ]    ]
	]     ]  ]    ]   ]  ]     ] ]   ]    ]  ]       ]]   ]
	]     ]  ]    ]    ]]       ]    ]       ]]]]]   ] ]  ]
	]     ]  ]    ]    ]]       ]    ]  ]]]  ]       ]  ] ]
	]     ]  ]    ]   ]  ]      ]    ]    ]  ]       ]   ]]
	]]]]]]    ]]]]   ]    ]     ]     ]]]]   ]]]]]]  ]    ]
 */

/*! \file tbwidgets.h
 *  \brief The tbwidgets header file for C/C++
 */

/*! \mainpage
 * 
 * Welcome to the TbWidgets docs!
 * 
 * The functions are currently undocumented, but rather than documenting
 * all of the nearly-identical functions, here's an example to get you started.
 * (Allways remember to use the setter functions rather than setting properties directly.
 * This is so that object-oriented window managers can pass the data along to their
 * underlying graphical toolkits. \a TbIcon and callback functions are the only exceptions to this).
 * 
```
// Note that this example isn't actually tested since no WM's have implemented the spec so far
#include <tbwidgets.h>
#include <stdio.h>
// gcc -o test test.c -ltbw

void share(){
	puts("Shared!"); // lie to user
}

int main(){
	// [Make X11 window named "win"...]
	
	Tb_t *tb = getWindowTb(TbXLibWindow, &win, false);
	
	TbButton_t *shareBtn = newTbButton(tb);
	
	TbLabel_t *shareBtnLabel = newTbLabel(NULL);
	TbLabel_setText(shareBtnLabel, "Share");
	TbButton_setLabel(shareBtn, shareBtnLabel);
	
	TbIcon_t *shareBtnIcon = newTbIcon(NULL);
	shareBtnIcon->source = TbCharIconSource;
	shareBtnIcon->path = "❤️";
	TbIcon_load(shareBtnIcon);
	TbButton_setIcon(shareBtnIcon);
	
	shareBtn->onClick = &share;
	
	// [...start X11 event loop]
}
```
 * 
 * For the full documentation, see tbwidgets.h.
 * 
 * <hr>
 * For WM developers: to implement a backend for the API, all you need to do
 * is create functions for each of the ones in the API (with the
 * same names), and call ```setTbBackendLib("/full/path/to/wm.elf")``` while initializing the WM.
 * "setTbBackendLib" will only work if all API functions have been implemented (empty functions could work as long as they return the right type).
 * 
 * An example implementation based off of FLWM is planned. It's called "FLTB" in the examples folder, but it's currently incomplete.
 */


/*! \enum TbWidget
 *  \brief An enum for storing a TbWidget's type
 *
 *  \var TbWidget::Tb
 *  \var TbWidget::TbSpacer
 *  \var TbWidget::TbSeparator
 *  \var TbWidget::TbLabel
 *  \var TbWidget::TbIcon
 *  \var TbWidget::TbButton
 *  \var TbWidget::TbIconButton
 *  \var TbWidget::TbCheckBox
 *  \var TbWidget::TbTextInput
 *  \var TbWidget::TbSlider
 *  \var TbWidget::TbComboBox
 *  \var TbWidget::TbListView
 *  \var TbWidget::TbButtonGroup
 *  \var TbWidget::TbMenu
 */


/*! \struct TbSpacer
 *  \brief An empty widget for managing layout
 */

/*! \struct TbSeparator
 *  \brief A vertical separator
 * 
 *  \var TbSeparator::full 
 *  \brief Should the separator take the full height of the titlebar?
 *  \var TbSeparator::dashed
 *  \brief Is the separator a dashed (or possibly dotted) line?
 */

/*! \struct TbLabel
 *  \brief A text display widget
 * 
 *  \var TbLabel::text 
 *  \brief The text to display
 *  \var TbLabel::italic 
 *  \brief *italic?*
 *  \var TbLabel::bold
 *  \brief **bold?**
 *  \var TbLabel::underlined
 *  \brief <u>underlined</u>?
 *  \var TbLabel::strikethrough
 *  \brief ~~strikethrough?~~
 */

/*! \enum TbIconSource
 *  \brief How to process an icon's \a path
 * 
 *  \var TbIconSource::TbXdgIconSource
 *  \brief An icon from the user's icon theme.
 *  \var TbIconSource::TbUrlIconSource
 *  \brief The path to an icon on the hard disk (NO INTERNET URLS!!!)
 *  \var TbIconSource::TbCharIconSource
 *  \brief A Unicode character such as an emoji or symbol. ❤️
 */

/*! \struct TbIcon
 *  \brief An icon/image
 * 
 *  \var TbIcon::path
 *  \brief The icon to load
 *  \var TbIcon::source
 *  \brief How to process \a path
 */

/*! \struct TbButton
 *  \brief A button
 * 
 *  \var TbButton::label
 *  \brief The text on the button
 *  \var TbButton::icon
 *  \brief The icon for the button, if any
 *  \var TbButton::disabled
 *  \brief If true, the button will ignore input
 *  \var TbButton::link
 *  \brief If true, the button will look like a browser link
 *  \var TbButton::toggle
 *  \brief If true, the button is toggled on/off when clicked
 *  \var TbButton::toggled
 *  \brief If true, the button is a toggled toggle (haha!). if \a toggle is false, this will allways be false
 *  \var TbButton::iconOnTheRight
 *  \brief What side of the label should the icon be on? (the default value is controlled by the WM)
 *  \var TbButton::onClick
 *  \brief Pointer to clicked/toggled callback function.
 */

/*! \struct TbIconButton
 *  \brief An Icon-only button, which may look exactly like TbButton depending on the window manager
 * 
 *  \var TbIconButton::icon
 *  \brief The icon for the button, if any
 *  \var TbIconButton::disabled
 *  \brief If true, the button will ignore input
 *  \var TbIconButton::toggle
 *  \brief If true, the button is toggled on/off when clicked
 *  \var TbIconButton::toggled
 *  \brief If true, the button is a toggled toggle (haha!). if \a toggle is false, this will allways be false
 *  \var TbIconButton::onClick
 *  \brief Pointer to clicked/toggled callback function.
 */

/*! \struct TbCheckBox
 *  \brief A checkbox or switch
 * 
 *  \var TbCheckBox::label
 *  \brief The label for the checkbox, if any
 *  \var TbCheckBox::disabled
 *  \brief If true, the checkbox will ignore input
 *  \var TbCheckBox::checked
 *  \brief The toggle state of the checkbox
 *  \var TbCheckBox::onClick
 *  \brief Pointer to checked/unchecked callback function.
 */

/*! \struct TbTextInput
 *  \brief A widget for getting text input
 * 
 *  \var TbTextInput::text
 *  \brief The text contained by the input
 *  \var TbTextInput::warning
 *  \brief A warning or error text, where NULL or "" means no error. eg: "Password must not contain spaces".
 *  \var TbTextInput::disabled
 *  \brief If true, the input will not take input or be selectible
 *  \var TbTextInput::password
 *  \brief If true, the WM will treat \a text as confidential material, and will typically replace all characters with "*".
 *  \var TbTextInput::locked
 *  \brief If true, the input is placed in a read-only state. This is similar to disabled, but it will appear enabled and still be selectible.
 *  \var TbTextInput::resizable
 *  \brief If true, the window manager will allow the user to resize the input (usually through a <a href="https://www.computerhope.com/jargon/s/sizehand.gif">sizegrip</a> or draggable right edge)
 *  \var TbTextInput::textChanged
 *  \brief A function to be called when \a text changes, either by the user or through TbTextInput_setText().
 */

/*! \struct TbSlider
 *  \brief A horizontal slider widget
 * 
 *  \var TbSlider::val
 *  \brief The slider's value between \a min and \a max.
 *  \var TbSlider::min
 *  \brief Minimum value of the slider. This has no effect on \a width.
 *  \var TbSlider::max
 *  \brief Maximum value of the slider. This has no effect on \a width.
 *  \var TbSlider::stops
 *  \brief The amount of evenly-spaced dashes on the slider.
 *  
 * By default there are zero stops. If there is 1 stop, it is placed at 0, or as close to 0 as possible. For example, if \a min is -1 and \a max = 1, the dash is placed in the middle. If there is more than one dash, 1 is placed at \a min, one is placed at \a max, and the rest are placed evenly in between.
 * 
 *  \var TbSlider::disabled
 *  \brief If true, the slider recieves no input.
 *  \var TbSlider::onValChanged
 *  \brief The callback to \a val changing.
 */

/*! \struct TbComboBox
 *  \brief A list of options that users can choose from. (aka a dropdown menu)
 * 
 *  \var TbComboBox::items
 *  \brief The list of buttons that the user can choose from
 *  \var TbComboBox::itemCount
 *  \brief The amount of items in \a items
 *  \var TbComboBox::val
 *  \brief The index of the currently selected item (starting at 0)
 *  \var TbComboBox::disabled
 *  \brief If true, the combo box recieves no input.
 *  \var TbComboBox::onValChanged
 *  \brief The callback to \a val changing.
 */

/*! \struct TbListView
 *  \brief A list of closely-packed buttons where only 1 can be selected. Can act as a tabbar.
 * 
 *  \var TbListView::items
 *  \brief The list of buttons that the user can choose from
 *  \var TbListView::itemCount
 *  \brief The amount of items in \a items
 *  \var TbListView::val
 *  \brief The index of the currently selected item (starting at 0)
 *  \var TbListView::disabled
 *  \brief If true, the combo box recieves no input.
 *  \var TbListView::onValChanged
 *  \brief The callback to \a val changing.
 */

/*! \struct TbButtonGroup
 *  \brief A list of closely-packed buttons.
 * 
 *  \var TbButtonGroup::items
 *  \brief The list of buttons that the user can choose from
 *  \var TbButtonGroup::itemCount
 *  \brief The amount of items in \a items
 *  \var TbButtonGroup::disabled
 *  \brief If true, the combo box recieves no input.
 *  \var TbButtonGroup::onValChanged
 *  \brief The callback to \a val changing.
 */

/*! \struct TbMenu
 *  \brief A menu
 * 
 *  \var TbMenu::items
 *  \brief The list of buttons that will act as menu actions. Buttons with \a toggle set to true are checkable menu items.
 *  \var TbMenu::itemCount
 *  \brief The amount of items in \a items
 *  \var TbMenu::disabled
 *  \brief If true, the menu recieves no input (or, at the WM's choice, it can be opened but it's items are all disabled)
 */
