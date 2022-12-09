

#ifndef MOTEUSWRAPPER_H__
#define MOTEUSWRAPPER_H__

#include <cassert>
#include <vector>

#include "MoteusAPI.h"
#include "moteus_protocol.h"

using namespace std;

class MoteusWrapper {
 public:
  vector<MoteusAPI> drivers;
  MoteusWrapper(vector<string> dev_name, vector<int> moteus_id) {
    assert((dev_name.size() != moteus_id.size()) &&
           "Length of dev_name and moteus_id vector does not match");
    for (int i = 0; i < dev_name.size(); i++) {
      MoteusAPI api(dev_name[i], moteus_id[i]);
      drivers.push_back(api);
    };
  };
  ~MoteusWrapper();
};

#endif