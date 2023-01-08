#include "display.h"
#include "player.h"
#include "building.h"
#include "academic.h"
#include <iostream>

Display::Display() {
    std::string row1  = "____________________________________________________________________________________________________";
    std::string row2  = "|Goose   |        |NEEDLES |        |        |V1      |        |        |CIF     |        |GO TO   |";
    std::string row3  = "|Nesting |--------|HALL2   |--------|--------|        |--------|--------|        |--------|TIMS    |";
    std::string row4  = "|        |EV1     |        |EV2     |EV3     |        |PHYS    |B1      |        |B2      |        |";
    std::string row5  = "|        |        |        |        |        |        |        |        |        |        |        |";
    std::string row6  = "|        |        |        |        |        |        |        |        |        |        |        |";
    std::string row7  = "|________|________|________|________|________|________|________|________|________|________|________|";
    std::string row8  = "|        |                                                                                |        |";
    std::string row9  = "|--------|                                                                                |--------|";
    std::string row10 = "|OPT     |                                                                                |EIT     |";
    std::string row11 = "|        |                                                                                |        |";
    std::string row12 = "|        |                                                                                |        |";
    std::string row13 = "|________|                                                                                |________|";
    std::string row14 = "|        |                                                                                |        |";
    std::string row15 = "|--------|                                                                                |--------|";
    std::string row16 = "|BMH     |                                                                                |ESC     |";
    std::string row17 = "|        |                                                                                |        |";
    std::string row18 = "|        |                                                                                |        |";
    std::string row19 = "|________|                                                                                |________|";
    std::string row20 = "|SLC2    |                                                                                |SLC3    |";
    std::string row21 = "|        |                                                                                |        |";
    std::string row22 = "|        |                                                                                |        |";
    std::string row23 = "|        |                                                                                |        |";
    std::string row24 = "|        |                                                                                |        |";
    std::string row25 = "|________|                                                                                |________|";
    std::string row26 = "|        |                                                                                |        |";
    std::string row27 = "|--------|                                                                                |--------|";
    std::string row28 = "|LHI     |                                                                                |C2      |";
    std::string row29 = "|        |                                                                                |        |";
    std::string row30 = "|        |                  _____________________________________________                 |        |";
    std::string row31 = "|________|                 |                                             |                |________|";
    std::string row32 = "|UWP     |                 | #   #  ##  #####  ###  ###   ###  #   #   # |                |REV     |";
    std::string row33 = "|        |                 | #   # #  #   #   #   # #  # #   # #   #   # |                |        |";
    std::string row34 = "|        |                 | # # # ####   #   #   # ###  #   # #    # #  |                |        |";
    std::string row35 = "|        |                 | # # # #  #   #   #   # #    #   # #     #   |                |        |";
    std::string row36 = "|________|                 | ##### #  #   #    ###  #     ###  ####  #   |                |________|";
    std::string row37 = "|        |                 |_____________________________________________|                |NEEDLES |";
    std::string row38 = "|--------|                                                                                |HALL3   |";
    std::string row39 = "|CPH     |                                                                                |        |";
    std::string row40 = "|        |                                                                                |        |";
    std::string row41 = "|        |                                                                                |        |";
    std::string row42 = "|________|                                                                                |________|";
    std::string row43 = "|        |                                                                                |        |";
    std::string row44 = "|--------|                                                                                |--------|";
    std::string row45 = "|DWE     |                                                                                |MC      |";
    std::string row46 = "|        |                                                                                |        |";
    std::string row47 = "|        |                                                                                |        |";
    std::string row48 = "|________|                                                                                |________|";
    std::string row49 = "|PAC     |                                                                                |COOP    |";
    std::string row50 = "|        |                                                                                |FEE     |";
    std::string row51 = "|        |                                                                                |        |";
    std::string row52 = "|        |                                                                                |        |";
    std::string row53 = "|        |                                                                                |        |";
    std::string row54 = "|________|                                                                                |________|";
    std::string row55 = "|        |                                                                                |        |";
    std::string row56 = "|--------|                                                                                |--------|";
    std::string row57 = "|RCH     |                                                                                |DC      |";
    std::string row58 = "|        |                                                                                |        |";
    std::string row59 = "|        |                                                                                |        |";
    std::string row60 = "|________|________________________________________________________________________________|________|";
    std::string row61 = "|DC Tims |        |        |NEEDLES |        |MKV     |Tuition |        |SLC1    |        |COLLECT |";
    std::string row62 = "|Line    |--------|--------|HALL1   |--------|        |        |--------|        |--------|OSAP    |";
    std::string row63 = "|        |HH      |PAS     |        |ECH     |        |        |ML      |        |AL      |        |";
    std::string row64 = "|        |        |        |        |        |        |        |        |        |        |        |";
    std::string row65 = "|        |        |        |        |        |        |        |        |        |        |        |";
    std::string row66 = "|________|________|________|________|________|________|________|________|________|________|________|";
    
    theDisplay.emplace_back(row1);
    theDisplay.emplace_back(row2);
    theDisplay.emplace_back(row3);
    theDisplay.emplace_back(row4);
    theDisplay.emplace_back(row5);
    theDisplay.emplace_back(row6);
    theDisplay.emplace_back(row7);
    theDisplay.emplace_back(row8);
    theDisplay.emplace_back(row9);
    theDisplay.emplace_back(row10);
    theDisplay.emplace_back(row11);
    theDisplay.emplace_back(row12);
    theDisplay.emplace_back(row13);
    theDisplay.emplace_back(row14);
    theDisplay.emplace_back(row15);
    theDisplay.emplace_back(row16);
    theDisplay.emplace_back(row17);
    theDisplay.emplace_back(row18);
    theDisplay.emplace_back(row19);
    theDisplay.emplace_back(row20);
    theDisplay.emplace_back(row21);
    theDisplay.emplace_back(row22);
    theDisplay.emplace_back(row23);
    theDisplay.emplace_back(row24);
    theDisplay.emplace_back(row25);
    theDisplay.emplace_back(row26);
    theDisplay.emplace_back(row27);
    theDisplay.emplace_back(row28);
    theDisplay.emplace_back(row29);
    theDisplay.emplace_back(row30);
    theDisplay.emplace_back(row31);
    theDisplay.emplace_back(row32);
    theDisplay.emplace_back(row33);
    theDisplay.emplace_back(row34);
    theDisplay.emplace_back(row35);
    theDisplay.emplace_back(row36);
    theDisplay.emplace_back(row37);
    theDisplay.emplace_back(row38);
    theDisplay.emplace_back(row39);
    theDisplay.emplace_back(row40);
    theDisplay.emplace_back(row41);
    theDisplay.emplace_back(row42);
    theDisplay.emplace_back(row43);
    theDisplay.emplace_back(row44);
    theDisplay.emplace_back(row45);
    theDisplay.emplace_back(row46);
    theDisplay.emplace_back(row47);
    theDisplay.emplace_back(row48);
    theDisplay.emplace_back(row49);
    theDisplay.emplace_back(row50);
    theDisplay.emplace_back(row51);
    theDisplay.emplace_back(row52);
    theDisplay.emplace_back(row53);
    theDisplay.emplace_back(row54);
    theDisplay.emplace_back(row55);
    theDisplay.emplace_back(row56);
    theDisplay.emplace_back(row57);
    theDisplay.emplace_back(row58);
    theDisplay.emplace_back(row59);
    theDisplay.emplace_back(row60);
    theDisplay.emplace_back(row61);
    theDisplay.emplace_back(row62);
    theDisplay.emplace_back(row63);
    theDisplay.emplace_back(row64);
    theDisplay.emplace_back(row65);
    theDisplay.emplace_back(row66);


}

void Display::notify( std::shared_ptr<Subject>  whoNotified ) {
    auto b = std::dynamic_pointer_cast<Building>(whoNotified);
    std::string name = b->getName();
    auto curPlayers = b->getCurPlayers();
    int numCurPlayers = curPlayers.size();
    
    
    if (name ==  "COLLECT OSAP" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
                theDisplay.at(64)[91+i] = curPlayers.at(i)->getChar();
                if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[91+j] = ' ';
                    }
            }
        }
    }
    
    if (name ==  "AL" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[82+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[82+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[82+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                theDisplay.at(60)[82 + i] = 'I';
                if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(60)[82+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(60)[82+j] = ' ';
            }
        }
    }
    
    if (name ==  "SLC1" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[73+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[73+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[73+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "ML" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[64+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[64+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[64+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(60)[64+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(60)[64+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(60)[64+j] = ' ';
            }
        }
    }
    
    if (name ==  "TUITION" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[55+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
        theDisplay.at(64)[55+i] = curPlayers.at(i)->getChar();
        if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[55+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "MKV" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[46+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[46+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[46+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "ECH" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[37+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[37+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[37+j] = ' ';
                    }
            }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(60)[37+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(60)[37+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(60)[37+j] = ' ';
            }
        }
    }
    
    if (name ==  "NEEDLES HALL1" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[28+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[28+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[28+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "PAS" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[19+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[19+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[19+j] = ' ';
                    }
            }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(60)[19+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(60)[19+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(60)[19+j] = ' ';
            }
        }
    }
    
    if ( name ==  "HH" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[10+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[10+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[10+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(60)[10+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(60)[10+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(60)[10+j] = ' ';
            }
        }
    }
    
    if (name ==  "DC Tims Line" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(64)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(64)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(64)[1+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "RCH" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(58)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(58)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(58)[1+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                theDisplay.at(54)[1+i] = 'I';
                if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(54)[1+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(54)[1+j] = ' ';
            }
        }
    }
    
    if (name ==  "PAC" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(52)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(52)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(52)[1+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "DWE" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(46)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(46)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(46)[1+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(42)[1+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(42)[1+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(42)[1+j] = ' ';
            }
        }
    }
    
    if ( name ==  "CPH" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(40)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(40)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(40)[1+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(36)[1+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(36)[1+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(36)[j+1] = ' ';
            }
        }
    }
    
    if (name ==  "UWP" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(34)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(34)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(34)[1+j] = ' ';
                    }
            }
        }
    }
    
    if ( name ==  "LHI" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(29)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(29)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(29)[1+j] = ' ';
                }
            }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                theDisplay.at(25)[1+i] = 'I';
                if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(25)[1+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(25)[1+j] = ' ';
            }
        }
    }
    
    if (name ==  "SLC2" ) {
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(23)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(23)[1+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "BMH" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(17)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(17)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(17)[1+j] = ' ';
                    }
            }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(13)[i+1] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(13)[1+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(13)[j+1] = ' ';
            }
        }
    }
    
    if ( name ==  "OPT" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(11)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(11)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(11)[1+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(7)[1+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(7)[1+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(7)[1+j] = ' ';
            }
        }
    }
    
    if (name ==  "Goose Nesting" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[1+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[1+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[1+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "EIT" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(11)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(11)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(11)[91+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(7)[91+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(7)[91+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 91; j < 4; j++ ) {
                theDisplay.at(7)[91+j] = ' ';
            }
        }
    }
    
    if ( name ==  "ESC" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(17)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(17)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(17)[91+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(13)[91+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(13)[91+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(13)[91+j] = ' ';
            }
        }
    }
    
    if (name ==  "SLC3" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(23)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(23)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(23)[91+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "C2" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(29)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(29)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(29)[91+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(25)[91+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(25)[91+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(25)[91+j] = ' ';
            }
        }
    }
    
    if (name ==  "REV" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(34)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(34)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(34)[91+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "NEEDLES HALL3" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(40)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(40)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(40)[91+j] = ' ';
                    }
                }
        }
    }
    
    if ( name ==  "MC" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(46)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(46)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(46)[91+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(42)[91+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(42)[91+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(42)[91+j] = ' ';
            }
        }
    }
    
    if (name ==  "COOP FEE" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(52)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(52)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(52)[91+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "EV1" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[10+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[10+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[10+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(1)[10+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(1)[10+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(1)[10+j] = ' ';
            }
        }
    }
    
    if (name ==  "NEEDLES HALL2" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[19+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[19+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[19+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "EV2" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[28+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[28+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[28+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(1)[28+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(1)[28+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(1)[28+j] = ' ';
            }
        }
    }
    
    if (name ==  "EV3" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[37+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[37+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[37+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(1)[i+37] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(1)[37+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(1)[j+37] = ' ';
            }
        }
    }
    
    if (name ==  "V1" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[46+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[46+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[46+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "PHYS" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[55+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[55+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[55+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(1)[55+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(1)[55+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(1)[55+j] = ' ';
            }
        }
    }
    
    if (name ==  "B1" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[64+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[64+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[64+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(1)[64+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(1)[64+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(1)[64+j] = ' ';
            }
        }
    }
    
    if (name ==  "CIF" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[73+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[73+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[73+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "B2" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[82+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[82+i] = curPlayers.at(i)->getChar(); 
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[82+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(1)[82+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(1)[82+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(1)[82+j] = ' ';
            }
        }
    }
    
    if (name ==  "Go To Tims" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(5)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(5)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(5)[91+j] = ' ';
                    }
                }
        }
    }
    
    if (name ==  "DC" ) {
        if ( numCurPlayers == 0 ) {
            for( int i = 0; i < 8; i++ ) {
                theDisplay.at(58)[91+i] = ' ';
            }
        }
        for( int i = 0; i < numCurPlayers; i++ ) {
            theDisplay.at(58)[91+i] = curPlayers.at(i)->getChar();
            if ( i == numCurPlayers - 1 ) {
                    for( int j = numCurPlayers; j < 8; j++ ) {
                        theDisplay.at(58)[91+j] = ' ';
                    }
                }
        }
        auto a = std::dynamic_pointer_cast<Academic>(whoNotified);
        int numImprovements = a->getImprovements();
        if ( numImprovements!= 0 ) {
            for( int i = 0; i < numImprovements; i++ ) {
                    theDisplay.at(54)[91+i] = 'I';
                    if ( i == numImprovements-1 ) {
                    for( int j = numImprovements; j < 8; j++ ) {
                        theDisplay.at(54)[91+j] = ' ';
                    }
                }
             }
        } else {
            for( int j = 0; j < 4; j++ ) {
                theDisplay.at(54)[91+j] = ' ';
            }
        }
    }

}

void Display::notify() {}

std::ostream &operator<<(std::ostream &out, const Display &td) {
    int n = td.theDisplay.size();
    for( int i = 0; i < n; i ++ ) {
        out << td.theDisplay.at(i) << '\n';
    }
    return out;
}
    
    

