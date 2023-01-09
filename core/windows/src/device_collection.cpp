#include <volume/core/windows/device_collection.hpp>

namespace vol::win {

DeviceCollection::~DeviceCollection() {
  if (is_ok()) p->Release();
}

StatusOf<UINT> DeviceCollection::count() {
  StatusOf<UINT> res;
  res.hr = p->GetCount(&res.val);
  return res;
}

Device DeviceCollection::get(UINT id) {
  Device res;
  res.hr = p->Item(id, &res.p);
  return res;
}

}  // namespace vol::win
