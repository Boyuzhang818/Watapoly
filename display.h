#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <vector>
#include <string>
#include "observer.h"

class Display: public Observer {
    std::vector<std::string> theDisplay;

 public:
    Display();
    virtual void notify( std::shared_ptr<Subject> /*Subject */ whoNotified ) override;
    virtual void notify() override;

    friend std::ostream &operator<<(std::ostream &out, const Display &td);
};

std::ostream &operator<<(std::ostream &out, const Display &td);

#endif


