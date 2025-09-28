#ifndef __FRAME_HPP
#define __FRAME_HPP

class Frame {
};

class SmallFrame: public Frame {
    char data[128];
};

class BigFrame: public Frame {
    char data[65536000];
};

#endif