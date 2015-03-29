/* 
 * File:   module.h
 * Author: m79lol
 *
 */

#ifndef MODULE_H
#define	MODULE_H

typedef int system_value;
typedef double variable_value;

struct FunctionData {
    system_value command_index;
    unsigned int count_params;
    bool give_exception;
    const char *name;
    FunctionData() : 
        command_index(0), count_params(0), give_exception(false), name(NULL) {}
    FunctionData(system_value command_index, unsigned int count_params, bool give_exception, const char *name) : 
        command_index(command_index), count_params(count_params), give_exception(give_exception), name(name) {}
};

struct AxisData {
    system_value axis_index;
    variable_value upper_value;
    variable_value lower_value;
    const char *name;
    AxisData() : 
        axis_index(0), upper_value(0), lower_value(0), name(NULL) {}
    AxisData(system_value axis_index, variable_value upper_value, variable_value lower_value, const char *name) : 
        axis_index(axis_index), upper_value(upper_value), lower_value(lower_value), name(name) {}
};

class FunctionResult {
    public:
        char type;
        variable_value result;
        FunctionResult(char type) : 
            type(type) {}
        FunctionResult(char type, variable_value result) : 
            type(type), result(result) {}
        void destroy() {
            delete this;
        }
};

struct ConsoleColor {
    enum colors {
        black = 0,
        dark_blue = 1,
        dark_green = 2,
        dark_aqua = 3,
        dark_red = 4,
        dark_purple = 5,
        dark_yellow = 6,
        dark_white = 7,
        gray = 8,
        blue = 9,
        green = 10,
        aqua = 11,
        red = 12,
        purple = 13,
        yellow = 14,
        white = 15
    };
    
    colors color_text;
    colors color_back;
    ConsoleColor() : color_text(ConsoleColor::white), color_back(ConsoleColor::black) {};
    ConsoleColor(colors color_text) : color_text(color_text), color_back(ConsoleColor::black) {};
    ConsoleColor(colors color_text, colors color_back) : color_text(color_text), color_back(color_back) {};
};

typedef void (colorPrintf_t)(void *, ConsoleColor, const char *, ...);
typedef void (colorPrintfVA_t)(void *, ConsoleColor, const char *, va_list);

#endif	/* MODULE_H */

