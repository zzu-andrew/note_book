//
// Created by wangyz38535 on 2024/5/6.
//


#include <iostream>
#include <string>
#include <vector>
#include "track_new/track_new.h"

int main()
{
    TrackNew::reset();

    std::vector<std::string> coll;
    for (int i = 0; i < 1000; ++i) {
        coll.emplace_back("just a non-SSO string");
    }

    TrackNew::status();
}


