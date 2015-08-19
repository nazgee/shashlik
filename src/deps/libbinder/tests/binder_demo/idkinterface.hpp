#ifndef __DK_IDKDEMO__
#define __DK_IDKDEMO__

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <utils/String8.h>

// defines communication protocol through binder. It just declares methods which can be
// executed via binder

class IDKInterface : public android::IInterface
{
public:
    enum {
        SEND_INT = 0x13,
        SEND_TEXT
    };

    // sends int to server
    virtual void sendInt(int32_t data) = 0;
    // sends String8 to server
    virtual void sendString8(android::String8 data) = 0;
    DECLARE_META_INTERFACE(DKInterface);
};

#endif
