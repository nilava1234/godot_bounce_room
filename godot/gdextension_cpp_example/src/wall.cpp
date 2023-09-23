#include "wall.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void wall::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_normal_x", "n"), &wall::set_normal_x);
    ClassDB::bind_method(D_METHOD("set_normal_y", "n"), &wall::set_normal_y);
    ClassDB::bind_method(D_METHOD("set_normal_z", "n"), &wall::set_normal_z);

    ClassDB::bind_method(D_METHOD("get_normal_x"), &wall::get_normal_x);
    ClassDB::bind_method(D_METHOD("get_normal_y"), &wall::get_normal_y);
    ClassDB::bind_method(D_METHOD("get_normal_z"), &wall::get_normal_z);

    ClassDB::bind_method(D_METHOD("get_normal_vector"), &wall::get_normal_vector);


    ClassDB::add_property("wall", PropertyInfo(Variant::FLOAT, "normal_x"), "set_normal_x", "get_normal_x");
    ClassDB::add_property("wall", PropertyInfo(Variant::FLOAT, "normal_y"), "set_normal_y", "get_normal_y");
    ClassDB::add_property("wall", PropertyInfo(Variant::FLOAT, "normal_z"), "set_normal_z", "get_normal_z");

}

wall::wall() {
    // Initialize any variables here.
    normal_x = 0;
    normal_y = 0;
    normal_z = 0;
}

wall::~wall() {
    // Add your cleanup here.
}

void wall::_process(double delta) {
}

float wall::get_normal_x()
{
    return normal_x;
}
float wall::get_normal_y()
{
    return normal_y;
}
float wall::get_normal_z()
{
    return normal_z;
}

void wall::set_normal_x(float n)
{
    normal_x = n;
}
void wall::set_normal_y(float n)
{
    normal_y = n;
}
void wall::set_normal_z(float n)
{
    normal_z = n;
}

Vector3 wall::get_normal_vector()
{
    return Vector3(normal_x, normal_y, normal_z);
}