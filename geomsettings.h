#ifndef GEOMSETTINGS_H
#define GEOMSETTINGS_H

//Class for overall geom settings for all objects
//may be expanded for new types of geometry
class GeomSettings
{
public:
    GeomSettings();

    double size1 = 0.5;
    double size2 = 0.5;

    //... other params for diferent objects
};

#endif // GEOMSETTINGS_H
