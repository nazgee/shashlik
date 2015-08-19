#include "client.hpp"

#include <binder/Parcel.h>

using namespace android;

void BpDKInterface::sendInt(int32_t _data)
{
    LOGD("send %i", _data);
    Parcel data, reply;
    data.writeInterfaceToken(IDKInterface::getInterfaceDescriptor());
    data.writeInt32(_data);
    remote()->transact(SEND_INT, data, &reply);
}

void BpDKInterface::sendString8(String8 data)
{
    LOGD("sendString %s", (char*)data.string());
    Parcel d, r;
    d.writeInterfaceToken(IDKInterface::getInterfaceDescriptor());
    d.writeString8(data);
    remote()->transact(SEND_INT, d, &r);}


