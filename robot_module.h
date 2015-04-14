/* 
 * File:   robots.h
 * Author: m79lol
 *
 */

#ifndef ROBOT_MODULE_H
#define	ROBOT_MODULE_H

#define ROBOT_COMMAND_FREE 0
#define ROBOT_COMMAND_HAND_CONTROL_BEGIN -1
#define ROBOT_COMMAND_HAND_CONTROL_END -2

class Robot {
    protected:
        Robot() {}
    public: 
        virtual FunctionResult* executeFunction(system_value command_index, void **args) = 0;
        virtual void axisControl(system_value axis_index, variable_value value) = 0;
        virtual ~Robot() {}
};

class RobotModule {
    protected:
        RobotModule() {}
    public: 
        virtual const char *getUID() = 0;
        virtual void prepare(colorPrintf_t *colorPrintf_p, colorPrintfVA_t *colorPrintfVA_p) = 0;
        virtual int init() = 0;
        virtual FunctionData** getFunctions(unsigned int *count_functions) = 0;
        virtual AxisData** getAxis(unsigned int *count_axis) = 0;
        virtual Robot* robotRequire() = 0;
        virtual void robotFree(Robot *robot) = 0;
        virtual void final() = 0;
        virtual void destroy() = 0;
        virtual ~RobotModule() {}
};

typedef RobotModule* (*getRobotModuleObject_t)();
extern "C" {
    __declspec(dllexport) RobotModule* getRobotModuleObject();
}

#endif	/* ROBOT_MODULE_H */

