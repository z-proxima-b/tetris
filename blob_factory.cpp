#include <stdexcept>
#include "blob.h"
#include "blob_factory.h"
#include "coordinate.h"
#include "raylib.h"

class s_blob : public blob
{
  public:
    s_blob() : blob(S_BLOB)
    {
      orientation data[4] = 
      {
        {{{0,1},{0,2},{1,0},{1,1}}},
        {{{0,1},{1,1},{1,2},{2,2}}},
        {{{1,1},{1,2},{2,0},{2,1}}},
        {{{0,0},{1,0},{1,1},{2,1}}}
      };  
      set_cell_data(data);
    }
};

class t_blob : public blob
{
  public:
    t_blob() : blob(T_BLOB)
    {
      orientation data[4] = 
      {
        {{{0,1},{1,0},{1,1},{1,2}}},
        {{{0,1},{1,1},{1,2},{2,1}}},
        {{{1,0},{1,1},{1,2},{2,1}}},
        {{{0,1},{1,0},{1,1},{2,1}}}
     };  
      set_cell_data(data);
    }
};

class z_blob : public blob
{
  public:
    z_blob() : blob(Z_BLOB)
    {
      orientation data[4] = 
      {
        {{{0,0},{0,1},{1,1},{1,2}}},
        {{{0,2},{1,1},{1,2},{2,1}}},
        {{{1,1},{1,2},{2,1},{2,2}}},
        {{{0,1},{1,0},{1,1},{2,0}}}
      };  
      set_cell_data(data);
    }
};

class i_blob : public blob
{
  public:
  i_blob() : blob(I_BLOB)
  {
    orientation data[4] = 
    {
      {{{0,1},{1,1},{2,1},{3,1}}},
      {{{1,0},{1,1},{1,2},{1,3}}},
      {{{0,2},{1,2},{2,2},{3,2}}},
      {{{2,0},{2,1},{2,2},{2,3}}}
    };  
    set_cell_data(data);
  }
};

class box_blob : public blob
{
  public:
  box_blob() : blob(BOX_BLOB)
  {
    orientation data[4] = 
    { 
      {{{1,1},{1,2},{2,1},{2,2}}},
      {{{1,1},{1,2},{2,1},{2,2}}},
      {{{1,1},{1,2},{2,1},{2,2}}},
      {{{1,1},{1,2},{2,1},{2,2}}},
    };  
    set_cell_data(data);
  }
};

class l_blob : public blob
{
  public:
  l_blob() : blob(L_BLOB)
  {
    orientation data[4] = 
    {
      {{{0,0},{1,0},{2,0},{2,1}}},
      {{{0,0},{0,1},{0,2},{1,0}}},
      {{{0,1},{0,2},{1,2},{2,2}}},
      {{{2,0},{2,1},{2,2},{1,2}}}
    };  
    set_cell_data(data);
  }
};

class r_blob : public blob
{
  public:
  r_blob() : blob(R_BLOB)
  {
    orientation data[4] = 
    {
      {{{0,0},{0,1},{1,0},{2,0}}},
      {{{0,0},{0,1},{0,2},{1,2}}},
      {{{0,2},{1,2},{2,2},{2,1}}},
      {{{1,0},{2,0},{2,1},{2,2}}}
    };  
    set_cell_data(data);
  }
};

blob make_blob(blob_type type)
{
  TraceLog(LOG_DEBUG, "%s:: %d", __FUNCTION__, static_cast<int>(type));
  switch(type)
  {
    case S_BLOB: return s_blob();
    case T_BLOB: return t_blob();
    case Z_BLOB: return z_blob();
    case I_BLOB: return i_blob();
    case BOX_BLOB: return box_blob();
    case L_BLOB: return l_blob();
    case R_BLOB: return r_blob();
    default: break;
  }
  throw std::invalid_argument("unknown blob type");  
}
