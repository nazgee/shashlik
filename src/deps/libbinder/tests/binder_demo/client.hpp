#ifndef __DK_CLIENT__
#define __DK_CLIENT__

#include "utils.hpp"
#include "idkinterface.hpp"

// this is only just a part of protocol implementation, it just took pack data and send it
// through binder

class BpDKInterface : public android::BpInterface<IDKInterface>
{
public:
    BpDKInterface(const android::sp<android::IBinder>& impl)
        : android::BpInterface<IDKInterface>(impl) {
        LOGD("DKClient ctor");
    }

    virtual void sendInt(int32_t data);
    virtual void sendString8(android::String8 data);
};

#endif
