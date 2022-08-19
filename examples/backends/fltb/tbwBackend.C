#include "tbwBackend.H"
#include <FL/x.H>

extern "C" {
#include <stdio.h>
}

unsigned int frameCount;
Frame **frames;


Tb_t *getWindowTb(enum TbWindowType winType, void *win, bool empty){
	if(winType != TbXLibWindow){
		eprintf("getWindowTb: FLTB doesn't support XCB or Wayland clients yet.\n");
		free(tb);
		return nullptr;
	}
	
	unsigned int i = 0;
	while(*(Window*)win != frames[i]->window() && i < frameCount) i++;
	if(i == frameCount){
		eprintf("getWindowTb: Provided XLib Window not found.\n");
		free(tb);
		return nullptr;
	}
	
	Tb_t *tb = frames[i]->getTb();
	if(tb == nullptr){ // if this frame has no titlebar object, make one
		tb = malloc(sizeof(tb));
		
		tb->raw = frames[i];
		tb->width = frames[i]->w();
		
		frame[i]->setTb(tb);
	}
	return tb;
}

