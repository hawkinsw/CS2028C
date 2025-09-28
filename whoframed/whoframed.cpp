#include <iostream>
#include "include/frame.hpp"
#include "include/utils.hpp"

Frame *get_frame() {
    Frame *next_frame{new BigFrame{}};
    return next_frame;
}

int main() {
    while (more_frames()) {
        Frame *current_frame{get_frame()};
    }
}