#include "test.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void test::_bind_methods() {
}

test::test() {
    // Initialize any variables here.
    time_passed = 0.0;
}

test::~test() {
    // Add your cleanup here.
}

void test::_process(double delta) {
    time_passed += delta;

    Vector3 new_position = Vector3(
        10.0 + (10.0 * sin(time_passed * 2.0)), 
        10.0 + (10.0 * cos(time_passed * 1.5)),
        10.0 + (10.0 * sin(time_passed * 2.0))
        );

    set_position(new_position);
}