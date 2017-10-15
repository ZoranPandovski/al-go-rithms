#ifndef FUNCTION_OBJECT_H
#define FUNCTION_OBJECT_H

template <class T>
struct Greatest{
  inline bool operator()(T a,T b){
    return a<b;
  }
};

template <class T>
struct Less{
  inline bool operator()(T a,T b){
    return a>b;
  }
};


#endif // FUNCTION_OBJECT_H
