#ifndef wall_H
#define wall_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class wall : public Area3D {
    GDCLASS(wall, Area3D)

private:
    float normal_x;
    float normal_y;
    float normal_z;

protected:
    static void _bind_methods();

public:
    wall();
    ~wall();

    void _process(double delta);
    float get_normal_x();
    float get_normal_y();
    float get_normal_z();

    void set_normal_x(float n);
    void set_normal_y(float n);
    void set_normal_z(float n);

    Vector3 get_normal_vector();
};

}

#endif