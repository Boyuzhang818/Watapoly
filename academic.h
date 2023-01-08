#ifndef _ACADEMIC_H_
#define _ACADEMIC_H_

#include "chargeable.h"

class Academic : public Chargeable {
    std::string block;
    int improvements;
    int improveCost;
    std::vector<int> tuition;
    
    
    
    
    public:
    Academic( std::string name, int purchase,  
        bool mortgaged, std::string block, int improvements, int improveCost, std::vector<int> tuition );
    
    ~Academic();
    std::string getBlock();
    int getImprovements();
    int getImproveCost();
    std::vector<int> getTuition();
    void incImprovements();
    void setCurBuilding ( int newBuilding );
    void decImprovements();
    virtual std::string getName() override;
    virtual void mortgage() override;
    virtual void unmortgage() override;
    virtual int getPurchase() override;
    virtual std::shared_ptr<Player> getOwner() override;
    virtual bool getMortgage() override;
    virtual int charge() override;
    virtual void setOwner(std::shared_ptr<Player> p) override;
    bool isArts1Mono();
    bool isArts2Mono();
    bool isEngMono();
    bool isHealthMono();
    bool isEnvMono();
    bool isSci1Mono();
    bool isSci2Mono();
    bool isMathMono();
};

#endif

