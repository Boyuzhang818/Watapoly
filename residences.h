#ifndef _RESIDENCES_H_
#define _RESIDENCES_H_

#include "chargeable.h"

class Residences : public Chargeable {
    
    public:
    Residences(  std::string name, int purchase,  bool mortgaged );
    ~Residences();
    virtual std::string getName() override;
    virtual void mortgage() override;
    virtual void unmortgage() override;
    virtual int getPurchase() override;
    virtual std::shared_ptr<Player> getOwner() override;
    virtual bool getMortgage() override;
    virtual int charge() override;
    virtual void setOwner(std::shared_ptr<Player>) override;
};

#endif


