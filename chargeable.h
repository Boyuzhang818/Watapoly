#ifndef _CHARGEABLE_H_
#define _CHARGEABLE_H_

#include "building.h"

class Player;

class Chargeable : public Building {
    
  protected:
  int purchase;
  std::shared_ptr<Player> owner;
  bool mortgaged;
  
  public:
  Chargeable( std::string name, int purchase, bool mortgaged );
  virtual ~Chargeable() = 0;
  virtual void mortgage() = 0;
  virtual void unmortgage() = 0;
  virtual int getPurchase() = 0;
  virtual void setOwner( std::shared_ptr<Player> ) = 0;
  virtual std::shared_ptr<Player> getOwner() = 0;
  virtual bool getMortgage() = 0;
  virtual int charge() = 0;
  
};

#endif


