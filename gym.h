#ifndef _GYM_H_
#define _GYM_H_

#include "chargeable.h"

class Player;

class Gym : public Chargeable {
    
    public:
    
    Gym(  std::string name, int purchase,  
        bool mortgaged );
    ~Gym();
    virtual std::string getName() override;
    virtual void mortgage() override;
    virtual void unmortgage() override;
    virtual int getPurchase() override;
    virtual std::shared_ptr<Player> getOwner() override;
    virtual void setOwner( std::shared_ptr<Player> ) override;
    virtual bool getMortgage() override;

    virtual int charge() override;
};

#endif
