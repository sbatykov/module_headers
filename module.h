/* 
 * File:   module.h
 * Author: m79lol
 *
 */

#ifndef MODULE_H
#define	MODULE_H

typedef unsigned int regnum;
typedef int regval;

struct FunctionData {
    regval command_index;
    regval count_params;
    bool give_exception;
    char *name;
    FunctionData() : 
        command_index(0), count_params(0), give_exception(false), name(NULL) {}
    FunctionData(regval command_index, regval count_params, bool give_exception, char *name) : 
        command_index(command_index), count_params(count_params), give_exception(give_exception), name(name) {}
};

struct AxisData {
    regval axis_index;
    regval upper_value;
    regval lower_value;
    char *name;
    AxisData() : 
        axis_index(0), upper_value(0), lower_value(0), name(NULL) {}
    AxisData(regval axis_index, regval upper_value, regval lower_value, char *name) : 
        axis_index(axis_index), upper_value(upper_value), lower_value(lower_value), name(name) {}
};

class FunctionResult {
    public:
        char type;
        regval result;
        FunctionResult(char type) : 
            type(type) {}
        FunctionResult(char type, regval result) : 
            type(type), result(result) {}
        virtual void destroy() {
            delete this;
        }
};

#endif	/* MODULE_H */

