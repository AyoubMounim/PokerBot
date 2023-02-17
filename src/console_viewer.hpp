
#ifndef CONSOLE_VIEWER
#define CONSOLE_VIEWER

#include "viewer.hpp"

struct Card;
struct Hand;
struct Table;


class ConsoleViewer: public Viewer{
  public:
    ConsoleViewer();
    void renderCard(Card *card);
    void renderHand(Hand *hand);
    void renderTable(Table *table);
};


#endif