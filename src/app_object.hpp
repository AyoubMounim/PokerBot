
#ifndef app_object
#define app_object


class AppObject{
  public:
    virtual void render() = 0;

  protected:
    AppObject(){}
};

#endif