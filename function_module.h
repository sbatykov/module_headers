/* 
 * File:   function_module.h
 * Author: m79lol
 *
 */

#ifndef FUNCTION_MODULE_H
#define	FUNCTION_MODULE_H

class FunctionModule {
    protected:
        FunctionModule() {}
    public: 
        virtual FunctionData* getFunctions(int *count_functions) = 0;
        virtual FunctionResult* executeFunction(regval functionId, regval *args) = 0;
        virtual void destroy() = 0;
        virtual ~FunctionModule() {}
};
typedef FunctionModule* (*getFunctionModuleObject_t)();

#endif	/* FUNCTION_MODULE_H */

