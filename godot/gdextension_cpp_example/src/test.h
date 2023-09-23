#ifndef test_H
#define test_H

#include <godot_cpp/classes/sprite3d.hpp>

namespace godot {

class test : public Sprite3D {
    GDCLASS(test, Sprite3D)

private:
    double time_passed;

protected:
    static void _bind_methods();

public:
    test();
    ~test();

    void _process(double delta);
};

}

#endif