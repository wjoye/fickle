// Copyright (C) 1999-2016
// Smithsonian Astrophysical Observatory, Cambridge, MA, USA
// For conditions of distribution and use, see copyright notice in "copyright"

#ifndef __polygon_h__
#define __polygon_h__

#include "basepolygon.h"
#include "marker.h"
#include "list.h"

class Polygon : public BasePolygon {
 protected:
  int isInRef(const Vector& v);
  void renderX(Drawable, Coord::InternalSystem, RenderMode);
  void renderPS(int);
#ifdef MAC_OSX_TK
  void renderMACOSX();
#endif
#ifdef __WIN32
  void renderWIN32();
#endif

public:
  Polygon(Base* p, const Vector& ctr,
	  const Vector& b);
  Polygon(Base* p, const Vector& ctr,
	  const Vector& b,
	  const char* clr, int* dsh,
	  int wth, const char* fnt, const char* txt,
	  unsigned short prop, const char* cmt,
	  const List<Tag>& tg, const List<CallBack>& cb);
  Polygon(Base* p, const List<Vertex>& v, 
	  const char* clr, int* dsh,
	  int wth, const char* fnt, const char* txt,
	  unsigned short prop, const char* cmt,
	  const List<Tag>& tg, const List<CallBack>& cb);
  Polygon(const Polygon& a) : BasePolygon(a) {}

  Marker* dup() {return new Polygon(*this);}

  void analysis(AnalysisTask, int);
  void analysisHistogram(char*, char*, int);
  void analysisPlot3d(char*, char*, Coord::CoordSystem, Marker::AnalysisMethod);
  void analysisStats(Coord::CoordSystem, Coord::SkyFrame sky);

  int isIn(const Vector& vv) {return isIn(vv, Coord::CANVAS);}
  int isIn(const Vector& vv, Coord::InternalSystem sys)
  {return isInRef(bckMap(vv,sys));}

  int isIn(const Vector& vv, const Matrix& bck)
  {return isInRef(vv*bck);}

  int getSegment(const Vector&);
  void reset(const Vector&);

  void list(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat, int, int);
  void listCiao(ostream&, Coord::CoordSystem, int);
  void listSAOtng(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat, int);
  void listSAOimage(ostream&, int);
  void listPros(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat, int);
};

#endif
