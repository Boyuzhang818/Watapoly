#include "subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> o) { observers.emplace_back(o); }

void Subject::detach(std::shared_ptr<Observer> o) {
    for ( auto it = observers.begin(); it != observers.end(); ++it ) {
        if ( *it == o ) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers() {
    std::shared_ptr<Subject> s(this);
    for (auto &ob : observers) ob->notify( s );
}

Subject::~Subject() {}



