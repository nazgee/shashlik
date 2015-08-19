#ifndef __DK_SERVER__
#define __DK_SERVER__

#include "utils.hpp"
#include <binder/IInterface.h>
#include <binder/IBinder.h>

#include "idkinterface.hpp"

// implementation of protocol from server side, itcontains only information how to unpack data
// from binder
class BnDKServer : public android::BnInterface<IDKInterface>
{
    virtual android::status_t onTransact(uint32_t code, const android::Parcel& data, android::Parcel* reply, uint32_t flags = 0);
};

// the server implementation, it could be done in above class, but the convention is to separate
// protocol implementation from server implementation
class DKServer : public BnDKServer
{
    virtual void sendInt(int32_t data) {
        LOGD("DKServer sendInt(%i)", data);
    }

    virtual void sendString8(android::String8 data) {
        LOGD("DKServer sendString8(%s)", (char*)data.string());
    }
};

#endif
