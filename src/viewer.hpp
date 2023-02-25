
#ifndef VIEWER
#define VIEWER


struct Card;
struct Hand;
struct Table;
struct Point;


class Viewer{
  public:
    virtual void renderCard(Card *card) = 0;
    virtual void renderHand(Hand *hand) = 0;
    virtual void renderTable(Table *table) = 0;
    virtual void renderRating(float rating) = 0;
    virtual void renderPoint(Point *pPoint) = 0;
  
  protected:
    Viewer(){};
};


#endif