
#ifndef VIEWER
#define VIEWER


struct Card;
struct Hand;
struct Table;


class Viewer{
  public:
    virtual void renderCard(Card *card) = 0;
    virtual void renderHand(Hand *hand) = 0;
    virtual void renderTable(Table *table) = 0;
  
  protected:
    Viewer(){};
};


#endif