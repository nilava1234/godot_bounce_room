#include "ball.h"
#include "wall.h"
#include <stdlib.h>     /* srand, rand */
#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void ball::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_ball_area_entered", "entered"), &ball::on_ball_area_entered);
    ClassDB::bind_method(D_METHOD("set_speed", "n"), &ball::set_speed);

    ClassDB::bind_method(D_METHOD("get_speed"), &ball::get_speed);

    ClassDB::add_property("ball", PropertyInfo(Variant::INT, "speed"), "set_speed", "get_speed");
}

ball::ball() {
    // Initialize any variables here.
    speedScale = Vector3( (rand()%5) - 5, (rand()%5) - 5, (rand()%5) - 5);
    speed = 100;
}

ball::~ball() {
    // Add your cleanup here.
}
void ball:: _ready()
{
    set_position(Vector3(0, 0, 0));
    connect("area_entered", Callable(this,"on_ball_area_entered"));
}

void ball::_process(double delta) {
    speedScale.normalize();
    Vector3 position = get_position();
    printf("Speed: %d\n", (int)speed);
    position.x += (speedScale.x * speed * delta);
    position.y += (speedScale.y * speed * delta);
    position.z += (speedScale.z * speed * delta);

    set_position(position);
}

void ball :: on_ball_area_entered(Area3D *entered){
    //printf("HIT");
    wall* a_wall = Object::cast_to<wall>(entered);
    if(a_wall)
    {
        Vector3 N = a_wall->get_normal_vector();
        Vector3 I = speedScale;

        speedScale = I - 2 * N * (N*I) ;

    }else
    {
        Vector3 N = entered->get_position() - get_position();
        Vector3 I = speedScale;

        speedScale = I - 2 * N * (N*I);
    }
    
    
}

double ball ::get_speed()
{
    return speed;
}

void ball :: set_speed(const double p_speed)
{
    speed = p_speed;
}

