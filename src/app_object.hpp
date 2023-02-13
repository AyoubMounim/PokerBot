
#ifndef APP_OBJECT
#define APP_OBJECT


class AppObject{
  public:
    virtual void render() = 0;

  protected:
    AppObject(){}
};

#endif