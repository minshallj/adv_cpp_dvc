// Float_array.h
// jacob minshall

#ifndef _Float_array_h
#define _Float_array_h

class Float_array{
  public:
    Float_array(int);
    ~Float_array();

    void add_member(float, int);
    float return_member(int);

    int get_fill_len();
    float max();
    float min();
    float mean();
  protected:
    float * arr;
    int allocated_len, filled_len;

    void grow_array();
};

#endif
