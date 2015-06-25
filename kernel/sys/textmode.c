#include <textmode.h>
#include <string.h>

void textmode_init(size_t width, size_t height) {
    tab_size = 2;
    buffer = (uint16_t *) 0xB8000;
    kputcolor(lightGrey,black);
    width = width;
    height = height;
    set_pos(0,0);
    textmode_clear();
};

void textmode_clear() {
    for ( size_t y = 0; y < height; y++ )
	{
		for ( size_t x = 0; x < width; x++ )
		{
			const size_t index = y * width + x;
			buffer[index] = vga_entry(' ', color);
		}
	}
};

void kprintf(const char* str, ...) {
    va_list va;
	va_start(va,str);
	kprintf_va(str,va);
	va_end(va);
};

void kprintf_va(const char* str, va_list va) {
    char buf[33];

    while(*str)  {
        if(*str == '%') {
            str++;
            switch(*str) {
                case 'c':
                    kputc(va_arg(va,int));
                    break;
                case 's' :
                    kputs(va_arg(va,const char*));
                    break;
                case 'b':
                    kputs(itoa(va_arg(va,unsigned int),buf,2));
                    break;
                case 'd':
                    kputs(itoa(va_arg(va,unsigned int),buf,10));
                    break;
                case 'u':
                    kputs(uitoa(va_arg(va,unsigned int),buf,10));
                    break;
                case 'x':
                    kputs(itoa(va_arg(va,unsigned int),buf,16));
                    break;
                default:
                    kputc('?');
        }
    } else {
        kputc(*str);
    }
    str++;
}
};

void kputc(char c) {
    switch(c) {  //Handle special cases.
		case '\n':
			set_pos(0,row+1);
			break;
		case '\r':
			set_pos(0,row);
			break;
		case '\b':
			set_pos(column-1,row);
			break;
		case '\t':
			set_pos(column+tab_size,row);
			break;
		default:
			vga_entry(c,color);
			set_pos(column+1,row);
			break;
	}

	if(column > width - 1) {
		set_pos(0,row+1);
	}
	if(row > height -1) {
		memmove(buffer,buffer+width,(height-1)*width*2);
		for(size_t i = 0; i < width; i++) {
			buffer[(row-1)*width+i] = vga_entry(' ', color);
		}
		set_pos(0,row-1);
	}
};

void kputs(const char* str) {
    while(*str) {
		kputc(*(str++));
	}
};

void kputcolor (enum colors fg, enum colors bg) {
    color = fg | bg << 4;
};

uint16_t vga_entry (char c, uint8_t color) {
    int16_t c16 = c; //Char to 16 bits
	uint16_t color16 = color; //Color to 16 bits
	return c16 | color16 << 8;
};

void set_pos(size_t c, size_t r) {
    column = c;
    row = r;
};
