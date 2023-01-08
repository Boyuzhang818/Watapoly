#include "chargeable.h"
#include "gym.h"
#include "residences.h"
#include "osap.h"
#include "academic.h"
#include "coop.h"
#include "dc.h"
#include "dice.h"
#include "goTims.h"
#include "goose.h"
#include "needles.h"
#include "slc.h"
#include "tuition.h"
#include "player.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "board.h"

int main(int argc, char * argv[]) {
    Dice d2 = Dice();
    //Initialization
    std::ifstream infile;
    bool testMode = false;
    auto board = Board();
    
    auto osap = std::make_shared<OSAP>();
    auto b = std::dynamic_pointer_cast<Building>(osap);
    board.addBuilding(b);
    
    std::vector<int> tui{ 2, 10, 30, 90, 160, 250 };
    auto al = std::make_shared<Academic>( "AL", 40, false, "Arts1", 0, 50, tui );
    b = std::dynamic_pointer_cast<Building>(al);
    board.addBuilding(b);
    
    auto slc1 = std::make_shared<SLC>( "SLC1" );
    b = std::dynamic_pointer_cast<Building>(slc1);
    board.addBuilding(b);
    
    std::vector<int> tui1{ 4, 20, 60, 180, 320, 450 };
    auto ml = std::make_shared<Academic>( "ML", 60, false, "Arts1", 0, 50, tui1 );
    b = std::dynamic_pointer_cast<Building>(ml);
    board.addBuilding(b);
    
    auto tuition = std::make_shared<Tuition>();
    b = std::dynamic_pointer_cast<Building>(tuition);
    board.addBuilding(b);
    
    auto mkv = std::make_shared<Residences>( "MKV", 200, false );
    b = std::dynamic_pointer_cast<Building>(mkv);
    board.addBuilding(b);
    
    std::vector<int> tui2{ 6, 30, 90, 270, 400, 550 };
    auto ech = std::make_shared<Academic>( "ECH", 100, false, "Arts2", 0, 50, tui2 );
    b = std::dynamic_pointer_cast<Building>(ech);
    board.addBuilding(b);
    
    auto needles1 = std::make_shared<Needles>( "NEEDLES HALL1" );
    b = std::dynamic_pointer_cast<Building>(needles1);
    board.addBuilding(b);
    
    std::vector<int> tui3{ 6, 30, 90, 270, 400, 550 };
    auto pas = std::make_shared<Academic>( "PAS", 100, false, "Arts2", 0, 50, tui3 );
    b = std::dynamic_pointer_cast<Building>(pas);
    board.addBuilding(b);
    
    std::vector<int> tui4{ 8, 40, 100, 300, 450, 600 };
    auto hh = std::make_shared<Academic>( "HH", 120, false, "Arts2", 0, 50, tui4 );
    b = std::dynamic_pointer_cast<Building>(hh);
    board.addBuilding(b);
    
    auto DCline = std::make_shared<DC>();
    b = std::dynamic_pointer_cast<Building>(DCline);
    board.addBuilding(b);
    
    std::vector<int> tui5{ 10, 50, 150, 450, 625, 750 };
    auto rch = std::make_shared<Academic>( "RCH", 140, false, "Eng", 0, 100, tui5 );
    b = std::dynamic_pointer_cast<Building>(rch);
    board.addBuilding(b);
    
    auto pac = std::make_shared<Gym>( "PAC", 150, false );
    b = std::dynamic_pointer_cast<Building>(pac);
    board.addBuilding(b);
    
    std::vector<int> tui6{ 10, 50, 150, 450, 625, 750 };
    auto dwe = std::make_shared<Academic>( "DWE", 140, false, "Eng", 0, 100, tui6 );
    b = std::dynamic_pointer_cast<Building>(dwe);
    board.addBuilding(b);
    
    std::vector<int> tui7{ 12, 60, 180, 500, 700, 900 };
    auto cph = std::make_shared<Academic>( "CPH", 160, false, "Eng", 0, 100, tui7 );
    b = std::dynamic_pointer_cast<Building>(cph);
    board.addBuilding(b);
    
    auto uwp = std::make_shared<Residences>( "UWP", 200, false );
    b = std::dynamic_pointer_cast<Building>(uwp);
    board.addBuilding(b);
    
    std::vector<int> tui8{ 14, 70, 200, 550, 750, 950 };
    auto lhi = std::make_shared<Academic>( "LHI", 180, false, "Health", 0, 100, tui8 );
    b = std::dynamic_pointer_cast<Building>(lhi);
    board.addBuilding(b);
    
    auto slc2 = std::make_shared<SLC>( "SLC2" );
    b = std::dynamic_pointer_cast<Building>(slc2);
    board.addBuilding(b);
    
    std::vector<int> tui9{ 14, 70, 200, 550, 750, 950 };
    auto bmh = std::make_shared<Academic>( "BMH", 180, false, "Health", 0, 100, tui9 );
    b = std::dynamic_pointer_cast<Building>(bmh);
    board.addBuilding(b);
    
    std::vector<int> tui10{ 16, 80, 220, 600, 800, 1000 };
    auto opt = std::make_shared<Academic>( "OPT", 200, false, "Health", 0, 100, tui10 );
    b = std::dynamic_pointer_cast<Building>(opt);
    board.addBuilding(b);
    
    auto goose = std::make_shared<Goose>( );
    b = std::dynamic_pointer_cast<Building>(goose);
    board.addBuilding(b);
    
    std::vector<int> tui11{ 18, 90, 250, 700, 875, 1050 };
    auto ev1 = std::make_shared<Academic>( "EV1", 220, false, "Env", 0, 150, tui11 );
    b = std::dynamic_pointer_cast<Building>(ev1);
    board.addBuilding(b);
    
    auto needles2 = std::make_shared<Needles>( "NEEDLES HALL2" );
    b = std::dynamic_pointer_cast<Building>(needles2);
    board.addBuilding(b);
    
    std::vector<int> tui90{ 18, 90, 250, 700, 875, 1050 };
    auto ev2 = std::make_shared<Academic>( "EV2", 220, false, "Env", 0, 150, tui90);
    b = std::dynamic_pointer_cast<Building>(ev2);
    board.addBuilding(b);
    
    std::vector<int> tui91{ 20, 100, 300, 750, 925, 1100 };
    auto ev3 = std::make_shared<Academic>( "EV3", 240, false, "Env", 0, 150, tui91);
    b = std::dynamic_pointer_cast<Building>(ev3);
    board.addBuilding(b);
    
    auto v1 = std::make_shared<Residences>("V1", 200, false);
    b = std::dynamic_pointer_cast<Building>(v1);
    board.addBuilding(b);
    
    std::vector<int> tui92{ 22, 110, 330, 800, 975, 1150 };
    auto phys = std::make_shared<Academic>( "PHYS", 260, false, "Sci1", 0, 150, tui92);
    b = std::dynamic_pointer_cast<Building>(phys);
    board.addBuilding(b);
    
    std::vector<int> tui93{ 22, 110, 330, 800, 975, 1150 };
    auto b1 = std::make_shared<Academic>( "B1", 260, false, "Sci1", 0, 150, tui93);
    b = std::dynamic_pointer_cast<Building>(b1);
    board.addBuilding(b);
   
    auto cif = std::make_shared<Gym>("CIF", 150, false);
    b = std::dynamic_pointer_cast<Building>(cif);
    board.addBuilding(b);
    
    std::vector<int> tui94{ 24, 120, 360, 850, 1025, 1200 };
    auto b2 = std::make_shared<Academic>( "B2", 280, false, "Sci1", 0, 150, tui94);
    b = std::dynamic_pointer_cast<Building>(b2);
    board.addBuilding(b);
    
    auto gotims = std::make_shared<GoTims>();
    b = std::dynamic_pointer_cast<Building>(gotims);
    board.addBuilding(b);
    
    std::vector<int> tui95{ 26, 130, 390, 900, 1100, 1275 };
    auto eit = std::make_shared<Academic>( "EIT", 300, false, "Sci2", 0, 200, tui95);
    b = std::dynamic_pointer_cast<Building>(eit);
    board.addBuilding(b);
    
    std::vector<int> tui96{ 26, 130, 390, 900, 1100, 1275 };
    auto esc = std::make_shared<Academic>( "ESC", 300, false, "Sci2", 0, 200, tui96);
    b = std::dynamic_pointer_cast<Building>(esc);
    board.addBuilding(b);
    
    auto slc3 = std::make_shared<SLC>("SLC3");
    b = std::dynamic_pointer_cast<Building>(slc3);
    board.addBuilding(b);
    
    std::vector<int> tui97{ 28, 150,450 , 1000, 1200, 1400 };
    auto c2 = std::make_shared<Academic>( "C2", 320, false, "Sci2", 0, 200, tui97 );
    b = std::dynamic_pointer_cast<Building>(c2);
    board.addBuilding(b);
    
    auto rev = std::make_shared<Residences>("REV", 200, false);
    b = std::dynamic_pointer_cast<Building>(rev);
    board.addBuilding(b);
    
    auto needles3 = std::make_shared<Needles>("NEEDLES HALL3");
    b = std::dynamic_pointer_cast<Building>(needles3);
    board.addBuilding(b);
    
    std::vector<int> tui98{ 35, 175, 500, 1100, 1300, 1500 };
    auto mc = std::make_shared<Academic>( "MC", 350, false, "Math", 0, 200, tui98 );
    b = std::dynamic_pointer_cast<Building>(mc);
    board.addBuilding(b);
    
    auto coop = std::make_shared<Coop>();
    b = std::dynamic_pointer_cast<Building>(coop);
    board.addBuilding(b);
    
    std::vector<int> tui99{ 50, 200, 600, 1400, 1700, 2000 };
    auto dc = std::make_shared<Academic>( "DC", 400, false, "Math", 0, 200, tui99 );
    b = std::dynamic_pointer_cast<Building>(dc);
    board.addBuilding(b);
    
    
    std::string testing = "-testing";
    std::string load = "-load";
    for( int i = 1; i < argc; i++ ) {
        if( argv[i] == testing ) {
            testMode = true;
        } else if ( argv[i] == load ) {
            infile.open( argv[argc-1] );
        }
    }
    
    std::string line;
    if ( infile.is_open() ) {
        getline ( infile, line );
        int numPlayers = std::stoi(line);
        std::string name;
        std::string s1;
        std::string s2;
        std::string s3;
        char c;
        int cups;
        int money;
        int position;
        int TimsLine;
        int turn;
        int improvements;
        std::string owner;
        for ( int i = 0; i < numPlayers; i++ ) {
            getline ( infile, line );
            std::istringstream iss(line);
            iss >> s1;
            if ( iss >> c && iss >> cups ) {
                name = s1;
                iss >> money;
                iss >> position;
            } else {
                std::istringstream iss1(line);
                iss1 >> s1;
                iss1 >> s2;
                if ( iss1 >> c && iss1 >> cups ) {
                    name = s1 + " "  + s2;
                    iss1 >> money;
                    iss1 >> position;
                } else {
                    std::istringstream iss2(line);
                    iss2 >> s1;
                    iss2 >> s2;
                    iss2 >> s3;
                    name = s1 + " "  + s2 + " " + s3;
                    iss2 >> c;
                    iss2 >> cups;
                    iss2 >> money;
                    iss2 >> position;
                }
            }
            
            if ( cups > 0 ) {
                slc1->addCup(-1*cups);
                slc2->addCup(-1*cups);
                slc3->addCup(-1*cups);
                needles1->addCup(-1*cups);
                needles2->addCup(-1*cups);
                needles3->addCup(-1*cups);
            }
            
            auto dc = std::dynamic_pointer_cast<DC>(board.getBuilding(10));
            dc->addTurns(c,-1);
            if ( position == 10 ) {
                iss >> TimsLine;
                if ( TimsLine == 1 ) {
                    iss >> turn;
                    auto line = std::dynamic_pointer_cast<DC>(board.getBuilding(10));
                    line->addTurns( c, turn+1 );
                }
            }
            auto player = std::make_shared<Player>( money, name, c, cups, position );
            board.addPlayer(player);
            board.update(board.getBuilding(position));
        }
        
    
        while( getline( infile, line ) ) {
            std::istringstream iss(line);
            iss >> name;
            iss >> owner;
            iss >> improvements;
            
            auto player = board.getPlayer(owner);
            if (player) {
                if ( name == "AL" ) {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(1));
                    player->addProperty(board.getBuilding(1));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            al->incImprovements();
                        }
                        board.update(board.getBuilding(1));
                    }
                }
                
                if ( name == "ML") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(3));
                    player->addProperty(board.getBuilding(3));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            ml->incImprovements();
                        }
                        board.update(board.getBuilding(3));
                    }
                }
                
                if ( name == "MKV") {
                    auto a = std::dynamic_pointer_cast<Residences>(board.getBuilding(5));
                    player->addProperty(board.getBuilding(5));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    }
                }
                
                if ( name == "ECH") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(6));
                    player->addProperty(board.getBuilding(6));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            ech->incImprovements();
                        }
                        board.update(board.getBuilding(6));
                    }
                }
                
                if ( name == "PAS") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(8));
                    player->addProperty(board.getBuilding(8));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            pas->incImprovements();
                        }
                        board.update(board.getBuilding(1));
                    }
                }
                
                if ( name == "HH") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(9));
                    player->addProperty(board.getBuilding(9));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            hh->incImprovements();
                        }
                        board.update(board.getBuilding(9));
                    }
                }
                
                if ( name == "RCH") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(11));
                    a->setOwner(player);
                    player->addProperty(board.getBuilding(11));
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            rch->incImprovements();
                        }
                        board.update(board.getBuilding(11));
                    }
                }
                
                if ( name == "PAC") {
                    auto a = std::dynamic_pointer_cast<Gym>(board.getBuilding(12));
                    player->addProperty(board.getBuilding(12));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    }
                }
                
                if ( name == "DWE") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(13));
                    player->addProperty(board.getBuilding(13));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            dwe->incImprovements();
                        }
                        board.update(board.getBuilding(13));
                    }
                }
                
                if ( name == "CPH") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(14));
                    player->addProperty(board.getBuilding(14));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            cph->incImprovements();
                        }
                        board.update(board.getBuilding(14));
                    }
                }
                
                if ( name == "UWP") {
                    auto a = std::dynamic_pointer_cast<Residences>(board.getBuilding(15));
                    player->addProperty(board.getBuilding(15));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    }
                }
                
                if ( name == "LHI") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(16));
                    player->addProperty(board.getBuilding(16));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            lhi->incImprovements();
                        }
                        board.update(board.getBuilding(16));
                    }
                }
                
                if ( name == "BMH") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(18));
                    player->addProperty(board.getBuilding(18));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            bmh->incImprovements();
                        }
                        board.update(board.getBuilding(18));
                    }
                }
                
                if ( name == "OPT") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(19));
                    player->addProperty(board.getBuilding(19));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            opt->incImprovements();
                        }
                        board.update(board.getBuilding(19));
                    }
                }
                
                if ( name == "EV1") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(21));
                    player->addProperty(board.getBuilding(21));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            ev1->incImprovements();
                        }
                        board.update(board.getBuilding(21));
                    }
                }
                
                if ( name == "EV2") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(23));
                    player->addProperty(board.getBuilding(23));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            ev2->incImprovements();
                        }
                        board.update(board.getBuilding(23));
                    }
                }
                
                if ( name == "EV3") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(24));
                    player->addProperty(board.getBuilding(24));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            ev3->incImprovements();
                        }
                        board.update(board.getBuilding(24));
                    }
                }
                
                if ( name == "V1") {
                    auto a = std::dynamic_pointer_cast<Residences>(board.getBuilding(25));
                    player->addProperty(board.getBuilding(25));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    }
                }
                
                if ( name == "PHYS") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(26));
                    player->addProperty(board.getBuilding(26));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            phys->incImprovements();
                        }
                        board.update(board.getBuilding(26));
                    }
                }
                
                if ( name == "B1") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(27));
                    player->addProperty(board.getBuilding(27));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            b1->incImprovements();
                        }
                        board.update(board.getBuilding(27));
                    }
                }
                
                if ( name == "CIF") {
                    auto a = std::dynamic_pointer_cast<Gym>(board.getBuilding(28));
                    player->addProperty(board.getBuilding(28));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    }
                }
                
                if ( name == "B2") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(29));
                    player->addProperty(board.getBuilding(29));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            b2->incImprovements();
                        }
                        board.update(board.getBuilding(29));
                    }
                }
                
                if ( name == "EIT") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(31));
                    player->addProperty(board.getBuilding(31));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            eit->incImprovements();
                        }
                        board.update(board.getBuilding(31));
                    }
                }
                
                if ( name == "ESC") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(32));
                    player->addProperty(board.getBuilding(32));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            esc->incImprovements();
                        }
                        board.update(board.getBuilding(32));
                    }
                }
                
                if ( name == "C2") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(34));
                    player->addProperty(board.getBuilding(34));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            c2->incImprovements();
                        }
                        board.update(board.getBuilding(34));
                    }
                }
                
                if ( name == "REV") {
                    auto a = std::dynamic_pointer_cast<Residences>(board.getBuilding(35));
                    player->addProperty(board.getBuilding(35));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    }
                }
                
                if ( name == "MC") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(37));
                    player->addProperty(board.getBuilding(37));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            mc->incImprovements();
                        }
                        board.update(board.getBuilding(37));
                    }
                }
                
                if ( name == "DC") {
                    auto a = std::dynamic_pointer_cast<Academic>(board.getBuilding(39));
                    player->addProperty(board.getBuilding(39));
                    a->setOwner(player);
                    if ( improvements == -1 ) {
                        a->mortgage();
                    } else {
                        for( int i = 0; i < improvements; i++ ) {
                            dc->incImprovements();
                        }
                        board.update(board.getBuilding(39));
                    }
                }
            }
        }
        infile.close();
    } else {
        auto player1 = std::make_shared<Player>( 1500, "Goose", 'G', 0, 0 );
        auto player2 = std::make_shared<Player>( 1500, "GRT Bus", 'B', 0, 0 );
        auto player3 = std::make_shared<Player>( 1500, "Professor", 'P', 0, 0 );
        auto player4 = std::make_shared<Player>( 1500, "Student", 'S', 0, 0 );
        auto player5 = std::make_shared<Player>( 1500, "Laptop", 'L', 0, 0 );
        auto player6 = std::make_shared<Player>( 1500, "Pink tie", 'T', 0, 0 );
        board.addPlayer(player1);
        board.addPlayer(player2);
        board.addPlayer(player3);
        board.addPlayer(player4);
        board.addPlayer(player5);
        board.addPlayer(player6);
        auto dc = std::dynamic_pointer_cast<DC>(board.getBuilding(10));
        dc->addTurns('G',-1);
        dc->addTurns('B',-1);
        dc->addTurns('P',-1);
        dc->addTurns('S',-1);
        dc->addTurns('L',-1);
        dc->addTurns('T',-1);
        std::cout << board << std::endl;
    }
    
    //GamePlay
    std::cin.exceptions(std::ios::eofbit|std::ios::failbit);
    std::string cmd;
    Dice d1 = Dice();
    std::cout << board << std::endl;
    try {
        while ( std::cin >> cmd ) {
            auto p = board.getCurPlayer();
            if ( cmd == "roll") {
                
                if ( testMode ) {
                    int a;
                    int b;
                    if (std::cin >> a && std::cin >> b) {
                        int n = a +b;
                        board.movePlayer(n);
                    } else {
                        int n = d1.roll() + d2.roll();
                        board.movePlayer( n);
                    }
                } else {
                    int n = d1.roll() + d2.roll();
                    board.movePlayer(n);
                }
            } else if ( cmd == "next" ) {
                board.nextPlayer();
            }  else if ( cmd == "trade" ) {
                std::string line;
                std::string give;
                std::string receive;
                int a;
                int b;
                std::string name;
                std::string s1;
                std::string s2;
                std::string s3;
                getline(std::cin, line);
                int count = std::count(line.begin(), line.end(), ' ')+1;
                std::istringstream iss(line);
                if ( count == 4 ) {
                    iss >> name;
                    iss >> give;
                    iss >> receive;
                } else if ( count == 5 ) {
                    iss >> s1;
                    iss >> s2;
                    name = s1 + " " + s2;
                    iss >> give;
                    iss >> receive;
                } else {
                    iss >> s1;
                    iss >> s2;
                    iss >> s3;
                    name = s1 + " " + s2 + " " + s3;
                    iss >> give;
                    iss >> receive;
                }
                
                if (std::istringstream(give) >> a) {
                    if (std::istringstream(receive) >> b) {
                        std::cout << "Cannot trade money with money!!!" << std::endl;
                    } else {
                        board.trade(name, a, receive);
                    }
                } else {
                    if (std::istringstream(receive) >> b) {
                        board.trade(name, give, b);
                    } else {
                        board.trade(name, give, receive);
                    }
                }
            } else if ( cmd == "improve" ) {
                std::string s;
                std::string ss;
                if (std::cin >> s) {
                    auto b = board.findBuilding(p, s);
                    if (b != nullptr){
                        while (true) {
                            std::cin >> ss;
                            if (ss == "buy"){
                                //auto ac = std::dynamic_pointer_cast<Academic>(b);
                                board.improve( p , b->getName() );
                                break;
                            } else if (ss == "sell") {
                                auto ac = std::dynamic_pointer_cast<Academic>(b);
                                if (ac->getImprovements() != 0) {
                                    
                                    board.sellImprove(p, s);
                                    break;
                                } else {
                                    std::cout << "You don't have any improvements made on " << b->getName() << std::endl;
                                 }
                            } else {
                                std::cout << "Please enter in the following format 'improve property buy/sell'" << std::endl;
                            }
                        }
                    } else {
                        std::cin >> ss;
                        std::cout << "You don't have such building" << std::endl;
                    }
                }
            } else if ( cmd == "mortgage" ) {
                std::string s;
                if (std::cin >> s) {
                    auto b = board.findBuilding(p, s);
                    if (b != nullptr) {
                        auto c = std::dynamic_pointer_cast<Chargeable>(b);
                        board.mortgage(c->getName());
                    } else {
                        std::cout << "You don't have such building" << std::endl;
                    }
                }
            } else if ( cmd == "unmortgage" ) {
                std::string s;
                if (std::cin >> s) {
                    auto b = board.findBuilding(p, s);
                    if (b != nullptr) {
                        auto c = std::dynamic_pointer_cast<Chargeable>(b);
                        board.unmortgage(c->getName());
                    } else {
                        std::cout << "You don't have such building" << std::endl;
                    }
                }
            } else if ( cmd == "bankrupt" ) {
                auto building = board.getBuilding(board.getCurPlayer()->getCurBuilding());
                std::string buildName = building->getName();
                if ( buildName == "CIF" || buildName == "PAC" || buildName == "V1" || buildName == "UWP" || buildName == "REV" ||
                     buildName == "MKV" || buildName == "AL"  || buildName == "ML" || buildName == "ECH" || buildName == "PAS" ||
                     buildName == "HH"  || buildName == "RCH" || buildName == "DWE"|| buildName == "CPH" || buildName == "LHI" ||
                     buildName == "BMH" || buildName == "OPT" || buildName == "EV1"|| buildName == "EV2" || buildName == "EV3" ||
                     buildName == "PHYS"|| buildName == "B1"  || buildName == "B2" || buildName == "EIT" || buildName == "ESC" ||
                     buildName == "C2"  || buildName == "MC"  || buildName == "DC" ) {
                    auto chargeable = std::dynamic_pointer_cast<Chargeable>(building);
                    auto owner = chargeable->getOwner();
                    board.bankrupt(owner);
                } else {
                    board.bankrupt();
                }
                int size = board.getNumPlayers();
                if ( size == 1 ) {
                    std::cout << "Only one players left. The winner of this game is: " << board.getCurPlayer()->getName() << std::endl;
                }
            } else if ( cmd == "assets" ) {
                if (p->getCurBuilding() == 4) {
                    std::cout << "You cannot see your assets while paying tuition" << std::endl;
                } else {
                    board.getAssets();
                }
            } else if ( cmd == "all") {
                if (p->getCurBuilding() == 4) {
                    std::cout << "You cannot see the assets of every player while paying tuition" << std::endl;
                } else {
                    board.getAllAssets();
                }
            } else if ( cmd == "save" ) {
                std::string filename;
                std::cin >> filename;
                std::ofstream outfile; 
                outfile.open(filename);
                if ( outfile.is_open() ) {
                    int n = board.getNumPlayers();
                    outfile << std::to_string(n) << "\n"; 
                    for( int i = 0; i < n; i++ ) {
                        auto curPlayer = board.getCurPlayer();
                        outfile << curPlayer->getName() << " ";
                        outfile << curPlayer->getChar() << " ";
                        outfile << curPlayer->getCup() << " ";
                        outfile << curPlayer->getMoney() << " ";
                        outfile << curPlayer->getCurBuilding() << " ";
                        
                        if ( curPlayer->getCurBuilding() == 10 ) {
                            auto dc = std::dynamic_pointer_cast<DC>(board.getBuilding(10));
                            int turns = dc->getTurns(curPlayer->getChar());
                            if ( turns != -1 ) {
                                outfile << "1 " << std::to_string(turns) << "\n";
                            } else {
                                outfile << "0\n";
                            }
                        } else {
                            outfile << "\n";
                        }
                        board.nextPlayer();
                    }
                    outfile << al->getName() << " ";
                    if ( al->getOwner() ) {
                        outfile << al->getOwner()->getName() << " ";
                        if ( al->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(al->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << ml->getName() << " ";
                    if ( ml->getOwner() ) {
                        outfile << ml->getOwner()->getName() << " ";
                        if ( ml->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(ml->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << mkv->getName() << " ";
                    if ( mkv->getOwner() ) {
                        outfile << mkv->getOwner()->getName() << " ";
                        if ( mkv->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << "0 \n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << ech->getName() << " ";
                    if ( ech->getOwner() ) {
                        outfile << ech->getOwner()->getName() << " ";
                        if ( ech->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(ech->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << pas->getName() << " ";
                    if ( pas->getOwner() ) {
                        outfile << pas->getOwner()->getName() << " ";
                        if ( pas->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(pas->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << hh->getName() << " ";
                    if ( hh->getOwner() ) {
                        outfile << hh->getOwner()->getName() << " ";
                        if ( hh->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(hh->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << rch->getName() << " ";
                    if ( rch->getOwner() ) {
                        outfile << rch->getOwner()->getName() << " ";
                        if ( rch->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(rch->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << pac->getName() << " ";
                    if ( pac->getOwner() ) {
                        outfile << pac->getOwner()->getName() << " ";
                        if ( pac->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << "0 \n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << dwe->getName() << " ";
                    if ( dwe->getOwner() ) {
                        outfile << dwe->getOwner()->getName() << " ";
                        if ( dwe->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(dwe->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << cph->getName() << " ";
                    if ( cph->getOwner() ) {
                        outfile << cph->getOwner()->getName() << " ";
                        if ( cph->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(cph->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << uwp->getName() << " ";
                    if ( uwp->getOwner() ) {
                        outfile << uwp->getOwner()->getName() << " ";
                        if ( uwp->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << "0 \n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << lhi->getName() << " ";
                    if ( lhi->getOwner() ) {
                        outfile << cph->getOwner()->getName() << " ";
                        if ( lhi->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(lhi->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << bmh->getName() << " ";
                    if ( bmh->getOwner() ) {
                        outfile << bmh->getOwner()->getName() << " ";
                        if ( bmh->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(bmh->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << opt->getName() << " ";
                    if ( opt->getOwner() ) {
                        outfile << opt->getOwner()->getName() << " ";
                        if ( opt->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(opt->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << ev1->getName() << " ";
                    if ( ev1->getOwner() ) {
                        outfile << ev1->getOwner()->getName() << " ";
                        if ( ev1->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(ev1->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << ev2->getName() << " ";
                    if ( ev2->getOwner() ) {
                        outfile << ev2->getOwner()->getName() << " ";
                        if ( ev2->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(ev2->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << ev3->getName() << " ";
                    if ( ev3->getOwner() ) {
                        outfile << ev3->getOwner()->getName() << " ";
                        if ( ev3->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(ev3->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << v1->getName() << " ";
                    if ( v1->getOwner() ) {
                        outfile << v1->getOwner()->getName() << " ";
                        if ( v1->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << "0 \n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << phys->getName() << " ";
                    if ( phys->getOwner() ) {
                        outfile << phys->getOwner()->getName() << " ";
                        if ( phys->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(phys->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << b1->getName() << " ";
                    if ( b1->getOwner() ) {
                        outfile << b1->getOwner()->getName() << " ";
                        if ( b1->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(b1->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << cif->getName() << " ";
                    if ( cif->getOwner() ) {
                        outfile << cif->getOwner()->getName() << " ";
                        if ( cif->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << "0 \n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << b2->getName() << " ";
                    if ( b2->getOwner() ) {
                        outfile << b2->getOwner()->getName() << " ";
                        if ( b2->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(b2->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << eit->getName() << " ";
                    if ( eit->getOwner() ) {
                        outfile << eit->getOwner()->getName() << " ";
                        if ( eit->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(eit->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << esc->getName() << " ";
                    if ( esc->getOwner() ) {
                        outfile << esc->getOwner()->getName() << " ";
                        if ( esc->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(esc->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << c2->getName() << " ";
                    if ( c2->getOwner() ) {
                        outfile << c2->getOwner()->getName() << " ";
                        if ( b2->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(c2->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << rev->getName() << " ";
                    if ( rev->getOwner() ) {
                        outfile << rev->getOwner()->getName() << " ";
                        if ( rev->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << "0 \n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << mc->getName() << " ";
                    if ( mc->getOwner() ) {
                        outfile << mc->getOwner()->getName() << " ";
                        if ( mc->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(mc->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    
                    outfile << dc->getName() << " ";
                    if ( dc->getOwner() ) {
                        outfile << dc->getOwner()->getName() << " ";
                        if ( dc->getMortgage() ) {
                            outfile << "-1 \n";
                        } else {
                            outfile << std::to_string(dc->getImprovements()) << "\n";
                        }
                    } else {
                        outfile << "BANK 0\n";
                    }
                    outfile.close();
                    
                } else {
                    std::cout << "Unable to open " << filename << " ." << std::endl;
                }
                
            } else if ( cmd == "give" ) {
                std::string line;
                int amount;
                std::string give;
                std::string name;
                std::string s1;
                std::string s2;
                std::string s3;
                getline(std::cin, line);
                int count = std::count(line.begin(), line.end(), ' ')+1;
                std::istringstream iss(line);
                if ( count == 3 ) {
                    iss >> name;
                    iss >> give;
                } else if ( count == 4 ) {
                    iss >> s1;
                    iss >> s2;
                    name = s1 + " " + s2;
                    iss >> give;
                } else {
                    iss >> s1;
                    iss >> s2;
                    iss >> s3;
                    name = s1 + " " + s2 + " " + s3;
                    iss >> give;
                }
                
                if (std::istringstream(give) >> amount) {
                    board.give(name, amount);
                } else {
                    std::cout << "Please follow the format: give [name] [amount]" << std::endl;
                }
            } else if ( cmd == "q" ) {
                break;
            } else {
                std::cout << "Invalid command!" << std::endl;
            } // if
            std::cout << board << std::endl;
        } // while
    } catch (std::ios::failure &) {}  // Any I/O failure quits
}

