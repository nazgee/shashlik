#include "server.hpp"
#include <binder/Parcel.h>

using namespace android;

status_t BnDKServer::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    LOGD("onTransact - code: %i; flags: %i", code, flags);
    // this is really needed, without this, there is a garbage read from binder
    // I don't know how it really works
    data.checkInterface(this);
    switch(code) {
        case SEND_INT: {
            int32_t inData = data.readInt32();
            sendInt(inData);
            return NO_ERROR;
        }
        case SEND_TEXT: {
            String8 str = data.readString8();
            sendString8(str);
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}
