/* 
 * File:   function_module.h
 * Author: m79lol
 *
 */

#ifndef CONTROL_MODULE_H
#define	CONTROL_MODULE_H
typedef void (*sendAxisState_t)(regval, regval);

class ControlModule {
    protected:
        ControlModule() {}
    public: 
        virtual int init() = 0;
        virtual AxisData* getAxis(int *count_functions) = 0;
        virtual void execute(sendAxisState_t sendAxisState) = 0;
        virtual void final() = 0;
        virtual void destroy() = 0;
        virtual ~ControlModule() {}
};
typedef ControlModule* (*getControlModuleObject_t)();


#endif	/* CONTROL_MODULE_H */

