#ifndef BALL_H
#define BALL_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class ball : public Area3D {
    GDCLASS(ball, Area3D)

private:
    Vector3 speedScale;
    int speed;
protected:
    static void _bind_methods();

public:
    
    ball();
    ~ball();

    void on_ball_area_entered(Area3D *entered);

    void _ready();
    void _process(double delta);

    double get_angle();
    void set_angle (const double p_angle);
    
    double get_speed();
    void set_speed (const double p_speed);

};

}

#endif