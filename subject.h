#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>
#include "dice.h"


class Observer;

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;

  public:
    virtual ~Subject() = 0;
    void attach(std::shared_ptr<Observer> o);
    void notifyObservers();
    void detach(std::shared_ptr<Observer> o);

};

#endif


